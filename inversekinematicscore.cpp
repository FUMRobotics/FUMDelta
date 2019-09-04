#include "inversekinematicscore.h"
#include "kinematicsexception.h"

InverseKinematicsCore::InverseKinematicsCore()
{

}

//class state {
//public:
//
//	// varibaled for IK
//	float z, y, x;
//	float  finalTeta[3];
//	sevenSeg M1;
//	sevenSeg M2;
//	sevenSeg M3;
//
//	float * q1;
//	float * q2;
//	float * q3;
//
//
//
//
//
//	/*
//	 typedef Eigen::Matrix<float, 3, 1> Vector3f ;
//	 EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
//
//	 Eigen::Vector3f rrb;
//
//	  rrb <<   r,0.0,0.0;
//	 Eigen::Matrix<float, 3, 1> Vector3f normal(0.0, 0.0, 0.0);
//	 MatrixXf R(3, 3);
//	 double xDegrees;
//	 Vector3f temp(0.0, 0.0, -1.0);
//
//	 */
//
//
//	float cosd(float a) {
//		float degree = a*3.14159 / 180;
//		return cos(degree);
//
//	}
//	float sind(float a) {
//		float degree = a*3.14159 / 180;
//		return sin(degree);
//
//	}
//
//	void InverseKinematics(float x, float y, float z) {
//
//		// varibales for IK
//		int alpha[3] = { 0, 120, 240 };
//		float r = 0.13; float la = 0.27; float lb = 0.74;
//		int e = 1;
//		float l[3];
//		float m[3];
//		float n[3];
//		float tteta[3][2];
//		float teta[3];
//		float teta2[3];
//		float teta3[3];
//		float beta;
//		Vector3f rrb(r, 0.0, 0.0);
//		Vector3f normal(0.0, 0.0, 0.0);
//		MatrixXf R(3, 3);
//		double xDegrees;
//		Vector3f temp(0.0, 0.0, -1.0);
//
//
//
//		int j = 0;
//		for (int i = 0; i < 3; i++) {
//			xDegrees = alpha[i];
//			//double alphaDeg = xDegrees*3.14159 / 180;
//			l[i] = 2 * r*la - 2 * x*la*cosd(xDegrees) + 2 * y*la*sind(xDegrees);
//			m[i] = 2 * z*la;
//			n[i] = pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0) + pow(la, 2.0) - pow(lb, 2.0) + pow(r, 2.0) + 2 * y*r*sind(xDegrees) - 2 * x*r*cosd(xDegrees);
//			if (imag(-m[i] + sqrt(pow(m[i], 2.0) + pow(l[i], 2.0) - pow(n[i], 2.0)) / (n[i] - l[i])) != 0) {  // need data to check this part z may never have real part
//				j = 1;
//
//			}
//			if (j == 1) {
//				cout << " out of work space";
//			}
//			else {
//
//
//				tteta[i][0] = 2 * (atan2(-m[i] + sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159));
//				tteta[i][1] = 2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159));
//				if (2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159)) < -90) {
//					tteta[i][1] += 360;
//				}
//				if (2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159)) > 90) {
//					tteta[i][1] -= 360;
//				}
//			}
//		}
//
//		// shard haye zavayaye link ha
//		if (tteta[0][1] > 90 || tteta[0][1] < -60) {
//			cout << "degree out of bounds";
//		}
//		if (tteta[1][1] > 90 || tteta[1][1] < -60) {
//			cout << "degree out of bounds";
//		}
//		if (tteta[2][1] > 90 || tteta[2][1] < -60) {
//			cout << "degree out of bounds";
//		}
//		else
//			for (int i = 0; i < 3; i++) {
//				teta[i] = tteta[i][1];
//			}
//		// **************** Checking Singularity Points  ********************** //
//
//		for (int i = 0; i < 3; i++) {
//			//double xDegrees = alpha[i];
//			//double alphaDeg = xDegrees*3.14159 / 180;
//			R << cosd(alpha[i]), -sind(alpha[i]), 0.0,
//				-sind(alpha[i]), cosd(alpha[i]), 0.0,
//				0.0, 0.0, 1.0;
//			//cout << R;
//
//			float xx0 = cosd(alpha[i])*(la*cosd(teta[i]) + r);
//			float yy0 = (la*cosd(teta[i]) + r)*sind(alpha[i]);
//			float zz0 = -la*sind(teta[i]);
//			Vector3f x0(xx0, yy0, zz0);
//			Vector3f x1(x, y, z);
//
//			Vector3f xb = R*rrb; // checckkk checcckk checcckkkk
//
//			teta2[i] = acos((x0 - xb).dot(x1 - x0) / ((x0 - xb).norm() * (x1 - x0).norm())) * (180 / 3.14159);
//			xb = temp;
//
//			//teta3(i) = acosd((dot(xb, x1 - x0)) / (norm(xb)*norm(x1 - x0)));
//
//			teta3[i] = acos(xb.dot(x1 - x0) / (xb.norm()*(x1 - x0).norm()))* (180 / 3.14159);
//
//			if ((teta2[i] > -30 && teta2[i] < 30) || (teta2[i] > 150 && teta2[i] < 210)) {}
//			if ((teta3[i] > -110 && teta3[i] < -70) || (teta3[i] > 70 && teta3[i] < 110)) {}
//
//		}
//		/// ******** Angle Limitation ************//
//		int rr = 0;
//		for (int i = 0; i < 3; i++) {
//			R << cosd(alpha[i]), -sind(alpha[i]), 0.0,
//				-sind(alpha[i]), cosd(alpha[i]), 0.0,
//				0.0, 0.0, 1.0;
//
//
//			float xx0 = cosd(alpha[i])*(la*cosd(teta[i]) + r);
//			float yy0 = (la*cosd(teta[i]) + r)*sind(alpha[i]);
//			float zz0 = -la*sind(teta[i]);
//			Vector3f x0(xx0, yy0, zz0);
//			Vector3f x1(x, y, z);
//
//			Vector3f xb = R*rrb;
//			normal = xb.cross(x0);
//
//			beta = acos(normal.dot(x1 - x0) / normal.norm()*(x1 - x0).norm()) * (180 / 3.14159);
//			if (beta > 135 || beta < 45) {
//				rr = 1;
//			}
//			if (rr == 0) {
//				for (int i = 0; i < 3; i++) {
//					finalTeta[i] = tteta[i][1];
//
//				}
//
//			}
//
//		}
//	}
//
//
//
//
//
//	//float x1, float y1, float z1, float x2, float y2, float z2
//
//	void Interpolation(state initial, state final) {
//		// state initial;
//		 //state final;
//		 //float x0, y0, z0;
//		 //float x1, y1, z1;
//		initial.InverseKinematics(initial.x, initial.y, initial.z);
//		final.InverseKinematics(final.x, final.y, final.z);
//		float size;
//		float xx = initial.finalTeta[0];
//		float yy = final.finalTeta[0];
//		M1.seven_segment(initial.finalTeta[0], final.finalTeta[0], 0, 0, 350, 10, 100, 0.001, 0.999);
//		M2.seven_segment(initial.finalTeta[1], final.finalTeta[1], 0, 0, 350, 10, 100, 0.001, 0.999);
//		M3.seven_segment(initial.finalTeta[2], final.finalTeta[2], 0, 0, 350, 10, 100, 0.001, 0.999);
//
//		int arr[3] = { 0,0,0 };
//		int greatest_is;
//		if (isgreater(M1.qsize, M2.qsize) && isgreater(M1.qsize, M3.qsize)) {
//			greatest_is = 1;
//			//m1 is greater
//			size = M1.qsize;
//		}
//		else if (isgreater(M2.qsize, M1.qsize) && isgreater(M2.qsize, M3.qsize)) {
//			greatest_is = 2;
//			//m2 is greater
//			size = M2.qsize;
//		}
//		else {
//			greatest_is = 3;
//			//all 3 have equal size or m3 is the greatest
//			size = M3.qsize;
//		}
//
//		q1 = new float[size];
//		q2 = new float[size];
//		q3 = new float[size];
//		float ratio;
//		float zavie;
//		float zavie2;
//		float zavie3;
//
//		for (int i = 0; i < (int)size; i++) {
//			switch (greatest_is)
//			{
//			case 1: ratio = (M1.q[i] - M1.q[0]) / (M1.q[(int)size - 1] - M1.q[0]); break;
//			case 2: ratio = (M2.q[i] - M2.q[0]) / (M2.q[(int)size - 1] - M2.q[0]); break;
//			case 3: ratio = (M3.q[i] - M3.q[0]) / (M3.q[(int)size - 1] - M3.q[0]); break;
//			default:
//				break;
//			}
//			q1[i] = ratio*(M1.q[(int)size - 1] - M1.q[0]) + M1.q[0];;
//			q2[i] = ratio*(M2.q[(int)size - 1] - M2.q[0]) + M2.q[0];
//			q3[i] = ratio*(M3.q[(int)size - 1] - M3.q[0]) + M3.q[0];
//		}
//	}
//
//
//	 ~state()
//	 {
//		 delete[] q1;
//		 q1 = NULL;
//		 delete[] q2;
//		 q2 = NULL;
//		 delete[] q3;
//		 q3 = NULL;
//
//	}
//};



