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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_data_Process
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QCustomPlot *p_chart;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QPushButton *select_files;
    QPushButton *select_algorithm;
    QPushButton *start_process;

    void setupUi(QWidget *data_Process)
    {
        if (data_Process->objectName().isEmpty())
            data_Process->setObjectName(QString::fromUtf8("data_Process"));
        data_Process->resize(1146, 496);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/001.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        data_Process->setWindowIcon(icon);
        horizontalLayout_3 = new QHBoxLayout(data_Process);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(data_Process);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout->addWidget(tableView);

        p_chart = new QCustomPlot(data_Process);
        p_chart->setObjectName(QString::fromUtf8("p_chart"));

        horizontalLayout->addWidget(p_chart);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        textEdit = new QTextEdit(data_Process);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_2->addWidget(textEdit);

        select_files = new QPushButton(data_Process);
        select_files->setObjectName(QString::fromUtf8("select_files"));
        select_files->setMinimumSize(QSize(0, 50));

        horizontalLayout_2->addWidget(select_files);

        select_algorithm = new QPushButton(data_Process);
        select_algorithm->setObjectName(QString::fromUtf8("select_algorithm"));
        select_algorithm->setMinimumSize(QSize(0, 50));

        horizontalLayout_2->addWidget(select_algorithm);

        start_process = new QPushButton(data_Process);
        start_process->setObjectName(QString::fromUtf8("start_process"));
        start_process->setMinimumSize(QSize(0, 50));

        horizontalLayout_2->addWidget(start_process);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(data_Process);

        QMetaObject::connectSlotsByName(data_Process);
    } // setupUi

    void retranslateUi(QWidget *data_Process)
    {
        data_Process->setWindowTitle(QCoreApplication::translate("data_Process", "\346\225\260\346\215\256\345\244\204\347\220\206", nullptr));
        select_files->setText(QCoreApplication::translate("data_Process", "\346\211\271\351\207\217\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        select_algorithm->setText(QCoreApplication::translate("data_Process", "\345\244\204\347\220\206\351\205\215\347\275\256", nullptr));
        start_process->setText(QCoreApplication::translate("data_Process", "\345\274\200\345\247\213\345\244\204\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class data_Process: public Ui_data_Process {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_PROCESS_H
