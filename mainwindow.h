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

signals:
    void sendFilePath(QString);
    void sendSaveSig(bool);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_fileselect_clicked();
    void on_checkBox_stateChanged(int);
    void contextMenuRequest(QPoint pos);
    void rescaleGraph();

private:
    Ui::MainWindow *ui;
    CH4_chart *CH4;
    CH4_serial *CH4_sp;
    savethread *CH4_sv;
};
#endif // MAINWINDOW_H