//new inverse

void InverseKinematicsCore:: InverseKinematicsNew(double x, double y, double z,double finalTeta[3])
{
    //KinematicsException newex = KinematicsException("this is test Exception");
    qDebug("salam");
    // varibales for IK
    static const int alpha[3] = { 0, 120, 240 };
    static const double r = 0.13; double la = 0.27; double lb = 0.74;
    //static const int e = 1;
    double l[3];
    double m[3];
    double n[3];
    double tteta[3][2];
    double teta[3];
    double teta2[3];
    double teta3[3];
    double beta;
    static const Vector3d rrb(r, 0.0, 0.0);
    Vector3d normal(0.0, 0.0, 0.0);
    MatrixXd R(3, 3);
    double xDegrees;
    Vector3d temp(0.0, 0.0, -1.0);



    int j = 0;
    for (int i = 0; i < 3; i++) {
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


            tteta[i][0] = 2 * (atan2(-m[i] + sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * 180 / (3.14159265358979323846));
            tteta[i][1] = 2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * 180 / (3.14159265358979323846));
            if (2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159265358979323846)) < -90) {
                tteta[i][1] += 360;
            }
            if (2 * (atan2(-m[i] - sqrt(pow(m[i], 2) + pow(l[i], 2) - pow(n[i], 2)), (n[i] - l[i])) * (180 / 3.14159265358979323846)) > 90) {
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
        for (int i = 0; i < 3; i++) {
            teta[i] = tteta[i][1];
        }
    // **************** Checking Singularity Points  ********************** //

    for (int i = 0; i < 3; i++) {
        //double xDegrees = alpha[i];
        //double alphaDeg = xDegrees*3.14159 / 180;
        R << cosd(alpha[i]), -sind(alpha[i]), 0.0,
            -sind(alpha[i]), cosd(alpha[i]), 0.0,
            0.0, 0.0, 1.0;
        //cout << R;

        double xx0 = cosd(alpha[i])*(la*cosd(teta[i]) + r);
        double yy0 = (la*cosd(teta[i]) + r)*sind(alpha[i]);
        double zz0 = -la*sind(teta[i]);
        Vector3d x0(xx0, yy0, zz0);
        Vector3d x1(x, y, z);

        Vector3d xb = R*rrb; // checckkk checcckk checcckkkk

        teta2[i] = acos((x0 - xb).dot(x1 - x0) / ((x0 - xb).norm() * (x1 - x0).norm())) * (180 / 3.14159265358979323846);
        xb = temp;

        //teta3(i) = acosd((dot(xb, x1 - x0)) / (norm(xb)*norm(x1 - x0)));

        teta3[i] = acos(xb.dot(x1 - x0) / (xb.norm()*(x1 - x0).norm()))* (180 /3.14159265358979323846);

        if ((teta2[i] > -30 && teta2[i] < 30) || (teta2[i] > 150 && teta2[i] < 210)) {
            //TODO error

        }
        if ((teta3[i] > -110 && teta3[i] < -70) || (teta3[i] > 70 && teta3[i] < 110)) {

            //TODO error
        }

    }
    /// ******** Angle Limitation ************//
    int rr = 0;
    for (int i = 0; i < 3; i++) {
        R << cosd(alpha[i]), -sind(alpha[i]), 0.0,
            -sind(alpha[i]), cosd(alpha[i]), 0.0,
            0.0, 0.0, 1.0;


        double xx0 = cosd(alpha[i])*(la*cosd(teta[i]) + r);
        double yy0 = (la*cosd(teta[i]) + r)*sind(alpha[i]);
        double zz0 = -la*sind(teta[i]);
        Vector3d x0(xx0, yy0, zz0);
        Vector3d x1(x, y, z);

        Vector3d xb = R*rrb;
        normal = xb.cross(x0);

        beta = acos(normal.dot(x1 - x0) / normal.norm()*(x1 - x0).norm()) * (180 / 3.14159265358979323846);
        if (beta > 135 || beta < 45) {
            rr = 1;
        }
        if (rr == 0) {
            for (int i = 0; i < 3; i++) {
                finalTeta[i] = tteta[i][1];

            }

        }

    }

    qDebug("values of finalTheta: %f , %f , %f",finalTeta[0],finalTeta[1],finalTeta[2]);
}



