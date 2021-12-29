#ifndef CH4_CHART_H
#define CH4_CHART_H
#include <ui_mainwindow.h>
#include "QLineSeries"
#include "QValueAxis"
#include <QObject>
#include <qthread.h>
#include <QDateTimeAxis>
#include "QDateTime"
#include <QDebug>
#include <QVBoxLayout>
#include <qcustomplot.h>
#include <QWidget>
#include <qfont.h>
#include <ui_configuration.h>
#include <ui_data_process.h>
#include <ch4_serial.h>
QT_CHARTS_USE_NAMESPACE
class CH4_chart :public QThread
{
    Q_OBJECT
public:
    CH4_chart();
    void Chart_Minit(Ui::MainWindow);
    void Chart_Mupdata(Ui::MainWindow,double,double);
    void Chart_Cinit(Ui::configuration);
    void Chart_Cupdata(Ui::configuration);
    void Chart_Pinit(Ui::configuration);
    void Chart_Pupdata(Ui::configuration,double * origin,double*after_s,double *after_s_e);
    void run();
    Max_Min coutMaxMin(double*,double);
public slots:
   void receiveDataFromS(double *originData,double  *after_s,double  *after_s_e);
};

#endif // CH4_CHART_H
