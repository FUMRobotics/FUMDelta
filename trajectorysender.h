#ifndef TRAJECTORYSENDER_H
#define TRAJECTORYSENDER_H

#include <QObject>
#include <QThread>
#include <QVector>
#include "sendcommand.h"

class TrajectorySender : public QThread
{
    Q_OBJECT
public:
    explicit TrajectorySender(QString fileName, int numberOfDrive,QObject *parent = nullptr);
    int getNumberOfPoint();
    int getTimeOfTrajectory();
    void loadPointFromCsv();
    void sendPointsToDrives();

protected:
    void run();

signals:
    void finishedLoading(int number_of_points,int time);
    void startedSendingPoints();
    void finishedSendingPoints();
public slots:

private:
    int numberOfPoint = 0;
    int numberOfDrive = 0;
    bool is_initiated = 0;
    int NUMBER_OF_motorpuls =524288;
    QVector<QVector<double>> loadedPoints;
    QString trajectoryFilePath;
};

#endif // TRAJECTORYSENDER_H
