#ifndef CIRCULARMOVEMENTSTATEMENT_H
#define CIRCULARMOVEMENTSTATEMENT_H
#include "statement.h"
#include "posVariable.h"

class circularMovementStatement : public statement
{
public:
    posVariable* pos1;
    posVariable* pos2;
    circularMovementStatement(posVariable* p1, posVariable* p2);
    void setPositions(posVariable* p1, posVariable* p2);
    void executeStatement();
};

#endif // CIRCULARMOVEMENTSTATEMENT_H
