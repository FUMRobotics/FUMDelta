#ifndef KINEMATICSSTATE_H
#define KINEMATICSSTATE_H

#include <QObject>
#include <Eigen/Dense>
#include "sevensegment.h"
//#include "kinematicsstate.h"


class KinematicsState : public QObject
{
    Q_OBJECT
public:
    explicit KinematicsState(QObject *parent = nullptr);
   void InverseKinematics(float x, float y, float z);
   void Interpolation(KinematicsState& initial ,KinematicsState& final);
   float cosd(float a) {
       float degree = a*3.14159 / 180;
       return cos(degree);

   }
   float sind(float a) {
       float degree = a*3.14159 / 180;
       return sin(degree);

   }
   ~KinematicsState();
signals:

public slots:

public:


    // varibaled for IK
   SevenSegment M1;
   SevenSegment M2;
   SevenSegment M3;

   float z, y, x;
   float  finalTeta[3];

   int size;

   float * q1;
   float * q2;
   float * q3;

};

#endif // KINEMATICSSTATE_H
