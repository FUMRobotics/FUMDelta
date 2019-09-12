#include "mainwindow.h"
#include <QApplication>
#include "sevensegment.h"
#include "inversekinematicscore.h"
#include "receiver.h"
#include <QtGlobal>
#include <stdio.h>
#include <stdlib.h>
#include "interpretercore.h"

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

    InterpreterCore* core=new InterpreterCore();
    core->base();
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
//    QProcess *ethercatProcess=new QProcess() ;
//    QProcess process1;

//    process1.startDetached("/bin/sh", QStringList()<< "/home/fumdelta/start_ethercat.sh");

//    ethercatProcess->waitForFinished(-1); // will wait forever until finished
//    qDebug("finished waiting for ethercat startup");
//    QString output1=ethercatProcess->readAllStandardOutput();
//    QString stderr1 = ethercatProcess->readAllStandardError();
//    qDebug()<< output1  << stderr;


//    //start drives
//    //start ethercat and drives
//    QProcess *startDrivesProcess=new QProcess() ;
//    QProcess process2;

//    process2.startDetached("/bin/sh", QStringList()<< "/home/fumdelta/start_drivers_via_main.sh");

//    startDrivesProcess->waitForFinished(-1); // will wait forever until finished
//    qDebug("finished waiting for drives startup");
//    QString output2=startDrivesProcess->readAllStandardOutput();
//    QString stderr2 = startDrivesProcess->readAllStandardError();

//    qDebug()<< output2  << stderr;

    Receiver receiver;
    MainWindow w(&receiver);

    receiver.start();

    qDebug("is running...");





    w.show();

    return a.exec();
}
