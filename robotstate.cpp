#include "robotstate.h"
#include <QDebug>

RobotState* RobotState::instance;

RobotState *RobotState::getInstance()
{

    if(instance==nullptr)
    {
        instance=new RobotState();
    }
    return instance;
}

void RobotState::getAngles(double angles[])
{
    angles[0]=drive_0_angle;
    angles[1]=drive_1_angle;
    angles[2]=drive_2_angle;
}

double RobotState::getAngle(int index)
{
    double return_value=0;
    switch (index) {
    case 0:
        return_value = drive_0_angle;
        break;
    case 1:
        return_value = drive_1_angle;
        break;
    case 2:
        return_value = drive_2_angle;
        break;
    case 3:
        return_value = drive_3_angle;
        break;
    default:
        break;
    }
    return return_value;
}

void RobotState::setAngles(double angle_0, double angle_1, double angle_2,double angle_3)
{
    drive_0_angle=angle_0;
    drive_1_angle=angle_1;
    drive_2_angle=angle_2;
    drive_3_angle=angle_3;
//    qDebug("set angle in robot state. angle_0=%lf angle_1=%lf angle_2=%lf angle_3=%lf"
//           ,angle_0,angle_1,angle_2,angle_3);
}

double RobotState::getX()
{
    return this->x;
}

double RobotState::getY()
{
    return this->y;
}

double RobotState::getZ()
{
    return this->z;
}

void RobotState::setPositons(double x, double y, double z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}

void RobotState::setAllCoordinates(double angle_0, double angle_1, double angle_2,double angle_3, double x, double y, double z)
{
    setAngles(angle_0,angle_1,angle_2,angle_3);
    setPositons(x,y,z);
}

RobotState::RobotState()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->drive_0_angle = 0;
    this->drive_1_angle = 0;
    this->drive_2_angle = 0;
}