void InverseKinematicsCore::Interpolation(SevenSegment& M1, SevenSegment& M2, SevenSegment &M3,double **q1 , double** q2 , double** q3) {

    int size;

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
            break;
        }
        (*q1)[i] = ratio*(M1.q[(int)size - 1] - M1.q[0]) + M1.q[0];;
        (*q2)[i] = ratio*(M2.q[(int)size - 1] - M2.q[0]) + M2.q[0];
        (*q3)[i] = ratio*(M3.q[(int)size - 1] - M3.q[0]) + M3.q[0];
    }
}

bool InverseKinematicsCore::isPositionValid(double x, double y, double z)
{
    qDebug("x=%lf y=%lf z=%lf",x,y,z);
    return  ((z >= -0.78 && z <= -0.53 && (pow(x, 2) + pow(y, 2)) <= (pow(0.4, 2)))  || (z >= -0.88 && z<= -0.78 && (pow(x, 2) + pow(y, 2)) <= pow((1.5*z + 1.570),2)));
}
//int InverseKinematicsCore:: base()
//{


//        //inverse
//        float inverse_start_output[3];
//        float inverse_end_output[3];
//        InverseKinematicsNew(0, 0, -.80, inverse_start_output);
//        InverseKinematicsNew(0, 0, -.85, inverse_end_output);
//        //in this point we have start and end degree

