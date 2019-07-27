#ifndef SENDCOMMAND_H
#define SENDCOMMAND_H

#include <QObject>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#define MSGSZ     128



class SendCommand : public QObject
{
    Q_OBJECT
public:

/*
 * Declare the message structure.
 */

typedef struct msgbuf {
    /* Mandatory, must be a positive number. */
    long       mtype;
    /* Data */
    long    update_period;

    int    opCode[4];
    int    data[4];
 } message_buf;


    static SendCommand* getInstance();
    //todo convert  int to u,,,
    void SendJog(int drive_id, int data);
    void SendData(message_buf msg);
    void ClearAlarm(int dirve_id);
    void SendPosition(int drive_id, int data);
    void GoHome(int drive_id);
 
   
signals:

public slots:

private:
   static SendCommand* instance;
   int msqid;
   int msgflg;

   key_t key;
   explicit SendCommand(QObject *parent = nullptr);
};

#endif // SENDCOMMAND_H