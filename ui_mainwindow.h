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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

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
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *saveCOCN;
    QLabel *label_4;
    QComboBox *COCN_interval;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *COCN_filepath;
    QPushButton *pushButton_fileselect;
    QLabel *label_3;
    QLCDNumber *lcdNumber;
    QLabel *label_2;
    QLCDNumber *lcdNumber_2;
    QLabel *label_5;
    QCustomPlot *customPlot;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1157, 528);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/001.jpg"), QSize(), QIcon::Normal, QIcon::Off);
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
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(pushButton_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        saveCOCN = new QCheckBox(centralwidget);
        saveCOCN->setObjectName(QString::fromUtf8("saveCOCN"));
        saveCOCN->setChecked(true);

        horizontalLayout_2->addWidget(saveCOCN);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        COCN_interval = new QComboBox(centralwidget);
        COCN_interval->setObjectName(QString::fromUtf8("COCN_interval"));

        horizontalLayout_2->addWidget(COCN_interval);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        COCN_filepath = new QLineEdit(centralwidget);
        COCN_filepath->setObjectName(QString::fromUtf8("COCN_filepath"));
        COCN_filepath->setEnabled(true);
        COCN_filepath->setEchoMode(QLineEdit::Normal);
        COCN_filepath->setDragEnabled(true);
        COCN_filepath->setReadOnly(true);

        horizontalLayout_3->addWidget(COCN_filepath);

        pushButton_fileselect = new QPushButton(centralwidget);
        pushButton_fileselect->setObjectName(QString::fromUtf8("pushButton_fileselect"));

        horizontalLayout_3->addWidget(pushButton_fileselect);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(20);
        lcdNumber->setFont(font2);
        lcdNumber->setLayoutDirection(Qt::LeftToRight);
        lcdNumber->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(lcdNumber);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        lcdNumber_2 = new QLCDNumber(centralwidget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));

        horizontalLayout->addWidget(lcdNumber_2);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 4);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 7);
        horizontalLayout->setStretch(5, 1);
        horizontalLayout->setStretch(6, 2);

        verticalLayout_2->addLayout(horizontalLayout);

        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));

        verticalLayout_2->addWidget(customPlot);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 8);

        horizontalLayout_4->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1157, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(system_Set);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CH4_Monitor", nullptr));
        system_Set->setText(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\351\205\215\347\275\256||\346\226\207\344\273\266\345\244\204\347\220\206", nullptr));
        actiondd->setText(QCoreApplication::translate("MainWindow", "\345\205\211\350\260\261", nullptr));
        data_process->setText(QCoreApplication::translate("MainWindow", "\346\211\271\351\207\217\345\244\204\347\220\206\346\225\260\346\215\256", nullptr));
        actiond->setText(QCoreApplication::translate("MainWindow", "d", nullptr));
        data_Process->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\211\271\351\207\217\345\244\204\347\220\206", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\350\256\276\345\244\207", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        saveCOCN->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\255\230\345\202\250\351\227\264\351\232\224", nullptr));
        pushButton_fileselect->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\255\230\345\202\250\350\267\257\345\276\204", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\266\351\227\264", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\265\223\345\272\246", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\345\220\216\345\217\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
