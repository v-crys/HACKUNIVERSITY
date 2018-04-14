#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sWindow = new Menu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString Password = "show"; // пока пусть будет тут

    if (ui->lineEdit->text() == Password){
        sWindow->show();
        this->close();
    }
}
