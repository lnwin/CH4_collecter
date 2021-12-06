#ifndef CH4_SERIAL_H
#define CH4_SERIAL_H
#include <ui_mainwindow.h>
#include <QObject>
#include <qthread.h>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
class CH4_serial :public QThread
{
    Q_OBJECT
public:
    CH4_serial();
    QSerialPort *mainport;
    void openPort(QString, Ui::MainWindow);

    void run();
    void anlyseData();

public slots:
    void readData();


};

#endif // CH4_SERIAL_H
