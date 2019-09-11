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
    KinematicsException(const char *desc,bool force_close) : KinematicsException(desc)
    {
        this->force_close=force_close;
    }

    ~KinematicsException()
    {
        if(force_close)
        {
            throw;
        }
    }

    bool force_close=false;
    const char *desc;
};

#endif // KINEMATICSEXCEPTION_H
