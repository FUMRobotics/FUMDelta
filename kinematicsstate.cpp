#include "kinematicsstate.h"
#include <cmath>
#include <iostream>
#include <complex>
#include <vector>
#include <Eigen/Dense>


using Eigen::MatrixXf;
using Eigen::Vector3f;

using namespace Eigen;
using namespace std;
KinematicsState::KinematicsState(QObject *parent) : QObject(parent)
{

}


void KinematicsState::InverseKinematics(float x, float y, float z)
{

    // varibales for IK
    int alpha[3] = { 0, 120, 240 };
    float r = 0.13;float la = 0.27;float lb = 0.74;
    int e = 1;
    float l[3];
    float m[3];
    float n[3];
    float tteta[3][2];
    float teta[3];
    float teta2[3];
    float teta3[3];
    float beta;
    Vector3f rrb(r, 0.0, 0.0);
    Vector3f normal(0.0, 0.0, 0.0);
    MatrixXf R(3, 3);
    double xDegrees;
    Vector3f temp(0.0, 0.0, -1.0);



    int j = 0;
    for (int i = 0;i < 3;i++) {
        xDegrees = alpha[i];
        //double alphaDeg = xDegrees*3.14159 / 180;
        l[i] = 2 * r*la - 2 * x*la*cosd(xDegrees) + 2 * y*la*sind(xDegrees);
        m[i] = 2 * z*la;
        n[i] = pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0) + pow(la, 2.0) - pow(lb, 2.0) + pow(r, 2.0) + 2 * y*r*sind(xDegrees) - 2 * x*r*cosd(xDegrees);
        if (imag(-m[i] + sqrt(pow(m[i], 2.0) + pow(l[i], 2.0) - pow(n[i], 2.0)) / (n[i] - l[i])) != 0) {  // need data to check this part z may never have real part
            j = 1;

        }
        if (j == 1) {
            cout << " out of work space";
        }
        else {


            tteta[i][0] = 2 * (atan2(-m[i] + sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159));
            tteta[i][1] = 2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159));
            if (2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159)) < -90) {
                tteta[i][1] += 360;
            }
            if (2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159)) > 90) {
                tteta[i][1] -= 360;
            }
        }
    }

    // shard haye zavayaye link ha
    if (tteta[0][1] > 90 || tteta[0][1] < -60) {
        cout << "degree out of bounds";
    }
    if (tteta[1][1] > 90 || tteta[1][1] < -60) {
        cout << "degree out of bounds";
    }
    if (tteta[2][1] > 90 || tteta[2][1] < -60) {
        cout << "degree out of bounds";
    }
    else
        for (int i = 0;i < 3;i++) {
            teta[i] = tteta[i][1];
        }
    // **************** Checking Singularity Points  ********************** //

    for (int i = 0;i < 3;i++) {
        //double xDegrees = alpha[i];
        //double alphaDeg = xDegrees*3.14159 / 180;
        R << cosd(alpha[i]), -sind(alpha[i]), 0.0,
            -sind(alpha[i]), cosd(alpha[i]), 0.0,
            0.0, 0.0, 1.0;
        //cout << R;

        float xx0 = cosd(alpha[i])*(la*cosd(teta[i]) + r);
        float yy0 = (la*cosd(teta[i]) + r)*sind(alpha[i]);
        float zz0 = -la*sind(teta[i]);
        Vector3f x0(xx0, yy0, zz0);
        Vector3f x1(x, y, z);

        Vector3f xb = R*rrb; // checckkk checcckk checcckkkk

        teta2[i] = acos((x0 - xb).dot(x1 - x0) / ((x0 - xb).norm() * (x1 - x0).norm())) * (180 / 3.14159);
        xb = temp;

        //teta3(i) = acosd((dot(xb, x1 - x0)) / (norm(xb)*norm(x1 - x0)));

        teta3[i] = acos(xb.dot(x1 - x0) / (xb.norm()*(x1 - x0).norm()))* (180 / 3.14159);

        if ((teta2[i] > -30 && teta2[i] < 30) || (teta2[i] > 150 && teta2[i] < 210)) {}
        if ((teta3[i] > -110 && teta3[i] < -70) || (teta3[i] > 70 && teta3[i] < 110)) {}

    }
    /// ******** Angle Limitation ************//
    int rr = 0;
    for (int i = 0;i < 3;i++) {
        R << cosd(alpha[i]), -sind(alpha[i]), 0.0,
            -sind(alpha[i]), cosd(alpha[i]), 0.0,
            0.0, 0.0, 1.0;


        float xx0 = cosd(alpha[i])*(la*cosd(teta[i]) + r);
        float yy0 = (la*cosd(teta[i]) + r)*sind(alpha[i]);
        float zz0 = -la*sind(teta[i]);
        Vector3f x0(xx0, yy0, zz0);
        Vector3f x1(x, y, z);

        Vector3f xb = R*rrb;
        normal = xb.cross(x0);

        beta = acos(normal.dot(x1 - x0) / normal.norm()*(x1 - x0).norm()) * (180 / 3.14159);
        if (beta > 135 || beta < 45) {
            rr = 1;
        }
        if (rr == 0) {
            for (int i = 0;i < 3;i++) {
                finalTeta[i] = tteta[i][1];

            }

        }

    }
}

