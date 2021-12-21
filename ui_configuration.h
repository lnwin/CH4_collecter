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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_configuration
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *b_n;
    QLineEdit *window_n;
    QLineEdit *a_n;
    QPushButton *pushButton;
    QCheckBox *use_process;
    QLineEdit *filelineEdit;
    QPushButton *pushButton_fileselect;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QLabel *label;

    void setupUi(QDialog *configuration)
    {
        if (configuration->objectName().isEmpty())
            configuration->setObjectName(QString::fromUtf8("configuration"));
        configuration->resize(360, 291);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/win_icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        configuration->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(configuration);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(190, 250, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::SaveAll);
        groupBox = new QGroupBox(configuration);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 171, 131));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 92, 151, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(11, 44, 71, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(11, 67, 81, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(11, 21, 71, 16));
        b_n = new QLineEdit(groupBox);
        b_n->setObjectName(QString::fromUtf8("b_n"));
        b_n->setEnabled(false);
        b_n->setGeometry(QRect(90, 37, 68, 20));
        window_n = new QLineEdit(groupBox);
        window_n->setObjectName(QString::fromUtf8("window_n"));
        window_n->setEnabled(false);
        window_n->setGeometry(QRect(90, 60, 68, 20));
        a_n = new QLineEdit(groupBox);
        a_n->setObjectName(QString::fromUtf8("a_n"));
        a_n->setEnabled(false);
        a_n->setGeometry(QRect(90, 14, 68, 20));
        pushButton = new QPushButton(configuration);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 20, 161, 41));
        use_process = new QCheckBox(configuration);
        use_process->setObjectName(QString::fromUtf8("use_process"));
        use_process->setGeometry(QRect(200, 80, 101, 16));
        use_process->setChecked(true);
        filelineEdit = new QLineEdit(configuration);
        filelineEdit->setObjectName(QString::fromUtf8("filelineEdit"));
        filelineEdit->setEnabled(true);
        filelineEdit->setGeometry(QRect(10, 200, 251, 21));
        filelineEdit->setEchoMode(QLineEdit::Normal);
        filelineEdit->setDragEnabled(true);
        filelineEdit->setReadOnly(true);
        pushButton_fileselect = new QPushButton(configuration);
        pushButton_fileselect->setObjectName(QString::fromUtf8("pushButton_fileselect"));
        pushButton_fileselect->setGeometry(QRect(270, 200, 81, 23));
        checkBox = new QCheckBox(configuration);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(200, 110, 101, 16));
        comboBox = new QComboBox(configuration);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(270, 130, 69, 22));
        label = new QLabel(configuration);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 140, 54, 12));

        retranslateUi(configuration);
        QObject::connect(buttonBox, SIGNAL(accepted()), configuration, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), configuration, SLOT(reject()));

        QMetaObject::connectSlotsByName(configuration);
    } // setupUi

    void retranslateUi(QDialog *configuration)
    {
        configuration->setWindowTitle(QCoreApplication::translate("configuration", "\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("configuration", "\346\240\207\345\256\232\347\263\273\346\225\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("configuration", "\350\247\243\351\224\201", nullptr));
        label_3->setText(QCoreApplication::translate("configuration", "\347\263\273\346\225\260b", nullptr));
        label_4->setText(QCoreApplication::translate("configuration", "\345\271\263\346\273\221\347\252\227\345\217\243\347\263\273\346\225\260", nullptr));
        label_5->setText(QCoreApplication::translate("configuration", "\347\263\273\346\225\260a", nullptr));
        b_n->setText(QCoreApplication::translate("configuration", "4", nullptr));
        window_n->setText(QCoreApplication::translate("configuration", "3", nullptr));
        a_n->setText(QCoreApplication::translate("configuration", "0.015", nullptr));
        pushButton->setText(QCoreApplication::translate("configuration", "\345\274\200\345\220\257\346\277\200\345\205\211\345\231\250", nullptr));
        use_process->setText(QCoreApplication::translate("configuration", "\345\274\200\345\220\257\346\273\244\346\263\242\347\256\227\346\263\225", nullptr));
        pushButton_fileselect->setText(QCoreApplication::translate("configuration", "\351\200\211\346\213\251\345\255\230\345\202\250\350\267\257\345\276\204", nullptr));
        checkBox->setText(QCoreApplication::translate("configuration", "\345\274\200\345\220\257\347\264\257\345\212\240", nullptr));
        label->setText(QCoreApplication::translate("configuration", "\347\264\257\345\212\240\346\254\241\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class configuration: public Ui_configuration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATION_H
