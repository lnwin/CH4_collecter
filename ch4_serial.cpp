#include "ch4_serial.h"
#include <mutex>

std::mutex MUTEX;
bool needread=false;
bool cNeedData;
double use_smooth;
double use_envelope;
double order,framleng;
double acc=0,a_n=0.0015,b_n=4,win_n=3,COCN;
QString spectrumfilepath,COCNfilepath;
double saveSpectrum,saveCOCN,COCN_interval,cocn_win,cocn_win_count=0;
QList <double> COCN_data_befor_win;
QList <QString> COCN_data;
QList <QString> COCN_data_after;
QList <QString> sp_data;
QList <QString> sp_channel_data;
QList <QString> sp_data_AP;
QString saveTime;
QByteArray FBuffer;
QString Serial_Port_Number;
double *accBuffer=new double[500];
double *accBuffer_1=new double[500];
double localAcc=0;
bool obiect_exist=false;
bool first_count=true;
bool ADclock=false;
CH4_serial::CH4_serial()
{
  // Serial_Port_Number=serialname;
  // qDebug()<<"主界面"<<QThread::currentThread();
    InitObject();
    getADclock->setInterval(1000);
    connect(getADclock, SIGNAL(timeout()), this, SLOT(onTimeOut()));

}
void CH4_serial::InitObject()
{

    CH4_SDT  =new savethread;

}

