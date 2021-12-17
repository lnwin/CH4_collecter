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
       // smoothdata(int nargout, mwArray& y, mwArray& winsz, const mwArray& A, const mwArray& varargin);
        int elementCntA=50;//元素个数
        double  *arrayA=new double[elementCntA]; //一维数组，用于C++向 MATLAB数组传递数据
        for (int j=0; j<50;j++)
        {
           arrayA[j]=j;

        }
       // sgolay
        mwArray WINSZ(5);
        mwArray Y(2);

        //arrayAxu 需要赋值
        mwArray matrixA(50,1,mxDOUBLE_CLASS, mxREAL);//定义数组，行，列，double类型
        mwArray matrixB(50,1,mxDOUBLE_CLASS, mxREAL);//定义数组，行，列，double类型
        matrixA.SetData(arrayA,elementCntA); //将C++ 的一维数组arrayA存储到 MATLAB的二维数组matrixA
       // smoothdata(1,Y,WINSZ,matrixB,matrixA);
       //  double  *arrayB;
       //  matrixB.GetData(arrayB,50);
        qDebug()<<arrayA[49];
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
