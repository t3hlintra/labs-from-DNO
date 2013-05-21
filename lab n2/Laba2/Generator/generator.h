#ifndef GENERATOR_H
#define GENERATOR_H

#include <QtCore>

class Generator
{
public:

    Generator();
    ~Generator();
    QStringList generateCode(QString str);
    bool getMis(){ return mistake; }
private:
    struct Node//трутура для описания корня дерева
    {
        Node();
        ~Node();
        QString info;
        bool isOperator;// true если корень содержит оператор
        Node *leftChild, *rightChild;//указатели на левую и правую ветви потомков
    };
    bool mistake;// покказвает что была ошибка в отаботке
    Node *tree;//указтель на начало дерева
    bool checkString(QString str);//проверяет строку на соответсвие требованиеям true если строка правильная
    Node* makeNode(QString *str, int index);//рекурсивная функция создания дерева по строке, возвращает указатель на созданный корень
    int searchRightOperand(QString *str, int index);//поиск правого операнда, идущего за оператором
    void treeCodeGeneration(QStringList *list, Node *cur);//рекурсивная функция по обходу дерева и создания кодаr
};

#endif // GENERATOR_H
