#include "realVariable.h"

realVariable::realVariable()
{
    type = "REAL";
}

double variable::getRealValue()
{
    return realValue;
}

void variable::setRealValue(double realVal)
{
    realValue = realVal;
}
