#include "sevensegment.h"
#include "kinematicsexception.h"
SevenSegment::SevenSegment(QObject *parent) : QObject(parent)
{

}

void SevenSegment::seven_segment(double q0, double q1, double v0, double v1, double vmax, double amax, double jmax, double dt, double lamda)
{
    double dist = q1 - q0;
    double Tj1; //time - interval in which the jerk is constant  during acc
    double Tj2;  //time-interval in which the jerk is constant during dec
    double Td; // time interval of dec
    double Ta; // time interval of acc
    double Tv; // constant velocity period
    double T;


    if (!(dist < 0 || dist > 0)) {
        timet = 0;
        qadad = q0;      // assssssssssssssssk
        v = nullptr;
        a = nullptr;
        j = nullptr;
        vlim = 0;
        alima = 0;
        alimd = 0;
        qDebug( "dist is zero ");
        //KinematicsException
        //throw KinematicsException("distance is zero",false);
        //=new KinematicsException("distance is zero");
    }
    // ask about the if  and landa values
    // Case 1: vlim = vmax.
    // max acc has been reached
    int sigma = signbit(dist);
    if (signbit(dist) == 1) {   // ask if zero needs to be checked too
        q0 = -1 * q0;
        q1 = -1 * q1;
        v0 = -1 * v0;
        v1 = -1 * v1;

    }

    // has mac acc reached?
    if ((vmax - v0)*jmax < pow(amax, 2)) {
        Tj1 = sqrt((vmax - v0) / jmax);
        Ta = 2 * Tj1;
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
                amax = lamda*amax;
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
    time = new double[(int)(T / dt)+1];
     sizeoftime = (int)(T / dt);
    //int test = sizeof(time);
    // cout << "jgfakjsdf ";
    q = new double[(int)(T / dt)+1];
    v = new double[(int)(T / dt)+1];
    a = new double[(int)(T / dt)+1];
    j = new double[(int)(T / dt)+1];
    double temp =(int)(T / dt);


    for (int i = 0;i < T / dt;i++) {
        time[i] = c;
        c += dt;
    }
    double jmin = -jmax;
    qsize = 0;
    for (double t = 0;t < T;t += dt) {
        //t = ceilf(t * 10000) / 10000;

        if (t < Tj1) {
            //cout <<  "first if ", Tj1;

            q[qsize] = q0 + v0*t + jmax*pow(t, 3) / 6;
            v[qsize] = v0 + jmax*pow(t, 2) / 2;
            a[qsize] = jmax*t;
            j[qsize] = jmax;
        }
        else if (t < Ta - Tj1) {

            //cout << "first else if";
            q[qsize] = q0 + v0*t + alima*(3 * pow(t, 2) - 3 * Tj1*t + pow(Tj1, 2)) / 6;
            v[qsize] = v0 + alima*(t - Tj1 / 2);
            a[qsize] = alima;
            j[qsize] = 0;
        }
        else if (t < Ta) {
            //cout << "second else if";
            q[qsize] = q0 + (vlim + v0)*Ta / 2 - vlim*(Ta - t) - jmin*pow((Ta - t), 3) / 6;
            v[qsize] = vlim + jmin*pow((Ta - t), 2) / 2;
            a[qsize] = -jmin*(Ta - t);
            j[qsize] = jmin;
        }

        else if (t < Ta + Tv) {
            //cout << "thirs else if";
            q[qsize] = q0 + (vlim + v0)*Ta / 2 + vlim*(t - Ta);
            v[qsize] = vlim;
            a[qsize] = 0;
            j[qsize] = 0;
        }
        else if (t < T - Td + Tj2) {
            //cout << "fourth else if";
            q[qsize] = q1 - (vlim + v1)*Td / 2 + vlim*(t - T + Td) - jmax*pow((t - T + Td), 3) / 6;
            v[qsize] = vlim - jmax*pow((t - T + Td), 2) / 2;
            a[qsize] = -jmax*(t - T + Td);
            j[qsize] = jmin;
        }
        else if (t < T - Tj2) {
            //cout << " 5th";
            q[qsize] = q1 - (vlim + v1)*Td / 2 + vlim*(t - T + Td) + alimd*(3 * pow((t - T + Td), 2) - 3 * Tj2*(t - T + Td) + pow(Tj2, 2)) / 6;
            v[qsize] = vlim + alimd*(t - T + Td - Tj2 / 2);
            a[qsize] = alimd;
            j[qsize] = 0;
        }
        else if (t <= T) {
            //cout << "6th";
            q[qsize] = q1 - v1*(T - t) - jmax*pow(T - t, 3) / 6;
            //cout << qsize << "  ";
            v[qsize] = v1 + jmax*pow((T - t), 2) / 2;
            a[qsize] = -jmax*(T - t);
            j[qsize] = jmax;
        }
        qsize++;
        //cout << t;
        //cout << "\n";
    }
    if (signbit(dist) == 1) {
        for (int i = 0;i < qsize;i++) {
            q[i] = -1 * q[i];
            v[i] = -1 * v[i];
            a[i] = -1 * a[i];
            j[i] = -1 * j[i];
        }
    }


    // //have to delete all the dynamic arrays
    //cout << temp;
    //cout << "heyy";
    //cout << qsize;
    //for (int i = 0;i < qsize;i++) {
        //cout << q[i];
    //	//cout << "\n";
    //}

    //cout << "dooooooooone";
    //cout << temp;


}

SevenSegment::~SevenSegment()
{
    if(time!=nullptr)
    {
        qDebug("time is not null");
        //cout << "remove " << q << endl;
        delete[] time;
        time = nullptr;
    }
    if(q!=nullptr)
    {
        qDebug("q is not null");
        delete[] q;
        q = nullptr;
    }
    if(v!=nullptr)
    {
        qDebug("v is not null");
        delete[] v;
        v = nullptr;
    }
    if(a!=nullptr)
    {
        qDebug("a is not null");
        delete[] a;
        a = nullptr;
    }
    if(j!=nullptr)
    {
        qDebug("j is not null");
        delete[] j;
        j = nullptr;
    }
}
