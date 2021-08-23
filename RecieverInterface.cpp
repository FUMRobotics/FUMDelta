#include "RecieverInterface.h"

FILE* ReceiverInterFace::fp;
int ReceiverInterFace::qID;
void ReceiverInterFace::run()
{
    receiverBase();
}

ReceiverInterFace::ReceiverInterFace(QObject *parent) : QThread (parent)
{
    qDebug("listening...");
}
void ReceiverInterFace::print_config(void)
{
    qDebug("\nLOG is defined. Number of cycles = %ld\n", NUMBER_OF_CYCLES);
    qDebug("FLUSH_CYCLE = %d\n\n", FLUSH_CYCLE);
}

ReceiverInterFace::~ReceiverInterFace()
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

void ReceiverInterFace::receiverBase()
{

   // signal(SIGINT, Receiver::signal_handler);

    print_config();

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
        /* Data */
        double_t    theta1;
        double_t    theta2;
        double_t    theta3;
        double_t    theta4;
    } receiveMassage,*addReceiveMassage;
    #pragma pack(pop)

    receiveMassage recvdMsg;
    size_t msgSize = sizeof(receiveMassage);
    qDebug("********************\nmsgSize is %lu\n********************" , msgSize);
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
            if (msgrcv(qID, &recvdMsg, msgSize, 0, 0) < 0)
            {
                qDebug("Error picking a message from the queue. Terminating the %d process...\n",errno);
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
//            addReceiveMassage rm = (addReceiveMassage)databuf.data_buff;
//            receiveMassage recvdMsg = *rm;
//            qDebug("1239 got it");

            qDebug("new point recived: theta 1: %f theta 2:%f, theta 3:%f, theta4:%f",recvdMsg.theta1,recvdMsg.theta2,recvdMsg.theta3,recvdMsg.theta4);
            qDebug("Sending point directly to Driver");
            SendCommand::getInstance()->SendPointTo3Drives(recvdMsg.theta1,recvdMsg.theta2,recvdMsg.theta3);
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
