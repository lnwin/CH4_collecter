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
    QString timeString;
    QList<QString>COCN_data;
};
Q_DECLARE_METATYPE(saveParameter);
class savethread: public QThread
{
    Q_OBJECT
public:
    savethread();

    void run();
    void saveData_1(double saveCOCN,double saveSp,double COCN_inter,QList <QString>COCN_data,QList <QString>sp_data,QString spFilePath,QString COCNFilePath,QString savetime);
    void saveCOCN(QList<QString>,QString);
    void saveSP(QString,QString);

public slots:

};

#endif // SAVETHREAD_H
