#include "boolVariable.h"
#include <stdlib.h>

boolVariable::boolVariable()
{
    type = "BOOL";
}

void variable::setBoolValue(bool boolVal)
{
    boolValue = boolVal;
}
bool variable::getBoolValue()
{
    return boolValue;
}
