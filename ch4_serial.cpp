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
        int elementCntA=500;//元素个数
        double  *originData=new double[elementCntA]; //一维数组，用于C++向 MATLAB数组传递数据
       // saveData_0(QString path,QString filename);
       // ***重要***smoothdata(int nargout, mwArray& y, mwArray& winsz, const mwArray& A, const mwArray& varargin); y为处理后输出的数据 A为需要输入的数据，varargin代表输入参数的个数，
        QString filename = QFileDialog::getOpenFileName();
        QFile datafile(filename);
        if(!datafile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<"Can't open the file!"<<endl;
        }
        int count_N=0;
        while(!datafile.atEnd())
        {
            QByteArray line = datafile.readLine();
            QString str(line);
            originData[count_N]=str.toDouble();
            count_N++;
        }

       // sgolay
        mwArray WINSZ(elementCntA,1,mxDOUBLE_CLASS, mxREAL);//需要和output纬度一样
        mwArray outPut(elementCntA,1,mxDOUBLE_CLASS, mxREAL);
        mwArray varargin(1);//输入参数的个数
        mwArray matrixA(elementCntA,1,mxDOUBLE_CLASS, mxREAL);//定义数组，行，列，double类型
        matrixA.SetData(originData,elementCntA); //将C++ 的一维数组arrayA存储到 MATLAB的二维数组matrixA
        smoothdata(1,outPut,WINSZ,matrixA,varargin);//
        double  *afterSmooth=new double[elementCntA];
       //  matrixA.GetData(,1);
       //  matrixB(0);

        mwArray d(10);
        mwArray up_01(elementCntA,1,mxDOUBLE_CLASS, mxREAL);
        mwArray lo_01(elementCntA,1,mxDOUBLE_CLASS, mxREAL);
        mwArray method("peak");
        envelope(2,up_01,lo_01,outPut,d,method);//通过测试
        double *mid_01=new double[elementCntA];
        double a,b;

        for (int j=0; j<elementCntA;j++)
        {

            a = up_01.Get(0,j+1);
            b = lo_01.Get(0,j+1);
            mid_01[j]=(a+b)/2;


        }
        double *B=new double[200];
        double *B1=new double[200];
        double *B2=new double[200];
        for(int j=150; j<350;j++)
        {
              B[j-150]=mid_01[j];
        }
        for(int j=0; j<100;j++)
        {
              B1[j]=B[j];

        }
        for(int j=0; j<100;j++)
        {
              B2[j]=B[j+100];
        }
        Max_Min MN_B;
        Max_Min MN_B1;
        Max_Min MN_B2;
        MN_B=coutMaxMin(B,200);
        MN_B1=coutMaxMin(B1,100);
        MN_B2=coutMaxMin(B2,100);
        MN_B.Max=(MN_B1.Max+MN_B2.Max)/2;
        double X = MN_B.Max-MN_B.Min;

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
Max_Min CH4_serial::coutMaxMin(double *dataIn,double n)
{
    Max_Min mn;
    mn.Max=dataIn[0];
    mn.Min=dataIn[0];
    for(int i=0;i<n;i++ )
    {


        if(dataIn[i]> mn.Max)
        {
           mn.Max =dataIn[i];
         // qDebug()<<Max;
        }
        if(dataIn[i]<mn.Min)
        {
          mn.Min=dataIn[i];
        }

    }
    return mn;

}
