/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 20. May 13:38:16 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableView *table;
    QGroupBox *newAutoGroupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *alfaEdit;
    QLineEdit *termsEdit;
    QLabel *help;
    QPushButton *newAutoOk;
    QPushButton *NewAutoCansel;
    QTextEdit *leftGram;
    QTextEdit *rightGram;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *makeGrammar;
    QLabel *misMassage;
    QLabel *label_6;
    QPushButton *newAuto;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(857, 510);
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        table = new QTableView(centralWidget);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(10, 30, 400, 320));
        table->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        table->setTextElideMode(Qt::ElideLeft);
        table->horizontalHeader()->setDefaultSectionSize(50);
        table->verticalHeader()->setDefaultSectionSize(50);
        newAutoGroupBox = new QGroupBox(centralWidget);
        newAutoGroupBox->setObjectName(QString::fromUtf8("newAutoGroupBox"));
        newAutoGroupBox->setGeometry(QRect(10, 390, 461, 101));
        newAutoGroupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        newAutoGroupBox->setFlat(false);
        newAutoGroupBox->setCheckable(false);
        layoutWidget = new QWidget(newAutoGroupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 434, 98));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        alfaEdit = new QLineEdit(layoutWidget);
        alfaEdit->setObjectName(QString::fromUtf8("alfaEdit"));

        gridLayout->addWidget(alfaEdit, 1, 0, 1, 1);

        termsEdit = new QLineEdit(layoutWidget);
        termsEdit->setObjectName(QString::fromUtf8("termsEdit"));

        gridLayout->addWidget(termsEdit, 1, 1, 1, 1);

        help = new QLabel(layoutWidget);
        help->setObjectName(QString::fromUtf8("help"));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        help->setFont(font2);

        gridLayout->addWidget(help, 2, 0, 1, 2);

        newAutoOk = new QPushButton(layoutWidget);
        newAutoOk->setObjectName(QString::fromUtf8("newAutoOk"));

        gridLayout->addWidget(newAutoOk, 3, 0, 1, 1);

        NewAutoCansel = new QPushButton(layoutWidget);
        NewAutoCansel->setObjectName(QString::fromUtf8("NewAutoCansel"));

        gridLayout->addWidget(NewAutoCansel, 3, 1, 1, 1);

        leftGram = new QTextEdit(centralWidget);
        leftGram->setObjectName(QString::fromUtf8("leftGram"));
        leftGram->setGeometry(QRect(430, 30, 180, 280));
        leftGram->setReadOnly(true);
        rightGram = new QTextEdit(centralWidget);
        rightGram->setObjectName(QString::fromUtf8("rightGram"));
        rightGram->setGeometry(QRect(620, 30, 190, 280));
        rightGram->setReadOnly(true);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(420, 10, 181, 16));
        label_3->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(625, 10, 191, 20));
        label_4->setFont(font1);
        makeGrammar = new QPushButton(centralWidget);
        makeGrammar->setObjectName(QString::fromUtf8("makeGrammar"));
        makeGrammar->setGeometry(QRect(520, 320, 201, 51));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        makeGrammar->setFont(font3);
        misMassage = new QLabel(centralWidget);
        misMassage->setObjectName(QString::fromUtf8("misMassage"));
        misMassage->setGeometry(QRect(440, 400, 364, 24));
        QFont font4;
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setWeight(75);
        misMassage->setFont(font4);
        misMassage->setFrameShadow(QFrame::Plain);
        misMassage->setScaledContents(false);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 10, 245, 16));
        label_6->setFont(font1);
        newAuto = new QPushButton(centralWidget);
        newAuto->setObjectName(QString::fromUtf8("newAuto"));
        newAuto->setGeometry(QRect(140, 350, 150, 35));
        newAuto->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\223\321\200\320\260\320\274\320\274\320\260\321\202\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        newAutoGroupBox->setTitle(QString());
        label->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \320\260\320\273\321\204\320\260\320\262\320\270\321\202", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\265 \320\275\320\265\321\202\320\265\321\200\320\274\320\270\320\275\320\260\320\273\321\213", 0, QApplication::UnicodeUTF8));
        help->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \320\260\320\273\321\204\320\260\320\262\320\270\321\202 \320\270 \320\275\320\276\320\262\321\213\320\265 \320\275\320\265\321\202\320\265\321\200\320\274\320\270\320\275\320\260\320\273\321\213 \320\262\320\262\320\276\320\264\321\217\321\202\321\201\321\217 \321\207\320\265\321\200\320\265\320\267 \320\267\320\260\320\277\321\217\321\202\321\203\321\216", 0, QApplication::UnicodeUTF8));
        newAutoOk->setText(QApplication::translate("MainWindow", "\320\236\320\272", 0, QApplication::UnicodeUTF8));
        NewAutoCansel->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\320\233\320\265\320\262\320\276\321\201\321\202\320\276\321\200\320\276\320\275\320\275\321\217\321\217 \320\263\321\200\320\260\320\274\320\274\320\260\321\202\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\276\321\201\321\202\320\276\321\200\320\276\320\275\320\275\321\217\321\217 \320\263\321\200\320\260\320\274\320\274\320\260\321\202\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        makeGrammar->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\320\274\320\274\320\260\321\202\320\270\320\272\320\270", 0, QApplication::UnicodeUTF8));
        misMassage->setText(QApplication::translate("MainWindow", "\320\235\320\265\320\272\320\276\321\200\321\200\320\265\320\272\321\202\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\262 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\265", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\274\320\260\321\202 \320\264\320\273\321\217 \320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\321\217 \320\263\321\200\320\260\320\274\320\274\320\260\321\202\320\270\320\272", 0, QApplication::UnicodeUTF8));
        newAuto->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \320\260\320\262\321\202\320\276\320\274\320\260\321\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
