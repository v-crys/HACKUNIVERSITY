#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>

#include <QMainWindow>

#include <QtSerialPort/QSerialPort>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

       QSerialPort *serial;
       void handleError(QSerialPort::SerialPortError error);
       void closeSerialPort();
   // Menu *sWindow;
    //SettingsDialog *settings;
};

#endif // MAINWINDOW_H
