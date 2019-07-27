#ifndef TRAJECTORYSENDER_H
#define TRAJECTORYSENDER_H

#include <QObject>
#include <QThread>

class TrajectorySender : public QThread
{
    Q_OBJECT
public:
    explicit TrajectorySender(QString fileName,QObject *parent = nullptr);
    int getNumberOfPoint();
    int getTimeOfTrajectory();
    void run();
signals:

public slots:

private:
    int numberOfPoint = 0;
    int numberOfdrive = 0;
};

#endif // TRAJECTORYSENDER_H
