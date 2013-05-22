#include "generator.h"

Generator::Generator()
{
    tree=NULL;
    mistake=false;
}

Generator::~Generator()
{
}

QStringList Generator::generateCode(QString str)
{
    QStringList list;

    mistake=false;//�������� ������ �� ������
    mistake=!checkString(str);
    if(!mistake && str[0]=='=')
    {
        str.remove(QChar(' '));//������� �� ������ ��� �������
        tree=makeNode(&str,0);
    }
    else
        mistake=true;
    if(!mistake)
        treeCodeGeneration(&list, tree);

    return list;
}

bool Generator::checkString(QString str)
{
    bool flag=false;
    int openBracCount=0, closeBracCount=0, operatorCount=0;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='-' || str[i]=='+' || str[i]=='*' || str[i]=='=')
            operatorCount+=1;
        if(str[i]=='(')
            openBracCount+=1;
        if(str[i]==')')
            closeBracCount+=1;
    }
    if(openBracCount==closeBracCount && closeBracCount==operatorCount)
        flag=true;
    return flag;
}

Generator::Node *Generator::makeNode(QString *str, int index)
{
    int pos=index+2;//������� � ������
    Node *cur=new Node;//������� ����� ������ ��� ���������
    cur->info=str->operator [](index);
    cur->isOperator=true;
    if(str->operator [](pos)=='-' || str->operator [](pos)=='+' || str->operator [](pos)=='*' || str->operator [](pos)=='=')//���� ����� �������-�������� �� �������� ��������
    {
        cur->leftChild=makeNode(str, pos);
        pos=searchRightOperand(str,pos);
    }
    else//���� ����� �������-�������
    {
        int i=0;
        cur->leftChild=new Node;
        cur->leftChild->isOperator=false;
        for(i=pos; str->operator [](i)!=',' && str->operator [](i)!=')'; i++)
            cur->leftChild->info+=str->operator [](i);
        pos=i;
    }
    if(str->operator [](pos)==',')//���� ��� �������� ��������, �� ������ �� ������ �������
    {
       pos+=1;
       if(str->operator [](pos)=='-' || str->operator [](pos)=='+' || str->operator [](pos)=='*' || str->operator [](pos)=='=')//���� ������ �������-�������� �� �������� ��������
       {
           cur->rightChild=makeNode(str, pos);
       }
       else//���� ������ �������-�������
       {
           int i=0;
           cur->rightChild=new Node;
           cur->rightChild->isOperator=false;
           for(i=pos; str->operator [](i)!=')'; i++)
               cur->rightChild->info+=str->operator [](i);
       }
    }
    return cur;
}

Generator::Node::Node()
{
    info="";
    isOperator=false;
    leftChild=NULL;
    rightChild=NULL;
}

Generator::Node::~Node()
{
    info.clear();
}


int Generator::searchRightOperand(QString *str, int index)//���� � ��� , ��� �� ���������� ������ ���� ���� ������, � ���� ����� �������� �����������
{
    int bracCount=1;//���-�� ����������� �����, 1 � � ���� ����� ���� ��������
    int i=index+2;
    while(bracCount>0)
    {
        if(str->operator [](i)=='-' || str->operator [](i)=='+' || str->operator [](i)=='*' || str->operator [](i)=='=')
        {
            bracCount+=1;
            i+=2;
        }
        else
        {
            if(str->operator [](i)==')')
                bracCount-=1;
            i+=1;
        }
    }
    return i;
}

