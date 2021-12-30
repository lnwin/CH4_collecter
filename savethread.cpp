#include "savethread.h"
QString sp_FP;
QString COCN_FP,SAVETime;
double save_SP,save_COCN,COCNInter;
QList <QString>COCNDATA,spdata;

savethread::savethread()
{

}
void savethread::run()
{
   if(save_COCN==1)
   {
       saveCOCN(COCNDATA,COCN_FP);

   }
   if(save_SP==1)
   {
       saveSP(spdata,sp_FP,SAVETime);

   }
}
void savethread::saveData_1(double saveCOCN,double saveSp,double COCN_inter,
                            QList <QString>COCN_data,QList <QString>sp_data,
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
      Delay_MSec(50);
      this->start();
}
void savethread::saveCOCN(QList<QString>COCN_DATA, QString PATH)
{
    QDateTime time =QDateTime::currentDateTime();
    QString filename =time.toString("yyyy-MM-dd")+"_COCN_DATA.txt";
    PATH+="COCN_DATA/";
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
void savethread::saveSP(QList<QString> SP_data,QString PATH,QString saveTime)
{

    QString filename =saveTime+"_SP_DATA.txt";
    PATH+="origin_DATA/";
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
void savethread::Delay_MSec(unsigned int msec)
{

        QTime _Timer = QTime::currentTime().addMSecs(msec);

        while( QTime::currentTime() < _Timer )

        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);

};
