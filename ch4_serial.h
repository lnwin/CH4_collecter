#ifndef CH4_SERIAL_H
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


class CH4_serial :public QThread
{
    Q_OBJECT
public:
    CH4_serial();
    QSerialPort *mainport;
    savethread  *CH4_SDT;
    void openPort(QString, Ui::MainWindow);
    void run();
    void anlyseData();
    void saveData_0(QString,QString);
    Max_Min coutMaxMin(double*,double);

signals:
    void sendData2Chart(QVector<double>,QVector<double>);
public slots:
    void readData();
    void receiveSaveSig(bool);
};

#endif // CH4_SERIAL_H
