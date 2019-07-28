#include "trajectorysender.h"

TrajectorySender::TrajectorySender(QString trajectoryFilePath, int numberOfDrive, QObject *parent) : QThread(parent)
{
    this->numberOfDrive = numberOfDrive;
    this->trajectoryFilePath = trajectoryFilePath;
    this->start();
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
    if (!is_initiated) {
        loadPointFromCsv();
        is_initiated = true;
        QString s="trajectory side, points="+QString::number(getNumberOfPoint())+"time= "+QString::number(getTimeOfTrajectory());
        qDebug(s.toLatin1());
        emit finishedLoading(getNumberOfPoint(),getTimeOfTrajectory());
    }else{
        sendPointsToDrives();
    }
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
