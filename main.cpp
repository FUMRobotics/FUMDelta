#include "mainwindow.h"
#include <QApplication>
#include "receiver.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Receiver receiver;
    MainWindow w(&receiver);
    receiver.start();
    qDebug("is running...");


    w.show();

    return a.exec();
}
