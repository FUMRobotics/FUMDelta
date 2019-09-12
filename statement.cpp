#include "statement.h"
#include <iostream>

statement::statement()
{

}

void statement::setType(std::string sType)
{
    type = sType;
}

std::string statement::getType()
{
    return type;
}

void statement::executeStatement()
{
    std::cout<<"";
}

