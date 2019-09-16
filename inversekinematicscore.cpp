#include "inversekinematicscore.h"
#include "kinematicsexception.h"


InverseKinematicsCore::InverseKinematicsCore()
{

}

//void InverseKinematicsCore:: InverseKinematicsNew(double x, double y, double z,double finalTeta[3])
//{
//    //KinematicsException newex = KinematicsException("this is test Exception");
//    qDebug("salam");
//    // varibales for IK
//    static const int alpha[3] = { 0, 120, 240 };
//    static const double r = 0.13; double la = 0.27; double lb = 0.74;
//    //static const int e = 1;
//    double l[3];
//    double m[3];
//    double n[3];
//    double tteta[3][2];
//    double teta[3];
//    double teta2[3];
//    double teta3[3];
//    double beta;
//    static const Vector3d rrb(r, 0.0, 0.0);
//    Vector3d normal(0.0, 0.0, 0.0);
//    MatrixXd R(3, 3);
//    double xDegrees;
//    Vector3d temp(0.0, 0.0, -1.0);



//    int j = 0;
//    for (int i = 0; i < 3; i++) {
//        xDegrees = alpha[i];
//        //double alphaDeg = xDegrees*3.14159 / 180;
//        l[i] = 2 * r*la - 2 * x*la*cosd(xDegrees) + 2 * y*la*sind(xDegrees);
//        m[i] = 2 * z*la;
//        n[i] = pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0) + pow(la, 2.0) - pow(lb, 2.0) + pow(r, 2.0) + 2 * y*r*sind(xDegrees) - 2 * x*r*cosd(xDegrees);
//        if (imag(-m[i] + sqrt(pow(m[i], 2.0) + pow(l[i], 2.0) - pow(n[i], 2.0)) / (n[i] - l[i])) != 0) {  // need data to check this part z may never have real part
//            j = 1;

//        }
//        if (j == 1) {
//            cout << " out of work space";
//        }
//        else {


//            tteta[i][0] = 2 * (atan2(-m[i] + sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * 180 / (3.14159265358979323846));
//            tteta[i][1] = 2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * 180 / (3.14159265358979323846));
//            if (2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159265358979323846)) < -90) {
//                tteta[i][1] += 360;
//            }
//            if (2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159265358979323846)) > 90) {
//                tteta[i][1] -= 360;
//            }
//        }
//    }

//    // shard haye zavayaye link ha
//    if (tteta[0][1] > 90 || tteta[0][1] < -60) {
//        cout << "degree out of bounds";
//    }
//    if (tteta[1][1] > 90 || tteta[1][1] < -60) {
//        cout << "degree out of bounds";
//    }
//    if (tteta[2][1] > 90 || tteta[2][1] < -60) {
//        cout << "degree out of bounds";
//    }
//    else
//        for (int i = 0; i < 3; i++) {
//            teta[i] = tteta[i][1];
//        }
//    // **************** Checking Singularity Points  ********************** //

//    for (int i = 0; i < 3; i++) {
//        //double xDegrees = alpha[i];
//        //double alphaDeg = xDegrees*3.14159 / 180;
//        R << cosd(alpha[i]), -sind(alpha[i]), 0.0,
//            -sind(alpha[i]), cosd(alpha[i]), 0.0,
//            0.0, 0.0, 1.0;
//        //cout << R;

//        double xx0 = cosd(alpha[i])*(la*cosd(teta[i]) + r);
//        double yy0 = (la*cosd(teta[i]) + r)*sind(alpha[i]);
//        double zz0 = -la*sind(teta[i]);
//        Vector3d x0(xx0, yy0, zz0);
//        Vector3d x1(x, y, z);

//        Vector3d xb = R*rrb; // checckkk checcckk checcckkkk

//        teta2[i] = acos((x0 - xb).dot(x1 - x0) / ((x0 - xb).norm() * (x1 - x0).norm())) * (180 / 3.14159265358979323846);
//        xb = temp;

