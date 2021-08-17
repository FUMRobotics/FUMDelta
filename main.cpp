#include "mainwindow.h"

#pragma push_macro("slots")
#undef slots
#include <boost/python.hpp>
#pragma pop_macro("slots")
#include <QApplication>
#include "sevensegment.h"
#include "inversekinematicscore.h"
#include "receiverVision.h"
#include "receiver.h"
#include <QtGlobal>
#include <stdio.h>
#include <stdlib.h>
#include "interpretercore.h"



using namespace boost::python;


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    QString txt;
    switch (type) {
    case QtDebugMsg:
        txt= QString("Debug: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);

        break;
    case QtInfoMsg:
        txt= QString("Info: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtWarningMsg:
        txt= QString("Warning: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtCriticalMsg:
        txt= QString("Critical: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtFatalMsg:
        txt= QString("Fatal: %1 (%2:%3, %4)\n").arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function);
        abort();
    }
    QFile outFile("debug-log");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << txt << endl;
}

int main(int argc, char *argv[])
{
    //TODO : find out actual x,y,z for home(or what the drives percieve as home) the x,y,z needs to be stored and given as initial positon to inverse kinematics
    //TODO : limit the input in positon(GUI)
    //TODO : implement clear alarm
    //TODO : go home for drives on startup



    //qInstallMessageHandler(myMessageOutput); // Install the handler

    QApplication a(argc, argv);




    // Initial python for scripting feature
    //remove all queue
    //we should remove queue whit id 1234 1235
    key_t msg_queue_key = msgget(1234 , IPC_CREAT | 0666);

    //the queu exists
    if (!(msgctl(msg_queue_key, IPC_RMID, nullptr)))
    {
        qDebug("The OLD 1234:receiver queue was successfully removed.");
    }else{
        qDebug("The OLD 1234:receiver queue was unsuccessful removed.");
    }

    //remove all queue
    //we should remove queue whit id 1234 1235
    msg_queue_key = msgget(1235 , IPC_CREAT | 0666);
    //the queu exists
    if (!(msgctl(msg_queue_key, IPC_RMID, nullptr)))
    {
        qDebug("The OLD 1235:command queue was successfully removed.");
    }else{
        qDebug("The OLD 1235:receiver queue was unsuccessful removed.");
    }

    msg_queue_key = msgget(1239 , IPC_CREAT | 0666);
    //the queu exists
    if (!(msgctl(msg_queue_key, IPC_RMID, nullptr)))
    {
        qDebug("The OLD 1239:command queue was successfully removed.");
    }else{
        qDebug("The OLD 1239:receiver queue was unsuccessful removed.");
    }

//    while (1) {

//    InterpreterCore* core=new InterpreterCore();
//    core->base();
    //    while (1) {
//        KinematicsState* test = new KinematicsState();
//        KinematicsState* initial = new KinematicsState();
//        KinematicsState* final = new KinematicsState();
//        initial->x = 0;
//        initial->y = 0;
//        initial->z = -0.8;

//        final->x = 0;
//        final->y = 0;
//        final->z = -0.85;

//        test->Interpolation(*initial, *final);
//        delete initial;
//        delete final;
//        delete test;
//            }
//    InverseKinematicsCore core;

//    core.base();


    //TrajectorySender *ts = new TrajectorySender(0,0,-0.8,0,0,-0.85);





    //start ethercat
    QProcess *ethercatProcess=new QProcess() ;
    QProcess process1;

    process1.startDetached("/bin/sh", QStringList()<< "/home/fumdelta/start_ethercat.sh");

    ethercatProcess->waitForFinished(-1); // will wait forever until finished
    qDebug("finished waiting for ethercat startup");
    QString output1=ethercatProcess->readAllStandardOutput();
    QString stderr1 = ethercatProcess->readAllStandardError();
    qDebug()<< output1  << stderr;



    //start drives
    //start ethercat and drives
    Receiver receiver;
    ReceiverVision receiverVision;

    MainWindow w(&receiver);

    receiver.start();
    receiverVision.start();

    QProcess *startDrivesProcess=new QProcess() ;
    QProcess process2;

    process2.startDetached("/bin/sh", QStringList()<< "/home/fumdelta/start_drivers_via_main.sh");



    startDrivesProcess->waitForFinished(-1); // will wait forever until finished
    qDebug("finished waiting for drives startup");
    QString output2=startDrivesProcess->readAllStandardOutput();
    QString stderr2 = startDrivesProcess->readAllStandardError();

    qDebug()<< output2  << stderr;


//    InterpreterCore* core=new InterpreterCore();
//    core->base();
    qDebug("is running...");






    /*------------------------------------TESTING CIRC & LINEAR-------------------------------------*/
//    InverseKinematicsCore core;
////    core.circ(-200,100,-700, 0, 0, 0, 0, 200,0,-800, 0, 0, 3.141592653589793, 0, 25, 10, 100, 50,100,-820,0);

//    core.linear(0, 0, -755,0,0, 3.141592653589793,0, 200,200 , -800, 0,0, 3.141592653589793 / 2,0,25,10,100);
//    QVector<double> m1;
//    QVector<double> m2;
//    QVector<double> m3;

//    QVector<QVector<double>>points;
//    points.push_back(m1);
//    points.push_back(m2);
//    points.push_back(m3);

//    for (int var = 0; var < core.size_of_trajectory_points; var++) {
//        qDebug("M1[%d]=%lf",var,core.M1[var]);
//        qDebug("M2[%d]=%lf",var,core.M2[var]);
//        qDebug("M3[%d]=%lf\n",var,core.M3[var]);

//        m1.push_back(core.M1[var]);
//        m2.push_back(core.M2[var]);
//        m3.push_back(core.M3[var]);
//    }

//    for (int var = 0; var < core.size_of_trajectory_points; var++) {
//        SendCommand::getInstance()->SendPointTo3Drives(core.M1[var],core.M2[var],core.M3[var]);
//    }
/*------------------------------------TESTING CIRC & LINEAR-------------------------------------*/

    //-----------------------------------------------------------------------------------------------------------
    /*---------------------------TESTING INVERSE--------------------------*/
/*    Receiver receiver;

    //InverseKinematicsCore(0.0)

    MainWindow w(&receiver);*/
    /*---------------------------TESTING INVERSE--------------------------*/
    w.show();

    return a.exec();
}
