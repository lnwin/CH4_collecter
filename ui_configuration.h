/********************************************************************************
** Form generated from reading UI file 'configuration.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATION_H
#define UI_CONFIGURATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_configuration
{
public:
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *b_n;
    QLineEdit *a_n;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *D_n;
    QCheckBox *checkBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QWidget *widget;
    QPushButton *pushButton_3;

    void setupUi(QDialog *configuration)
    {
        if (configuration->objectName().isEmpty())
            configuration->setObjectName(QString::fromUtf8("configuration"));
        configuration->resize(1019, 439);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/001.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        configuration->setWindowIcon(icon);
        groupBox = new QGroupBox(configuration);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 210, 111, 71));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(12, 45, 30, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(12, 22, 30, 16));
        b_n = new QLineEdit(groupBox);
        b_n->setObjectName(QString::fromUtf8("b_n"));
        b_n->setEnabled(true);
        b_n->setGeometry(QRect(48, 45, 61, 22));
        a_n = new QLineEdit(groupBox);
        a_n->setObjectName(QString::fromUtf8("a_n"));
        a_n->setEnabled(true);
        a_n->setGeometry(QRect(48, 22, 61, 22));
        pushButton = new QPushButton(configuration);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 111, 41));
        comboBox = new QComboBox(configuration);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(60, 60, 61, 31));
        label_4 = new QLabel(configuration);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 100, 51, 31));
        label = new QLabel(configuration);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 54, 31));
        D_n = new QLineEdit(configuration);
        D_n->setObjectName(QString::fromUtf8("D_n"));
        D_n->setEnabled(true);
        D_n->setGeometry(QRect(60, 100, 61, 31));
        checkBox = new QCheckBox(configuration);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 150, 111, 18));
        lineEdit = new QLineEdit(configuration);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 180, 71, 20));
        pushButton_2 = new QPushButton(configuration);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 180, 41, 20));
        widget = new QWidget(configuration);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(130, 10, 881, 421));
        pushButton_3 = new QPushButton(configuration);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 370, 111, 51));

        retranslateUi(configuration);

        QMetaObject::connectSlotsByName(configuration);
    } // setupUi

    void retranslateUi(QDialog *configuration)
    {
        configuration->setWindowTitle(QCoreApplication::translate("configuration", "\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("configuration", "\346\240\207\345\256\232\347\263\273\346\225\260", nullptr));
        label_3->setText(QCoreApplication::translate("configuration", "\347\263\273\346\225\260b", nullptr));
        label_5->setText(QCoreApplication::translate("configuration", "\347\263\273\346\225\260a", nullptr));
        b_n->setText(QCoreApplication::translate("configuration", "4", nullptr));
        a_n->setText(QCoreApplication::translate("configuration", "0.015", nullptr));
        pushButton->setText(QCoreApplication::translate("configuration", "\346\216\247\345\210\266\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("configuration", "\346\273\244\346\263\242\347\252\227\345\217\243", nullptr));
        label->setText(QCoreApplication::translate("configuration", "\347\264\257\345\212\240\346\254\241\346\225\260", nullptr));
        D_n->setText(QCoreApplication::translate("configuration", "3", nullptr));
        checkBox->setText(QCoreApplication::translate("configuration", "\344\277\235\345\255\230\345\205\211\350\260\261\346\225\260\346\215\256", nullptr));
        pushButton_2->setText(QCoreApplication::translate("configuration", "Path", nullptr));
        pushButton_3->setText(QCoreApplication::translate("configuration", "\344\277\235\345\255\230\351\205\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class configuration: public Ui_configuration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATION_H
