#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <automatic.h>

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

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Automatic Ka;
};

#endif // MAINWINDOW_H
