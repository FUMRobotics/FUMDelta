#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

#include <QObject>
#include <iostream>
#include <Eigen/Dense>
#include <math.h>

using Eigen::MatrixXd;
using Eigen::Vector3d;

using namespace Eigen;
using namespace std;

class SevenSegment : public QObject
{
    Q_OBJECT
public:
    explicit SevenSegment(QObject *parent = nullptr);
    void seven_segment(double q0, double  q1, double  v0, double v1, double vmax, double  amax, double jmax, double  dt, double lamda);
    ~SevenSegment();
signals:

public slots:

public:

    //variables for 7seg
    double timet;
    double * time;
    double * q;
    double qadad;
    double * v;
    double * a;
    double * j;
    double vlim = 0;
    double alima = 0;
    double alimd = 0;
    double sizeoftime;
    int qsize;

};

#endif // SEVENSEGMENT_H
