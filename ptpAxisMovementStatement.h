#ifndef PTPAXISMOVEMENTSTATEMENT_H
#define PTPAXISMOVEMENTSTATEMENT_H
#include <statement.h>
#include <map>

class ptpAxisMovementStatement : public statement
{
public:
    std::map<std::string, double> parameters;
    ptpAxisMovementStatement(double A1Value, double A2Value, double A3Value, double A4Value);
    void setParameters(double A1Value, double A2Value, double A3Value, double A4Value);
    std::map<std::string, double> getParameters();
    void printParameters();
    void executeStatement();
};

#endif // PTPAXISMOVEMENTSTATEMENT_H
