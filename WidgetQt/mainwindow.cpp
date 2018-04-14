
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingport.h"

#include "menu.h"

#include <QMessageBox>
#include <QtSerialPort/QSerialPort>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //sWindow = new Menu();

        serial = new QSerialPort(this);
        connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
                    this, &MainWindow::handleError);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString Password = "show"; // пока пусть будет тут

  /*  if (ui->lineEdit->text() == Password){
        sWindow->show();
        this->close();
    }*/




    QByteArray test = "hello";



    serial->setPortName("COM4");
    serial->setBaudRate(serial->Baud9600);
    serial->setDataBits( serial->Data8 );
    serial->setParity(serial->NoParity);
    serial->setStopBits(serial->OneStop);
    serial->setFlowControl( serial->NoFlowControl);
    if (serial->open(QIODevice::ReadWrite)) {
            serial->write( test );
    } else {
        //QMessageBox::critical(this, tr("Error"), serial->errorString());

        //showStatusMessage(tr("Open error"));
    }
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}

void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();

}
