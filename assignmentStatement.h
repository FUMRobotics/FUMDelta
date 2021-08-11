#ifndef ASSIGNMENTEXPRESSIONSTATEMENT_H
#define ASSIGNMENTEXPRESSIONSTATEMENT_H
#include <statement.h>
#include <variable.h>

class assignmentStatement : public statement
{
public:
    variable* var;
    int intVal;
    bool boolVal;
    double realVal;
    assignmentStatement(variable* v, int value);
    assignmentStatement(variable* v, bool value);
    assignmentStatement(variable* v, double value);
    void executeStatement();
};

#endif // ASSIGNMENTEXPRESSIONSTATEMENT_H
