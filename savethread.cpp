#include "savethread.h"
QString sp_FP;
QString COCN_FP,SAVETime;
double save_SP,save_COCN;int COCNInter=0,SUB=0;
QList <QString>COCNDATA, COCNDATA_after,  spdata,spdata_after;
//==========================
bool firstCount=true;
uint startTime=0;
uint endTime=0;
//==========================
savethread::savethread()
{

}
void savethread::run()
{
   // qDebug()<<"save_COCN"<<save_COCN;
   if(save_COCN==1)
   {


        //========================
        if(firstCount)
        {
            firstCount=false;
            QDateTime sk=QDateTime::currentDateTime();
            startTime = sk.toTime_t();

        }

            QDateTime sk=QDateTime::currentDateTime();
            endTime = sk.toTime_t();
            int ss=endTime-startTime;

          switch (COCNInter)
            {
              case 0: SUB=1*60   ;
              break;
              case 1: SUB=10*60  ;
              break;
              case 2: SUB=20*60  ;
              break;
              case 3: SUB=30*60  ;
              break;
              case 4: SUB=40*60  ;
              break;
              case 5: SUB=50*60  ;
              break;
            }

          if(ss>=SUB)
          {

              saveCOCN_after(COCNDATA_after,COCN_FP);
              firstCount=true;

          }


        //========================

   }
   if(save_SP==1)
   {
       saveSP(spdata,sp_FP,SAVETime);
       saveCOCN(COCNDATA,sp_FP);
       saveSP_afterP(spdata_after,sp_FP,SAVETime);
   }

}
void savethread::saveData_1(double saveCOCN,double saveSp,double COCN_inter,
                            QList <QString>COCN_data,QList <QString>COCN_data_after,QList <QString>sp_data,
                            QList <QString>sp_data_AfterP,
                            QString spFilePath,QString COCNFilePath,QString savetime)
{
      save_SP=saveSp;
      save_COCN=saveCOCN;
      COCNInter=COCN_inter;
      sp_FP=spFilePath;
      COCN_FP=COCNFilePath;
      COCNDATA=COCN_data;
      spdata=sp_data;
      SAVETime=savetime;
      spdata_after=sp_data_AfterP;
      COCNDATA_after=COCN_data_after;
      Delay_MSec(50);
      this->start();

}
void savethread::saveCOCN(QList<QString>COCN_DATA, QString PATH)
{
    QDateTime time =QDateTime::currentDateTime();
    QString filename =time.toString("yyyy-MM-dd")+"_origin_COCN_DATA.txt";
    PATH+="/";
    filename=PATH+filename;
    QFile datafile(filename);
    QTextStream stream(&datafile);
    if(!datafile.exists())
    {
       QDir *path =new QDir;
       path->mkdir(PATH);
       datafile.open(QIODevice::WriteOnly | QIODevice::Text);

           stream<<COCN_DATA[0]+"\t"+COCN_DATA[1]<<"\n";

    }
    else
    {
        datafile.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append);
        stream<<COCN_DATA[0]+"\t"+COCN_DATA[1]<<"\n";
    }
    datafile.close();


}
void savethread::saveCOCN_after(QList<QString>COCN_DATA_after, QString PATH)
{

    QDateTime time =QDateTime::currentDateTime();
    QString filename =time.toString("yyyy-MM-dd")+"_COCN_DATA.txt";
   // PATH+="/";
    filename=PATH+"/"+filename;
    QFile datafile(filename);
    QTextStream stream(&datafile);
    if(!datafile.exists())
    {
       QDir *path =new QDir;
       path->mkdir(PATH);
       datafile.open(QIODevice::WriteOnly | QIODevice::Text);

           stream<<COCN_DATA_after[0]+"\t"+COCN_DATA_after[1]<<"\n";

    }
    else
    {
        datafile.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append);
        stream<<COCN_DATA_after[0]+"\t"+COCN_DATA_after[1]<<"\n";
    }
    datafile.close();
};
void savethread::saveSP(QList<QString> SP_data,QString PATH,QString saveTime)
{

    QString filename =saveTime+"_origin_DATA.txt";
    PATH+="/";
    filename=PATH+filename;

    QFile cloudfile(filename);
    QTextStream stream(&cloudfile);
    if(!cloudfile.exists())

            {
                 QDir *folder = new QDir;
                 folder->mkdir(PATH);
                 cloudfile.open(QIODevice::WriteOnly | QIODevice::Text);
                 for( int i=0;i<SP_data.length(); i++)
                 {
                      stream<< SP_data[i]<<"\n";

                 }

             }
    else
    {
        cloudfile.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append);
        for( int i=0;i<SP_data.length(); i++)
        {
             stream<< SP_data[i]<<"\n";

        }

    }
    cloudfile.close();
}
void savethread::saveSP_afterP(QList<QString> SP_data_after_p,QString PATH,QString saveTime)
{
    QString filename =saveTime+"_afterProcess_DATA.txt";
    PATH+="/";
    filename=PATH+filename;

    QFile cloudfile(filename);
    QTextStream stream(&cloudfile);
    if(!cloudfile.exists())

            {
                 QDir *folder = new QDir;
                 folder->mkdir(PATH);
                 cloudfile.open(QIODevice::WriteOnly | QIODevice::Text);
                 for( int i=0;i<SP_data_after_p.length(); i++)
                 {
                      stream<< SP_data_after_p[i]<<"\n";

                 }

             }
    else
    {
        cloudfile.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append);
        for( int i=0;i<SP_data_after_p.length(); i++)
        {
             stream<< SP_data_after_p[i]<<"\n";

        }

    }
    cloudfile.close();

};
void savethread::Delay_MSec(unsigned int msec)
{

        QTime _Timer = QTime::currentTime().addMSecs(msec);

        while( QTime::currentTime() < _Timer )

        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);

};
