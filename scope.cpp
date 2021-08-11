#include "scope.h"

scope::scope(scope* p, std::string n)
{
    parent = p;
    name = n;
}

void scope::addStatement(statement* s)
{
    statementsVector.push_back(s); 
}

void scope::setName(std::string n)
{
    name = n;
}
std::string scope::getName()
{
    return name;
}
