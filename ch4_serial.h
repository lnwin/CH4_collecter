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
#include <sgolayfilt.h>
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
   int COCN_intercal;
   QString spectrumfilepath;
   QString COCNfilepath;
   QString portname;
   double USE_SMOOTH;
   double COCN_WIN;
   double USE_envelope;
   double order;
   double framelen;
};

Q_DECLARE_METATYPE(Parameter);

class CH4_serial :public QThread
{
    Q_OBJECT
public:
    CH4_serial();
    QSerialPort *mainport;
    savethread  *CH4_SDT;

    void run();
    void anlyseData();
    void saveData_0();
    Max_Min coutMaxMin(double*,double);
    float Hex2Dec_yrp(QByteArray hex);
    void Delay_MSec(unsigned int msec);
    void InitObject();

signals:
    void sendData2CChart(mwArray origin,mwArray afterP);
    void sendSSig2Conf(bool);
    void sendSSig2Main(bool);
    void sendData2M(double,double);
    void sendData2C( double *originData,double  *after_s,double  *after_s_e);
public slots:
    void readData();
    void receiveCof(Parameter);
    void receiveNeedSIG(bool);
     bool openPort();



};

#endif // CH4_SERIAL_H
