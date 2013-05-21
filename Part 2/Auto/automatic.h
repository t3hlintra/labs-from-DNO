#ifndef AUTOMATIC_H
#define AUTOMATIC_H

#include <qstring.h>

class Automatic
{
public:
    Automatic();
    ~Automatic();
    bool Identify(QString str);
    bool getResult(){ return result; }
private:
    int state;
    bool result;
    int transMatr[2][2];
};

#endif // AUTOMATIC_H
