#ifndef TRAJECTORYSENDER_H
#define TRAJECTORYSENDER_H

#include <QObject>
#include <QThread>
#include <QVector>
#include "sendcommand.h"
#include "inversekinematicscore.h"

class TrajectorySender : public QThread
{
    Q_OBJECT
public:
    explicit TrajectorySender(QString fileName, int numberOfDrive,QObject *parent = nullptr);
    TrajectorySender(double x_start, double y_start,double z_start,
                     double x_end,   double y_end,  double z_end);
    TrajectorySender();
    int getNumberOfPoint();
    int getTimeOfTrajectory();
    void loadPointFromCsv();
    void testLinear();
    void ptpCore(double inverse_start_output[],double inverse_end_output[],InverseKinematicsCore core);
    void sendPointsToDrives(QVector<QVector<double>> &points_for_drives);
    void sendPointsToDrives();
    static bool isDistanceZero(double start_drive1,double end_drive1,
                        double start_drive2,double end_drive2,
                        double start_drive3,double end_drive3);

protected:
    void run();

signals:
    void finishedLoading(int number_of_points,int time);
    void startedSendingPoints();
    void startedSendingArrayPoints();
    void finishedSendingPoints();
    void finishedSendingArrayPoints();
public slots:
    void startSendingArrayPointsSlot();

private:
    int numberOfPoint = 0;
    int numberOfDrive = 0;
    bool is_initiated = 0;
    bool is_in_kinematics_state = 0;
    bool go_home_for_all_drives=0;

    double x_start;
    double y_start;
    double z_start;

    double x_end;
    double y_end;
    double z_end;


    int NUMBER_OF_motorpuls =524288;

    QVector<QVector<double>> loadedPoints;
    QVector<QVector<double>> arrayPoints;
    QString trajectoryFilePath;
};

#endif // TRAJECTORYSENDER_H
