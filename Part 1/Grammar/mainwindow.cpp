#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->newAutoGroupBox->setVisible(false);
    ui->misMassage->setVisible(false);
    maker=new gramMaker();
    ui->table->setModel(maker->getModel());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_NewAutoCansel_clicked()
{
    ui->newAutoGroupBox->setVisible(false);
    ui->makeGrammar->setEnabled(true);
    ui->alfaEdit->clear();
    ui->termsEdit->clear();
}

void MainWindow::on_newAuto_clicked()
{
    ui->newAutoGroupBox->setVisible(true);
    ui->makeGrammar->setEnabled(false);
    ui->alfaEdit->setFocus();
    ui->newAutoOk->setEnabled(false);
}

void MainWindow::on_newAutoOk_clicked()
{
    ui->newAutoGroupBox->setVisible(false);
    ui->makeGrammar->setEnabled(true);
    QString str=ui->alfaEdit->text().toLower();//перевод в нижний регистр и удаление дубликатов
    QStringList list=str.split(',', QString::SkipEmptyParts);
    list.removeDuplicates();
    maker->setAlfa(list);
    str=ui->termsEdit->text().toUpper();//перевод в верхний регистр и удаление дубликатов
    list=str.split(',', QString::SkipEmptyParts);
    list.removeDuplicates();
    maker->setTerms(list);
    maker->clear();
    ui->alfaEdit->clear();
    ui->termsEdit->clear();
}


void MainWindow::on_alfaEdit_textChanged(const QString &arg1)
{
    if(!ui->alfaEdit->text().isEmpty() && !ui->termsEdit->text().isEmpty())
        ui->newAutoOk->setEnabled(true);
    else
        ui->newAutoOk->setEnabled(false);
}

void MainWindow::on_termsEdit_textChanged(const QString &arg1)
{
    if(!ui->alfaEdit->text().isEmpty() && !ui->termsEdit->text().isEmpty())
        ui->newAutoOk->setEnabled(true);
    else
        ui->newAutoOk->setEnabled(false);
}

void MainWindow::on_makeGrammar_clicked()
{
    if(maker->correctTable())
    {
        QStringList list;
        ui->rightGram->clear();
        ui->leftGram->clear();
        ui->misMassage->setVisible(false);
        list=maker->makeRightGrammar();
        foreach(QString itm, list)
            ui->rightGram->append(itm);
        list=maker->makeLeftGrammar();
        foreach(QString itm, list)
            ui->leftGram->append(itm);
    }
    else
        ui->misMassage->setVisible(true);
}

