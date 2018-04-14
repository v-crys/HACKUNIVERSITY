#ifndef SETTINGPORT_H
#define SETTINGPORT_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>

namespace Ui {
class SettingPort;
}

class SettingPort : public QWidget
{
    Q_OBJECT

    QString name;
    qint32 baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::StopBits stopBits;

signals:
    void menu();

public:
    explicit SettingPort(QWidget *parent = 0);
    ~SettingPort();
    QString NameReturn() { return name; }

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    void Save();

    Ui::SettingPort *ui;
};

#endif // SETTINGPORT_H