void Generator::treeCodeGeneration(QStringList *list, Generator::Node *cur)
{
    QString str="";//�������� ������
    bool flag=false;
    if(cur->info=="=")//���� ��� �������� ���������
    {
        treeCodeGeneration(list, cur->rightChild);
        str="mov "; str+=cur->leftChild->info; str+=", eax";
        list->operator +=(str);
    }
    else//���� ��� �� ���������
    {
        if(cur->leftChild && cur->rightChild)//���� �������� ��������
        {
            if(cur->leftChild->isOperator && cur->rightChild->isOperator)//���� ��� �������-���������
            {
             treeCodeGeneration(list, cur->rightChild);
             list->operator +=(QString::fromLocal8Bit("push eax"));
             treeCodeGeneration(list, cur->leftChild);
             list->operator +=(QString::fromLocal8Bit("pop edx"));
             switch(cur->info[0].toAscii())//���������� ��������������� ��� ��������
             {
             case '+':
                 list->operator +=(QString::fromLocal8Bit("add eax, edx"));
                 break;
             case '-':
                 list->operator +=(QString::fromLocal8Bit("sub eax, edx"));
                 break;
             case '*':
                 list->operator +=(QString::fromLocal8Bit("mul eax, edx"));
                 break;
             default:
                 break;
             }
            }
            else//���� ���� ��� ��� �� �������� �� ���������
            {
                if(!cur->leftChild->isOperator && !cur->rightChild->isOperator)//���� ��� �� ���������
                {

                    str="mov eax, "; str+=cur->leftChild->info;
                    list->operator +=(str);
                    switch(cur->info[0].toAscii())//��� ��������
                    {
                    case '+':
                        str="add eax, ";
                        break;
                    case '-':
                        str="sub eax, ";
                        break;
                    case '*':
                        str="mul eax, ";
                        break;
                    default:
                        break;
                    }
                    cur->rightChild->info.toInt(&flag, 10);
                    if(flag)//���� ������ ��������-�����
                        str+=cur->rightChild->info;
                    else
                    {
                        list->operator +=(QString::fromLocal8Bit("mov edx, ")+cur->rightChild->info);
                        str+="edx";
                    }
                    list->operator +=(str);
                }
                else//���� ���� �� �������� �� ��������
                {
                    if(cur->leftChild->isOperator)//���� ����� �������-��������
                    {
                        treeCodeGeneration(list, cur->leftChild);
                        switch(cur->info[0].toAscii())//��� ��������
                        {
                        case '+':
                            str="add eax, ";
                            break;
                        case '-':
                            str="sub eax, ";
                            break;
                        case '*':
                            str="mul eax, ";
                            break;
                        default:
                            break;
                        }
                        cur->rightChild->info.toInt(&flag, 10);
                        if(flag)//���� ������ �������-�����
                            str+=cur->rightChild->info;
                        else
                        {
                            list->operator +=(QString::fromLocal8Bit("mov edx, ")+cur->rightChild->info);
                            str+="edx";
                        }
                        list->operator +=(str);
                    }
                    else//���� ������ �������-��������
                    {
                        if(cur->info[0].toAscii()=='-')//���� ������ �������� �� �������������
                        {
                            treeCodeGeneration(list, cur->rightChild);
                            list->operator +=(QString::fromLocal8Bit("mov edx, ")+cur->leftChild->info);
                            list->operator +=(QString::fromLocal8Bit("xchg eax, edx"));
                            list->operator +=(QString::fromLocal8Bit("sub eax, edx"));
                        }
                        else//���� �������������
                        {
                            treeCodeGeneration(list, cur->rightChild);
                            if(cur->info[0].toAscii()=='+')
                                str="add eax, ";
                            else
                                str="mul eax, ";
                            cur->leftChild->info.toInt(&flag, 10);
                            if(flag)//���� ������ ��������-�����
                                str+=cur->leftChild->info;
                            else
                            {
                                list->operator +=(QString::fromLocal8Bit("mov edx, ")+cur->leftChild->info);
                                str+="edx";
                            }
                            list->operator +=(str);
                        }
                    }
                }

            }
        }
        else//���� ������� ��������
        {
            if(cur->leftChild->isOperator)//���� �������-��������
            {
                treeCodeGeneration(list, cur->leftChild);
                str="neg eax";
                list->operator +=(str);
            }
            else//���� ������� ��������� ��� ����������
            {
                str="mov eax, ";
                str+=cur->leftChild->info;
                list->operator +=(str);
                list->operator +=(QString::fromLocal8Bit("neg eax"));
            }
        }
    }
}

