#include "whileStatement.h"

whileStatement::whileStatement(variable* conditionVar, std::string relationalOp)
{
    type = "whileStatement";
    conditionVariable = conditionVar;
    relationalOperator = relationalOp;
}

void whileStatement::setValue(int intVal)
{
    intValue = intVal;
}
void whileStatement::setValue(bool boolVal)
{
    boolValue = boolVal;
}

void whileStatement::setValue(double realVal)
{
    realValue = realVal;
}

void whileStatement::setWhileStatements(std::vector<statement*> s)
{
    whileStatements = s;
}

void whileStatement::executeStatement()
{
    if(conditionVariable->getType() == "INT")
    {
        if(relationalOperator == "<")
        {
            while(conditionVariable->getIntValue() < intValue)
            {
                for(int i=0; i<whileStatements.size();i++)
                {
                    whileStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == "<=")
        {
            while(conditionVariable->getIntValue() <= intValue)
            {
                for(int i=0; i<whileStatements.size();i++)
                {
                    whileStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == ">")
        {
            while(conditionVariable->getIntValue() > intValue)
            {
                for(int i=0; i<whileStatements.size();i++)
                {
                    whileStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == ">=")
        {
            while(conditionVariable->getIntValue() >= intValue)
            {
                for(int i=0; i<whileStatements.size();i++)
                {
                    whileStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == "==")
        {
            if(conditionVariable->getIntValue() == intValue)
            {
                for(int i=0; i<whileStatements.size();i++)
                {
                    whileStatements[i]->executeStatement();
                }
            }
        }
        else
        {
            if(conditionVariable->getIntValue() != intValue)
            {
                for(int i=0; i<whileStatements.size();i++)
                {
                    whileStatements[i]->executeStatement();
                }
            }
        }

    }

    else if(conditionVariable->getType() == "BOOLEAN")
    {
        if(relationalOperator == "==")
        {
            while(conditionVariable->getBoolValue() == boolValue)
            {
                for(int i=0; i<whileStatements.size();i++)
                {
                    whileStatements[i]->executeStatement();
                }
            }
        }
        else
        {
            while(conditionVariable->getIntValue() != intValue)
            {
                for(int i=0; i<whileStatements.size();i++)
                {
                    whileStatements[i]->executeStatement();
                }
            }
        }
    }

    else if (conditionVariable->getType() == "REAL")
    {
        if(relationalOperator == "<")
        {
            while(conditionVariable->getRealValue() < realValue)
            {
                for(int i=0; i<whileStatements.size();i++)
                {
                    whileStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == "<=")
        {
            while(conditionVariable->getRealValue() <= realValue)
            {
                for(int i=0; i<whileStatements.size();i++)
                {
                    whileStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == ">")
        {
            while(conditionVariable->getRealValue() > realValue)
            {
                for(int i=0; i<whileStatements.size();i++)
                {
                    whileStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == ">=")
        {
            while(conditionVariable->getRealValue() >= realValue)
            {
                for(int i=0; i<whileStatements.size();i++)
                {
                    whileStatements[i]->executeStatement();
                }
            }
        }
        else if(relationalOperator == "==")
        {
            while(conditionVariable->getRealValue() == realValue)
            {
                for(int i=0; i<whileStatements.size();i++)
                {
                    whileStatements[i]->executeStatement();
                }
            }
        }
        else
        {
            while(conditionVariable->getRealValue() != realValue)
            {
                for(int i=0; i<whileStatements.size();i++)
                {
                    whileStatements[i]->executeStatement();
                }
            }
        }
    }
}
