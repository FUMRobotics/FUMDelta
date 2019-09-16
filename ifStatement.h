#ifndef IFSTATEMENT_H
#define IFSTATEMENT_H
#include "statement.h"
#include "variable.h"
#include <vector>


class ifStatement : public statement
{
public:
    variable* conditionVariable;
    int intValue;
    double realValue;
    bool boolValue;
    bool hasElse;
    std::string relationalOperator;
    std::vector<statement*> ifStatements;
    std::vector<statement*> elseStatements;
    ifStatement(variable* conditionVar, std::string relationalOp, int intVal);
    ifStatement(variable* conditionVar, std::string relationalOp, bool boolVal);
    ifStatement(variable* conditionVar, std::string relationalOp, double realVal);
    bool getHasElse();
    void setHasElse(bool hasElseOrNot);
    void setIfStatements(std::vector<statement*> ifStat);
    void setElseStatements(std::vector<statement*> elseStat);
    void executeStatement();

};

#endif // IFSTATEMENT_H
