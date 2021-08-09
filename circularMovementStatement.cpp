#include "circularMovementStatement.h"

circularMovementStatement::circularMovementStatement(posVariable* p1, posVariable* p2)
{
    type = "circularMovementStatement";
    pos1 = p1;
    pos2 = p2;
}

void circularMovementStatement::setPositions(posVariable *p1, posVariable *p2)
{
    pos1 = p1;
    pos2 = p2;
}

void circularMovementStatement::executeStatement()
{

}
