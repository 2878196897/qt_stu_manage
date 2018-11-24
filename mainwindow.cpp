#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addstu_win = new addstu;
}

MainWindow::~MainWindow()
{
    delete addstu_win;
    delete ui; 
}

void MainWindow::on_actionDfad_triggered()
{
   addstu_win->show();
}

void MainWindow::on_actionChax_triggered()
{
    query_stu a;
    a.exec();
}
