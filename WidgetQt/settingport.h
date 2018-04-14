#ifndef SETTINGPORT_H
#define SETTINGPORT_H

#include <QWidget>

namespace Ui {
class SettingPort;
}

class SettingPort : public QWidget
{
    Q_OBJECT

signals:
    void menu();

public:
    explicit SettingPort(QWidget *parent = 0);
    ~SettingPort();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SettingPort *ui;
};

#endif // SETTINGPORT_H