//        //teta3(i) = acosd((dot(xb, x1 - x0)) / (norm(xb)*norm(x1 - x0)));

//        teta3[i] = acos(xb.dot(x1 - x0) / (xb.norm()*(x1 - x0).norm()))* (180 /3.14159265358979323846);

//        if ((teta2[i] > -30 && teta2[i] < 30) || (teta2[i] > 150 && teta2[i] < 210)) {
//            //TODO error

//        }
//        if ((teta3[i] > -110 && teta3[i] < -70) || (teta3[i] > 70 && teta3[i] < 110)) {

//            //TODO error
//        }

//    }
//    /// ******** Angle Limitation ************//
//    int rr = 0;
//    for (int i = 0; i < 3; i++) {
//        R << cosd(alpha[i]), -sind(alpha[i]), 0.0,
//            -sind(alpha[i]), cosd(alpha[i]), 0.0,
//            0.0, 0.0, 1.0;


//        double xx0 = cosd(alpha[i])*(la*cosd(teta[i]) + r);
//        double yy0 = (la*cosd(teta[i]) + r)*sind(alpha[i]);
//        double zz0 = -la*sind(teta[i]);
//        Vector3d x0(xx0, yy0, zz0);
//        Vector3d x1(x, y, z);

//        Vector3d xb = R*rrb;
//        normal = xb.cross(x0);

//        beta = acos(normal.dot(x1 - x0) / normal.norm()*(x1 - x0).norm()) * (180 / 3.14159265358979323846);
//        if (beta > 135 || beta < 45) {
//            rr = 1;
//        }
//        if (rr == 0) {
//            for (int i = 0; i < 3; i++) {
//                finalTeta[i] = tteta[i][1];

//            }

//        }

//    }

//    qDebug("values of finalTheta: %f , %f , %f",finalTeta[0],finalTeta[1],finalTeta[2]);
//}



void InverseKinematicsCore::Interpolation(SevenSegment& M1, SevenSegment& M2, SevenSegment &M3,double **q1 , double** q2 , double** q3) {

    int size;
    int temp1=M1.qsize;
    int temp2=M2.qsize;
    int temp3=M3.qsize;

    int greatest_is;

    if (isgreater(M1.qsize, M2.qsize) && isgreater(M1.qsize, M3.qsize)) {
        greatest_is = 1;
        //m1 is greater
        size = M1.qsize;
    }
    else if (isgreater(M2.qsize, M1.qsize) && isgreater(M2.qsize, M3.qsize)) {
        greatest_is = 2;
        //m2 is greater
        size = M2.qsize;
    }
    else {
        greatest_is = 3;
        //all 3 have equal size or m3 is the greatest
        size = M3.qsize;
    }
    this->size_of_trajectory_points=size;

    *q1 = new double[size];
    *q2 = new double[size];
    *q3 = new double[size];
    double ratio;

    for (int i = 0; i < (int)size; i++) {
        switch (greatest_is)
        {
        case 1: ratio = (M1.q[i] - M1.q[0]) / (M1.q[(int)size - 1] - M1.q[0]); break;
        case 2: ratio = (M2.q[i] - M2.q[0]) / (M2.q[(int)size - 1] - M2.q[0]); break;
        case 3: ratio = (M3.q[i] - M3.q[0]) / (M3.q[(int)size - 1] - M3.q[0]); break;
        default:
            qDebug("IMPOSSIBLE CASE,UKNOWN GREATEST_IS");
            ratio=0;
            break;
        }
        (*q1)[i] = ratio*(M1.q[temp1 - 1] - M1.q[0]) + M1.q[0];;
        (*q2)[i] = ratio*(M2.q[temp2 - 1] - M2.q[0]) + M2.q[0];
        (*q3)[i] = ratio*(M3.q[temp3 - 1] - M3.q[0]) + M3.q[0];
    }
}

