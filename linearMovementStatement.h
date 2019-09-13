#ifndef MOVEMENTSTATEMENT_H
#define MOVEMENTSTATEMENT_H
#include <statement.h>
#include <map>

class linearMovementStatement : public statement
{
public:
    std::map<std::string, double> parameters;
    linearMovementStatement(double XValue, double YValue, double ZValue, double AValue, double BValue, double CValue);
    void setParameters(double XValue, double YValue, double ZValue, double AValue, double BValue, double CValue);
    std::map<std::string, double> getParameters();
    void printParameters();
    void executeStatement();
};

#endif // MOVEMENTSTATEMENT_H
