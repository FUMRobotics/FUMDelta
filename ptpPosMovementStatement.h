#ifndef PTPPOSMOVEMENTSTATEMENT_H
#define PTPPOSMOVEMENTSTATEMENT_H
#include <statement.h>
#include <map>


class ptpPosMovementStatement : public statement
{
public:
    std::map<std::string, double> parameters;
    ptpPosMovementStatement(double XValue, double YValue, double ZValue, double AValue, double BValue, double CValue);
    void setParameters(double XValue, double YValue, double ZValue, double AValue, double BValue, double CValue);
    std::map<std::string, double> getParameters();
    void printParameters();
    void executeStatement();
};

#endif // PTPPOSMOVEMENTSTATEMENT_H
