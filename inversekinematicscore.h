#ifndef INVERSEKINEMATICSCORE_H
#define INVERSEKINEMATICSCORE_H

#include <iostream>
#include <Eigen/Dense>
#include <math.h>
#include <QtConcurrent>
#include "sevensegment.h"

using Eigen::MatrixXd;
using Eigen::Vector3d;

using namespace Eigen;
using namespace std;


class InverseKinematicsCore
{
public:
    InverseKinematicsCore();
    double cosd(double a) {
        double degree = a*3.14159265358979323846 / 180;
        return cos(degree);

    }
    double sind(double a) {
        double degree = a*3.14159265358979323846 / 180;
        return sin(degree);

    }
    void InverseKinematicsNew(double x, double y, double z,double finalTeta[3]);
    void Interpolation(SevenSegment& M1, SevenSegment& M2, SevenSegment &M3,double **q1 , double** q2 , double** q3);

    static bool isPositionValid(double x,double y, double z);

    int size_of_trajectory_points;
};

#endif // INVERSEKINEMATICSCORE_H
