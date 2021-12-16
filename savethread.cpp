#include "savethread.h"
QString FN;
QString FP;

savethread::savethread()
{

}
void savethread::run()
{
    SVD(FP,FN);
}
void savethread::saveData_1(QString filepath,QString filename)
{
      FP=filepath;
      FN=filename;
      this->start();
}
void savethread::SVD(QString filepath,QString filename)
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

