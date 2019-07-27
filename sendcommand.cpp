#include "sendcommand.h"
#include "qdebug.h"

int SendCommand:: msqid;
int SendCommand:: msgflg;
key_t SendCommand:: key;
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
    qDebug("Sending jog to queue with data: %d, %d, %d, %d",msg.data[0],msg.data[1],msg.data[2],msg.data[3]);
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

