#ifndef INVERSEKINEMATICSCORE_H
#define INVERSEKINEMATICSCORE_H
#include <iostream>
#define BOOST_PYTHON_MAX_ARITY 22
#pragma push_macro("slots")
#undef slots
#include <boost/python.hpp>
#pragma pop_macro("slots")
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
        double degree = a*(3.14159265358979323846 / 180);
        return cos(degree);

    }
    double sind(double a) {
        double degree = a*(3.14159265358979323846 / 180);
        return sin(degree);

    }
    void InverseKinematicsNew(double x, double y, double z,double finalTeta[3]);
    void Interpolation(SevenSegment& M1, SevenSegment& M2, SevenSegment &M3,
                       double **q1 , double** q2 , double** q3);
    void iK(double x, double y, double z, double finalTeta[3]);
    void linear(double X0, double Y0, double Z0,double  Ro0,
                double Pi0,double  Ya0,double  v0, double X1,
                double  Y1,double  Z1,double Ro1,double Pi1,
                double Ya1,double v1,double vmax,
                double amax,double jmax);
    void circ(double X0,double  Y0, double Z0,
              double Ro0, double Pi0, double Ya0,
              double v0,double  X1,double Y1,
              double Z1,double Ro1,double Pi1,
              double Ya1,double v1, double vmax,
              double  amax,double jmax,double  X2,
              double Y2,double Z2,double Ta);




    // Proxy function for converting python list to c-array
    void InverseKinematicsNewProxy(double x, double y, double z, boost::python::list& ns){
        qDebug("IKCore : IKNew proxy has been called");
        double finalTeta[3];
        for (int i = 0; i < len(ns); ++i)
          {
                finalTeta[i] = boost::python::extract<double>(ns[i]);
          }
        this->InverseKinematicsNew(x,y,z,finalTeta);

    }
    //Test function to use it with Boost.Py library
    void callFromPy(){
        qDebug("Called from python");
    }

    static bool isPositionValid(double x,double y, double z);
    Eigen::Quaterniond ToQuaternion(double yaw, double pitch, double roll);

    double ToEulerAngles(Quaterniond &q);

    ~InverseKinematicsCore();
    int size_of_trajectory_points;


    double *M1;
    double *M2;
    double *M3;
    double *yaw;

    Quaterniond final;
    double X;
    double Y;
    double Z;
};

#endif // INVERSEKINEMATICSCORE_H
