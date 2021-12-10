#include "ch4_serial.h"
bool needread=false;
bool SAVEDATA_1=true;
CH4_serial::CH4_serial()
{
   mainport =new QSerialPort;
   CH4_SDT  =new savethread;
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
        ui.checkBox->setEnabled(false);
        ui.pushButton_fileselect->setEnabled(false);
        ui.pushButton->setText( QString::fromLocal8Bit("停止读取"));
        connect(mainport,SIGNAL(readyRead()),this,SLOT(readData()));
    }
     else
    {

        mainport->close();
        ui.comboBox->setEnabled(true);
        ui.checkBox->setEnabled(true);
        ui.pushButton_fileselect->setEnabled(true);
        ui.pushButton->setText( QString::fromLocal8Bit("开始读取"));
    }
};

void CH4_serial::readData()
{

    this->start();
};
void CH4_serial::anlyseData()
{

    if(SAVEDATA_1)
    {
     // saveData_0(QString path,QString filename);
    }
    else
    {

    }
}
void CH4_serial::run()
{
      anlyseData();

}
void CH4_serial::saveData_0(QString path,QString filename)
{
    CH4_SDT->saveData_1(path,filename);
};
void CH4_serial::receiveSaveSig(bool Y)
{
    SAVEDATA_1=Y;
};
