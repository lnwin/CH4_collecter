﻿#include "ch4_serial.h"
#include <mutex>
std::mutex MUTEX;
bool needread=false;
bool cNeedData;
double use_smooth;
double acc=0,a_n=0.0015,b_n=4,win_n=3,COCN;
QString spectrumfilepath,COCNfilepath;
double saveSpectrum,saveCOCN,COCN_interval;
QList <QString> COCN_data;
QList <QString> sp_data;
QList <QString> sp_data_AP;
QString saveTime;
QByteArray FBuffer;

double *accBuffer=new double[500];
double localAcc=0;
CH4_serial::CH4_serial()
{
   mainport =new QSerialPort;
   CH4_SDT  =new savethread;
}
bool CH4_serial::openPort(QString portName,Ui::MainWindow ui)
{
     if(!mainport->isOpen())
    {
        mainport->setPortName(portName);//设置串口名
        mainport->open(QIODevice::ReadWrite);//以读写方式打开串口
        mainport->setBaudRate(QSerialPort::Baud115200);//波特率
        mainport->setDataBits(QSerialPort::Data8);//数据位
        mainport->setParity(QSerialPort::NoParity);//校验位
        mainport->setStopBits(QSerialPort::OneStop);//停止位
        ui.comboBox->setEnabled(false);
        ui.pushButton->setText("停止读取");
        ui.pushButton_fileselect->setEnabled(false);
        ui.saveCOCN->setEnabled(false);
        connect(mainport,SIGNAL(readyRead()),this,SLOT(readData()));
        //anlyseData();
        emit sendSSig2Conf(true);
        return true;



    }
     else
    {

        mainport->close();
        ui.comboBox->setEnabled(true);
        ui.pushButton_fileselect->setEnabled(true);
        ui.saveCOCN->setEnabled(true);
        ui.pushButton->setText("开始读取");
        emit sendSSig2Conf(false);
        FBuffer.clear();
        return false;

    }


};

