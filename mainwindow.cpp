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

    setUpDynamicGUIElements();

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
    connect(btn_loadFile_inner,SIGNAL(clicked()),this,SLOT(loadTrajectory_inner_slot()));
    connect(btn_sendPosition,SIGNAL(clicked()),this,SLOT(sendPositionSlot()));

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

void MainWindow::loadTrajectory_inner_slot()
{
    qDebug("LOADING TRAJECTORY");
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

void MainWindow::setButtonsEnable(bool enable)
{
    ui->btn_jogControl->setEnabled(enable);
    ui->btn_loadTrajectory->setEnabled(enable);
    ui->btn_positionControl->setEnabled(enable);
    ui->btn_goHome->setEnabled(enable);

    ui->btn_addJog_drive1->setEnabled(enable);
    ui->btn_addJog_drive2->setEnabled(enable);
    ui->btn_addJog_drive3->setEnabled(enable);
    ui->btn_addJog_drive4->setEnabled(enable);

    ui->btn_subtractJog_drive1->setEnabled(enable);
    ui->btn_subtractJog_drive2->setEnabled(enable);
    ui->btn_subtractJog_drive3->setEnabled(enable);
    ui->btn_subtractJog_drive4->setEnabled(enable);

    btn_loadFile_inner->setEnabled(enable);

    btn_goHome_drive1->setEnabled(enable);
    btn_goHome_drive2->setEnabled(enable);
    btn_goHome_drive3->setEnabled(enable);
    btn_goHome_drive4->setEnabled(enable);
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

void MainWindow::showLoadFileElement()
{
    btn_loadFile_inner->show();
}

void MainWindow::hideLoadFileElement()
{
    btn_loadFile_inner->hide();
}

void MainWindow::showGoHomeElements()
{

    btn_goHome_drive1->show();
    btn_goHome_drive2->show();
    btn_goHome_drive3->show();
    btn_goHome_drive4->show();


}

void MainWindow::hideGoHomeElements()
{
    btn_goHome_drive1->hide();
    btn_goHome_drive2->hide();
    btn_goHome_drive3->hide();
    btn_goHome_drive4->hide();

}

void MainWindow::setUpDynamicGUIElements()
{
    ui->jogData_drive1->setText("00");
    ui->jogData_drive2->setText("00");
    ui->jogData_drive3->setText("00");
    ui->jogData_drive4->setText("00");

    btn_goHome_drive1=new QPushButton();
    btn_goHome_drive2=new QPushButton();
    btn_goHome_drive3=new QPushButton();
    btn_goHome_drive4=new QPushButton();
    btn_loadFile_inner=new QPushButton();

    btn_sendPosition=new QPushButton();


    label_xPos=new QLabel();
    label_yPos=new QLabel();
    label_zPos=new QLabel();



    textEdit_xPos=new QTextEdit();
    textEdit_yPos=new QTextEdit();
    textEdit_zPos=new QTextEdit();




    textEdit_xPos->setFixedSize(QSize(50,45));
    textEdit_yPos->setFixedSize(QSize(50,45));
    textEdit_zPos->setFixedSize(QSize(50,45));
    btn_sendPosition->setFixedSize(QSize(100,30));



    textEdit_xPos->setStyleSheet("color:rgb(238, 238, 236);background-color:rgb(85, 87, 83);font: 16pt \"Ubuntu\";");
    textEdit_yPos->setStyleSheet("color:rgb(238, 238, 236);background-color:rgb(85, 87, 83);font: 16pt \"Ubuntu\";");
    textEdit_zPos->setStyleSheet("color:rgb(238, 238, 236);background-color:rgb(85, 87, 83);font: 16pt \"Ubuntu\";");

    label_xPos->setStyleSheet("color:rgb(238, 238, 236);font: 16pt \"Ubuntu\";");
    label_yPos->setStyleSheet("color:rgb(238, 238, 236);font: 16pt \"Ubuntu\";");
    label_zPos->setStyleSheet("color:rgb(238, 238, 236);font: 16pt \"Ubuntu\";");

    label_xPos->setText("X");
    label_yPos->setText("Y");
    label_zPos->setText("Z");

    label_xPos->setFixedSize(QSize(20,20));
    label_yPos->setFixedSize(QSize(20,20));
    label_zPos->setFixedSize(QSize(20,20));

    btn_sendPosition->setText("Send Position");
    btn_sendPosition->setStyleSheet("color:rgb(238, 238, 236);font: 8pt \"Ubuntu\";");



    ui->horizontalLayout_6->addWidget(label_xPos);
    ui->horizontalLayout_6->addWidget(textEdit_xPos);

    ui->horizontalLayout_5->addWidget(label_yPos);
    ui->horizontalLayout_5->addWidget(textEdit_yPos);

    ui->horizontalLayout_3->addWidget(label_yPos);
    ui->horizontalLayout_3->addWidget(textEdit_yPos);

    ui->horizontalLayout_4->addWidget(label_zPos);
    ui->horizontalLayout_4->addWidget(textEdit_zPos);

    ui->verticalLayout_3->addWidget(btn_sendPosition);


    label_xPos->hide();
    label_yPos->hide();
    label_zPos->hide();

    textEdit_xPos->hide();
    textEdit_yPos->hide();
    textEdit_zPos->hide();
    btn_sendPosition->hide();



    btn_goHome_drive1->setText("Go Home");
    btn_goHome_drive2->setText("Go Home");
    btn_goHome_drive3->setText("Go Home");
    btn_goHome_drive4->setText("Go Home");
    btn_loadFile_inner->setText("Load Trajectory");
    btn_goHome_drive1->setStyleSheet("color:rgb(238, 238, 236)");
    btn_goHome_drive2->setStyleSheet("color:rgb(238, 238, 236)");
    btn_goHome_drive3->setStyleSheet("color:rgb(238, 238, 236)");
    btn_goHome_drive4->setStyleSheet("color:rgb(238, 238, 236)");
    btn_loadFile_inner->setStyleSheet("color:rgb(238, 238, 236)");

//    btn_goHome_drive1->sizePolicy().setVerticalPolicy(QSizePolicy::Fixed);
//    btn_goHome_drive2->sizePolicy().setVerticalPolicy(QSizePolicy::Fixed);
//    btn_goHome_drive3->sizePolicy().setVerticalPolicy(QSizePolicy::Fixed);
//    btn_goHome_drive4->sizePolicy().setVerticalPolicy(QSizePolicy::Fixed);
//    btn_loadFile_inner->sizePolicy().setVerticalPolicy(QSizePolicy::Fixed);

//    btn_goHome_drive1->sizePolicy().setHorizontalPolicy(QSizePolicy::Preferred);
//    btn_goHome_drive2->sizePolicy().setHorizontalPolicy(QSizePolicy::Preferred);
//    btn_goHome_drive3->sizePolicy().setHorizontalPolicy(QSizePolicy::Preferred);
//    btn_goHome_drive4->sizePolicy().setHorizontalPolicy(QSizePolicy::Preferred);
//    btn_loadFile_inner->sizePolicy().setHorizontalPolicy(QSizePolicy::Preferred);
    const QSize btnSize = QSize(100, 50);
    const QSize btnJogSize = QSize(50, 50);
    btn_loadFile_inner->setFixedSize(btnSize);
    btn_goHome_drive1->setFixedSize(btnSize);
    btn_goHome_drive2->setFixedSize(btnSize);
    btn_goHome_drive3->setFixedSize(btnSize);
    btn_goHome_drive4->setFixedSize(btnSize);

    ui->btn_addJog_drive1->setFixedSize(btnJogSize);
    ui->btn_addJog_drive2->setFixedSize(btnJogSize);
    ui->btn_addJog_drive3->setFixedSize(btnJogSize);
    ui->btn_addJog_drive4->setFixedSize(btnJogSize);

    ui->btn_subtractJog_drive1->setFixedSize(btnJogSize);
    ui->btn_subtractJog_drive2->setFixedSize(btnJogSize);
    ui->btn_subtractJog_drive3->setFixedSize(btnJogSize);
    ui->btn_subtractJog_drive4->setFixedSize(btnJogSize);

    ui->horizontalLayout_6->addWidget(btn_goHome_drive1);
    ui->horizontalLayout_5->addWidget(btn_goHome_drive2);
    ui->horizontalLayout_3->addWidget(btn_goHome_drive3);
    ui->horizontalLayout_4->addWidget(btn_goHome_drive4);

    //called hide for now to hide go home elements,
    //so that jog elements are shown at startup
    //if go home elements need to be shown, simply show them
    //with show() in setUpGoHomeElements()
    hideGoHomeElements();

    ui->verticalLayout_3->addWidget(btn_loadFile_inner);
    hideLoadFileElement();

    ui->drive1->setMinimumSize(QSize(500,130));
    ui->drive2->setMinimumSize(QSize(500,130));
    ui->drive3->setMinimumSize(QSize(500,130));
    ui->drive4->setMinimumSize(QSize(500,130));


    ui->btn_goHome->setMinimumSize(QSize(100,100));
    ui->btn_jogControl->setMinimumSize(QSize(100,100));
    ui->btn_loadTrajectory->setMinimumSize(QSize(100,100));
    ui->btn_positionControl->setMinimumSize(QSize(100,100));

}

void MainWindow::showPositionElements()
{
    label_xPos->show();
    label_yPos->show();
    label_zPos->show();

    textEdit_xPos->show();
    textEdit_yPos->show();
    textEdit_zPos->show();
    btn_sendPosition->show();

}

void MainWindow::hidePositionElements()
{
    label_xPos->hide();
    label_yPos->hide();
    label_zPos->hide();
    textEdit_xPos->hide();
    textEdit_yPos->hide();
    textEdit_zPos->hide();
    btn_sendPosition->hide();
}

void MainWindow::sendPositionSlot()
{
    qDebug("send position slot called");
    QString xPos=textEdit_xPos->toPlainText();
    QString yPos=textEdit_yPos->toPlainText();
    QString zPos=textEdit_zPos->toPlainText();

    float x=xPos.toFloat();
    float y=yPos.toFloat();
    float z=zPos.toFloat();

    qDebug("x="+QString::number(x).toLatin1()+" y="+QString::number(y).toLatin1()+" z="+QString::number(z).toLatin1());
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
     hideJogUIElements();
     hideGoHomeElements();
     hidePositionElements();

     showLoadFileElement();
}

void MainWindow::on_btn_goHome_clicked()
{
    hideJogUIElements();
    hideLoadFileElement();
    hidePositionElements();

    showGoHomeElements();
}

void MainWindow::on_btn_jogControl_clicked()
{
    hideGoHomeElements();
    hideLoadFileElement();
    hidePositionElements();

    showJogUIElements();
}

void MainWindow::on_btn_positionControl_clicked()
{
    hideJogUIElements();
    hideGoHomeElements();
    hideLoadFileElement();

    showPositionElements();
}
