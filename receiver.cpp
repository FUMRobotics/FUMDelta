#include "receiver.h"
#include "qdebug.h"
#include <QVector>

FILE* Receiver::fp;
int Receiver::qID;
void Receiver::run()
{
    receiverBase();
}

Receiver::Receiver(QObject *parent) : QThread (parent)
{
    qDebug("listening...");
}
void Receiver::print_config(void)
{
    qDebug("\nLOG is defined. Number of cycles = %ld\n", NUMBER_OF_CYCLES);
    qDebug("FLUSH_CYCLE = %d\n\n", FLUSH_CYCLE);
}

Receiver::~Receiver()
{
    qDebug("Removing the queue...\n");
    if (!(msgctl(qID, IPC_RMID, NULL)))
        qDebug("The queue was successfully removed.\n");
    /* close the file */
    if (!fclose(fp))
        qDebug("The log file was successfully closed.\n");
    pid_t pid = getpid();
    kill(pid, SIGKILL);
}



double Receiver::motor_to_degree_position(int32_t point)
{
    return (point * 360 /static_cast<double>(NUMBER_OF_motorpulse*GEARBOX_RATIO));
}

void Receiver::calculate_motor_to_degree_array(int32_t points[4], double *ret_data){
    for(int i = 0 ; i < 4; i++){
        ret_data[i] = motor_to_degree_position(points[i]);
    }
}
void Receiver::calculate_motor_to_degree_vector(int32_t points[4], QVector<double> *retval){
//    QVector<double> retval(4);
    for(int i = 0 ; i < 4; i++){
        (*retval)[i]=motor_to_degree_position(points[i]);
    }
}

