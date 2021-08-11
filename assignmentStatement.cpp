#include "assignmentStatement.h"
#include "variable.h"

assignmentStatement::assignmentStatement(variable* v, int value)
{
    type = "assignmentStatement";
    var = v;
    intVal = value;
}

assignmentStatement::assignmentStatement(variable* v, bool value)
{
    var = v;
    boolVal = value;
}

assignmentStatement::assignmentStatement(variable* v, double value)
{
    var = v;
    realVal = value;
}

void assignmentStatement::executeStatement()
{
    if(var->getType() == "INT")
        var->setIntValue(intVal);
    else if(var->getType() == "BOOLEAN")
        var->setBoolValue(boolVal);
    else
        var->setRealValue(realVal);

}