void InverseKinematicsCore::linear(double X0, double Y0, double Z0, double Ro0, double Pi0, double Ya0, double v0, double X1, double Y1, double Z1, double Ro1, double Pi1, double Ya1, double v1, double vmax, double amax, double jmax)
{
    double D0 = 0;
    double D1 = sqrt(pow((X1 - X0), 2) + pow((Y1 - Y0), 2) + pow((Z1 - Z0), 2));

    Quaterniond Q0 = ToQuaternion(Ya0, Pi0 ,Ro0);

    Quaterniond Q1 = ToQuaternion(Ya1, Pi1, Ro1);


    double x = (X1 - X0) / D1;
    double y = (Y1 - Y0) / D1;
    double z = (Z1 - Z0) / D1;

    SevenSegment temp;
    double finalTeta[3];
    temp.seven_segment(D0, D1, v0, v1, vmax, amax, jmax, 0.001, 0.999);
    //the upper motors
    M1= new double[temp.qsize];
    M2= new double[temp.qsize];
    M3 = new double[temp.qsize];
    //the lower motor
    double *yaw = new double[temp.qsize];//temp.qsize];
    size_of_trajectory_points=temp.qsize;

//    ofstream yawww;
//    yawww.open("yawwww.txt");

    int j = 0;
    for (int i = 0;i < temp.qsize;i++) {

        // double X = X0 + temp.q[i] *(temp.qsize/D1) * x;
        double tempsd = X1 - X0;
        X = X0 + (temp.q[i])*((X1 - X0)/ D1);
        Y = Y0 + (temp.q[i] / D1)*(Y1 - Y0);
        Z = Z0 + (temp.q[i] / D1)*(Z1 - Z0);
        //
        final = Q0.slerp(temp.q[i]/D1, Q1);

        yaw[i] = ToEulerAngles(final);

//        yawww << setprecision(15) << fixed << i << "," << X << endl;

        InverseKinematicsNew(X,Y,Z, finalTeta);
        M1[i] = finalTeta[0];
        M2[i] = finalTeta[1];
        M3[i] = finalTeta[2];


    }
//    yawww.close();
//    ofstream motor1;
//    ofstream Motor2;
//    ofstream Motor3;
//    motor1.open("M1.txt");
//    Motor2.open("M2.txt");
//    Motor3.open("M3.txt");
//    for (int i = 0;i < temp.qsize;i++) {
//        motor1 << setprecision(15) << fixed << M1[i] << endl;
//        Motor2 << setprecision(15) << fixed << M2[i] << endl;
//        Motor3 << setprecision(15) << fixed << M3[i] << endl;

//        //cout.precision(15);
//        //cout << fixed <<q[i] << endl;
//    }
//    motor1.close();
//    Motor2.close();
//    Motor3.close();

    // tempx.close();

    qDebug("deleting M1, M2, M3");
    delete M1;
    delete M2;
    delete M3;
    cout  << endl << "End linear" << endl;

}

