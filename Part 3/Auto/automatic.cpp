#include "automatic.h"

Automatic::Automatic()
{
    state=0;
    result=false;
    transMatr[0][0]=1;   transMatr[0][1]=15;  transMatr[0][2]=15;  transMatr[0][3]=15;  transMatr[0][4]=15;  transMatr[0][5]=15;  transMatr[0][6]=15;  transMatr[0][7]=15;  transMatr[0][8]=15;
    transMatr[1][0]=1;   transMatr[1][1]=2;   transMatr[1][2]=15;  transMatr[1][3]=15;  transMatr[1][4]=15;  transMatr[1][5]=15;  transMatr[1][6]=15;  transMatr[1][7]=15;  transMatr[1][8]=15;
    transMatr[2][0]=15;  transMatr[2][1]=3;   transMatr[2][2]=15;  transMatr[2][3]=15;  transMatr[2][4]=15;  transMatr[2][5]=15;  transMatr[2][6]=15;  transMatr[2][7]=15;  transMatr[2][8]=15;
    transMatr[3][0]=4;   transMatr[3][1]=15;  transMatr[3][2]=15;  transMatr[3][3]=15;  transMatr[3][4]=15;  transMatr[3][5]=15;  transMatr[3][6]=15;  transMatr[3][7]=15;  transMatr[3][8]=15;
    transMatr[4][0]=4;   transMatr[4][1]=15;  transMatr[4][2]=15;  transMatr[4][3]=15;  transMatr[4][4]=15;  transMatr[4][5]=15;  transMatr[4][6]=5;   transMatr[4][7]=15;  transMatr[4][8]=15;
    transMatr[5][0]=7;   transMatr[5][1]=15;  transMatr[5][2]=15;  transMatr[5][3]=6;   transMatr[5][4]=9;   transMatr[5][5]=15;  transMatr[5][6]=8;   transMatr[5][7]=15;  transMatr[5][8]=15;
    transMatr[6][0]=6;   transMatr[6][1]=15;  transMatr[6][2]=15;  transMatr[6][3]=15;  transMatr[6][4]=15;  transMatr[6][5]=15;  transMatr[6][6]=5;   transMatr[6][7]=15;  transMatr[6][8]=15;
    transMatr[7][0]=7;   transMatr[7][1]=15;  transMatr[7][2]=15;  transMatr[7][3]=6;   transMatr[7][4]=9;   transMatr[7][5]=15;  transMatr[7][6]=15;  transMatr[7][7]=15;  transMatr[7][8]=15;
    transMatr[8][0]=7;   transMatr[8][1]=15;  transMatr[8][2]=8;   transMatr[8][3]=6;   transMatr[8][4]=9;   transMatr[8][5]=15;  transMatr[8][6]=8;   transMatr[8][7]=8;   transMatr[8][8]=15;
    transMatr[9][0]=10;  transMatr[9][1]=15;  transMatr[9][2]=15;  transMatr[9][3]=15;  transMatr[9][4]=15;  transMatr[9][5]=15;  transMatr[9][6]=15;  transMatr[9][7]=11;  transMatr[9][8]=15;
    transMatr[10][0]=10; transMatr[10][1]=15; transMatr[10][2]=15; transMatr[10][3]=15; transMatr[10][4]=15; transMatr[10][5]=15; transMatr[10][6]=15; transMatr[10][7]=11; transMatr[10][8]=15;
    transMatr[11][0]=14; transMatr[11][1]=15; transMatr[11][2]=15; transMatr[11][3]=9;  transMatr[11][4]=15; transMatr[11][5]=12; transMatr[11][6]=15; transMatr[11][7]=11; transMatr[11][8]=15;
    transMatr[12][0]=13; transMatr[12][1]=15; transMatr[12][2]=15; transMatr[12][3]=6; transMatr[12][4]=15; transMatr[12][5]=15; transMatr[12][6]=15; transMatr[12][7]=15; transMatr[12][8]=15;
    transMatr[13][0]=13; transMatr[13][1]=15; transMatr[13][2]=15; transMatr[13][3]=6;  transMatr[13][4]=15; transMatr[13][5]=15; transMatr[13][6]=15; transMatr[13][7]=15; transMatr[13][8]=15;
    transMatr[14][0]=14; transMatr[14][1]=15; transMatr[14][2]=15; transMatr[14][3]=9;  transMatr[14][4]=15; transMatr[14][5]=12; transMatr[14][6]=15; transMatr[14][7]=15; transMatr[14][8]=15;
    transMatr[15][0]=15; transMatr[15][1]=15; transMatr[15][2]=15; transMatr[15][3]=15; transMatr[15][4]=15; transMatr[15][5]=15; transMatr[15][6]=15; transMatr[15][7]=15; transMatr[15][8]=15;

}
Automatic::~Automatic()
{

}

bool Automatic::Identify(QString str)
{
    result=false;
    state=0;
    int col;//äëÿ âûáîğà ñòîëáöà
    for(int i=0; i<str.length(); i++)
    {
        switch(str[i].toAscii())
        {
        case ' ':
            col=0;
            break;
        case ':':
            col=1;
            break;
        case '_':
            col=2;
            break;
        case ',':
            col=3;
            break;
        case '(':
            col=4;
            break;
        case ')':
            col=5;
            break;
        default:
            if(str[i].isDigit())
                col=7;
            else
            {
                if(str[i].isLetter())
                {
                    char ch=str[i].toAscii();
                    if(ch>='A' && ch<='Z' || ch>='a' && ch<='z')//åñëè áóêâà ëàòèíñêà
                        col=6;
                    else
                        col=8;
                }
                else
                    col=8;
            }
        break;
        }
        state=transMatr[state][col];
    }
    if(state==5 || state==6 || state==7 || state==8 || state==12 || state==13)
        result=true;
    return result;
}
