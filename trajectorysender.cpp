#include "trajectorysender.h"

TrajectorySender::TrajectorySender(QString trajectoryFilePath, int numberOfDrive, QObject *parent) : QThread(parent)
{
    this->numberOfDrive = numberOfDrive;
    this->trajectoryFilePath = trajectoryFilePath;
    this->start();
}

TrajectorySender::TrajectorySender(float x_start, float y_start, float z_start, float x_end, float y_end, float z_end)
{
    is_in_kinematics_state = true;
    initial = new KinematicsState();
    initial->x = x_start;
    initial->y = y_start;
    initial->z = z_start;


    final = new KinematicsState();
    final->x = x_end;
    final->y = y_end;
    final->z = z_end;

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
    for (int i = 0; i < loadedPoints[0].size(); i++) {
        SendCommand::getInstance()->SendPointTo4Drives(loadedPoints[0][i],loadedPoints[1][i],loadedPoints[2][i],loadedPoints[3][i]);
    }
}

void TrajectorySender::run()
{

    qDebug("runn...");
    if (is_in_kinematics_state) {
        if(!is_initiated){
            emit startedSendingArrayPoints();
           KinematicsState* test = new KinematicsState();
           test->Interpolation(*initial, *final);
           QVector<QVector<double>>points_for_all_drives;


           for(int i=0;i<3;i++)
           {
               points_for_all_drives.push_back(QVector<double>());
           }
           int size_of_queues=initial->size;
           QString s=QString::number(initial->q1[0]);
           qDebug("first element: "+s.toLatin1());
           //TODO: check i later: 0 or 1?
           for(int i=1;i<10;i++)
           {
               points_for_all_drives[0].push_back(initial->q1[i]);
               points_for_all_drives[1].push_back(initial->q2[i]);
               points_for_all_drives[2].push_back(initial->q3[i]);
           }


           sendPointsToDrives(points_for_all_drives);

           emit finishedSendingArrayPoints();

           delete initial;
           delete final;
//           delete test;
        }else{

            emit startedSendingArrayPoints();
            sendPointsToDrives(this->arrayPoints);
            emit finishedSendingArrayPoints();
        }



        return;
    }

    if (!is_initiated) {
        loadPointFromCsv();
        is_initiated = true;
        QString s="trajectory side, points="+QString::number(getNumberOfPoint())+"time= "+QString::number(getTimeOfTrajectory());
        qDebug(s.toLatin1());
        QString log="size of arrays respectively: "+QString::number(loadedPoints[0].size())+" "+QString::number(loadedPoints[1].size())+" "+QString::number(loadedPoints[2].size())+" "+QString::number(loadedPoints[3].size());
        qDebug(log.toLatin1());
        emit finishedLoading(getNumberOfPoint(),getTimeOfTrajectory());
    }else{
        emit startedSendingPoints();
        sendPointsToDrives();
        emit finishedSendingPoints();
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