bool CH4_serial::openPort()
{

       char serial[15] = { 0 };
        BYTE byVerified;
        if (byDevIndex != 0xFF)
        {
            if (myADCCfg.byTrigOptions & 0x80)   //trig mode
            {
                myADCCfg.byTrigOptions &= 0x7F;

            }
            if (M3F20xm_CloseDevice(byDevIndex) == false)
            {
                QMessageBox msgBox ;
               // msgBox.setIcon(QMessageBox::Icon::Warning);
                msgBox.setWindowIcon(QIcon(":/image/image/001.jpg"));
                msgBox.setText("关闭设备失败!");
                msgBox.exec();


            }
            else
            {

                emit sendSSig2Conf(false);
                emit sendSSig2Main(false);
            }
            byDevIndex = 0xFF;
        }
        else
        {
            byDevIndex = M3F20xm_OpenDevice();
            if (byDevIndex == 0xFF)
            {
                QMessageBox msgBox ;
               // msgBox.setIcon(QMessageBox::Icon::Warning);
                msgBox.setWindowIcon(QIcon(":/image/image/001.jpg"));
                msgBox.setText("打开设备失败!");
                msgBox.exec();

                emit sendSSig2Conf(false);
                emit sendSSig2Main(false);

                return false;


            }
            else
            {

                if (!M3F20xm_Verify(byDevIndex, &byVerified))
                {
                    QMessageBox msgBox ;
                   // msgBox.setIcon(QMessageBox::Icon::Warning);
                    msgBox.setWindowIcon(QIcon(":/image/image/001.jpg"));
                    msgBox.setText("设备认证失败!");
                    msgBox.exec();
                    M3F20xm_CloseDevice(byDevIndex);
                    byDevIndex = 0xFF;

                }

                if (byVerified)
                {
                    M3F20xm_ADCGetConfig(byDevIndex, &myADCCfg);
                    if (myADCCfg.byADCOptions & 0x10)
                        MaxVol = 10;
                    else
                        MaxVol = 5;
                    emit sendSSig2Conf(true);
                    emit sendSSig2Main(true);
                   // qDebug()<<"串口已打开"<<QThread::currentThread();
                   // qDebug()<<mainport->isOpen();
                     M3F20xm_GetSerialNo(byDevIndex, serial);
                     setADconf();

                    return true;

                }

              //  SetWindowText(CString(serial));

            }
        }




};
void CH4_serial::startADC()
{
    if (M3F20xm_ADCStart(byDevIndex))
        {
            myADCCfg.dwCycleCnt = 0;
            myADCCfg.byTrigOptions |= 0x80;

        }
}
void CH4_serial::setADconf()
{


    ADC_CONFIG tmpcfg;
    BYTE index;
    memcpy(&tmpcfg, &myADCCfg, sizeof(ADC_CONFIG));

//
    qDebug()<<tmpcfg.byADCOptions;






        tmpcfg.wTrigSize = 3072;

        tmpcfg.dwMaxCycles = 500;

        tmpcfg.wPeriod = 1000;
        tmpcfg.byADCOptions &= 0xC8;
        index = 0<< 5;
        tmpcfg.byADCOptions += index;
        index = 0 ;//rangge
        index = index << 4;
        tmpcfg.byADCOptions += index;
        index = 0;//os
        tmpcfg.byADCOptions += index;
//        index = 0;//OS
//        tmpcfg.byADCOptions += index;
        index = 6;//trig mode  2=both
       // index += 0<< 3;

        tmpcfg.byTrigOptions = index;
//        index = 0;
//        tmpcfg.byTrigOptions += index;
        if (M3F20xm_ADCSetConfig(byDevIndex, &tmpcfg))
        {

            memcpy(&myADCCfg, &tmpcfg, sizeof(ADC_CONFIG));
            if (myADCCfg.byADCOptions & 0x10)
                MaxVol = 10;
            else
                MaxVol = 5;
        }
        else
        {
            QMessageBox msgBox ;
           // msgBox.setIcon(QMessageBox::Icon::Warning);
            msgBox.setWindowIcon(QIcon(":/image/image/001.jpg"));
            msgBox.setText("设置失败!");
            msgBox.exec();
        }
}
void CH4_serial::readData()
{
    if(!ADclock)
    {
        getADclock->start();
        emit sendSADSig2Main(true);
        ADclock=true;

    }
    else
    {
        getADclock->stop();
        emit sendSADSig2Main(false);
        ADclock=false;
    }
}
void CH4_serial::anlyseData()
{


        COCN=0;
        sp_data.clear();
        sp_data_AP.clear();
        sp_channel_data.clear();
        int elementCntA=500;//元素个数
       // double  *originData=new double[elementCntA]; //一维数组，用于C++向 MATLAB数组传递数据
        double  *after_s=new double[elementCntA];
        double *mid_01=new double[elementCntA];
        double  *AK=new double[elementCntA];
       // saveData_0(QString path,QString filename);
       //***重要***smoothdata(int nargout, mwArray& y, mwArray& winsz, const mwArray& A, const mwArray& varargin); y为处理后输出的数据 A为需要输入的数据，varargin代表输入参数的个数，

        mwArray WINSZ(elementCntA,1,mxDOUBLE_CLASS, mxREAL);//需要和output纬度一样
        mwArray outPut(elementCntA,1,mxDOUBLE_CLASS, mxREAL);
        mwArray varargin(1);//输入参数的个数
        mwArray Order(order);//输入参数的个数
        mwArray framelen(framleng);//输入参数的个数
        mwArray dim(1);
      // char str[1] = "";
      //或 CString str = "abcd"
      //mwArray mwA(str);
        mwArray weights(1,31,mxDOUBLE_CLASS, mxREAL);
       // mwArray weights(str);
        mwArray matrixA(elementCntA,1,mxDOUBLE_CLASS, mxREAL);//定义数组，行，列，double类型
        mwArray up_01(elementCntA,1,mxDOUBLE_CLASS, mxREAL);
        mwArray lo_01(elementCntA,1,mxDOUBLE_CLASS, mxREAL);
        mwArray d(win_n);//串窗口平滑参数
        mwArray method("peak");
        double a[31] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};

        weights.SetData(a,31);//将C++ 的一维数组arrayA存储到 MATLAB的二维数组matrixA
        matrixA.SetData(accBuffer,elementCntA);//将C++ 的一维数组arrayA存储到 MATLAB的二维数组matrixA
        sgolayfilt(1,outPut,matrixA,Order,framelen,weights,dim);

        for (int j=0; j<elementCntA;j++)
        {
            after_s[j]=outPut.Get(0,j+1);
           // qDebug()<<after_s[j];
        }
        double *B=new double[40];
        double *B1=new double[50];
        double *B2=new double[60];
        for(int j=120; j<160;j++)
        {
              B[j-120]=after_s[j];
        }
        for(int j=180; j<230;j++)
        {
              B1[j-180]=after_s[j];

        }
        for(int j=40; j<100;j++)
        {
              B2[j-40]=after_s[j];
        }
        Max_Min MN_B;
        Max_Min MN_B1;
        Max_Min MN_B2;
        MN_B=coutMaxMin(B,40);
        MN_B1=coutMaxMin(B1,50);
        MN_B2=coutMaxMin(B2,60);
        MN_B.Min=(MN_B1.Min+MN_B2.Min)/2;
        double X = MN_B.Max-MN_B.Min;
        COCN = (a_n*X)+b_n;
        //COCN = MN_B.Max-MN_B.Min;
        emit sendData2C(accBuffer,after_s,accBuffer_1);

