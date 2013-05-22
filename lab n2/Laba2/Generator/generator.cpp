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

    mistake=false;//обнуляем данные об ошибке
    mistake=!checkString(str);
    if(!mistake && str[0]=='=')
    {
        str.remove(QChar(' '));//удаляем из строки все пробелы
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
    int pos=index+2;//позиция в строке
    Node *cur=new Node;//создаем новый корень для оператора
    cur->info=str->operator [](index);
    cur->isOperator=true;
    if(str->operator [](pos)=='-' || str->operator [](pos)=='+' || str->operator [](pos)=='*' || str->operator [](pos)=='=')//если левый операнд-оператор то вызываем рекурсию
    {
        cur->leftChild=makeNode(str, pos);
        pos=searchRightOperand(str,pos);
    }
    else//если левый операнд-операнд
    {
        int i=0;
        cur->leftChild=new Node;
        cur->leftChild->isOperator=false;
        for(i=pos; str->operator [](i)!=',' && str->operator [](i)!=')'; i++)
            cur->leftChild->info+=str->operator [](i);
        pos=i;
    }
    if(str->operator [](pos)==',')//если был бинарный оператор, то смотри на правай операнд
    {
       pos+=1;
       if(str->operator [](pos)=='-' || str->operator [](pos)=='+' || str->operator [](pos)=='*' || str->operator [](pos)=='=')//если правый операнд-оператор то вызываем рекурсию
       {
           cur->rightChild=makeNode(str, pos);
       }
       else//если правый операнд-операнд
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


int Generator::searchRightOperand(QString *str, int index)//идея в том , что за оператором должна быть пара скобок, и надо найти последюю закрывающую
{
    int bracCount=1;//кол-во открывающих скобо, 1 т к есть точно один оператор
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
    QString str="";//буферная строка
    bool flag=false;
    if(cur->info=="=")//если это оператор присвоить
    {
        treeCodeGeneration(list, cur->rightChild);
        str="mov "; str+=cur->leftChild->info; str+=", eax";
        list->operator +=(str);
    }
    else//если это на присвоить
    {
        if(cur->leftChild && cur->rightChild)//если бинарный оператор
        {
            if(cur->leftChild->isOperator && cur->rightChild->isOperator)//если оба потомка-операторы
            {
             treeCodeGeneration(list, cur->rightChild);
             list->operator +=(QString::fromLocal8Bit("push eax"));
             treeCodeGeneration(list, cur->leftChild);
             list->operator +=(QString::fromLocal8Bit("pop edx"));
             switch(cur->info[0].toAscii())//дописываем непосредственно сам оператор
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
            else//если один или оба из потомков не операторы
            {
                if(!cur->leftChild->isOperator && !cur->rightChild->isOperator)//если оба не операторы
                {

                    str="mov eax, "; str+=cur->leftChild->info;
                    list->operator +=(str);
                    switch(cur->info[0].toAscii())//сам оператор
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
                    if(flag)//если правый оператор-число
                        str+=cur->rightChild->info;
                    else
                    {
                        list->operator +=(QString::fromLocal8Bit("mov edx, ")+cur->rightChild->info);
                        str+="edx";
                    }
                    list->operator +=(str);
                }
                else//есди один из потомков не оператор
                {
                    if(cur->leftChild->isOperator)//если левый потомок-оператор
                    {
                        treeCodeGeneration(list, cur->leftChild);
                        switch(cur->info[0].toAscii())//сам оператор
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
                        if(flag)//если правый оператр-число
                            str+=cur->rightChild->info;
                        else
                        {
                            list->operator +=(QString::fromLocal8Bit("mov edx, ")+cur->rightChild->info);
                            str+="edx";
                        }
                        list->operator +=(str);
                    }
                    else//если правый потомок-оператор
                    {
                        if(cur->info[0].toAscii()=='-')//если данный оператор не коммутативный
                        {
                            treeCodeGeneration(list, cur->rightChild);
                            list->operator +=(QString::fromLocal8Bit("mov edx, ")+cur->leftChild->info);
                            list->operator +=(QString::fromLocal8Bit("xchg eax, edx"));
                            list->operator +=(QString::fromLocal8Bit("sub eax, edx"));
                        }
                        else//если коммутативный
                        {
                            treeCodeGeneration(list, cur->rightChild);
                            if(cur->info[0].toAscii()=='+')
                                str="add eax, ";
                            else
                                str="mul eax, ";
                            cur->leftChild->info.toInt(&flag, 10);
                            if(flag)//если правый оператор-число
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
        else//если унарный оператор
        {
            if(cur->leftChild->isOperator)//если потомок-оператор
            {
                treeCodeGeneration(list, cur->leftChild);
                str="neg eax";
                list->operator +=(str);
            }
            else//если потомок константа или переменная
            {
                str="mov eax, ";
                str+=cur->leftChild->info;
                list->operator +=(str);
                list->operator +=(QString::fromLocal8Bit("neg eax"));
            }
        }
    }
}

