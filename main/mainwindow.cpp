#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qlabel.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    FirstObs = new DisplayEditText("DisplayEditText");
    SecondObs = new DisplayLineEdit("DisplayLineEdit");
    ui->setupUi(this);
    QVBoxLayout  *Hlayout = ui->verticalLayout;
    Hlayout->addWidget(new QLabel("DisplayEditText"));
    Hlayout->addWidget(FirstObs->display());
    Hlayout->addWidget(new QLabel("DisplayLineEdit"));
    Hlayout->addWidget(SecondObs->display());

    _WS.addObserver(FirstObs);
    _WS.addObserver(SecondObs);
    QString nameFile="ThirdObs.txt";
    _WS.addObserver(new DisplayDocTxt(nameFile));
}

MainWindow::~MainWindow()
{
    _WS.end();
    _WS.wait();

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
{   QRegExp re("\\d*");
    QString buf = ui->lineEdit->text();
    if(re.exactMatch(buf))
            _WS.setFreqNewData(buf.toInt());
    else
        ui->lineEdit->setText("not a number");
}
