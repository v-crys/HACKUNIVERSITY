#include "settingport.h"
#include "ui_settingport.h"

SettingPort::SettingPort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingPort)
{
    ui->setupUi(this);
}

SettingPort::~SettingPort()
{
    delete ui;
}

void SettingPort::on_pushButton_clicked()
{
    this->close();
    emit menu();
}