void InverseKinematicsCore::circ(double X0, double Y0, double Z0, double Ro0, double Pi0, double Ya0, double v0, double X1, double Y1, double Z1, double Ro1, double Pi1, double Ya1, double v1, double vmax, double amax, double jmax, double X2, double Y2, double Z2, double Ta)
{
    double D0 = 0;
    double D1 = 0;
    Vector3d A(X0, Y0, Z0);
    Vector3d B(X1 ,Y1 ,Z1);
    Vector3d C(X2 ,Y2, Z2);


    Vector3d u1 = B - A;
    Vector3d w1 = u1.cross(C - A);
    Vector3d u = u1 / (u1.norm());
    Vector3d w = w1 / (w1.norm());
    Vector3d v = w.cross(u);

    double bx = (B-A).dot(u);
    double cx = (C - A).dot(u);
    double cy = (C - A).dot(v);

    double h = (pow((cx - bx / 2), 2) + pow(cy, 2) - pow((bx / 2), 2)) / (2 * cy);
    Vector2d A2d(0, 0);
    Vector2d B2d(bx, 0);
    Vector2d C2d(cx, cy);
    Vector2d Cen2d(bx/2, h);
    double R = Cen2d.norm();

    if (Ta == 0) {

        double nom = ((A2d - Cen2d).dot(B2d - Cen2d));
        double denom = (A2d - Cen2d).norm() * (B2d - Cen2d).norm();
        Ta = acos(nom / denom);
        if(h > 0){
            Ta = 2 * 3.141592653589793 - Ta;
        }
        D0 = (3.141592653589793 + Ta) / 2;
        D1 = (3.141592653589793 - Ta) / 2;
    }
    else {
        double nom = ((A2d - Cen2d).dot(B2d - Cen2d));
        double denom = (A2d - Cen2d).norm() * (B2d - Cen2d).norm();
        double T0 = acos(nom / denom);
        //double T0 = acos((A2d - Cen2d).dot(B2d - Cen2d)) / (A2d - Cen2d).norm() * (B2d - Cen2d).norm();
        if (h > 0) {
            T0 = 2 * 3.141592653589793 - T0;
        }
        D0 = (3.141592653589793 + Ta) / 2 - (Ta-T0)/2;
        D1 = (3.141592653589793 - Ta) / 2 - (Ta - T0) / 2;

    }

    v0 = -v0 / R;
    v1 = -v1 / R;
    vmax = vmax / R;
    amax = amax / R;
    jmax = jmax / R;

    SevenSegment temp;
    double finalTeta[3];
    temp.seven_segment(D0, D1, v0, v1, vmax, amax, jmax, 0.001, 0.999);
    //the upper motors
    M1 = new double[temp.qsize];
    M2 = new double[temp.qsize];
    M3 = new double[temp.qsize];
    //the lower motor
    yaw = new double[temp.qsize];
    this->size_of_trajectory_points=temp.qsize;


    Quaterniond Q0 = ToQuaternion(Ya0, Pi0, Ro0);
    Quaterniond Q1 = ToQuaternion(Ya1, Pi1, Ro1);
//    ofstream xx;
//    xx.open("xCirc.txt");
//    ofstream yy;
//    yy.open("yCirc.txt");
//    ofstream zz;
//    zz.open("zCirc.txt");
//    ofstream yaww;
//    yaww.open("yawCrc.txt");
    for (int i = 0;i < temp.qsize;i++) {

        double X= (X0 + Cen2d(0)*u(0) + Cen2d(1)*v(0))+ (R*cos(temp.q[i])*u(0)+ R*sin(temp.q[i])*v(0));

//        xx << setprecision(15) << fixed <<i+1<< "," << X << endl;
        double Y = (Y0 + Cen2d(0)*u(1) + Cen2d(1)*v(1)) + (R*cos(temp.q[i])*u(1) + R*sin(temp.q[i])*v(1));

//        yy << setprecision(15) << fixed << i+1 << "," << Y << endl;
        double Z = (Z0 + Cen2d(0)*u(2) + Cen2d(1)*v(2)) + (R*cos(temp.q[i])*u(2) + R*sin(temp.q[i])*v(2));

//        zz << setprecision(15) << fixed << i +1<< "," << Z << endl;

        double ratio = (temp.q[i] - D0) / (D1 - D0);
        Quaterniond final = Q0.slerp(ratio, Q1);
        yaw[i] = ToEulerAngles(final);

//        yaww << setprecision(15) << fixed << i+1 << "," << yaw[i] << endl;

        InverseKinematicsNew(X, Y, Z, finalTeta);
        M1[i] = finalTeta[0];
        M2[i] = finalTeta[1];
        M3[i] = finalTeta[2];
        //cout << M1[i];


        //	cout << "in loop" << i << endl;

    }

//    xx.close();
//    yy.close();
//    zz.close();
//    yaww.close();
    qDebug("deleting M1, M2, M3");

    delete M1;
    delete M2;
    delete M3;
    cout  << endl << "End circ" << endl;






}

