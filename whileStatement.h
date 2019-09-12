#ifndef WHILESTATEMENT_H
#define WHILESTATEMENT_H
#include "statement.h"
#include "variable.h"
#include <vector>

class whileStatement : public statement
{
public:
    variable* conditionVariable;
    int intValue;
    double realValue;
    bool boolValue;
    std::string relationalOperator;
    std::vector<statement*> whileStatements;
    whileStatement(variable* conditionVar, std::string relationalOp);
    void setValue(int intVal);
    void setValue(bool boolVal);
    void setValue(double realVal);
    void setWhileStatements(std::vector<statement*> s);
    void executeStatement();
};

#endif // WHILESTATEMENT_H
