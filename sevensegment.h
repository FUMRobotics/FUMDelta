#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

#include <QObject>
#include <iostream>
#include <Eigen/Dense>
#include <math.h>

using namespace std;

class SevenSegment : public QObject
{
    Q_OBJECT
public:
    explicit SevenSegment(QObject *parent = nullptr);
    void calculate(float q0, float  q1, float  v0, float v1, float vmax, float  amax, float jmax, float  dt, float lamda);
    ~SevenSegment();
signals:

public slots:

public:

    //variables for 7seg
    float timet;
    float * time;
    float * q;
    float qadad;
    float * v;
    float * a;
    float * j;
    float vlim = 0;
    float alima = 0;
    float alimd = 0;
    float sizeoftime;
    int qsize;
};

#endif // SEVENSEGMENT_H
