#include "dialog_loadpoints.h"
#include "ui_dialog_loadpoints.h"

Dialog_LoadPoints::Dialog_LoadPoints(TrajectorySender* trajectory_sender, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_LoadPoints)
{
    //ui->frame->layout()->setContentsMargins(0,0,0,0);
    this->trajectory_sender=trajectory_sender;
    ui->setupUi(this);
    ui->btn_sendData->setEnabled(false);
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
//    progressBar = new QProgressBar();
//    progressBar->setMinimum(0);
//    progressBar->setMaximum(time);

//       ui->verticalLayout->addWidget(progressBar);
//       ui->label_numbe_of_points->setText("Number of Points: "+number_of_points);
//       QTimer *timer = new QTimer(this);
//       connect(timer, &QTimer::timeout, this, &dialog_loadingPoints::updateProgress);
//       timer->start(1000);


       //resize(200, 200);
}

Dialog_LoadPoints::~Dialog_LoadPoints()
{
    delete ui;
}

void Dialog_LoadPoints::finishedLoadingDataSlot(int number_of_points,int time)
{
    QString s="number of points: "+QString::number(number_of_points)+"time: "+QString::number(time);
    qDebug(s.toLatin1());
    ui->label_number_of_points->setText(QString("Number Of Points: %L1 ms").arg(number_of_points)); //QString::number(number_of_points));
    ui->label_expected_time->setText(QString("Expected Execution Time: %L1").arg(time));
    ui->btn_sendData->setEnabled(true);
}


void Dialog_LoadPoints::on_btn_sendData_clicked()
{
    ui->btn_sendData->hide();
    trajectory_sender->start();
    this->accept();
}
