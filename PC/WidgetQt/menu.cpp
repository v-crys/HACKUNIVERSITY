#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    WindowSettingPort = new SettingPort();
    //connect(WindowSettingPort, &SettingPort::menu, this, &Menu::show);


    serial = new QSerialPort(this);
    Connect();
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    Connect();
}

void Menu::on_pushButton_2_clicked()
{
    WindowSettingPort->show();
    //this->close();
}

void Menu::on_pushButton_3_clicked()
{

    QByteArray test = "";
    QString temp(ui->lineEdit->text());

    test.append("d");
    test.append(temp.length());
    test.append(temp);

    //test.append(ui->lineEdit->text());

    serial->write( test );
}

void Menu::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}

void Menu::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
}

void Menu::Connect(){
    closeSerialPort();

    serial->setPortName(WindowSettingPort->NameReturn());
    serial->setBaudRate(serial->Baud9600);
    serial->setDataBits( serial->Data8 );
    serial->setParity(serial->NoParity);
    serial->setStopBits(serial->OneStop);
    serial->setFlowControl( serial->NoFlowControl);

    if (serial->open(QIODevice::ReadWrite)) {

    }
}
