#include "inversekinematics.h"
#include <cmath>
#include <iostream>
#include <complex>
#include <vector>
#include <Eigen/Dense>



InverseKinematics::InverseKinematics(QObject *parent) : QObject(parent)
{
    alpha[0]=0;
    alpha[1]=120;
    alpha[2]=240;

}

InverseKinematics::~InverseKinematics()
{
//    qDebug("deleting dynamic arrays");
//    delete[] q;
//    delete[] v;
//    delete[] a;
//    delete[] j;

}


int InverseKinematics:: dotProduct(vector<int> A, vector<int> B)
{

    int product = 0;

    // Loop for calculate cot product
    for (int i = 0; i < A.size(); i++)

        product = product + A[i] * B[i];
    return product;
}

float InverseKinematics::cosd(float a) {
    double degree = a*3.14159 / 180;
     return cos(degree);

}
float InverseKinematics:: sind(float a) {
    double degree = a*3.14159 / 180;
    return sin(degree);

}


void InverseKinematics:: InverseKinematicsCalculation(float x, float y, float z) {
    int j = 0;
    MatrixXf R(3, 3);
    Vector3f temp(0.0, 0.0, -1.0);
    Vector3f normal(0.0, 0.0, 0.0);
    Vector3f rrb(r,0.0,0.0);

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
            qDebug(" out of work space");
        }
        else {


            tteta[i][0] = 2 * (atan2(-m[i] + sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159));
            tteta[i][1] = 2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159));
            if (2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159)) < -90) {
                tteta[i - 1][0] += 360;
            }
            if (2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159)) > 90) {
                tteta[i - 1][0] -= 360;
            }
        }
    }

    // shard haye zavayaye link ha
    if (tteta[0][1] > 90 || tteta[0][1] < -60) {
        qDebug("degree out of bounds");
    }
    if (tteta[1][1] > 90 || tteta[1][1] < -60) {
        qDebug("degree out of bounds");
    }
    if (tteta[2][1] > 90 || tteta[2][1] < -60) {
        qDebug("degree out of bounds");
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
        cout << R;

        float xx0 = cosd(alpha[i])*(la*cosd(teta[i]) + r);
        float yy0 = (la*cosd(teta[i]) + r)*sind(alpha[i]);
        float zz0 = -la*sind(teta[i]);
        Vector3f x0(xx0, yy0, zz0);
        Vector3f x1(x, y, z);

        Vector3f xb = R*rrb; // checckkk checcckk checcckkkk

        teta2[i] = acos((x0 - xb).dot(x1 - x0) /( (x0 - xb).norm() * (x1 - x0).norm() )) * (180 / 3.14159);
        xb = temp;

        //teta3(i) = acosd((dot(xb, x1 - x0)) / (norm(xb)*norm(x1 - x0)));

        teta3[i] = acos(xb.dot(x1 - x0) /( xb.norm()*(x1 - x0).norm() ))* (180 / 3.14159);

        if ((teta2[i] > -30 && teta2[i] < 30) || (teta2[i] > 150 && teta2[i] < 210)) {}
        if ((teta3[i] > -110 && teta3[i] < -70) || (teta3[i] > 70 && teta3[i] < 110)) {}

    }
        /// ******** Angle Limitation ************//
    int r = 0;
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
                r = 1;
            }
            if (r == 0) {
                for (int i = 0;i < 3;i++) {
                    finalTeta[i]=tteta[i][1];

                }

            }

        }
}

    //cout << test;


