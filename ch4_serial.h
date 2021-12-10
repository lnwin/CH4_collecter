#ifndef CH4_SERIAL_H
#define CH4_SERIAL_H
#include <ui_mainwindow.h>
#include <QObject>
#include <qthread.h>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <savethread.h>
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

public slots:
    void readData();
    void receiveSaveSig(bool);

};

#endif // CH4_SERIAL_H
