#include "savethread.h"
QString sp_FP;
QString COCN_FP,SAVETime;
double save_SP,save_COCN,COCNInter;
QList <QString>COCNDATA, COCNDATA_after,  spdata,spdata_after;

savethread::savethread()
{

}
void savethread::run()
{
   if(save_COCN==1)
   {
       saveCOCN(COCNDATA,sp_FP);

   }
   if(save_SP==1)
   {
       saveSP(spdata,sp_FP,SAVETime);
       saveCOCN_after(COCNDATA_after,COCN_FP);
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
    QString filename =time.toString("yyyy-MM-dd")+"_COCN_DATA.txt";
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
    QString filename =time.toString("yyyy-MM-dd")+"_COCN_DATA_after.txt";
    PATH+="/";
    filename=PATH+filename;
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
