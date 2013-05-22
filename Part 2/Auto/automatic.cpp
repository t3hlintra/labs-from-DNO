#include "automatic.h"

Automatic::Automatic()
{
    state=0;
    result=false;
    transMatr[0][0]=0; transMatr[0][1]=1;
    transMatr[1][0]=1; transMatr[1][1]=1;

}
Automatic::~Automatic()
{

}

bool Automatic::Identify(QString str)
{
    result=false;
    state=0;
    int col;//הכÿ גûבמנא סעמכבצא
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='1')
            col=1;
        else
            col=0;
        state=transMatr[state][col];
    }
    if(state==1)
        result=true;
    return result;
}
