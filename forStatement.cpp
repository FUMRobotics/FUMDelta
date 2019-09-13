#include "forStatement.h"

forStatement::forStatement(variable* counterVar, int sPoint, int ePoint, int stepVal)
{
    type = "forStatement";
    counterVariable = counterVar;
    startPoint = sPoint;
    endPoint = ePoint;
    stepValue = stepVal;
}

void forStatement::setStatements(std::vector<statement*> s)
{
    statements = s;
}

void forStatement::executeStatement()
{
    counterVariable->setIntValue(startPoint);
    while(counterVariable->getIntValue() <= endPoint)
    {
        for(int i=0; i<statements.size();i++)
        {
            statements[i]->executeStatement();
        }
        counterVariable->setIntValue(counterVariable->getIntValue() + stepValue);
    }

}
