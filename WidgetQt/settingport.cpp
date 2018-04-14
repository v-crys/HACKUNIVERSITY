#include "settingport.h"
#include "ui_settingport.h"

SettingPort::SettingPort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingPort)
{
   // ui->setupUi(this);
   // baudRate = 9600;
   // dataBits = 8;
   // stopBits = serial.
}

SettingPort::~SettingPort()
{
    delete ui;
}

void SettingPort::on_pushButton_clicked()
{
    this->close();
    //emit menu();
}

void SettingPort::on_pushButton_2_clicked()
{
    Save();
    this->close();
}

void SettingPort::Save(){
    name = ui->lineEdit->text();
}