void KinematicsState::Interpolation(KinematicsState& initial ,KinematicsState& final)//;float x1, float y1, float z1, float x2, float y2, float z2)
{
    // state initial;
     //state final;
     //float x0, y0, z0;
     //float x1, y1, z1;
     initial.InverseKinematics(initial.x, initial.y, initial.z);
     final.InverseKinematics(final.x, final.y, final.z);

     float xx = initial.finalTeta[0];
     float yy = final.finalTeta[0];
     M1.calculate(initial.finalTeta[0], final.finalTeta[0], 0, 0, 350, 10, 100, 0.001, 0.999);
     M2.calculate(initial.finalTeta[1], final.finalTeta[1], 0, 0, 350, 10, 100, 0.001, 0.999);
     M3.calculate(initial.finalTeta[2], final.finalTeta[2], 0, 0, 350, 10, 100, 0.001, 0.999);

     int arr[3] = {0,0,0};
     if (isgreater(M1.qsize, M2.qsize)) {
         if (isgreater(M1.qsize, M3.qsize)) {
             size = M1.qsize;
             q1 = new float[size];
             q2 = new float[size];
             q3 = new float[size];
             float zavie;
             float zavie2;
             float zavie3;
             for (int i = 0;i < (int)size;i++) {
                 zavie=(M1.q[i]-M1.q[0])/(M1.q[(int)size-1]-M1.q[0]);
                 q1[i] = zavie;
                 zavie2 = zavie*(M2.q[(int)size - 1] - M2.q[0]) + M2.q[0];
                 q2[i] = zavie2;
                 zavie3 = zavie*(M3.q[(int)size - 1] - M3.q[0]) + M3.q[0];
                 q3[i] = zavie3;

             }



         }
         else {
             size = M3.qsize;
             q1 = new float[size];
             q2 = new float[size];
             q3 = new float[size];
             float zavie;
             float zavie2;
             float zavie3;
             for (int i = 0;i < (int)size;i++) {
                 zavie3 = (M3.q[i] - M3.q[0]) / (M3.q[(int)size - 1] - M3.q[0]);
                 q3[i] = zavie3;
                 zavie2 = zavie3*(M2.q[(int)size - 1] - M2.q[0]) + M2.q[0];
                 q2[i] = zavie2;
                 zavie = zavie3*(M1.q[(int)size - 1] - M1.q[0]) + M1.q[0];
                 q1[i] = zavie;
             }

         }
     }
     else if (isgreater(M2.qsize, M3.qsize)) {
         size = M2.qsize;
         size = M3.qsize;
         q1 = new float[(int)size];
         q2 = new float[(int)size];
         q3 = new float[(int)size];
         float zavie;
         float zavie2;
         float zavie3;
         for (int i = 0;i < (int)size;i++) {
             zavie2 = (M2.q[i] - M2.q[0]) / (M2.q[(int)size - 1] - M2.q[0]);
             q2[i] = zavie2;
             zavie = zavie2*(M1.q[(int)size - 1] - M1.q[0]) + M1.q[0];
             q1[i] = zavie;
             zavie = zavie2*(M1.q[(int)size - 1] - M1.q[0]) + M1.q[0];
             q1[i] = zavie;
         }

     }
     else {
         size = M3.qsize;

         q1 = new float[size];
         q2 = new float[size];
         q3 = new float[size];
         float zavie;
         float zavie2;
         float zavie3;
        // cout << "starts from here ";
         int i;
         for (i = 0;i < (int)size;i++) {
             float x = M3.q[(int)size - 1];
             zavie3 = (M3.q[i] - M3.q[0]) / (M3.q[(int)size - 1] - M3.q[0]);
             q3[i] =  zavie3*(M3.q[(int)size - 1] - M3.q[0]) + M3.q[0];;
             //cout << "starts from here ";
            // cout << q3[i];
             //cout << "\n";
             zavie2 = zavie3*(M2.q[(int)size - 1] - M2.q[0]) + M2.q[0];
             q2[i] = zavie2;
             //cout << q2[i];
             //cout << "\n";
             zavie = zavie3*(M1.q[(int)size - 1] - M1.q[0]) + M1.q[0];
             q1[i] = zavie;
         }
        // cout << "i= " << i<<endl;

         //for (int i = 0;i < size;i++) {

         //}

     }



}

KinematicsState::~KinematicsState()
{

    delete[] q1;
    q1 = NULL;
    delete[] q2;
    q2 = NULL;
    delete[] q3;
    q3 = NULL;

}
