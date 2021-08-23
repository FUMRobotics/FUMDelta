#ifndef RECEIVERINTERFACE_H
#define RECEIVERINTERFACE_H



#include <QObject>
#include <QThread>
#include <stdio.h>
/* For IPC_CREAT */
#include <sys/msg.h>
/* For int32_t */
#include <stdint.h>
// for double_t
#include <math.h>
/* Header for handling signals (definition of SIGINT) */
#include <signal.h>
/* For pid_t and getpid() */
#include <unistd.h>
#include <sys/types.h>
/* For using real-time scheduling policy (FIFO) and sched_setaffinity */
#include <sched.h>
/* For locking the program in RAM (mlockall) to prevent swapping */
#include <sys/mman.h>

#include "robotstate.h"
#include "sendcommand.h"


class ReceiverInterFace : public QThread
{
     Q_OBJECT
private:
    static FILE *fp;
    static int qID;
    unsigned int messageCounter=0;
    /*after each "", a message is emitted*/
    unsigned int emitFrequency=300;
    /* Assuming an update rate of exactly 1 ms, number of cycles for 24h = 24*3600*1000. */
    long NUMBER_OF_CYCLES =86400000;
    /* Flush the data every ... cycle */
    int FLUSH_CYCLE =60000;
    int NUMBER_OF_motorpulse=524287;
    int GEARBOX_RATIO=20;
    void run();
public:
   explicit ReceiverInterFace(QObject *parent = nullptr);
public:
    void print_config(void);
    static void signal_handler()
    {

        printf("Removing the queue...\n");
        if (!(msgctl(qID, IPC_RMID, NULL)))
            printf("The queue was successfully removed.\n");
        /* close the file */
        if (!fclose(fp))
            printf("The log file was successfully closed.\n");
        pid_t pid = getpid();
        kill(pid, SIGKILL);

    }
    ~ReceiverInterFace();
    void receiverBase();
signals:
    void newMessage(unsigned int key,QVector<double> actualPosition,QVector<double> targetPosition);
};

#endif // RECEIVERINTERFACE_H
