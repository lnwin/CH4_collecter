#ifndef SAVETHREAD_H
#define SAVETHREAD_H
#include <ui_mainwindow.h>
#include <QObject>
#include <qthread.h>
#include <qfile.h>
#include <qfiledialog.h>
#include <QTextStream>
#include <QDebug>

struct saveParameter
{

    double saveCOCN;
    double saveSpectrum;
    double COCN_interval;
    QString spectrumfilepath;
    QString COCNfilepath;
    QString saveTime;
    QList<QString>COCN_data;
    QList<QString>SP_data;

};
Q_DECLARE_METATYPE(saveParameter);
class savethread: public QThread
{
    Q_OBJECT
public:
    savethread();
    void Delay_MSec(unsigned int msec);
    void run();
    void saveData_1(double saveCOCN,double saveSp,double COCN_inter,QList <QString>COCN_data,QList <QString>COCN_data_after,QList <QString>sp_data,QList <QString>sp_channel_data,QList <QString>sp_data_AfterP,QString spFilePath,QString COCNFilePath,QString savetime);
    void saveCOCN_after(QList<QString>,QString);
    void saveCOCN(QList<QString>,QString);
    void saveSP(QList<QString>,QString,QString);
    void saveSP_channel(QList<QString>,QString,QString);
    void saveSP_afterP(QList<QString>,QString,QString);

public slots:

};

#endif // SAVETHREAD_H
