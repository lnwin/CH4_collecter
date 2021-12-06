#ifndef CH4_CHART_H
#define CH4_CHART_H
#include <ui_mainwindow.h>
#include "QtCharts/QChart"
#include "QChartView"
#include "QLineSeries"
#include "QValueAxis"
#include <QObject>
#include <qthread.h>
#include <QDateTimeAxis>
#include "QDateTime"
#include <QDebug>
#include <QVBoxLayout>
QT_CHARTS_USE_NAMESPACE
class CH4_chart :public QThread
{
    Q_OBJECT
public:
    CH4_chart();
    void Chart_init(Ui::MainWindow);
    QChart *mainChart;
    QLineSeries *qlineSerie;
};

#endif // CH4_CHART_H
