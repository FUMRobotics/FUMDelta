#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "receiver.h"
#include "sendcommand.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Receiver* receiver, QWidget *parent = nullptr);
    ~MainWindow();
    //void updatePlotData(int key, double targetPosition[4], double actualPosition[4]);


private slots:
    void SendJog(bool sign,int drive_id);

//    void on_btn_addJog_drive1_clicked();

//    void on_btn_addJog_drive2_clicked();

    void on_btn_addJog_drive1_pressed();

    void on_btn_addJog_drive2_pressed();

    void on_btn_addJog_drive3_pressed();

    void on_btn_addJog_drive4_pressed();

    void on_btn_subtractJog_drive1_pressed();

    void on_btn_subtractJog_drive2_pressed();

    void on_btn_subtractJog_drive3_pressed();

    void on_btn_subtractJogdrive4_pressed();

    void on_btn_addJog_drive1_released();

    void on_btn_addJog_drive2_released();

    void on_btn_addJog_drive3_released();

    void on_btn_addJog_drive4_released();

    void on_btn_subtractJog_drive1_released();

    void on_btn_subtractJog_drive2_released();

    void on_btn_subtractJog_drive3_released();

    void on_btn_subtractJogdrive4_released();

    void on_btn_loadTrajectory_clicked();

private:
    Ui::MainWindow *ui;
    SendCommand* send_command;
    int jog_value=500000;
};

#endif // MAINWINDOW_H
