#include "ifStatement.h"

ifStatement::ifStatement(variable* conditionVar, std::string relationalOp, int intVal)
{
    type = "ifStatement";
    conditionVariable = conditionVar;
    relationalOperator = relationalOp;
    intValue = intVal;
}

ifStatement::ifStatement(variable* conditionVar, std::string relationalOp, bool boolVal)
{
    type = "ifStatement";
    conditionVariable = conditionVar;
    relationalOperator = relationalOp;
    boolValue = boolVal;
}

ifStatement::ifStatement(variable* conditionVar, std::string relationalOp, double realVal)
{
    type = "ifStatement";
    conditionVariable = conditionVar;
    relationalOperator = relationalOp;
    realValue = realVal;
}

bool ifStatement::getHasElse()
{
    return hasElse;
}

void ifStatement::setHasElse(bool hasElseOrNot)
{
    hasElse = hasElseOrNot;
}

void ifStatement::setIfStatements(std::vector<statement*> ifStat)
{
    ifStatements = ifStat;
}

void ifStatement::setElseStatements(std::vector<statement*> elseStat)
{
    elseStatements = elseStat;
}

void ifStatement::executeStatement()
{
    if(conditionVariable->getType() == "INT")
    {
        if(relationalOperator == "<")
        {
            if(conditionVariable->getIntValue() < intValue)
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
            else
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == "<=")
        {
            if(conditionVariable->getIntValue() <= intValue)
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
            else
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == ">")
        {
            if(conditionVariable->getIntValue() > intValue)
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
            else
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == ">=")
        {
            if(conditionVariable->getIntValue() >= intValue)
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
            else
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == "==")
        {
            if(conditionVariable->getIntValue() == intValue)
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
            else
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
        }
        else
        {
            if(conditionVariable->getIntValue() != intValue)
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
            else
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
        }

    }


    else if(conditionVariable->getType() == "BOOLEAN")
    {
        if(relationalOperator == "==")
        {
            if(conditionVariable->getBoolValue() == boolValue)
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
            else
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
        }
        else
        {
            if(conditionVariable->getIntValue() != intValue)
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
            else
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
        }

    }
    else if (conditionVariable->getType() == "REAL")
    {
        if(relationalOperator == "<")
        {
            if(conditionVariable->getRealValue() < realValue)
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
            else
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == "<=")
        {
            if(conditionVariable->getRealValue() <= realValue)
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
            else
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == ">")
        {
            if(conditionVariable->getRealValue() > realValue)
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
            else
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == ">=")
        {
            if(conditionVariable->getRealValue() >= realValue)
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
            else
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == "==")
        {
            if(conditionVariable->getRealValue() == realValue)
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
            else
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
        }
        else
        {
            if(conditionVariable->getRealValue() != realValue)
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
            else
            {
                for(int i=0; i<ifStatements.size();i++)
                {
                    ifStatements[i]->executeStatement();
                }
            }
        }

    }

}