void InverseKinematics:: sevenSegment(float q0,float  q1,float  v0, float v1, float vmax,float  amax,float jmax, float  dt, float landa) {
    float dist = q1 - q0;
    float Tj1; //time - interval in which the jerk is constant  during acc
    float Tj2;  //time-interval in which the jerk is constant during dec
    float Td; // time interval of dec
    float Ta; // time interval of acc
    float Tv; // constant velocity period
    float T;


    if (dist == 0) {
        timeForCalculation = 0;
        qadad= q0;      // assssssssssssssssk
        v = 0;
        a = 0;
        j = 0;
        vlim = 0;
        alima = 0;
        alimd = 0;
        qDebug("dist is zero ");

    }
        // ask about the if  and landa values

        // Case 1: vlim = vmax.
        // max acc has been reached
        int sigma = signbit(dist);
        if (signbit(dist) == 1) {   // ask if zero needs to be checked too
            q0 = -1*q0;
            q1 = -1*q1;
            v0 = -1*v0;
            v1 = -1*v1;

        }

        // has mac acc reached?
        if ((vmax - v0)*jmax < pow(amax, 2)) {
            Tj1 = sqrt((vmax - v0) / jmax);
            Td = 2 * Tj1;
        }
        else {
            Tj1 = amax / jmax;
            Ta = Tj1 + (vmax - v0) / amax;
        }
        if ((vmax - v1)*jmax < pow(amax, 2)) {
            Tj2 = sqrt((vmax - v1) / jmax);
            Td = 2 * Tj2;
        }
        else {
            Tj2 = amax / jmax;
            Td = Tj2 + (vmax - v1) / amax;
        }

        Tv = (q1 - q0) / vmax - (Ta / 2)*(1 + v0 / vmax) - (Td / 2)*(1 + v1 / vmax);


        //Case 2: vlim < vmax.

        if (Tv < 0) {
            Tv = 0;
            while (1) {
                Tj1 = amax / jmax;
                    Tj2 = amax / jmax;
                    long double delta = (pow(amax, 4) / pow(jmax, 2)) + 2 * (pow(v0, 2) + pow(v1, 2)) + amax*(4 * (q1 - q0) - 2 * (amax / jmax) *(v0 + v1));

                    Ta = ((pow(amax, 2) / jmax) - 2 * v0 + sqrt(delta)) / (2 * amax);
                    Td = ((pow(amax, 2) / jmax) - 2 * v1 + sqrt(delta)) / (2 * amax);


                        if (Ta < 0) {
                            Ta = 0;
                            Td = 2 * (q1 - q0) / (v1 + v0);
                            Tj2 = (jmax*(q1 - q0) - sqrt(jmax*(pow(jmax*(q1 - q0), 2) + pow((v1 + v0), 2)*(v1 - v0)))) / (jmax*(v1 + v0));
                        }
                        else if (Td < 0) {
                            Td = 0;
                            Ta = 2 * (q1 - q0) / (v1 + v0);
                            Tj1 = (jmax*(q1 - q0) - sqrt(jmax*(pow(jmax*(q1 - q0), 2)*(v1 - v0)))) / (jmax*(v1 + v0));
                        }

                        if (Ta >= 2 * Tj1 && Td >= 2 * Tj2)
                        {
                            break;
                        }
                        else
                        {
                             amax = landa*amax;
                        }

            }
            alima = jmax*Tj1;
            alimd = -jmax*Tj2;
            vlim = v0 + (Ta - Tj1)*alima;
        }
        else {
            alima = amax;
            alimd = -amax;
            vlim = vmax;
        }
        T = Ta + Tv + Td;
        T = ceilf(T * 10000) / 10000; // checkkk
        int c = 0;
         time = new float[(int)(T / dt)];
        q = new float[(int)(T / dt)];
        v = new float[(int)(T / dt)];
        a = new float[(int)(T / dt)];
        j = new float[(int)(T / dt)];
//        cout<<"time[370]"<<time[370]<<endl;
//        cout<<"T/dt="<<T/dt<<endl;
        float temp = T / dt;

        for (int i = 0;i < T / dt;i++) {
            time[i] = c;
            c += dt;
        }
         float jmin = -jmax;
         int i = 0;
         for (float t = 0;t < T;t = t+  dt) {
             t = ceilf(t * 10000) /10000;

             if (t < Tj1) {

                 q[i] = q0 +v0*t+jmax*pow(t, 3) / 6;
                 v[i] = v0 + jmax*pow(t, 2) / 2;
                 a[i] = jmax*t;
                 j[i] = jmax;
             }
             else if (t < Ta - Tj1) {
                 q[i] = q0 + v0*t + alima*(3 * pow(t,2)- 3 * Tj1*t + pow(Tj1,2)) / 6;
                 v[i] = v0 + alima*(t - Tj1 / 2);
                 a[i] = alima;
                 j[i] = 0;
             }
             else if (t < Ta) {
                 q[i] = q0 + (vlim + v0)*Ta / 2 - vlim*(Ta - t) - jmin*pow((Ta - t), 3) / 6;
                 v[i] = vlim + jmin*pow((Ta - t), 2) / 2;
                 a[i] = -jmin*(Ta - t);
                 j[i] = jmin;
             }

             else if (t < Ta + Tv) {
                 q[i] = q0 + (vlim + v0)*Ta / 2 + vlim*(t - Ta);
                 v[i] = vlim;
                 a[i] = 0;
                 j[i] = 0;
             }
             else if (t < T - Td + Tj2) {
                 q[i] = q1 - (vlim + v1)*Td / 2 + vlim*(t - T + Td) - jmax*pow((t - T + Td),3) / 6;
                 v[i] = vlim - jmax*pow((t - T + Td), 2) / 2;
                 a[i] = -jmax*(t - T + Td);
                 j[i] = jmin;
             }
             else if (t < T - Tj2) {
                 q[i] = q1 - (vlim + v1)*Td / 2 + vlim*(t - T + Td) + alimd*(3 *pow( (t - T + Td) , 2) - 3 * Tj2*(t - T + Td) + pow(Tj2 , 2)) / 6;
                 v[i] = vlim + alimd*(t - T + Td - Tj2 / 2);
                 a[i] = alimd;
                 j[i] = 0;
             }
             else if (t <= T) {
                 q[i] = q1 - v1*(T - t) - jmax*pow((T - t), 3) / 6;
                 v[i] = v1 + jmax*pow((T - t), 2) / 2;
                 a[i] = -jmax*(T - t);
                 j[i] = jmax;
             }
             i++;
         }


  // have to delete all the dynamic arrays
    //delete[] time;

}


int InverseKinematics:: base() {

    InverseKinematicsCalculation(0,0,-0.8);
    cout<<"ik done"<<endl;
    sevenSegment(0, 2, 0, 0, 350, 10, 100, 0.001, 0.999);

    QString log1="calculation completed. teta[0]="+QString::number(teta[0])+" teta[1]="+QString::number(teta[1])+" teta[2]="+QString::number(teta[2]);
    QString log2="teta2[0]="+QString::number(teta2[0])+" teta2[1]="+QString::number(teta2[1])+" teta2[2]="+QString::number(teta2[2]);
    QString log3=" teta3[0]="+QString::number(teta3[0])+" teta3[1]="+QString::number(teta3[1])+" teta3[2]="+QString::number(teta3[2]);
    QString log4="finalTeta[0]="+QString::number(finalTeta[0])+" finalTeta[1]="+QString::number(finalTeta[1])+" finalTeta[2]="+QString::number(finalTeta[2]);
    qDebug(log1.toLatin1());
    qDebug(log2.toLatin1());
    qDebug(log3.toLatin1());
    qDebug(log4.toLatin1());
}