//------------------------- THE NEW REFINED INVERSE KINEMATICS : iK ------------------------------------
void InverseKinematicsCore::InverseKinematicsNew(double x, double y, double z, double finalTeta[])
{
    // varibales for IK

    static const int alpha[3] = { 0, 120, 240 };
    static const double r = 130; double la = 270; double lb = 740;
    static const int e = 1;
    double l[3];
    double m[3];
    double n[3];
    double tteta[3][2];
    double teta[3];
    double teta2[3];
    double teta3[3];
    double beta;
    static const Vector3d rrb(r, 0, 0);
    Vector3d normal(0, 0, 0);
    Matrix3d R(3, 3);
    double xDegrees;
    Vector3d temp(0, 0, -1.0);

    if (z >= -780 && z <= -530 && (pow(x, 2) + pow(y, 2)) <= (pow(400, 2))
            || (z >= -880 && z<= -780 && (pow(x, 2) + pow(y, 2)) <= pow((1.5*z + 1.570),2)))  {

        int j = 0;
        for (int i = 0; i < 3; i++) {
            xDegrees = alpha[i];
            //double alphaDeg = xDegrees*3.14159 / 180;
            l[i] = 2 * r*la - 2 * x*la*cosd(xDegrees) + 2 * y*la*sind(xDegrees);
            m[i] = 2 * z*la;
            n[i] = pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0) + pow(la, 2.0) - pow(lb, 2.0) + pow(r, 2.0) + 2 * y*r*sind(xDegrees) - 2 * x*r*cosd(xDegrees);


            tteta[i][0] = 2 * (atan2(-m[i] + sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.141592653589793));
            tteta[i][1] = 2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.141592653589793));
            if (2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.141592653589793)) < -90) {
                tteta[i][1] += 360;
            }
            if (2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.141592653589793)) > 90) {
                tteta[i][1] -= 360;
            }
        }
        for (int i = 0; i < 3; i++) {
            finalTeta[i] = tteta[i][1];

        }

    }
    else {
        cout << "not in workspace";
    }

}

bool InverseKinematicsCore::isPositionValid(double x, double y, double z)
{
    qDebug("x=%lf y=%lf z=%lf",x,y,z);
    return ((z >= -0.78 && z <= -0.53 &&
              (pow(x, 2) + pow(y, 2)) <= (pow(0.4, 2)))
             || (z >= -0.88 && z<= -0.78 &&
                 (pow(x, 2) + pow(y, 2)) <= pow((1.5*z + 1.570),2)));
}

Quaterniond InverseKinematicsCore::ToQuaternion(double yaw, double pitch, double roll)
{
    // Abbreviations for the various angular functions
    double cy = cos(yaw * 0.5);
    double sy = sin(yaw * 0.5);
    double cp = cos(pitch * 0.5);
    double sp = sin(pitch * 0.5);
    double cr = cos(roll * 0.5);
    double sr = sin(roll * 0.5);

    Eigen::Quaterniond q(cy * cp * cr + sy * sp * sr, cy * cp * sr - sy * sp * cr, sy * cp * sr + cy * sp * cr, sy * cp * cr - cy * sp * sr);

    return q;
}

double InverseKinematicsCore::ToEulerAngles(Quaterniond &q)
{
    double yaw;

    // yaw (z-axis rotation)
    double siny_cosp = +2.0 * (q.w() * q.z() + q.x() * q.y());
    double cosy_cosp = +1.0 - 2.0 * (q.y() * q.y() + q.z() * q.z());
     yaw = atan2(siny_cosp, cosy_cosp) *( 180 / 3.141592653589793);
     return yaw;
}

InverseKinematicsCore::~InverseKinematicsCore()
{
//    qDebug("deleting M1,M2,M3");
//    delete M1;
//    delete M2;
//    delete M3;
}
