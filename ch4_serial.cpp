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
        ui.use_process->setEnabled(false);
        ui.pushButton_fileselect->setEnabled(false);
        ui.pushButton->setText("停止读取");
        connect(mainport,SIGNAL(readyRead()),this,SLOT(readData()));
        anlyseData();



    }
     else
    {

        mainport->close();
        ui.comboBox->setEnabled(true);
        ui.checkBox->setEnabled(true);
        ui.use_process->setEnabled(true);
        ui.pushButton_fileselect->setEnabled(true);
        ui.pushButton->setText("开始读取");
    }
};

void CH4_serial::readData()
{

    this->start();
};

   // mwArray matrixA(10,10,mxDOUBLE_CLASS, mxREAL);//定义数组，行，列，double类型

void CH4_serial::anlyseData()
{

    if(SAVEDATA_1)
    {
       // saveData_0(QString path,QString filename);
       // smoothdata(int nargout, mwArray& y, mwArray& winsz, const mwArray& A, const mwArray& varargin); y为处理后输出的数据 A为需要输入的数据，varargin代表输入参数的个数，
        int elementCntA=20;//元素个数
        double  *originData=new double[elementCntA]; //一维数组，用于C++向 MATLAB数组传递数据
       // for (int j=0; j<50;j++)
       // {
       //    arrayA[j]=j;
           originData[0]=36967;
           originData[1]=36964.5;
           originData[2]=36828;
           originData[3]=36677.5;
           originData[4]= 36602;
           originData[5]=36619;
           originData[6]=36632.5;
           originData[7]= 36623.5;
           originData[8]= 36760;
           originData[9]=36828.5;
           originData[10]= 36970;
           originData[11]= 36971;
           originData[12]= 36822;
           originData[13]=36729;
           originData[14]= 37170.5;
           originData[15]= 36971;
           originData[16]= 36766;
           originData[17]= 36379.5;
           originData[18]= 36596;
           originData[19]= 36228.5;


     //   }
       // sgolay
        mwArray WINSZ(20,1,mxDOUBLE_CLASS, mxREAL);//需要和output纬度一样
        mwArray outPut(20,1,mxDOUBLE_CLASS, mxREAL);
        mwArray varargin(1);//输入参数的个数
        mwArray matrixA(20,1,mxDOUBLE_CLASS, mxREAL);//定义数组，行，列，double类型
        matrixA.SetData(originData,elementCntA); //将C++ 的一维数组arrayA存储到 MATLAB的二维数组matrixA
        smoothdata(1,outPut,WINSZ,matrixA,varargin);//
        double  *afterSmooth=new double[elementCntA];
       //  matrixA.GetData(,1);
       //  matrixB(0);
        for (int j=0; j<20;j++)
        {
            double a;
            a= outPut.Get(0,j+1);
            afterSmooth[j]=outPut.Get(0,j+1);
            qDebug()<<a;

        }


        //
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
