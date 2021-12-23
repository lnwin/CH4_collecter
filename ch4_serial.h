﻿#ifndef CH4_SERIAL_H
#define CH4_SERIAL_H
#include <ui_mainwindow.h>
#include <QObject>
#include <qthread.h>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <savethread.h>
#include <smoothdata.h>
#include <envelope.h>
#include <QMetaType>
#include <QFile>
#include <QFileDialog>
#include <iostream>
#include <fstream>
struct Max_Min
{

    double Max;
    double Min;

};
Q_DECLARE_METATYPE(Max_Min);
struct Parameter
{
   double acc;
   double a;
   double b;
   double win_d;
   double saveSpectrum;
   double saveCOCN;
   double COCN_intercal;
   QString spectrumfilepath;
   QString COCNfilepath;
};

Q_DECLARE_METATYPE(Parameter);

class CH4_serial :public QThread
{
    Q_OBJECT
public:
    CH4_serial();
    QSerialPort *mainport;
    savethread  *CH4_SDT;
    bool openPort(QString, Ui::MainWindow);
    void run();
    void anlyseData();
    void saveData_0();
    Max_Min coutMaxMin(double*,double);

signals:
    void sendData2Chart(QVector<double>,QVector<double>);
    void sendSSig2Conf(bool);
public slots:
    void readData();
    void receiveCof(Parameter);


};

#endif // CH4_SERIAL_H
