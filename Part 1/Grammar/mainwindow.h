#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "grammaker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void on_NewAutoCansel_clicked();

    void on_newAuto_clicked();

    void on_newAutoOk_clicked();



    void on_alfaEdit_textChanged(const QString &arg1);

    void on_termsEdit_textChanged(const QString &arg1);

    void on_makeGrammar_clicked();

private:
    Ui::MainWindow *ui;
    gramMaker *maker;
};

#endif // MAINWINDOW_H