/*
        if((use_smooth==1)&&(use_envelope==1))
        {
            smoothdata(1,outPut,WINSZ,matrixA,varargin);//
            for (int j=0; j<elementCntA;j++)
            {

                after_s[j]=outPut.Get(0,j+1);

            }
            envelope(2,up_01,lo_01,outPut,d,method);//通过测试

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
            if(cNeedData)
            {
                emit sendData2C(accBuffer,after_s,mid_01);

            }

        }
        else if((use_smooth!=1)&&(use_envelope!=1))
        {
            double *B=new double[200];
            double *B1=new double[200];
            double *B2=new double[200];
            for(int j=150; j<350;j++)
            {
                  B[j-150]=accBuffer[j];
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
            if(cNeedData)
            {
                emit sendData2C(accBuffer,accBuffer,accBuffer);

            }
        }
        else if((use_smooth==1)&&(use_envelope!=1))
        {
              smoothdata(1,outPut,WINSZ,matrixA,varargin);

              for (int j=0; j<elementCntA;j++)
              {
                   AK[j]= outPut.Get(0,j+1);
              }

              double *B=new double[200];
              double *B1=new double[200];
              double *B2=new double[200];
              for(int j=150; j<350;j++)
              {
                    B[j-150]=AK[j];
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
              if(cNeedData)
              {
                  emit sendData2C(accBuffer,AK,AK);

              }
        }
        else if((use_smooth!=1)&&(use_envelope==1))
        {
            envelope(2,up_01,lo_01,matrixA,d,method);//通过测试
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
            if(cNeedData)
            {
                emit sendData2C(accBuffer,accBuffer,mid_01);

            }
        }

*/

        //==============================================

        Delay_MSec(50);

        //==============================================

       if(first_count)
       {
           if(cocn_win==0)
           {

               out_data=COCN;
               double nowTime = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
               emit sendData2M(nowTime,out_data);
               first_count=false;
           }

           if(cocn_win_count==cocn_win)
        {


          // out_data=0;
           for(int i=0;i<COCN_data_befor_win.length();i++)
           {
               out_data+=COCN_data_befor_win[i];
           }


           out_data=out_data/cocn_win;
           double nowTime = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
           emit sendData2M(nowTime,out_data);
           first_count=false;

         }
            if(cocn_win_count<cocn_win)
            {

              COCN_data_befor_win.append(COCN);
              cocn_win_count+=1;

            }

       }

        else//(cocn_win_count==cocn_win)
       {

           if(cocn_win==0)
           {

               double nowTime = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
               emit sendData2M(nowTime,COCN);
               QDateTime datatime =QDateTime::currentDateTime();
               QString timeString =datatime.toString("HH:mm:ss");
               COCN_data_after.append(timeString);
               COCN_data_after.append(QString::number(COCN));
           }
           else
           {
           COCN_data_befor_win.append(COCN);
           COCN_data_befor_win.removeFirst();

           //cocn_win_count=0;
           for(int i=0;i<COCN_data_befor_win.length();i++)
           {
               out_data+=COCN_data_befor_win[i];
             //qDebug()<<COCN_data_befor_win[i];
           }

           out_data=out_data/cocn_win;
           double nowTime = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
           emit sendData2M(nowTime,out_data);
           QDateTime datatime =QDateTime::currentDateTime();
           QString timeString =datatime.toString("HH:mm:ss");
           COCN_data_after.append(timeString);
           COCN_data_after.append(QString::number(out_data));

           }
       }

        //==============================================
       COCN_data.clear();
      // COCN_data_after.clear();
       Delay_MSec(20);
       QDateTime datatime =QDateTime::currentDateTime();
       QString timeString =datatime.toString("HH:mm:ss");

       COCN_data.append(timeString);
       COCN_data.append(QString::number(COCN));

        if((saveSpectrum!=0)||(saveCOCN!=0))
        {
            for(int i=0;i<500;i++)
            {
                 sp_data.append(QString::number(accBuffer[i]));
                 sp_data_AP.append(QString::number(after_s[i]));
                 sp_channel_data.append(QString::number(accBuffer_1[i]));
//                 if((use_smooth==1)&&(use_envelope==1))
//                 {
//                     sp_data_AP.append(QString::number(mid_01[i]));
//                 }
//                 else if((use_smooth!=1)&&(use_envelope!=1))
//                 {
//                     sp_data_AP.append(QString::number(accBuffer[i]));
//                 }
//                 else if((use_smooth==1)&&(use_envelope!=1))
//                 {
//                     sp_data_AP.append(QString::number(AK[i]));
//                 }
//                 else if((use_smooth!=1)&&(use_envelope==1))
//                 {
//                     sp_data_AP.append(QString::number(mid_01[i]));
//                 }


            }
            Delay_MSec(50);
            saveData_0();

        }
        for(int i=0;i<500;i++)
        {
            accBuffer[i]=0;
            accBuffer_1[i]=0;

        }




}
void CH4_serial::run()
{

   // MUTEX.lock();
   // anlyseData();
   // MUTEX.unlock();
//    if(!obiect_exist)
//    {
      //   mainport =new QSerialPort;
        // obiect_exist=true;
//    }

   //
   // qDebug()<<"创建对象"<<QThread::currentThread();
    if(!mainport->isOpen())
   {

       mainport->setPortName(Serial_Port_Number);//设置串口名
       mainport->open(QIODevice::ReadWrite);//以读写方式打开串口
       mainport->setBaudRate(QSerialPort::Baud115200);//波特率
       mainport->setDataBits(QSerialPort::Data8);//数据位
       mainport->setParity(QSerialPort::NoParity);//校验位
       mainport->setStopBits(QSerialPort::OneStop);//停止位
       mainport->write("d");
//        ui.comboBox->setEnabled(false);
//        ui.pushButton->setText("停止读取");
//        ui.pushButton_fileselect->setEnabled(false);
//        ui.saveCOCN->setEnabled(false);
       connect(mainport,SIGNAL(readyRead()),this,SLOT(readData()));
       //anlyseData();
       emit sendSSig2Conf(true);
       emit sendSSig2Main(true);
      // qDebug()<<"串口已打开"<<QThread::currentThread();
      // qDebug()<<mainport->isOpen();
      // return true;



   }
    else
   {

       mainport->close();
//      ui.comboBox->setEnabled(true);
//      ui.pushButton_fileselect->setEnabled(true);
//      ui.saveCOCN->setEnabled(true);
//      ui.pushButton->setText("开始读取");
       emit sendSSig2Conf(false);
       emit sendSSig2Main(false);
       FBuffer.clear();
      // qDebug()<<"串口已关闭";
     //  qDebug()<<mainport->isOpen();
      // return false;


   }

}
void CH4_serial::saveData_0()
{
    QDateTime datatime =QDateTime::currentDateTime();
   // QString saveTime =datatime.toString("yyyy-MM-dd-HH-mm-ss");
    CH4_SDT->saveData_1(saveCOCN,saveSpectrum,COCN_interval,COCN_data,COCN_data_after,sp_data,sp_channel_data,sp_data_AP,spectrumfilepath,COCNfilepath,datatime);
    COCN_data_after.clear();
    sp_data.clear();
    sp_channel_data.clear();
    sp_data_AP.clear();
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
    Serial_Port_Number=PM.portname;
    cocn_win=PM.COCN_WIN;
    use_envelope=PM.USE_envelope;
    order=PM.order;
    framleng=PM.framelen;
   // qDebug()<<"order"<<order;
   // qDebug()<<"framleng"<<framleng;

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
void CH4_serial::onTimeOut()
{


    startADC();
    Delay_MSec(50);

   if(byDevIndex == 0xFF)
   {
      qDebug()<< "设备未连接!";
   return;
   }
      DWORD pdwRealSize = 0;//实际读取的数据长度
       byte lpBuffer[320000];//用来保存读取内容的缓存区
      // char Temp[200];
       WORD cycles;
       float realVol;
       float realVol_1;
       int i =0;
       if (myADCCfg.byADCOptions & 0x10)
               MaxVol = 10;
               MaxVol = 5;
      QList <double> originBuffer;
      QList <double> originBuffer_1;
       if (M3F20xm_ReadFIFO(byDevIndex, lpBuffer, 320000, &pdwRealSize))
       {
           if (pdwRealSize > 0)
           {
               cycles = pdwRealSize / 16;
               for(int j = 0; j < cycles;j++)
               {

                   WORD byDataArray[8];
                  // CString s;
                  // s.Empty();
                   memcpy(byDataArray, &lpBuffer[j * 16], 16);

                       if ((byDataArray[0] & 0x8000) == 0x8000)
                       {
                           byDataArray[0] = ~byDataArray[0];
                           //realVol = -1 * MaxVol * (code + 1) / 32768;
                           realVol = -1 * MaxVol * (byDataArray[0] + 1) / 32768;
                           //str.Format("%3.6f   ",realVol);
                           //str = String.Format("{0:0.000000}", realVol);

                       }
                       else
                       {
                           //realVol = MaxVol * (Sample[i] + 1) / 32768;
                           realVol = MaxVol * (byDataArray[0] + 1) / 32768;
                           //str = String.Format("{0:0.000000}", realVol);

                       }
                        originBuffer.append(realVol);
                        if ((byDataArray[1] & 0x8000) == 0x8000)
                        {
                            byDataArray[1] = ~byDataArray[1];
                            //realVol = -1 * MaxVol * (code + 1) / 32768;
                            realVol_1 = -1 * MaxVol * (byDataArray[1] + 1) / 32768;
                            //str.Format("%3.6f   ",realVol);
                            //str = String.Format("{0:0.000000}", realVol);

                        }
                        else
                        {
                            //realVol = MaxVol * (Sample[i] + 1) / 32768;
                            realVol_1 = MaxVol * (byDataArray[1] + 1) / 32768;
                            //str = String.Format("{0:0.000000}", realVol);

                        }
                       originBuffer_1.append(realVol_1);
                       //qDebug()<<realVol_1;

               }



               if((localAcc<acc)&&(acc!=0))
                       {
                          for(int i=0;i<500;i++)
                          {

                              accBuffer[i]+=originBuffer[i];
                              accBuffer_1[i]+=originBuffer_1[i];

                          }
                          localAcc++;
                       }
                       if(localAcc==acc)
                       {
                           for(int i=0;i<500;i++)
                           {

                               accBuffer[i]=accBuffer[i]/localAcc;
                               accBuffer_1[i]=accBuffer_1[i]/localAcc;
                              // qDebug()<<accBuffer[i];
                           }

                          // this->start();
                           anlyseData();
                           localAcc=0;
                       }

           }
       }
               else
                   {
                      qDebug()<<"采样读数据失败!";
                   }

       if (myADCCfg.dwCycleCnt == myADCCfg.dwMaxCycles)
                   {
                       myADCCfg.byTrigOptions &= 0x7F;

                   }

}
void CH4_serial::closeCAD()
{
    if (byDevIndex != 0xFF)
    {
        if (myADCCfg.byTrigOptions & 0x80)   //trig mode
        {
            myADCCfg.byTrigOptions &= 0x7F;

        }
        M3F20xm_CloseDevice(byDevIndex);
    }
}
