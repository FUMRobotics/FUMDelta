#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include "plothandler.h"


MainWindow::MainWindow(Receiver* receiver,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->layout()->setContentsMargins(0,0,0,0);
    //setUpAllPlots();
    PlotHandler *plot_0 = new PlotHandler(0,ui->drive1,ui->jogData_drive1,ui->label_totalPoints_drive1,this);
    PlotHandler *plot_1 = new PlotHandler(1,ui->drive2,ui->jogData_drive2,ui->label_totalPoints_drive2,this);
    PlotHandler *plot_2 = new PlotHandler(2,ui->drive3,ui->jogData_drive3,ui->label_totalPoints_drive3,this);
    PlotHandler *plot_3 = new PlotHandler(3,ui->drive4,ui->jogData_drive4,ui->label_totalPoints_drive4,this);
    send_command=SendCommand::getInstance();

    QObject::connect(receiver,&Receiver::newMessage,plot_0, &PlotHandler::updatePlotData);
    QObject::connect(receiver,&Receiver::newMessage,plot_1, &PlotHandler::updatePlotData);

    QObject::connect(receiver,&Receiver::newMessage,plot_2, &PlotHandler::updatePlotData);
    QObject::connect(receiver,&Receiver::newMessage,plot_3, &PlotHandler::updatePlotData);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::SendJog(bool sign, int drive_id)
{
        qDebug("add %d jog for drive %d...",sign,drive_id);
        //sign sign == 1 1
        //sign sign == 0-1
       //send_command->SendJog(drive_id,((sign * 2) - 1 )*jog_value);
        if(sign)
        {
            send_command->SendJog(drive_id,jog_value);
        }else
        {
            send_command->SendJog(drive_id,-jog_value);
        }

}


//void MainWindow::on_btn_addJog_drive1_clicked()
//{
//    qDebug("add jog for drive 1...");
//    send_command->SendJog(1,jog_value);
//}

//void MainWindow::on_btn_addJog_drive2_clicked()
//{
//  send_command->SendJog(2,jog_value);
//}

void MainWindow::on_btn_addJog_drive1_pressed()
{
    SendJog(1,0);
}

void MainWindow::on_btn_addJog_drive2_pressed()
{
    SendJog(1,1);
}

void MainWindow::on_btn_addJog_drive3_pressed()
{
    SendJog(1,2);
}

void MainWindow::on_btn_addJog_drive4_pressed()
{
    SendJog(1,3);
}

void MainWindow::on_btn_subtractJog_drive1_pressed()
{
    SendJog(0,0);
}

void MainWindow::on_btn_subtractJog_drive2_pressed()
{
    SendJog(0,1);
}

void MainWindow::on_btn_subtractJog_drive3_pressed()
{
    SendJog(0,2);
}

void MainWindow::on_btn_subtractJogdrive4_pressed()
{
    SendJog(0,3);
}
