#ifndef VARIABLE_H
#define VARIABLE_H
#include <stdlib.h>
#include <string>

class variable
{
public:
    std::string name;
    std::string type;
    int intValue;
    bool boolValue;
    double realValue;
    variable();
    std::string getType();
    void setType(std::string vType);
    std::string getName();
    void setName(std::string vName);
    void setIntValue(int value);
    void setBoolValue(bool value);
    void setRealValue(double value);
    int getIntValue();
    bool getBoolValue();
    double getRealValue();
};

#endif // VARIABLE_H