void Receiver::receiverBase()
{

   // signal(SIGINT, Receiver::signal_handler);

    print_config();

    /* SCHED_FIFO tasks are allowed to run until they have completed their work or voluntarily yield. */
    /* Note that even the lowest priority realtime thread will be scheduled ahead of any thread with a non-realtime policy;
           if only one realtime thread exists, the SCHED_FIFO priority value does not matter.
        */
//    struct sched_param param = {};
//    param.sched_priority = 20;
//    qDebug("Using priority %i.\n", param.sched_priority);
//    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1)
//    {
//        qDebug("sched_setscheduler failed\n");
//    }

//    /* Lock the program into RAM to prevent page faults and swapping */
//    /* MCL_CURRENT: Lock in all current pages.
//           MCL_FUTURE:  Lock in pages for heap and stack and shared memory.
//        */
//    //munlockall();
//    if (mlockall(MCL_CURRENT | MCL_FUTURE) == -1)
//    {
//        qDebug("mlockall failed\n");

//    }



    /* open the file */
    fp = fopen("newlog.txt", "w");

    if (fp == NULL)
    {
        qDebug("Failed to open file log.txt\n");

    }

    /* Cycle number. */
    int i = 0;


    /* key is specified by the process which creates the queue (receiver). */
    key_t qKey = 1234;

    /* IPC_CREAT: Create a new queue.*/
    int qFlag = IPC_CREAT;

    qDebug("Creating a queue with key = %d\n", qKey);

    //here first check if queue exist


    if ((qID = msgget(qKey, qFlag)) < 0)
    {
        qDebug("Queue creation failed. Terminating the process...\n");

    }
    else
        qDebug("Queue creation successful.\n");


    typedef struct receiveMassageType
    {
        /* Mandatory */
        long       mtype;
        /* Data */
        long       updatePeriod;
        int32_t    actPos[4];
        int32_t    targetPos[4];

    } receiveMassage;

    /* Received message. */
    receiveMassage recvdMsg;
    size_t msgSize;

    /* size of data = size of structure - size of mtype */
    msgSize = sizeof(struct receiveMassageType) - sizeof(long);

    /* Pick messages with type = 1. (msg.mtype = 1 in the producer) */
    int msgType = 1;

    /* No flag for receiving the message. */
    int msgFlag = 0;


    while (i != NUMBER_OF_CYCLES - 1)

        while (1)

        {

            /* Removes a message from the queue specified by qID and
               places it in the buffer pointed to by recvdMsg.
            */
            if (msgrcv(qID, &recvdMsg, msgSize, msgType, msgFlag) < 0)
            {
                qDebug("Error picking a message from the queue. Terminating the %d process...\n",errno);
                qDebug("Error picking a message from the queue. Terminating the process...\n");
                qDebug("Removing the queue...\n");
                switch (errno) {
                    case E2BIG: qDebug("The length of mtext is greater than msgsz and (msgflg & MSG_NOERROR) is zero.");
                    break;
                    case EACCES: qDebug("Operation permission is denied to the calling process. ");
                    break;
                    case EFAULT: qDebug("msgp is an invalid pointer. ");
                    break;
                    case EIDRM:  qDebug("msqid was removed.");
                    break;
                    case EINTR: qDebug("A signal interrupted the call.");
                    break;
                    case EINVAL: qDebug("msgsz is less than 0. OR msqid is not a valid message queue identifier.");
                    break;
                    case ENOMSG: qDebug("The queue does not contain a message of the desired type and (msgtyp & IPC_NOWAIT) is non-zero.");
                    break;

                }
               if (!(msgctl(qID, IPC_RMID, NULL)))
               {
                   qDebug("The queue was successfully removed.\n");
               }

                    pid_t pid = getpid();
                    kill(pid, SIGKILL);
                    quit();
            }


            /* Write data to the log.*/
            QVector<double> act_actpos(4);
            QVector<double> target_actpos(4);

            calculate_motor_to_degree_vector(recvdMsg.actPos, &act_actpos);
            calculate_motor_to_degree_vector(recvdMsg.targetPos, &target_actpos);
            //update current state
            RobotState::getInstance()->setAngles(act_actpos[0],act_actpos[1],act_actpos[2],act_actpos[3]);
            if(messageCounter%emitFrequency==0)
            {
               // double actual_data[4],target_data[4];
//                calculate_motor_to_degree_array(recvdMsg.actPos,actual_data);
//                calculate_motor_to_degree_array(recvdMsg.targetPos,target_data);
                emit newMessage(messageCounter,target_actpos, act_actpos);
            }
            messageCounter++;
            fprintf(fp, "%ld,%ld,%ld,%f,%f,%ld,%ld,%f,%f,%ld,%ld,%f,%f,%ld,%ld,%f,%f\n", recvdMsg.updatePeriod ,recvdMsg.actPos[0] ,recvdMsg.targetPos[0] ,motor_to_degree_position(recvdMsg.actPos[0]) , motor_to_degree_position(recvdMsg.targetPos[0])
                    , recvdMsg.actPos[1] ,recvdMsg.targetPos[1] ,motor_to_degree_position(recvdMsg.actPos[1]) , motor_to_degree_position(recvdMsg.targetPos[1])
                    , recvdMsg.actPos[2] ,recvdMsg.targetPos[2] ,motor_to_degree_position(recvdMsg.actPos[2]) , motor_to_degree_position(recvdMsg.targetPos[2])
                    , recvdMsg.actPos[3] ,recvdMsg.targetPos[3] ,motor_to_degree_position(recvdMsg.actPos[3]) , motor_to_degree_position(recvdMsg.targetPos[3])
                    );

            /* Print the message's data. */
//            qDebug("Motor 0 actual position: %d\n", recvdMsg.actPos[0]);
//            qDebug("Motor 1 actual position: %d\n", recvdMsg.actPos[1]);
//            qDebug("Motor 2 actual position: %d\n", recvdMsg.actPos[2]);
//            qDebug("Motor 3 actual position: %d\n", recvdMsg.actPos[3]);
//            qDebug("Motor 0 target position: %d\n", recvdMsg.targetPos[0]);
//            qDebug("Motor 1 target position: %d\n", recvdMsg.targetPos[1]);
//            qDebug("Motor 2 target position: %d\n", recvdMsg.targetPos[2]);
//            qDebug("Motor 3 target position: %d\n", recvdMsg.targetPos[3]);
//            qDebug("Update period:           %ld\n", recvdMsg.updatePeriod);



            i = i + 1;


            /* Flush the buffer every 1 minute. */
            if (i % FLUSH_CYCLE == 0)
            {
                if (fflush(fp))
                    qDebug("Flushing output stream buffer failed! %d\n", i);

            }

        }


    /* close the file */
    if (!fclose(fp))
        qDebug("The log file was successfully closed.\n");


}
