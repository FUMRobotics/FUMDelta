#ifndef DIALOG_LOADPOINTS_H
#define DIALOG_LOADPOINTS_H

#include <QDialog>
#include <QProgressBar>
#include "trajectorysender.h"

namespace Ui {
class Dialog_LoadPoints;
}

class Dialog_LoadPoints : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_LoadPoints(TrajectorySender* trajectory_sender, QWidget *parent = nullptr);
    ~Dialog_LoadPoints();

public slots:
    void finishedLoadingDataSlot(int number_of_points,int time);

private slots:
    void on_btn_sendData_clicked();

private:
    Ui::Dialog_LoadPoints *ui;
    TrajectorySender* trajectory_sender;
    QProgressBar* progressBar;
};

#endif // DIALOG_LOADPOINTS_H
