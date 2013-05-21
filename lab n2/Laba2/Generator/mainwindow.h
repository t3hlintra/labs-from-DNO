#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <generator.h>

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
    void on_lineEdit_textEdited(const QString &arg1);

    void on_ok_clicked();

    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
    Generator *gen;
};

#endif // MAINWINDOW_H
