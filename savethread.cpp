#include "savethread.h"
QString sp_FP;
QString COCN_FP;
double save_SP,save_COCN,COCNInter;
QList <QString>COCNDATA;

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

      this->start();
}
void savethread::saveCOCN(QList<QString>COCN_DATA, QString PATH)
{
    QTime time =QTime::currentTime();
    QString filename =time.toString("yyyy-MM-dd")+"_COCN_DATA.txt";
    filename=PATH+"/"+filename;
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


}
void savethread::saveSP(QString filepath,QString filename)
{
    QFile cloudfile(filename);
    QTextStream stream(&cloudfile);
    if(!cloudfile.exists())

            {
                 QDir *folder = new QDir;
                 folder->mkdir(filepath);
                 cloudfile.open(QIODevice::WriteOnly | QIODevice::Text);
//                 for( int i=0;i<countNumber; i++)
//                 {
//                      stream<< QString::number( cloud_X[i]) +","+QString::number( cloud_Y[i])+","+QString::number( cloud_Z[i])+","+QString::number( RGB_Intensity[i])<<"\n";

//                 }

             }
    else
    {
        cloudfile.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append);
//        for( int i=0;i<countNumber; i++)
//        {
//            stream<< QString::number( cloud_X[i]) +","+QString::number( cloud_Y[i])+","+QString::number( cloud_Z[i])+","+QString::number( RGB_Intensity[i])<<"\n";


//         }

    }
    cloudfile.close();
}

