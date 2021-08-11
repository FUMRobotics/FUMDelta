#include "variable.h"
#include <stdlib.h>
#include <string>

variable::variable()
{

}

std::string variable::getType()
{
    return type;
}

void variable::setType(std::string vType)
{
    type = vType;
}

std::string variable::getName()
{
    return name;
}

void variable::setName(std::string vName)
{
    name = vName;
}

