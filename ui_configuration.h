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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <qcustomplot.h>

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
    QLabel *label_4;
    QLabel *label;
    QLineEdit *win_n;
    QCheckBox *ifSave;
    QLineEdit *Spectrumline;
    QPushButton *pushButton_2;
    QCustomPlot *chart_widget;
    QPushButton *pushButton_3;
    QLineEdit *add_lin;
    QPushButton *read_Button;
    QPushButton *start_process;
    QPushButton *select_files;
    QTextEdit *textEdit;
    QTableView *tableView;
    QPushButton *pushButton_4;
    QCheckBox *ifsmooth;
    QLineEdit *COCN_WIN;
    QLabel *label_2;
    QCheckBox *ifenvelope;

    void setupUi(QDialog *configuration)
    {
        if (configuration->objectName().isEmpty())
            configuration->setObjectName(QString::fromUtf8("configuration"));
        configuration->resize(1155, 489);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/001.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        configuration->setWindowIcon(icon);
        groupBox = new QGroupBox(configuration);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 290, 111, 71));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(12, 45, 30, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(12, 22, 30, 16));
        b_n = new QLineEdit(groupBox);
        b_n->setObjectName(QString::fromUtf8("b_n"));
        b_n->setEnabled(true);
        b_n->setGeometry(QRect(48, 45, 51, 16));
        a_n = new QLineEdit(groupBox);
        a_n->setObjectName(QString::fromUtf8("a_n"));
        a_n->setEnabled(true);
        a_n->setGeometry(QRect(48, 22, 51, 16));
        pushButton = new QPushButton(configuration);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 111, 41));
        label_4 = new QLabel(configuration);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 130, 51, 21));
        label = new QLabel(configuration);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 101, 54, 20));
        win_n = new QLineEdit(configuration);
        win_n->setObjectName(QString::fromUtf8("win_n"));
        win_n->setEnabled(true);
        win_n->setGeometry(QRect(60, 130, 61, 21));
        ifSave = new QCheckBox(configuration);
        ifSave->setObjectName(QString::fromUtf8("ifSave"));
        ifSave->setGeometry(QRect(10, 210, 101, 18));
        Spectrumline = new QLineEdit(configuration);
        Spectrumline->setObjectName(QString::fromUtf8("Spectrumline"));
        Spectrumline->setGeometry(QRect(10, 230, 71, 20));
        pushButton_2 = new QPushButton(configuration);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 230, 41, 20));
        chart_widget = new QCustomPlot(configuration);
        chart_widget->setObjectName(QString::fromUtf8("chart_widget"));
        chart_widget->setGeometry(QRect(130, 10, 841, 411));
        pushButton_3 = new QPushButton(configuration);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 370, 111, 51));
        add_lin = new QLineEdit(configuration);
        add_lin->setObjectName(QString::fromUtf8("add_lin"));
        add_lin->setGeometry(QRect(60, 99, 61, 21));
        read_Button = new QPushButton(configuration);
        read_Button->setObjectName(QString::fromUtf8("read_Button"));
        read_Button->setGeometry(QRect(10, 250, 111, 31));
        start_process = new QPushButton(configuration);
        start_process->setObjectName(QString::fromUtf8("start_process"));
        start_process->setGeometry(QRect(980, 430, 171, 50));
        start_process->setMinimumSize(QSize(0, 50));
        select_files = new QPushButton(configuration);
        select_files->setObjectName(QString::fromUtf8("select_files"));
        select_files->setGeometry(QRect(980, 320, 171, 50));
        select_files->setMinimumSize(QSize(0, 50));
        textEdit = new QTextEdit(configuration);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 430, 961, 51));
        tableView = new QTableView(configuration);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(980, 10, 171, 301));
        pushButton_4 = new QPushButton(configuration);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(980, 380, 171, 41));
        ifsmooth = new QCheckBox(configuration);
        ifsmooth->setObjectName(QString::fromUtf8("ifsmooth"));
        ifsmooth->setGeometry(QRect(10, 160, 71, 21));
        COCN_WIN = new QLineEdit(configuration);
        COCN_WIN->setObjectName(QString::fromUtf8("COCN_WIN"));
        COCN_WIN->setGeometry(QRect(60, 65, 61, 20));
        label_2 = new QLabel(configuration);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 65, 54, 21));
        ifenvelope = new QCheckBox(configuration);
        ifenvelope->setObjectName(QString::fromUtf8("ifenvelope"));
        ifenvelope->setGeometry(QRect(10, 185, 81, 18));

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
        win_n->setText(QCoreApplication::translate("configuration", "3", nullptr));
        ifSave->setText(QCoreApplication::translate("configuration", "\344\277\235\345\255\230\345\205\211\350\260\261\346\225\260\346\215\256", nullptr));
        pushButton_2->setText(QCoreApplication::translate("configuration", "Path", nullptr));
        pushButton_3->setText(QCoreApplication::translate("configuration", "\344\277\235\345\255\230\351\205\215\347\275\256", nullptr));
        read_Button->setText(QCoreApplication::translate("configuration", "\345\274\200\345\247\213\350\257\273\345\217\226\345\205\211\350\260\261\346\225\260\346\215\256", nullptr));
        start_process->setText(QCoreApplication::translate("configuration", "\345\274\200\345\247\213\345\244\204\347\220\206", nullptr));
        select_files->setText(QCoreApplication::translate("configuration", "\346\211\271\351\207\217\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        pushButton_4->setText(QCoreApplication::translate("configuration", "\350\276\223\345\207\272\350\267\257\345\276\204", nullptr));
        ifsmooth->setText(QCoreApplication::translate("configuration", "\346\230\257\345\220\246\345\271\263\346\273\221", nullptr));
        label_2->setText(QCoreApplication::translate("configuration", "\346\265\223\345\272\246\345\271\263\346\273\221", nullptr));
        ifenvelope->setText(QCoreApplication::translate("configuration", "\346\230\257\345\220\246\346\261\202\345\214\205\347\273\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class configuration: public Ui_configuration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATION_H
