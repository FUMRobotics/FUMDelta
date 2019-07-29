#include "sendcommand.h"
#include "qdebug.h"


SendCommand* SendCommand::instance;

SendCommand::SendCommand(QObject *parent) : QObject(parent)
{
    msgflg = IPC_CREAT | 0666;
    key=1235;

    qDebug("\nmsgget: Calling msgget(%#lx,%#o)\n",key, msgflg);

    if ((msqid = msgget(key, msgflg )) < 0) {
        perror("msgget");
        //exit(1);
    }
    else
    {
        qDebug("msgget: msgget succeeded: msqid = %d\n", msqid);
    }


}

SendCommand* SendCommand::getInstance()
{
    if(instance==NULL)
    {
        instance=new SendCommand(NULL);
    }
    return instance;
}
inline int32_t SendCommand::degree_to_motor_position(double point) {
    return (int32_t)(point * NUMBER_OF_motorpuls / 360);
}
void SendCommand::SendJog(int drive_id, int data)
{
    message_buf sbuf;
    //size_t buf_length;

    sbuf.mtype = 1;
    for(int i=0;i<4;i++)
    {
        if(i!=drive_id)
        {
            sbuf.opCode[i]=0;
            sbuf.data[i]=0;
        }else{
            sbuf.opCode[drive_id]=4;
            sbuf.data[drive_id]=data;
        }
    }
    SendData(sbuf);
}

void SendCommand::SendData(SendCommand::message_buf msg)
{
    //qDebug("Sending jog to queue with data: %d, %d, %d, %d",msg.data[0],msg.data[1],msg.data[2],msg.data[3]);
    size_t msgSize;
   /* size of data = size of structure - size of mtype */
    msgSize = sizeof(struct msgbuf) - sizeof(long);
    if (msgsnd(msqid, &msg, msgSize, IPC_NOWAIT) < 0)
    {
            //    printf ("%d, %d, %s, %d\n", msqid, sbuf.mtype, sbuf.mtext, buf_length);
                perror("msgsnd");
                //exit(1);
    }
}

void SendCommand::SendPointTo4Drives(double p0, double p1, double p2, double p3)
{
    message_buf sbuf;
    //size_t buf_length;

    sbuf.mtype = 1;
    sbuf.opCode[0]=1;
    sbuf.data[0]=degree_to_motor_position(p0);

    sbuf.opCode[1]=1;
    sbuf.data[1]=degree_to_motor_position(p1);;

    sbuf.opCode[2]=1;
    sbuf.data[2]=degree_to_motor_position(p2);

    sbuf.opCode[3]=1;
    sbuf.data[3]=degree_to_motor_position(p3);


    SendData(sbuf);
}

