#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    _WS.end();
}

void MainWindow::on_pushButton_2_clicked()
{
   _WS.start();
}

void MainWindow::on_pushButton_3_clicked()
{
    _WS._End=false;
    _WS.curData();
}