void CH4_serial::readData()
{



    QByteArray serialBuffer;
    serialBuffer=mainport->readAll();
    // if(!serialBuffer.isEmpty()&&(QString(serialBuffer.at(0))=="0xaa")&&(serialBuffer.length()==1012))
     if(!serialBuffer.isEmpty())
     {
         //qDebug()<<"get number";
           FBuffer.append(serialBuffer);
           if((FBuffer.length()==1012))
        {
              qDebug()<<"number=========1012";
             if(quint8(FBuffer.at(0))==170)
        {
            double *originBuffer=new double[500];
            FBuffer.remove(0,9);

         for(int i=0;i<1000;i++)
         {

            originBuffer[i/2] = quint8(FBuffer[i])*256+quint8(FBuffer[i+1]);
            i=i+1;
         }

         if((localAcc<acc)&&(acc!=0))
         {
            for(int i=0;i<500;i++)
            {

                accBuffer[i]+=originBuffer[i];

            }
            localAcc++;
         }
         if(localAcc==acc)
         {
             for(int i=0;i<500;i++)
             {

                 accBuffer[i]=accBuffer[i]/localAcc;

             }

             this->start();
             localAcc=0;
         }


            FBuffer.clear();
          }
               else
               {
                   FBuffer.clear();
                   qDebug()<<"---qingkongg---";

               }
       }

     }
     else
     {
        // FBuffer
     }




};
void CH4_serial::anlyseData()
{


        COCN=0;
        sp_data.clear();
        sp_data_AP.clear();
        int elementCntA=500;//元素个数
       // double  *originData=new double[elementCntA]; //一维数组，用于C++向 MATLAB数组传递数据
        double  *after_s=new double[elementCntA];
       // saveData_0(QString path,QString filename);
       // ***重要***smoothdata(int nargout, mwArray& y, mwArray& winsz, const mwArray& A, const mwArray& varargin); y为处理后输出的数据 A为需要输入的数据，varargin代表输入参数的个数，
       // sgolay
        mwArray WINSZ(elementCntA,1,mxDOUBLE_CLASS, mxREAL);//需要和output纬度一样
        mwArray outPut(elementCntA,1,mxDOUBLE_CLASS, mxREAL);
        mwArray varargin(1);//输入参数的个数
        mwArray matrixA(elementCntA,1,mxDOUBLE_CLASS, mxREAL);//定义数组，行，列，double类型
        matrixA.SetData(accBuffer,elementCntA); //将C++ 的一维数组arrayA存储到 MATLAB的二维数组matrixA
        if(use_smooth==1)
        {
            smoothdata(1,outPut,WINSZ,matrixA,varargin);//
            for (int j=0; j<elementCntA;j++)
            {

                after_s[j]=outPut.Get(0,j+1);

            }
        }




        mwArray d(win_n);//串窗口平滑参数
        mwArray up_01(elementCntA,1,mxDOUBLE_CLASS, mxREAL);
        mwArray lo_01(elementCntA,1,mxDOUBLE_CLASS, mxREAL);
        mwArray method("peak");
        if(use_smooth==1)
        {
            envelope(2,up_01,lo_01,outPut,d,method);//通过测试
        }
        else
        {
            envelope(2,up_01,lo_01,matrixA,d,method);//通过测试
        }


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
        COCN = (a_n*X)+b_n;
        qDebug()<<COCN;
        //==============================================
        if(cNeedData)
        {
            emit sendData2C(accBuffer,after_s,mid_01);
            Delay_MSec(50);

        }

        //==============================================
        double nowTime = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;             
            emit sendData2M(nowTime,COCN);        
        //==============================================
        COCN_data.clear();
        QDateTime datatime =QDateTime::currentDateTime();
        QString timeString =datatime.toString("HH:mm:ss");
        COCN_data.append(timeString);
        COCN_data.append(QString::number(COCN));

        if((saveSpectrum!=0)||(saveCOCN!=0))
        {
            for(int i=0;i<500;i++)
            {
                 sp_data.append(QString::number(accBuffer[i]));
                 sp_data_AP.append(QString::number(mid_01[i]));
            }
            Delay_MSec(50);
            saveData_0();

        }
        for(int i=0;i<500;i++)
        {
            accBuffer[i]=0;            

        }




}
void CH4_serial::run()
{
   // MUTEX.lock();
    anlyseData();
   // MUTEX.unlock();


}
void CH4_serial::saveData_0()
{
    QDateTime datatime =QDateTime::currentDateTime();
    QString saveTime =datatime.toString("yyyy-MM-dd-HH-mm-ss");

    CH4_SDT->saveData_1(saveCOCN,saveSpectrum,COCN_interval,COCN_data,sp_data,sp_data_AP,spectrumfilepath,COCNfilepath,saveTime);

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
void CH4_serial::receiveCof(Parameter PM)
{
    acc=PM.acc+1;
    a_n=PM.a;
    b_n=PM.b;
    win_n=PM.win_d;
    spectrumfilepath=PM.spectrumfilepath;
    saveSpectrum=PM.saveSpectrum;
    saveCOCN =PM.saveCOCN;
    COCNfilepath=PM.COCNfilepath;
    COCN_interval =PM.COCN_intercal;
    use_smooth=PM.USE_SMOOTH;
    //qDebug()<<use_smooth;
}
void CH4_serial::receiveNeedSIG(bool need)
{
    cNeedData=need;

};
float CH4_serial::Hex2Dec_yrp(QByteArray hex)
 {
    bool ok;
    float finaldata;
//    QByteArray zz;
//    zz.append(hex.at(1));
//    zz.append(hex.at(0));
//    int a = zz.toHex().toInt(&ok,16);
 //   int b = zz.mid(0,1).toHex().toInt(&ok,16);
    int a = hex.toHex().toInt(&ok,16);
    int b = hex.mid(0,1).toHex().toInt(&ok,16);
    QString bin =QString::number(a,2);
    int datalength =bin.length();
    if(b>=128)
 {

           for (int i=0;i<datalength;i++)
           {
               if(bin[i]=="0")
               {
                   bin[i]='1';
               }
               else
               {
                   bin[i]='0';
               }

           }

           finaldata = (float)(-(bin.toInt(&ok,2)+1));
           return finaldata;

     }
    else
    {
          finaldata = (float)((bin.toInt(&ok,2)));
          return finaldata;
    }
 };
void CH4_serial::Delay_MSec(unsigned int msec)
{

        QTime _Timer = QTime::currentTime().addMSecs(msec);

        while( QTime::currentTime() < _Timer )

        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);

};
