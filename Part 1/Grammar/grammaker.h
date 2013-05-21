#ifndef GRAMMAKER_H
#define GRAMMAKER_H

#include <QtCore>
#include <QtGui>

class gramMaker
{
public:
    gramMaker();
    ~gramMaker();
    QStandardItemModel *getModel(){ return table; }
    QStringList makeRightGrammar();
    QStringList makeLeftGrammar();
    void setAlfa(QStringList list);
    void setTerms(QStringList list);
    void clear();
    bool correctTable();
private:
    QStandardItemModel *table;//модель для хранения таблицы
    QStringList vertLables, horLables;//наименования строк и столбцов
};

#endif // GRAMMAKER_H
