#include "receiverVision.h"
#include "qdebug.h"
#include "trajectorysender.h"
#include "robotstate.h"
#include "kinematicsexception.h"
#include <QVector>

FILE* ReceiverVision::fp;
int ReceiverVision::qID;
void ReceiverVision::run()
{
    receiverBase();
}

ReceiverVision::ReceiverVision(QObject *parent) : QThread (parent)
{
    qDebug("listening...");
}
void ReceiverVision::print_config(void)
{
    qDebug("\nLOG is defined. Number of cycles = %ld\n", NUMBER_OF_CYCLES);
    qDebug("FLUSH_CYCLE = %d\n\n", FLUSH_CYCLE);
}

ReceiverVision::~ReceiverVision()
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



double ReceiverVision::motor_to_degree_position(int32_t point)
{
    return (point * 360 /static_cast<double>(NUMBER_OF_motorpulse*GEARBOX_RATIO));
}

void ReceiverVision::calculate_motor_to_degree_array(int32_t points[4], double *ret_data){
    for(int i = 0 ; i < 4; i++){
        ret_data[i] = motor_to_degree_position(points[i]);
    }
}
void ReceiverVision::calculate_motor_to_degree_vector(int32_t points[4], QVector<double> *retval){
//    QVector<double> retval(4);
    for(int i = 0 ; i < 4; i++){
        (*retval)[i]=motor_to_degree_position(points[i]);
    }
}

void ReceiverVision::receiverBase()
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
    key_t qKey = 1239;

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

#pragma pack(push, 1)
    typedef struct
    {
        /* Mandatory */
        long       mtype;

        /* Data */
        long   updatePeriod;
        int32_t    actPos[4];
        int32_t    targetPos[4];
    } receiveMassage,*addReceiveMassage;
    #pragma pack(pop)
    typedef struct {
        long  data_type;
        //int   data_num;
        unsigned char  data_buff[73];
    } t_data;
    /* Received message. */
    t_data databuf;
//    typedef struct receiveMassageType
//    {
//        /* Mandatory */
//        long       mtype;
//        /* Data */
//        long       updatePeriod;
//        int32_t    actPos[4];
//        int32_t    targetPos[4];

//    } receiveMassage;

    /* Received message. */
//    receiveMassage recvdMsg;
    size_t msgSize;

    /* size of data = size of structure - size of mtype */
//    msgSize = sizeof(struct receiveMassageType) - sizeof(long);

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
//            if (msgrcv(qID, &recvdMsg, msgSize, msgType, msgFlag) < 0)
            if (msgrcv(qID, &databuf,  sizeof( t_data) - sizeof( long), 0, 0) < 0)
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
            addReceiveMassage rm = (addReceiveMassage)databuf.data_buff;
            receiveMassage recvdMsg = *rm;
//            qDebug("1239 got it");


            qDebug("new point recived: theta 1: %d theta 2:%d, theta 3:%d",recvdMsg.targetPos[0],recvdMsg.targetPos[1],recvdMsg.targetPos[2] );


            TrajectorySender *ts = new TrajectorySender(0,0,-0.8,(float)recvdMsg.targetPos[0] /100,(float)recvdMsg.targetPos[1]/100,(float)recvdMsg.targetPos[2]/100);

//            double inverse_start_output[3];
//            double inverse_end_output[3];
//            InverseKinematicsCore core;

//            //provide inverse kinematics with start and final positions
//            //core.InverseKinematicsNew(x_start, y_start, z_start, inverse_start_output);

//            RobotState::getInstance()->getAngles(inverse_start_output);
//            qDebug("fetched position in robot state: theta 1: %lf theta 2:%lf, theta 3:%lf",inverse_start_output[0],inverse_start_output[1],inverse_start_output[2]);
//            core.InverseKinematicsNew(recvdMsg.targetPos[0] * 10, recvdMsg.targetPos[1] * 10, recvdMsg.targetPos[2] * 10, inverse_end_output);
//            qDebug("calculate position robot: theta 1: %lf theta 2:%lf, theta 3:%lf",inverse_end_output[0],inverse_end_output[1],inverse_end_output[2]);
//            int32_t inverse_start_output2[4];
//            int32_t inverse_end_output2[4];
//            inverse_start_output2[0] = inverse_start_output[0];
//            inverse_start_output2[1] = inverse_start_output[1];
//            inverse_start_output2[2] = inverse_start_output[2];
//            inverse_end_output2[0] = inverse_end_output[0];
//            inverse_end_output2[1] = inverse_end_output[1];
//            inverse_end_output2[2] = inverse_end_output[2];
            /*---------------------------------testing inverse---------------------------------------------------*/
            //core.InverseKinematicsNew(0.000250252, 0.112717, -0.578326, inverse_start_output);
            //core.InverseKinematicsNew(0.161748, 0.117002, -0.649968, inverse_end_output);
            /*---------------------------------testing inverse---------------------------------------------------*/



            //TODO set this after send point to drive and change physical state
 //           RobotState::getInst0ance()->setAllCoordinates(inverse_end_output[0],inverse_end_output[1],inverse_end_output[2],
 //                                                        x_end, y_end, z_end);

