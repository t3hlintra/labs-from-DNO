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
    struct Node//������� ��� �������� ����� ������
    {
        Node();
        ~Node();
        QString info;
        bool isOperator;// true ���� ������ �������� ��������
        Node *leftChild, *rightChild;//��������� �� ����� � ������ ����� ��������
    };
    bool mistake;// ��������� ��� ���� ������ � ���������
    Node *tree;//��������� �� ������ ������
    bool checkString(QString str);//��������� ������ �� ����������� ����������� true ���� ������ ����������
    Node* makeNode(QString *str, int index);//����������� ������� �������� ������ �� ������, ���������� ��������� �� ��������� ������
    int searchRightOperand(QString *str, int index);//����� ������� ��������, ������� �� ����������
    void treeCodeGeneration(QStringList *list, Node *cur);//����������� ������� �� ������ ������ � �������� ����
};

#endif // GENERATOR_H
