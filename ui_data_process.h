/********************************************************************************
** Form generated from reading UI file 'data_process.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_PROCESS_H
#define UI_DATA_PROCESS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_data_Process
{
public:
    QPushButton *select_files;
    QPushButton *start_process;
    QProgressBar *progressBar;
    QTableView *tableView;
    QTableView *tableView_2;
    QPushButton *select_algorithm;
    QTextEdit *textEdit;
    QCustomPlot *p_chart;

    void setupUi(QDialog *data_Process)
    {
        if (data_Process->objectName().isEmpty())
            data_Process->setObjectName(QString::fromUtf8("data_Process"));
        data_Process->resize(1059, 437);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/001.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        data_Process->setWindowIcon(icon);
        select_files = new QPushButton(data_Process);
        select_files->setObjectName(QString::fromUtf8("select_files"));
        select_files->setGeometry(QRect(720, 340, 101, 51));
        start_process = new QPushButton(data_Process);
        start_process->setObjectName(QString::fromUtf8("start_process"));
        start_process->setGeometry(QRect(930, 340, 121, 51));
        progressBar = new QProgressBar(data_Process);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 400, 1031, 23));
        progressBar->setValue(0);
        tableView = new QTableView(data_Process);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 20, 180, 311));
        tableView_2 = new QTableView(data_Process);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(210, 20, 180, 311));
        select_algorithm = new QPushButton(data_Process);
        select_algorithm->setObjectName(QString::fromUtf8("select_algorithm"));
        select_algorithm->setGeometry(QRect(830, 340, 91, 51));
        textEdit = new QTextEdit(data_Process);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 339, 691, 51));
        p_chart = new QCustomPlot(data_Process);
        p_chart->setObjectName(QString::fromUtf8("p_chart"));
        p_chart->setGeometry(QRect(400, 20, 651, 311));

        retranslateUi(data_Process);

        QMetaObject::connectSlotsByName(data_Process);
    } // setupUi

    void retranslateUi(QDialog *data_Process)
    {
        data_Process->setWindowTitle(QCoreApplication::translate("data_Process", "\346\225\260\346\215\256\345\244\204\347\220\206", nullptr));
        select_files->setText(QCoreApplication::translate("data_Process", "\346\211\271\351\207\217\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        start_process->setText(QCoreApplication::translate("data_Process", "\345\274\200\345\247\213\345\244\204\347\220\206", nullptr));
        select_algorithm->setText(QCoreApplication::translate("data_Process", "\345\244\204\347\220\206\351\205\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class data_Process: public Ui_data_Process {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_PROCESS_H
