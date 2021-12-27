#include "ch4_serial.h"
#include <mutex>
std::mutex MUTEX;
bool needread=false;
bool cNeedData;
double acc=0,a_n=0.0015,b_n=4,win_n=3,COCN;
QString spectrumfilepath,COCNfilepath;
double saveSpectrum,saveCOCN,COCN_interval;
QList <QString> COCN_data;
QList <QString> sp_data;
QString saveTime;
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
        mainport->setBaudRate(QSerialPort::Baud9600);//波特率
        mainport->setDataBits(QSerialPort::Data8);//数据位
        mainport->setParity(QSerialPort::NoParity);//校验位
        mainport->setStopBits(QSerialPort::OneStop);//停止位
        ui.comboBox->setEnabled(false);
        ui.pushButton->setText("停止读取");
        connect(mainport,SIGNAL(readyRead()),this,SLOT(readData()));
        //anlyseData();
        emit sendSSig2Conf(true);
        return true;



    }
     else
    {

        mainport->close();
        ui.comboBox->setEnabled(true);
        ui.pushButton->setText("开始读取");
        emit sendSSig2Conf(false);
        return false;

    }


};

void CH4_serial::readData()
{
    MUTEX.lock();
    this->start();
    MUTEX.unlock();
};
void CH4_serial::anlyseData()
{


        QByteArray serialBuffer;

        serialBuffer=mainport->readAll();
         if(!serialBuffer.isEmpty())
         {






         }

        int elementCntA=500;//元素个数
        double  *originData=new double[elementCntA]; //一维数组，用于C++向 MATLAB数组传递数据
        double  *after_s=new double[elementCntA];
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

        for (int j=0; j<elementCntA;j++)
        {

            after_s[j]=outPut.Get(0,j+1);

        }

        mwArray d(win_n);//串窗口平滑参数
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
        COCN = a_n*X+b_n;
        //==============================================
        if(cNeedData)
        {
            emit sendData2C(originData,after_s,mid_01);
        }
        //==============================================
        double nowTime = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
        QList<double>CCD;
        COCN=34;
            emit sendData2M(nowTime,COCN);
        //==============================================
        COCN_data.clear();
        QTime datatime =QTime::currentTime();
        QString timeString =datatime.toString("HH:mm:ss");
        COCN_data.append(timeString);
        COCN_data.append(QString::number(COCN));

        if((saveSpectrum!=0)&&(saveCOCN!=0))
        {
            saveData_0();
        }


}
void CH4_serial::run()
{

     anlyseData();

}
void CH4_serial::saveData_0()
{
    QTime datatime =QTime::currentTime();
    QString saveTime =datatime.toString("yyyy-MM-dd-HH:mm:ss");
    CH4_SDT->saveData_1(saveCOCN,saveSpectrum,COCN_interval,COCN_data,sp_data,spectrumfilepath,COCNfilepath,saveTime);

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
    acc=PM.acc;
    a_n=PM.a;
    b_n=PM.b;
    win_n=PM.win_d;
    spectrumfilepath=PM.spectrumfilepath;
    saveSpectrum=PM.saveSpectrum;
    saveCOCN =PM.saveCOCN;
    COCNfilepath=PM.COCNfilepath;
    COCN_interval =PM.COCN_intercal;
}
void CH4_serial::receiveNeedSIG(bool need)
{
    cNeedData=need;
    qDebug()<<cNeedData;
};
