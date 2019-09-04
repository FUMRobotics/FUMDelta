#ifndef RECIEVER_H
#define RECIEVER_H

#include <QObject>
#include <QThread>
#include <stdio.h>
/* For IPC_CREAT */
#include <sys/msg.h>
/* For int32_t */
#include <stdint.h>
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


class Receiver : public QThread
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
    int GEARBOX_RATIO=10;
    void run();
public:
    explicit Receiver(QObject *parent = nullptr);
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

    ~Receiver();

    double motor_to_degree_position(int32_t point) ;
    void calculate_motor_to_degree_array(int32_t points[4],double *ret_data);
    void calculate_motor_to_degree_vector(int32_t points[4], QVector<double>* retval);
    void receiverBase();
signals:
    void newMessage(unsigned int key,QVector<double> actualPosition,QVector<double> targetPosition);
public slots:

};

#endif // RECIEVER_H
