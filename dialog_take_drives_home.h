#ifndef DIALOG_TAKE_DRIVES_HOME_H
#define DIALOG_TAKE_DRIVES_HOME_H

#include <QDialog>

namespace Ui {
class Dialog_Take_Drives_Home;
}

class Dialog_Take_Drives_Home : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Take_Drives_Home(QWidget *parent = nullptr);
    ~Dialog_Take_Drives_Home();

private:
    Ui::Dialog_Take_Drives_Home *ui;
};

#endif // DIALOG_TAKE_DRIVES_HOME_H
