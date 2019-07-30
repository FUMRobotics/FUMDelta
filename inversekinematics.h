#ifndef INVERSEKINEMATICS_H
#define INVERSEKINEMATICS_H

#include <QObject>
#include <cmath>
#include <iostream>
#include <complex>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class InverseKinematics : public QObject
{
    Q_OBJECT
public:
    explicit InverseKinematics(QObject *parent = nullptr);
    ~InverseKinematics();
    int dotProduct(vector<int> A, vector<int> B);
    float cosd(float a);
    float sind(float a);
    void InverseKinematicsCalculation(float x, float y, float z);
    void sevenSegment(float q0,float  q1,float  v0, float v1, float vmax,float  amax,float jmax, float  dt, float landa) ;
    int base();
signals:

public slots:
    // varibales for inverse kinematics
private:
    int alpha[3];
    float r = 0.13;
    float la = 0.27;
    float lb = 0.74;
    int e = 1;
    float l[3];
    float m[3];
    float n[3];
    float tteta[3][2];
    float teta[3];
    float teta2[3];
    float teta3[3];
    float beta;
    float * time;


    float timeForCalculation;

    double xDegrees;

    float finalTeta[3];

    // varibles for seven segment

    float * q;
    float qadad;
    float * v;
    float * a;
    float * j;
    float vlim = 0;
     float alima = 0;
    float alimd = 0;
};

#endif // INVERSEKINEMATICS_H
