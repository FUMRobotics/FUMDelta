#include "trajectorysender.h"
#include "robotstate.h"
TrajectorySender::TrajectorySender(QString trajectoryFilePath, int numberOfDrive, QObject *parent) : QThread(parent)
{
    this->numberOfDrive = numberOfDrive;
    this->trajectoryFilePath = trajectoryFilePath;
    this->start();
}

TrajectorySender::TrajectorySender(double x_start, double y_start, double z_start, double x_end, double y_end, double z_end)
{
    is_in_kinematics_state = true;

    this->x_start=x_start;
    this->y_start=y_start;
    this->z_start=z_start;

    this->x_end=x_end;
    this->y_end=y_end;
    this->z_end=z_end;

    this->start();
}

//TrajectorySender::TrajectorySender(QVector<QVector<double>> &points_for_drives)
//{
//    this->send_array=1;
//    this->arrayPoints=points_for_drives;
//    this->start();
//}
void TrajectorySender:: startSendingArrayPointsSlot()
{

}
int TrajectorySender::getNumberOfPoint()
{
    return numberOfPoint;
}

int TrajectorySender::getTimeOfTrajectory()
{
    //this return time in second
    return numberOfPoint * 1000;
}

void TrajectorySender::loadPointFromCsv(){
    //load file from trajectoryFilePath

    qDebug("loading points from csv");

    for (int var = 0; var < numberOfDrive; ++var) {
        loadedPoints.push_back(QVector<double>());
    }


    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen(this->trajectoryFilePath.toLatin1(), "r");
    if (fp == NULL){
        perror("Error");
        qDebug("file not found");
        exit(EXIT_FAILURE);
    }

    int numberofline = 0 ;
    //read line by line for find out number of line in trajectory
    while ((read = getline(&line, &len, fp)) != -1) {
        numberofline++;
    }
    printf("numberof line %d" , numberofline);

    this->numberOfPoint = numberofline;
    rewind(fp); // go to first line of file

    int h = 0;
    while ((read = getline(&line, &len, fp)) != -1) {

        //printf("csvline length:%zu\n", read);
        printf("%s", line);

        char *pt;
        pt = strtok (line,",");
        int i = 0;
        while (pt != NULL) {
           // printf(" %c \n " , pt[0] );
            double a = atof(pt);
            for (int ii = 0;ii < this->numberOfDrive;ii++) {
                if(i == ii){
                    loadedPoints[ii].push_back(a);
                }
            }
            i++;
            pt = strtok (NULL, ",");
       }
        h++;
    }

    fclose(fp);
    if (line)
        free(line);
    //   exit(EXIT_SUCCESS);


}

void TrajectorySender::sendPointsToDrives(QVector<QVector<double>> &points_for_drives)
{
    /*should we check if all vectors inside points_for_drives have the same size?*/

    qDebug("started sending points to drives");

    if(points_for_drives.size()!=3)
    {
        qDebug("cannot send array points: number of drives must be 4");
        quit();
    }

    for (int i = 0; i < points_for_drives[0].size(); ++i) {
       SendCommand::getInstance()->SendPointTo3Drives(points_for_drives[0][i],points_for_drives[1][i],points_for_drives[2][i]);

    }
}

void TrajectorySender::sendPointsToDrives(){
    if (numberOfDrive != 4) {
        qDebug("we can't run this trajectroy ");
        quit(); //:)
    }
    for (int var = 0; var < 10; var++) {
        for (int i = 0; i < loadedPoints[0].size(); i++) {
            SendCommand::getInstance()->SendPointTo4Drives(loadedPoints[0][i],loadedPoints[1][i],loadedPoints[2][i],loadedPoints[3][i]);
        }
    }
}

