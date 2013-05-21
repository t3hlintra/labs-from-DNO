#include "grammaker.h"
#include "mainwindow.h"
gramMaker::gramMaker()
{
    table=new QStandardItemModel(4,3);
    horLables.append("0");
    horLables.append("1");
    horLables.append(QString::fromLocal8Bit("К С"));
    table->setHorizontalHeaderLabels(horLables);
    vertLables.append("A");
    vertLables.append("B");
    vertLables.append("C");
    vertLables.append("D");
    table->setVerticalHeaderLabels(vertLables);
    table->setData(table->index(0,0), "B"); table->setData(table->index(0,1), "A"); table->setData(table->index(0,2), "0");
    table->setData(table->index(1,0), "D");  table->setData(table->index(1,1), "C"); table->setData(table->index(1,2), "0");
    table->setData(table->index(2,0), "C"); table->setData(table->index(2,1), "D"); table->setData(table->index(2,2), "0");
    table->setData(table->index(3,0), "D"); table->setData(table->index(3,1), "D"); table->setData(table->index(3,2), "1");
}

gramMaker::~gramMaker()
{
    delete table;
}

QStringList gramMaker::makeRightGrammar()
{
    QString str="";
    QStringList list;
    for(int i=0; i<table->rowCount(); ++i)//собираем строки грамматики
    {
        str+=vertLables[i];
        str+=" ::= ";
        for(int j=0; j<table->columnCount()-1; ++j)
        {
            str+=horLables[j];
            if(vertLables[i]!=table->data(table->index(i, j, QModelIndex()), Qt::EditRole).toString())
                str+=table->data(table->index(i, j, QModelIndex()), Qt::EditRole).toString();
            if(j!=table->columnCount()-2)
                str+=" | ";
        }
       list.append(str);
       str="";
    }
    for(int i=0; i<table->rowCount(); ++i)//удаляем лишние данные
    {
        if(table->data(table->index(i, table->columnCount()-1, QModelIndex()), Qt::EditRole).toString()=="1")//если конечное состояние
        {
            int j=0;
            for(j=0; j<table->columnCount()-1 && vertLables[i]==table->data(table->index(i, j, QModelIndex()), Qt::EditRole).toString(); ++j);
            if(j==table->columnCount()-1)//если из конечного состояния нет дуг
            {
                list.removeAt(i);//удаляем строку с конечным состояние и без дуг
                str=" [a-z0-9_]+"; str+=vertLables[i];str+=" [|]"; str+="|[|] [a-z0-9_]+"; str+=vertLables[i]; str+="$";//регулярное выражение для удаления нетерминалов
                list.replaceInStrings(QRegExp(str), "");
            }
        }
    }
    return list;
}

QStringList gramMaker::makeLeftGrammar()
{
    QString str="";
    QStringList list;
    for(int nt=0; nt<table->rowCount(); ++nt)
    {
        str+=vertLables[nt];
        str+=" ::= ";
        for(int j=0; j<table->columnCount()-1; ++j)
        {
            for(int i=0; i<table->rowCount(); ++i)
            {
                if(vertLables[nt]==table->data(table->index(i, j, QModelIndex()), Qt::EditRole).toString())
                {
                    str+=vertLables[i];
                    str+=horLables[j];
                    str+=" | ";
                }
            }
        }
        list.append(str);
        str="";
    }
    str=" [|] $";//удаляем лишние разделители
    list.replaceInStrings(QRegExp(str), "");
    str=vertLables[0];
    str+=" ::= ";
    if(list[0]==str)//если в первое состояние не ведут дуги
    {
        list.removeFirst();
        str=" "; str+=vertLables[0]; str+="[a-z0-9_]+ [|]|[|] "; str+=vertLables[0]; str+="[a-z0-9_]+$";
        list.replaceInStrings(QRegExp(str), "");
    }
    return list;
}

void gramMaker::setTerms(QStringList list)
{
    if(list.count()<table->rowCount())
        table->setRowCount(list.count());
    table->setVerticalHeaderLabels(list);
    vertLables=list;
}

void gramMaker::setAlfa(QStringList list)
{
    if(list.count()<table->columnCount())
        table->setColumnCount(list.count());
    list+=QString::fromLocal8Bit("К С");
    horLables=list;
    table->setHorizontalHeaderLabels(list);
}

void gramMaker::clear()
{
    for(int i=0; i<table->rowCount(); ++i)
        for(int j=0; j<table->columnCount(); ++j)
            table->setData(table->index(i,j),"");
}

bool gramMaker::correctTable()
{
    bool flag=true;
    for(int i=0; i<table->rowCount(); ++i)
        for(int j=0; j<table->columnCount(); ++j)
            if(table->data(table->index(i, j, QModelIndex()), Qt::EditRole).toString().isEmpty())
                flag=false;
    if(flag)
    {
        for(int i=0; i<table->rowCount() && flag; ++i)
            for(int j=0; j<table->columnCount()-1 && flag; ++j)
            {

                int x=0;
                for(x=0; x<vertLables.count() && vertLables[x]!=table->data(table->index(i, j, QModelIndex()), Qt::EditRole).toString(); x++);
                    if(x==vertLables.count())
                        flag=false;
            }
    }
    return flag;
}
