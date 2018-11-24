#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addstu.h"
#include "query_stu.h"


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
    void on_actionDfad_triggered();

    void on_actionChax_triggered();

private:
    Ui::MainWindow *ui;
    addstu *addstu_win;
};

#endif // MAINWINDOW_H
