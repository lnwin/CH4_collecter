#ifndef CH4_SERIAL_H
#define CH4_SERIAL_H
#include <ui_mainwindow.h>
#include <QObject>
#include <qthread.h>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
class CH4_serial :public QThread
{
    Q_OBJECT
public:
    CH4_serial();
    QSerialPort *mainport;


    void readData();
    void run();
protected:


};

#endif // CH4_SERIAL_H
