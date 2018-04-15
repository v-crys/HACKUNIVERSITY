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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingPort
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QWidget *SettingPort)
    {
        if (SettingPort->objectName().isEmpty())
            SettingPort->setObjectName(QStringLiteral("SettingPort"));
        SettingPort->resize(550, 500);
        pushButton = new QPushButton(SettingPort);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 460, 93, 28));
        pushButton_2 = new QPushButton(SettingPort);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(450, 460, 93, 28));
        label = new QLabel(SettingPort);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 171, 61));
        lineEdit = new QLineEdit(SettingPort);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(210, 30, 241, 41));

        retranslateUi(SettingPort);

        QMetaObject::connectSlotsByName(SettingPort);
    } // setupUi

    void retranslateUi(QWidget *SettingPort)
    {
        SettingPort->setWindowTitle(QApplication::translate("SettingPort", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SettingPort", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("SettingPort", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
        label->setText(QApplication::translate("SettingPort", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 COM \320\277\320\276\321\200\321\202\320\260:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingPort: public Ui_SettingPort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGPORT_H