//        //sevenseg
//        SevenSegment M1;
//        SevenSegment M2;
//        SevenSegment M3;

//        M1.seven_segment(inverse_start_output[0], inverse_end_output[0], 0, 0, 350, 10, 100, 0.001, 0.999);
//        M2.seven_segment(inverse_start_output[1], inverse_end_output[1], 0, 0, 350, 10, 100, 0.001, 0.999);
//        M3.seven_segment(inverse_start_output[2], inverse_end_output[2], 0, 0, 350, 10, 100, 0.001, 0.999);
//        float* q1 = 0;
//        float* q2 = 0;
//        float* q3 = 0;

//        ////interpolate
//        Interpolation(M1, M2, M3, &q1, &q2, &q3);
//        delete[] q1;
//        delete[] q2;
//        delete[] q3;

//}



        //ss.seven_segment(33.8310394,43.4499359, 0, 0, 350, 10, 100, 0.001, 0.999);
        //ss.deletAllDtat();
        //cout << " xy z ";
        //state initial;
        //state final;
        //initial.InverseKinematics(0, 0, -0.7);
        //while (1) {
        //	state* test = new state();
        //	state* initial = new state();
        //	state* final = new state();
        //	initial->x = 0;
        //	initial->y = 0;
        //	initial->z = -0.8;

        //	final->x = 0;
        //	final->y = 0;
        //	final->z = -0.85;

        //	test->Interpolation(*initial, *final);
        //	delete initial;
        //	delete final;
        //	delete test;
        //}
        ////cout << "done";



        ////getchar();





//}
