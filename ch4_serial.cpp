#include "ch4_serial.h"
bool needread=false;
CH4_serial::CH4_serial()
{
   mainport =new QSerialPort;
}
void CH4_serial::openPort(QString portName,Ui::MainWindow ui)
{
     if(!mainport->isOpen())
    {
        mainport->setPortName(portName);//设置串口名
        mainport->open(QIODevice::ReadWrite);//以读写方式打开串口
        mainport->setBaudRate(QSerialPort::Baud9600);//波特率
        mainport->setDataBits(QSerialPort::Data8);//数据位
        mainport->setParity(QSerialPort::NoParity);//校验位
        mainport->setStopBits(QSerialPort::OneStop);//停止位
        ui.comboBox->setEnabled(false);
        ui.pushButton->setText( QString::fromLocal8Bit("停止读取"));
        connect(mainport,SIGNAL(readyRead()),this,SLOT(readData()));
    }
     else
    {

        mainport->close();
        ui.comboBox->setEnabled(true);
        ui.pushButton->setText( QString::fromLocal8Bit("开始读取"));
    }
};

void CH4_serial::readData(){

    this->start();
};
void CH4_serial::anlyseData()
{
      qDebug()<<"buf";
}
void CH4_serial::run()
{
      anlyseData();

}
