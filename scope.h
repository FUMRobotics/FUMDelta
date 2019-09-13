#ifndef SCOPE_H
#define SCOPE_H
#include "statement.h"
#include <vector>

class scope
{
public:
    std::string name;
    std::vector<statement*> statementsVector;
    scope* parent;
    scope(scope* p, std::string n);
    void addStatement(statement* s);
    void setName(std::string n);
    std::string getName();
};

#endif // SCOPE_H
