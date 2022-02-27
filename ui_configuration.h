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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_configuration
{
public:
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *COCN_WIN;
    QLabel *label;
    QLineEdit *add_lin;
    QLabel *label_4;
    QLineEdit *win_n;
    QLabel *label_6;
    QLineEdit *order;
    QLabel *label_7;
    QLineEdit *frameleng;
    QLineEdit *Spectrumline;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *ifsmooth;
    QCheckBox *ifenvelope;
    QCheckBox *ifSave;
    QPushButton *read_Button;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QWidget *widget;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QLineEdit *a_n;
    QLabel *label_3;
    QLineEdit *b_n;
    QPushButton *pushButton_3;
    QVBoxLayout *verticalLayout;
    QCustomPlot *chart_widget;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QPushButton *select_files;
    QPushButton *pushButton_4;
    QPushButton *start_process;

    void setupUi(QDialog *configuration)
    {
        if (configuration->objectName().isEmpty())
            configuration->setObjectName(QString::fromUtf8("configuration"));
        configuration->resize(1155, 526);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/001.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        configuration->setWindowIcon(icon);
        horizontalLayout_3 = new QHBoxLayout(configuration);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(1);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton = new QPushButton(configuration);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);


        verticalLayout_6->addLayout(verticalLayout_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(configuration);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        COCN_WIN = new QLineEdit(configuration);
        COCN_WIN->setObjectName(QString::fromUtf8("COCN_WIN"));

        formLayout->setWidget(0, QFormLayout::FieldRole, COCN_WIN);

        label = new QLabel(configuration);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        add_lin = new QLineEdit(configuration);
        add_lin->setObjectName(QString::fromUtf8("add_lin"));

        formLayout->setWidget(1, QFormLayout::FieldRole, add_lin);

        label_4 = new QLabel(configuration);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        win_n = new QLineEdit(configuration);
        win_n->setObjectName(QString::fromUtf8("win_n"));
        win_n->setEnabled(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, win_n);

        label_6 = new QLabel(configuration);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        order = new QLineEdit(configuration);
        order->setObjectName(QString::fromUtf8("order"));

        formLayout->setWidget(3, QFormLayout::FieldRole, order);

        label_7 = new QLabel(configuration);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        frameleng = new QLineEdit(configuration);
        frameleng->setObjectName(QString::fromUtf8("frameleng"));

        formLayout->setWidget(4, QFormLayout::FieldRole, frameleng);

        Spectrumline = new QLineEdit(configuration);
        Spectrumline->setObjectName(QString::fromUtf8("Spectrumline"));

        formLayout->setWidget(5, QFormLayout::LabelRole, Spectrumline);

        pushButton_2 = new QPushButton(configuration);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        formLayout->setWidget(5, QFormLayout::FieldRole, pushButton_2);


        verticalLayout_6->addLayout(formLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        ifsmooth = new QCheckBox(configuration);
        ifsmooth->setObjectName(QString::fromUtf8("ifsmooth"));

        verticalLayout_4->addWidget(ifsmooth);

        ifenvelope = new QCheckBox(configuration);
        ifenvelope->setObjectName(QString::fromUtf8("ifenvelope"));

        verticalLayout_4->addWidget(ifenvelope);

        ifSave = new QCheckBox(configuration);
        ifSave->setObjectName(QString::fromUtf8("ifSave"));

        verticalLayout_4->addWidget(ifSave);

        read_Button = new QPushButton(configuration);
        read_Button->setObjectName(QString::fromUtf8("read_Button"));

        verticalLayout_4->addWidget(read_Button);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox = new QGroupBox(configuration);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(12, 22, 91, 51));
        formLayout_2 = new QFormLayout(widget);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setHorizontalSpacing(1);
        formLayout_2->setVerticalSpacing(1);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        a_n = new QLineEdit(widget);
        a_n->setObjectName(QString::fromUtf8("a_n"));
        a_n->setEnabled(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, a_n);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_3);

        b_n = new QLineEdit(widget);
        b_n->setObjectName(QString::fromUtf8("b_n"));
        b_n->setEnabled(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, b_n);


        verticalLayout_5->addWidget(groupBox);

        pushButton_3 = new QPushButton(configuration);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_5->addWidget(pushButton_3);


        verticalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 3);
        verticalLayout_6->setStretch(2, 4);
        verticalLayout_6->setStretch(3, 4);

        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        chart_widget = new QCustomPlot(configuration);
        chart_widget->setObjectName(QString::fromUtf8("chart_widget"));

        verticalLayout->addWidget(chart_widget);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 9);

        verticalLayout_7->addLayout(horizontalLayout);

        textEdit = new QTextEdit(configuration);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_7->addWidget(textEdit);

        verticalLayout_7->setStretch(0, 4);
        verticalLayout_7->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView = new QTableView(configuration);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        select_files = new QPushButton(configuration);
        select_files->setObjectName(QString::fromUtf8("select_files"));
        select_files->setMinimumSize(QSize(0, 20));

        verticalLayout_2->addWidget(select_files);

        pushButton_4 = new QPushButton(configuration);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_2->addWidget(pushButton_4);

        start_process = new QPushButton(configuration);
        start_process->setObjectName(QString::fromUtf8("start_process"));
        start_process->setMinimumSize(QSize(0, 20));

        verticalLayout_2->addWidget(start_process);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(0, 4);
        horizontalLayout_2->setStretch(1, 1);

        horizontalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(configuration);

        QMetaObject::connectSlotsByName(configuration);
    } // setupUi

    void retranslateUi(QDialog *configuration)
    {
        configuration->setWindowTitle(QCoreApplication::translate("configuration", "\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
        pushButton->setText(QCoreApplication::translate("configuration", "\346\216\247\345\210\266\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("configuration", "\346\265\223\345\272\246\345\271\263\346\273\221", nullptr));
        label->setText(QCoreApplication::translate("configuration", "\347\264\257\345\212\240\346\254\241\346\225\260", nullptr));
        label_4->setText(QCoreApplication::translate("configuration", "\346\273\244\346\263\242\347\252\227\345\217\243", nullptr));
        win_n->setText(QCoreApplication::translate("configuration", "3", nullptr));
        label_6->setText(QCoreApplication::translate("configuration", "order", nullptr));
        label_7->setText(QCoreApplication::translate("configuration", "framelen", nullptr));
        pushButton_2->setText(QCoreApplication::translate("configuration", "Path", nullptr));
        ifsmooth->setText(QCoreApplication::translate("configuration", "\346\230\257\345\220\246\345\271\263\346\273\221", nullptr));
        ifenvelope->setText(QCoreApplication::translate("configuration", "\346\230\257\345\220\246\346\261\202\345\214\205\347\273\234", nullptr));
        ifSave->setText(QCoreApplication::translate("configuration", "\344\277\235\345\255\230\345\205\211\350\260\261\346\225\260\346\215\256", nullptr));
        read_Button->setText(QCoreApplication::translate("configuration", "\345\274\200\345\247\213\350\257\273\345\217\226\345\205\211\350\260\261\346\225\260\346\215\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("configuration", "\346\240\207\345\256\232\347\263\273\346\225\260", nullptr));
        label_5->setText(QCoreApplication::translate("configuration", "\347\263\273\346\225\260a", nullptr));
        a_n->setText(QCoreApplication::translate("configuration", "0.015", nullptr));
        label_3->setText(QCoreApplication::translate("configuration", "\347\263\273\346\225\260b", nullptr));
        b_n->setText(QCoreApplication::translate("configuration", "4", nullptr));
        pushButton_3->setText(QCoreApplication::translate("configuration", "\344\277\235\345\255\230\351\205\215\347\275\256", nullptr));
        select_files->setText(QCoreApplication::translate("configuration", "\346\211\271\351\207\217\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        pushButton_4->setText(QCoreApplication::translate("configuration", "\350\276\223\345\207\272\350\267\257\345\276\204", nullptr));
        start_process->setText(QCoreApplication::translate("configuration", "\345\274\200\345\247\213\345\244\204\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class configuration: public Ui_configuration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATION_H
