#ifndef KINEMATICSEXCEPTION_H
#define KINEMATICSEXCEPTION_H

#include <QMessageBox>



class KinematicsException
{
public:
    KinematicsException();

    KinematicsException(const char *desc) {
        QMessageBox::critical(NULL,QObject::tr("Warning"),QObject::tr(desc));
    }

    ~KinematicsException()
    {
        throw;
    }
};

#endif // KINEMATICSEXCEPTION_H
