/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *system_Set;
    QAction *actiondd;
    QAction *data_process;
    QAction *actiond;
    QAction *data_Process;
    QWidget *centralwidget;
    QCustomPlot *customPlot;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QLabel *label_3;
    QLCDNumber *lcdNumber_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1060, 521);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/win_icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(true);
        system_Set = new QAction(MainWindow);
        system_Set->setObjectName(QString::fromUtf8("system_Set"));
        actiondd = new QAction(MainWindow);
        actiondd->setObjectName(QString::fromUtf8("actiondd"));
        data_process = new QAction(MainWindow);
        data_process->setObjectName(QString::fromUtf8("data_process"));
        actiond = new QAction(MainWindow);
        actiond->setObjectName(QString::fromUtf8("actiond"));
        data_Process = new QAction(MainWindow);
        data_Process->setObjectName(QString::fromUtf8("data_Process"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(10, 50, 1041, 441));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(570, 0, 71, 47));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label_2->setFont(font1);
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(90, 0, 281, 50));
        lcdNumber->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(20);
        lcdNumber->setFont(font2);
        lcdNumber->setLayoutDirection(Qt::LeftToRight);
        lcdNumber->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 0, 71, 47));
        label_3->setFont(font1);
        lcdNumber_2 = new QLCDNumber(centralwidget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(650, 0, 101, 50));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(790, 0, 251, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(comboBox);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(pushButton);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1060, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(system_Set);
        menu_2->addAction(data_Process);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CH4_Monitor", nullptr));
        system_Set->setText(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
        actiondd->setText(QCoreApplication::translate("MainWindow", "\345\205\211\350\260\261", nullptr));
        data_process->setText(QCoreApplication::translate("MainWindow", "\346\211\271\351\207\217\345\244\204\347\220\206\346\225\260\346\215\256", nullptr));
        actiond->setText(QCoreApplication::translate("MainWindow", "d", nullptr));
        data_Process->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\211\271\351\207\217\345\244\204\347\220\206", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\265\223\345\272\246", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\266\351\227\264", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\257\273\345\217\226", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\244\204\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
