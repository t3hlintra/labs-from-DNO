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
    int col;//для выбора столбца
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
//    for(int i=0; i<str.length() && state!=1; i++)
//        switch (state)
//        {
//        case 0:
//            if(str[i]=='1')
//                state=1;
//            break;
//        case 1:
//            state=1;
//            break;
//        }
//    if(state==1)
//        result=true;
    /*другие варианты реализации*/
//    int i;
//    for(i=0; i<str.length() && str[i]!=1; i++);
//    if(i<str.length())
//        result=true;
    /**/
//    for(int i=0; i<str.length(); i++)
//        switch (state)
//        {
//        case 0:
//            if(str[i]=='1')
//                state=1;
//            break;
//        case 1:
//            state=1;
//            break;
//        }
//    if(state==1)
//        result=true;
    return result;
}