//            if(isDistanceZero
//                    (inverse_start_output[0],inverse_end_output[0],
//                     inverse_start_output[1],inverse_end_output[1],
//                     inverse_start_output[2],inverse_end_output[2]))
//            {
//                KinematicsException expection("DISTANCE IS ZERO,DUPLICATED POINT");
//            }
            //THE FOLLOWING LINE IS COMMENTED DUE TO THE POSSIBILITY OF SERIOUS BUGS WHICH MIGHT LEAD TO SERIOUS INCIDENTS
           // RobotState::getInstance()->setAngles(inverse_end_output[0],inverse_end_output[1],inverse_end_output[2],0);
//            qDebug("newly set position in robot state: x: %lf y:%lf, z:%lf  theta 1:%lf theta 2:%lf theta 3:%lf",
//                   x_end,y_end,z_end,inverse_end_output[0],inverse_end_output[1],inverse_end_output[2]);

//            qDebug("drive 1:  data=%d  opcode=%d  data=%d  opcode=%d data=%d  opcode=%d data=%d  opcode=%d \n",
//                                    recvdMsg.actPos[0],recvdMsg.targetPos[0],
//                                    recvdMsg.actPos[1],recvdMsg.targetPos[1],
//                                    recvdMsg.actPos[2],recvdMsg.targetPos[2],
//                                    recvdMsg.actPos[3],recvdMsg.targetPos[3]);
            /* Write data to the log.*/
//            QVector<double> act_actpos(4);
//            QVector<double> target_actpos(4);

//            calculate_motor_to_degree_vector(inverse_start_output2, &act_actpos);
//            calculate_motor_to_degree_vector(inverse_end_output2, &target_actpos);
//            qDebug("drive 1:  data=%d  opcode=%d  data=%d  opcode=%d data=%d  opcode=%d data=%d  opcode=%d \n",
//                                                act_actpos[0],recvdMsg.targetPos[0],
//                                                act_actpos[1],recvdMsg.targetPos[1],
//                                                act_actpos[2],recvdMsg.targetPos[2],
//                                                act_actpos[3],recvdMsg.targetPos[3]);
////            //update current state
//            RobotState::getInstance()->setAngles(act_actpos[0],act_actpos[1],act_actpos[2],act_actpos[3]);
//            if(messageCounter%emitFrequency==0)
//            {
//               // double actual_data[4],target_data[4];
////                calculate_motor_to_degree_array(recvdMsg.actPos,actual_data);
////                calculate_motor_to_degree_array(recvdMsg.targetPos,target_data);
//                emit newMessage(messageCounter,target_actpos, act_actpos);
//            }
//            messageCounter++;
//            fprintf(fp, "%ld,%ld,%ld,%f,%f,%ld,%ld,%f,%f,%ld,%ld,%f,%f,%ld,%ld,%f,%f\n", recvdMsg.updatePeriod ,recvdMsg.actPos[0] ,recvdMsg.targetPos[0] ,motor_to_degree_position(recvdMsg.actPos[0]) , motor_to_degree_position(recvdMsg.targetPos[0])
//                    , recvdMsg.actPos[1] ,recvdMsg.targetPos[1] ,motor_to_degree_position(recvdMsg.actPos[1]) , motor_to_degree_position(recvdMsg.targetPos[1])
//                    , recvdMsg.actPos[2] ,recvdMsg.targetPos[2] ,motor_to_degree_position(recvdMsg.actPos[2]) , motor_to_degree_position(recvdMsg.targetPos[2])
//                    , recvdMsg.actPos[3] ,recvdMsg.targetPos[3] ,motor_to_degree_position(recvdMsg.actPos[3]) , motor_to_degree_position(recvdMsg.targetPos[3])
//                    );



            /* Print the message's data. */
            //qDebug("Motor 0 actual position: %d\n", recvdMsg.actPos[0]);
            //qDebug("Motor 1 actual position: %d\n", recvdMsg.actPos[1]);
            //qDebug("Update period:           %ld\n", recvdMsg.updatePeriod);



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
