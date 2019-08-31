#include "dialog_take_drives_home.h"
#include "ui_dialog_take_drives_home.h"

Dialog_Take_Drives_Home::Dialog_Take_Drives_Home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Take_Drives_Home)
{
    ui->setupUi(this);
}

Dialog_Take_Drives_Home::~Dialog_Take_Drives_Home()
{
    delete ui;
}

