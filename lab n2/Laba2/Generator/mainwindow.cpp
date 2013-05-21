#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gen=new Generator;
    ui->mistake->setVisible(false);
    ui->ok->setEnabled(false);
    ui->clear->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    if(!ui->lineEdit->text().isEmpty())
        ui->ok->setEnabled(true);
    else
        ui->ok->setEnabled(false);
    ui->mistake->setVisible(false);
}

void MainWindow::on_ok_clicked()
{
    QStringList list;
    ui->lineEdit->setEnabled(false);
//    ui->textEdit->clear();
    ui->ok->setEnabled(false);
    ui->clear->setEnabled(true);
    list=gen->generateCode(ui->lineEdit->text());
    if(!gen->getMis())
    {
        foreach(QString it, list)
            ui->textEdit->append(it);
    }
    else
        ui->mistake->setVisible(true);
}

void MainWindow::on_clear_clicked()
{
    ui->lineEdit->setEnabled(true);
    ui->lineEdit->clear();
    ui->textEdit->clear();
    ui->ok->setEnabled(true);
    ui->clear->setEnabled(false);
    ui->mistake->setVisible(false);
}
