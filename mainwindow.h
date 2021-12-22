﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <ch4_chart.h>
#include <ch4_serial.h>
#include <savethread.h>
#include <qfiledialog.h>
#include <smoothdata.h>
#include <configuration.h>
#include <data_process.h>
#include <QTimer>
#include <QDateTime>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void CH4Chart();
    void searchPort();
    void readConf();

signals:
    void sendFilePath(QString);
    void sendCof2serial(Parameter);
private slots:
    void on_pushButton_clicked();
    void contextMenuRequest(QPoint pos);
    void rescaleGraph();
    void open_Configuration();
    void open_Dataprocess();
    void onTimeOut();
    void on_pushButton_fileselect_clicked();

private:
    Ui::MainWindow *ui;
    CH4_chart *CH4;
    CH4_serial *CH4_sp;
    savethread *CH4_sv;
    configuration *COF;
    data_Process *DAP;

};
#endif // MAINWINDOW_H
