#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
    ui->Rec->setVisible(false);
    ui->NotRec->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    ui->Rec->setVisible(false);
    ui->NotRec->setVisible(false);
    if(ui->lineEdit->text().isEmpty())
        ui->pushButton->setEnabled(false);
    else
        ui->pushButton->setEnabled(true);
}

void MainWindow::on_pushButton_clicked()
{
    Ka.Identify(ui->lineEdit->text());
    if(Ka.getResult())
        ui->Rec->setVisible(true);
    else
        ui->NotRec->setVisible(true);
    ui->pushButton->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->lineEdit->setFocus();
}
