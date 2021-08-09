#ifndef POINTVARIABLE_H
#define POINTVARIABLE_H
#include <variable.h>


class posVariable : public variable
{
public:
    double XValue;
    double YValue;
    double ZValue;
    double AValue;
    double BValue;
    double CValue;
    posVariable(double XVal, double YVal, double ZVal, double AVal, double BVal, double CVal);
};

#endif // POINTVARIABLE_H
