#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "receiver.h"
#include "receiverVision.h"
#include "sendcommand.h"
#include "dialog_loadpoints.h"
#include "codeeditor.h"
#include "robotstate.h"
#include "dialog_take_drives_home.h"

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

public slots:
    void startedSendingPoints();
    void finishedSendingPoints();
    void goHome_slot_drive_1();
    void goHome_slot_drive_2();
    void goHome_slot_drive_3();
    void goHome_slot_drive_4();
    void loadTrajectory_inner_slot();
    void sendPositionSlot();
    void goHomeForAllDrivesSlot();
    void hidePlots();
    void showPlots();
    void hideCodeEditor();
    void showCodeEditor();
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

    void on_btn_subtractJog_drive4_pressed();

    void on_btn_addJog_drive1_released();

    void on_btn_addJog_drive2_released();

    void on_btn_addJog_drive3_released();

    void on_btn_addJog_drive4_released();

    void on_btn_subtractJog_drive1_released();

    void on_btn_subtractJog_drive2_released();

    void on_btn_subtractJog_drive3_released();

    void on_btn_subtractJog_drive4_released();

    void on_btn_loadTrajectory_clicked();

    void on_btn_goHome_clicked();

    void on_btn_jogControl_clicked();

    void on_btn_positionControl_clicked();

    void on_btn_program_clicked();




private:
    Ui::MainWindow *ui;
    SendCommand* send_command;
    int jog_value=5000;
    Dialog_LoadPoints* dialog_loading;
    Dialog_Take_Drives_Home* dialog_take_home;
    //QVector<bool> isGoingHome;


    void setButtonsEnable(bool enable);

    void hideJogUIElements();
    void showJogUIElements();
    void showGoHomeElements();
    void showLoadFileElement();
    void hideLoadFileElement();
    void hideGoHomeElements();
    void setUpDynamicGUIElements();
    void showPositionElements();
    void hidePositionElements();

    //buttons for go home
    QPushButton* btn_goHome_drive1;
    QPushButton* btn_goHome_drive2;
    QPushButton* btn_goHome_drive3;
    QPushButton* btn_goHome_drive4;

    QPushButton* btn_goHome_all_drives;


    //button for load file
    QPushButton* btn_loadFile_inner;

    //button for program
    QPushButton* btn_run;


    //text edits for position controls
    QTextEdit* textEdit_xPos;
    QTextEdit* textEdit_yPos;
    QTextEdit* textEdit_zPos;

    CodeEditor* code_editor;



    QPushButton* btn_sendPosition;


    //labels for position control text edits
    QLabel* label_xPos;
    QLabel* label_yPos;
    QLabel* label_zPos;


};

#endif // MAINWINDOW_H
