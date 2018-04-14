#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    WindowSettingPort = new SettingPort();
    connect(WindowSettingPort, &SettingPort::menu, this, &Menu::show);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{

}

void Menu::on_pushButton_2_clicked()
{
    WindowSettingPort->show();
    this->close();
}
