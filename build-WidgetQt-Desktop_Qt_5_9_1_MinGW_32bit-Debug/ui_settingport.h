/********************************************************************************
** Form generated from reading UI file 'settingport.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGPORT_H
#define UI_SETTINGPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingPort
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *SettingPort)
    {
        if (SettingPort->objectName().isEmpty())
            SettingPort->setObjectName(QStringLiteral("SettingPort"));
        SettingPort->resize(400, 300);
        pushButton = new QPushButton(SettingPort);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 250, 93, 28));

        retranslateUi(SettingPort);

        QMetaObject::connectSlotsByName(SettingPort);
    } // setupUi

    void retranslateUi(QWidget *SettingPort)
    {
        SettingPort->setWindowTitle(QApplication::translate("SettingPort", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SettingPort", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingPort: public Ui_SettingPort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGPORT_H
