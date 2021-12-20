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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QLineEdit *filelineEdit;
    QPushButton *pushButton_fileselect;
    QCustomPlot *customPlot;
    QCheckBox *use_process;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1060, 521);
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
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(50, 410, 81, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 410, 41, 16));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 370, 41, 16));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 440, 121, 51));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 350, 121, 16));
        checkBox->setChecked(true);
        filelineEdit = new QLineEdit(centralwidget);
        filelineEdit->setObjectName(QString::fromUtf8("filelineEdit"));
        filelineEdit->setEnabled(true);
        filelineEdit->setGeometry(QRect(10, 370, 101, 21));
        filelineEdit->setEchoMode(QLineEdit::Normal);
        filelineEdit->setDragEnabled(true);
        filelineEdit->setReadOnly(true);
        pushButton_fileselect = new QPushButton(centralwidget);
        pushButton_fileselect->setObjectName(QString::fromUtf8("pushButton_fileselect"));
        pushButton_fileselect->setGeometry(QRect(115, 370, 21, 23));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(150, 10, 901, 481));
        use_process = new QCheckBox(centralwidget);
        use_process->setObjectName(QString::fromUtf8("use_process"));
        use_process->setGeometry(QRect(10, 160, 101, 16));
        use_process->setChecked(true);
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        system_Set->setText(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
        actiondd->setText(QCoreApplication::translate("MainWindow", "\345\205\211\350\260\261", nullptr));
        data_process->setText(QCoreApplication::translate("MainWindow", "\346\211\271\351\207\217\345\244\204\347\220\206\346\225\260\346\215\256", nullptr));
        actiond->setText(QCoreApplication::translate("MainWindow", "d", nullptr));
        data_Process->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\211\271\351\207\217\345\244\204\347\220\206", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", nullptr));
        label_2->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\257\273\345\217\226", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        pushButton_fileselect->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        use_process->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\220\257\346\273\244\346\263\242\347\256\227\346\263\225", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\244\204\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
