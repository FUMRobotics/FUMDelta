#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include "plothandler.h"
#include "trajectorysender.h"

//QVector<bool> MainWindow:: isGoingHome;

MainWindow::MainWindow(Receiver* receiver,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->layout()->setContentsMargins(0,0,0,0);
    //setUpAllPlots();

//    for (int i = 0; i < 4; ++i) {
//       isGoingHome[i]=0;
//    }

    ui->jogData_drive1->setText("00");
    ui->jogData_drive2->setText("00");
    ui->jogData_drive3->setText("00");
    ui->jogData_drive4->setText("00");

    btn_goHome_drive1=new QPushButton();
    btn_goHome_drive2=new QPushButton();
    btn_goHome_drive3=new QPushButton();
    btn_goHome_drive4=new QPushButton();
    btn_goHome_drive1->setText("Go Home");
    btn_goHome_drive2->setText("Go Home");
    btn_goHome_drive3->setText("Go Home");
    btn_goHome_drive4->setText("Go Home");
    btn_goHome_drive1->setStyleSheet("color:rgb(238, 238, 236)");
    btn_goHome_drive2->setStyleSheet("color:rgb(238, 238, 236)");
    btn_goHome_drive3->setStyleSheet("color:rgb(238, 238, 236)");
    btn_goHome_drive4->setStyleSheet("color:rgb(238, 238, 236)");

    btn_goHome_drive1->sizePolicy().setVerticalPolicy(QSizePolicy::Fixed);
    btn_goHome_drive2->sizePolicy().setVerticalPolicy(QSizePolicy::Fixed);
    btn_goHome_drive3->sizePolicy().setVerticalPolicy(QSizePolicy::Fixed);
    btn_goHome_drive4->sizePolicy().setVerticalPolicy(QSizePolicy::Fixed);

    PlotHandler *plot_0 = new PlotHandler(0,ui->drive1,ui->jogData_drive1,ui->label_totalPoints_drive1,this);
    PlotHandler *plot_1 = new PlotHandler(1,ui->drive2,ui->jogData_drive2,ui->label_totalPoints_drive2,this);
    PlotHandler *plot_2 = new PlotHandler(2,ui->drive3,ui->jogData_drive3,ui->label_totalPoints_drive3,this);
    PlotHandler *plot_3 = new PlotHandler(3,ui->drive4,ui->jogData_drive4,ui->label_totalPoints_drive4,this);
    //send_command=SendCommand::getInstance();

    QObject::connect(receiver,&Receiver::newMessage,plot_0, &PlotHandler::updatePlotData);
    QObject::connect(receiver,&Receiver::newMessage,plot_1, &PlotHandler::updatePlotData);

    QObject::connect(receiver,&Receiver::newMessage,plot_2, &PlotHandler::updatePlotData);
    QObject::connect(receiver,&Receiver::newMessage,plot_3, &PlotHandler::updatePlotData);
    connect(btn_goHome_drive1,SIGNAL(clicked()),this,SLOT(goHome_slot_drive_1()));
    connect(btn_goHome_drive2,SIGNAL(clicked()),this,SLOT(goHome_slot_drive_2()));
    connect(btn_goHome_drive3,SIGNAL(clicked()),this,SLOT(goHome_slot_drive_3()));
    connect(btn_goHome_drive4,SIGNAL(clicked()),this,SLOT(goHome_slot_drive_4()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startedSendingPoints()
{
    qDebug("set buttons disable");
    setButtonsEnable(false);
}

void MainWindow::finishedSendingPoints()
{
    qDebug("set buttons enable");
    setButtonsEnable(true);
}

void MainWindow::goHome_slot_drive_1()
{
    qDebug("slot:go home for drive 1");
    SendCommand::getInstance()->GoHome(0);
}

void MainWindow::goHome_slot_drive_2()
{
    qDebug("slot:go home for drive 2");
    SendCommand::getInstance()->GoHome(1);
}

void MainWindow::goHome_slot_drive_3()
{
    qDebug("slot:go home for drive 3");
    SendCommand::getInstance()->GoHome(2);
}

void MainWindow::goHome_slot_drive_4()
{
    qDebug("slot:go home for drive 4");
    SendCommand::getInstance()->GoHome(3);
}

void MainWindow::setButtonsEnable(bool enable)
{
    ui->btn_jogControl->setEnabled(enable);
    ui->btn_loadTrajectory->setEnabled(enable);
    ui->btn_positionControl->setEnabled(enable);

    ui->btn_addJog_drive1->setEnabled(enable);
    ui->btn_addJog_drive2->setEnabled(enable);
    ui->btn_addJog_drive3->setEnabled(enable);
    ui->btn_addJog_drive4->setEnabled(enable);

    ui->btn_subtractJog_drive1->setEnabled(enable);
    ui->btn_subtractJog_drive2->setEnabled(enable);
    ui->btn_subtractJog_drive3->setEnabled(enable);
    ui->btn_subtractJog_drive4->setEnabled(enable);
}

void MainWindow::hideJogUIElements()
{
    ui->btn_addJog_drive1->hide();
    ui->btn_addJog_drive2->hide();
    ui->btn_addJog_drive3->hide();
    ui->btn_addJog_drive4->hide();

    ui->btn_subtractJog_drive1->hide();
    ui->btn_subtractJog_drive2->hide();
    ui->btn_subtractJog_drive3->hide();
    ui->btn_subtractJog_drive4->hide();

    ui->jogData_drive1->hide();
    ui->jogData_drive2->hide();
    ui->jogData_drive3->hide();
    ui->jogData_drive4->hide();

}

void MainWindow::showJogUIElements()
{
    ui->btn_addJog_drive1->show();
    ui->btn_addJog_drive2->show();
    ui->btn_addJog_drive3->show();
    ui->btn_addJog_drive4->show();

    ui->btn_subtractJog_drive1->show();
    ui->btn_subtractJog_drive2->show();
    ui->btn_subtractJog_drive3->show();
    ui->btn_subtractJog_drive4->show();

    ui->jogData_drive1->show();
    ui->jogData_drive2->show();
    ui->jogData_drive3->show();
    ui->jogData_drive4->show();
}

void MainWindow::setUpGoHomeElements()
{

    btn_goHome_drive1->show();
    btn_goHome_drive2->show();
    btn_goHome_drive3->show();
    btn_goHome_drive4->show();
    ui->horizontalLayout_6->addWidget(btn_goHome_drive1);
    ui->horizontalLayout_5->addWidget(btn_goHome_drive2);
    ui->horizontalLayout_3->addWidget(btn_goHome_drive3);
    ui->horizontalLayout_4->addWidget(btn_goHome_drive4);

}

void MainWindow::hideGoHomeElements()
{
    btn_goHome_drive1->hide();
    btn_goHome_drive2->hide();
    btn_goHome_drive3->hide();
    btn_goHome_drive4->hide();

}


void MainWindow::SendJog(bool sign, int drive_id)
{
        qDebug("add %d jog for drive %d...",sign,drive_id);
        //sign sign == 1 1
        //sign sign == 0-1
       //send_command->SendJog(drive_id,((sign * 2) - 1 )*jog_value);
        if(sign)
        {
            SendCommand::getInstance()->SendJog(drive_id,jog_value);
        }else
        {
             SendCommand::getInstance()->SendJog(drive_id,-jog_value);
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

void MainWindow::on_btn_addJog_drive1_released()
{
    SendJog(0,0);
}


void MainWindow::on_btn_addJog_drive2_released()
{
    SendJog(0,1);
}

void MainWindow::on_btn_addJog_drive3_released()
{
    SendJog(0,2);
}



void MainWindow::on_btn_addJog_drive4_released()
{
    SendJog(0,3);
}



void MainWindow::on_btn_subtractJog_drive1_released()
{
    SendJog(1,0);
}

void MainWindow::on_btn_subtractJog_drive2_released()
{
    SendJog(1,1);
}

void MainWindow::on_btn_subtractJog_drive3_released()
{
    SendJog(1,2);
}

void MainWindow::on_btn_subtractJogdrive4_released()
{
    SendJog(1,3);
}

void MainWindow::on_btn_loadTrajectory_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose points file"), "/home", tr("CSV files (*.csv)"));
    qDebug("file name="+fileName.toLatin1());
    if(fileName!="")
    {
        TrajectorySender *ts = new TrajectorySender(fileName, 4);
        qDebug("load points dialog 3");
        dialog_loading=new Dialog_LoadPoints(ts);
        QObject::connect(ts,&TrajectorySender::finishedLoading,dialog_loading, &Dialog_LoadPoints::finishedLoadingDataSlot);
        QObject::connect(ts,&TrajectorySender::startedSendingPoints,this, &MainWindow::startedSendingPoints);
        QObject::connect(ts,&TrajectorySender::finishedSendingPoints,this, &MainWindow::finishedSendingPoints);

        dialog_loading->setModal(true);
        dialog_loading->exec();
    }

}

void MainWindow::on_btn_goHome_clicked()
{
    //TODO: remove hide bool and handle changing controlls in slots
    if(hide)
    {
        qDebug("set false");
        hideJogUIElements();
        setUpGoHomeElements();
        hide=false;
    }
    else{
        qDebug("set true");
        hideGoHomeElements();
        showJogUIElements();
        hide=true;
    }
}
