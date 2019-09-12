#ifndef FORSTATEMENT_H
#define FORSTATEMENT_H
#include "variable.h"
#include <statement.h>
#include <vector>

class forStatement : public statement
{
public:
    variable* counterVariable;
    int startPoint;
    int endPoint;
    int stepValue;
    std::vector<statement*> statements;
    forStatement(variable* counterVar, int sPoint, int ePoint, int stepVal);
    void setStatements(std::vector<statement*> s);
    void executeStatement();
};

#endif // FORSTATEMENT_H
