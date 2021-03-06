#ifndef MAINWINDOW_H
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
#include <QTimer>
#include <QDateTime>
#include <QInputDialog>
#include <sgolayfilt.h>
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
    void Delay_MSec(unsigned int msec);
signals:
    void sendFilePath(QString);
    void sendCof2serial(Parameter);
    void ToSerialThread();

private slots:
    void on_pushButton_clicked();
    void contextMenuRequest(QPoint pos);
    void rescaleGraph();
    void open_Configuration();   
    void onTimeOut();
    void on_pushButton_fileselect_clicked();
    void receiveSerialSIGFromConf(Parameter);
    void receiveDataFromS(double time,double data);
    void receiveSSigFromS(bool);

private:
    Ui::MainWindow *ui;
    CH4_chart *CH4;
    CH4_serial *CH4_sp;
    savethread *CH4_sv;
    configuration *COF;
    QThread *seriai_thread;


};
#endif // MAINWINDOW_H
