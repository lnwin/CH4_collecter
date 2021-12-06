#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    searchPort();
    CH4 =new CH4_chart;
    CH4->Chart_init(*ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::searchPort()
{
     ui->comboBox->clear();
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->comboBox->addItem(serial.portName());
            serial.close();

        }
    }
};

void MainWindow::on_pushButton_clicked()
{
     qDebug()<<"dffd";
};