void TrajectorySender::run()
{

    qDebug("runn...");
    if (is_in_kinematics_state) {
        if(!is_initiated){
           qDebug("entered kinematic state");
           emit startedSendingArrayPoints();
//           KinematicsState* test = new KinematicsState();
//           test->Interpolation(*initial, *final);
//           QVector<QVector<double>>points_for_all_drives;


//           for(int i=0;i<3;i++)
//           {
//               points_for_all_drives.push_back(QVector<double>());
//               qDebug("added qvector");
//           }
////           int size_of_queues=initial->size;
////           QString s=QString::number(initial->q1[0]);
////           qDebug("first element: "+s.toLatin1());
//           //TODO: check i later: 0 or 1?
//           for(int i=1;i<test->size;i++)
//           {
//               points_for_all_drives[0].push_back(test->q1[i]);
//               points_for_all_drives[1].push_back(test->q2[i]);
//               points_for_all_drives[2].push_back(test->q3[i]);
//           }


//           sendPointsToDrives(points_for_all_drives);

//           emit finishedSendingArrayPoints();

//           delete initial;
//           delete final;
//           delete test;



           double inverse_start_output[3];
           double inverse_end_output[3];
           InverseKinematicsCore core;

           //provide inverse kinematics with start and final positions
           //core.InverseKinematicsNew(x_start, y_start, z_start, inverse_start_output);

           RobotState::getInstance()->getAngles(inverse_start_output);
           qDebug("fetched position in robot state: theta 1: %lf theta 2:%lf, theta 3:%lf",inverse_start_output[0],inverse_start_output[1],inverse_start_output[2]);
           core.InverseKinematicsNew(x_end, y_end, z_end, inverse_end_output);

           //TODO set this after send point to drive and change physical state
//           RobotState::getInstance()->setAllCoordinates(inverse_end_output[0],inverse_end_output[1],inverse_end_output[2],
//                                                        x_end, y_end, z_end);
           qDebug("newly set position in robot state: x: %lf y:%lf, z:%lf  theta 1:%lf theta 2:%lf theta 3:%lf",
                  x_end,y_end,z_end,inverse_end_output[0],inverse_end_output[1],inverse_end_output[2]);
           //in this point we have start and end degree

           //sevenseg
           SevenSegment M1;
           SevenSegment M2;
           SevenSegment M3;

           M1.seven_segment(inverse_start_output[0], inverse_end_output[0], 0, 0, 350, 10, 100, 0.001, 0.999);
           M2.seven_segment(inverse_start_output[1], inverse_end_output[1], 0, 0, 350, 10, 100, 0.001, 0.999);
           M3.seven_segment(inverse_start_output[2], inverse_end_output[2], 0, 0, 350, 10, 100, 0.001, 0.999);
           double* q1 = 0;
           double* q2 = 0;
           double* q3 = 0;

           ////interpolate
           core.Interpolation(M1, M2, M3, &q1, &q2, &q3);

           //all queues are filled now
           //send points as messages

           QVector<QVector<double>>points_for_all_drives;


           for(int i=0;i<3;i++)
           {
               points_for_all_drives.push_back(QVector<double>());
               //qDebug("added qvector");
           }
           int size_of_queues=core.size_of_trajectory_points;

           //TODO: check i later: 0 or 1?
           for(int i=1;i<size_of_queues;i++)
           {
               points_for_all_drives[0].push_back(q1[i]);
               points_for_all_drives[1].push_back(q2[i]);
               points_for_all_drives[2].push_back(q3[i]);
           }


           sendPointsToDrives(points_for_all_drives);

           emit finishedSendingArrayPoints();
           qDebug("emitting finished sending array points");


           delete[] q1;
           delete[] q2;
           delete[] q3;





        }else{

            emit startedSendingArrayPoints();
            sendPointsToDrives(this->arrayPoints);
            emit finishedSendingArrayPoints();
        }



        return;
    }

    if (!is_initiated) {
        loadPointFromCsv();
        qDebug("loaded points from csv");
        is_initiated = true;
        QString s="trajectory side, points="+QString::number(getNumberOfPoint())+"time= "+QString::number(getTimeOfTrajectory());
        qDebug(s.toLatin1());
        QString log="size of arrays respectively: "+QString::number(loadedPoints[0].size())+" "+QString::number(loadedPoints[1].size())+" "+QString::number(loadedPoints[2].size())+" "+QString::number(loadedPoints[3].size());
        qDebug(log.toLatin1());
        emit finishedLoading(getNumberOfPoint(),getTimeOfTrajectory());
    }else{
        qDebug("trajectory sender side, started sending points");
        emit startedSendingPoints();
        sendPointsToDrives();
        emit finishedSendingPoints();
        qDebug("trajectory sender side, finished sending points");
    }
//    else {

//        //send array=true
//        emit startedSendingArrayPoints();
//        sendPointsToDrives(this->arrayPoints);
//        emit finishedSendingArrayPoints();

//    }
}

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}
