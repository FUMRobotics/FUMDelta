#include "mainwindow.h"
#include <QApplication>
#include "sevensegment.h"
#include "kinematicsstate.h"
#include "receiver.h"
#include <QtGlobal>
#include <stdio.h>
#include <stdlib.h>


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
    //qInstallMessageHandler(myMessageOutput); // Install the handler
    QApplication a(argc, argv);
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
    Receiver receiver;
    MainWindow w(&receiver);

    receiver.start();

    qDebug("is running...");

    w.show();

    return a.exec();
}
