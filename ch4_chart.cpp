#include "ch4_chart.h"
QVector<double> X(500),Y(500);
CH4_chart::CH4_chart()
{

}
void CH4_chart::Chart_Minit(Ui::MainWindow ui)
{

    ui.customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                    QCP::iSelectLegend | QCP::iSelectPlottables);
    ui.customPlot->xAxis->setRange(-100, 100);
    ui.customPlot->yAxis->setRange(-100, 100);
    ui.customPlot->axisRect()->setupFullAxesBox();
    ui.customPlot->plotLayout()->insertRow(0);
    QCPTextElement *title = new QCPTextElement(ui.customPlot, "CH4浓度曲线", QFont("sans", 17, QFont::Bold));
    ui.customPlot->plotLayout()->addElement(0, 0, title);
    ui.customPlot->xAxis->setLabel("时间");
    ui.customPlot->yAxis->setLabel("浓度（PPM）");
    ui.customPlot->legend->setVisible(true);
//    QLinearGradient plotGradient;
//  //  plotGradient.setStart(0, 0);
//   // plotGradient.setFinalStop(0, 350);
//   // plotGradient.setColorAt(0, QColor(80, 80, 80));
//    plotGradient.setColorAt(1, QColor(50, 50, 50));
//    ui.customPlot->setBackground(plotGradient);
    QFont legendFont("Times", 10, QFont::Bold);
    legendFont.setPointSize(10);
    ui.customPlot->legend->setFont(legendFont);
    ui.customPlot->legend->setSelectedFont(legendFont);
    ui.customPlot->legend->setSelectableParts(QCPLegend::spItems);
    ui.customPlot->addGraph();   
    ui.customPlot->graph()->setName("CH4浓度");
    Chart_Mupdata(ui);
    ui.customPlot->rescaleAxes();
};
void CH4_chart::receiveData(QVector<double> x,QVector<double> y)
{
    for (int i=0; i<50; i++)
    {
      X[i] = i;
      Y[i] = i;
    }
};
void CH4_chart::Chart_Mupdata(Ui::MainWindow ui)
{
    for (int i=0; i<200; i++)
    {
      X[i] = i;
      Y[i] = i;
    }
   ui.customPlot->graph()->setData(X,Y);
   ui.customPlot->graph()->setLineStyle((QCPGraph::lsLine));
   ui.customPlot->graph()->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ssNone)));
   QPen graphPen;
//   int r,g,b;
//   r=std::rand()%245+10;
//   g=std::rand()%245+10;
//   b=std::rand()%245+10;
   graphPen.setColor(QColor(16,177,171));
//   qDebug()<<r<<"---"<<g<<"---"<<b;
   graphPen.setWidthF(2);
   ui.customPlot->graph()->setPen(graphPen);
   ui.customPlot->replot();


};
void CH4_chart::run()
{

}
void CH4_chart::Chart_Cinit(Ui::configuration ui_cof)
{
   ui_cof.chart_widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                                       QCP::iSelectLegend | QCP::iSelectPlottables);
   ui_cof.chart_widget->xAxis->setRange(-100, 100);
   ui_cof.chart_widget->yAxis->setRange(-100, 100);
   ui_cof.chart_widget->axisRect()->setupFullAxesBox();
   ui_cof.chart_widget->plotLayout()->insertRow(0);
   QCPTextElement *title = new QCPTextElement(ui_cof.chart_widget, "光谱信号曲线图", QFont("sans", 17, QFont::Bold));
   ui_cof.chart_widget->plotLayout()->addElement(0, 0, title);
   ui_cof.chart_widget->xAxis->setLabel("时间");
   ui_cof.chart_widget->yAxis->setLabel("光谱信号");
   ui_cof.chart_widget->legend->setVisible(true);
   QFont legendFont("Times", 10, QFont::Bold);
   legendFont.setPointSize(10);
   ui_cof.chart_widget->legend->setFont(legendFont);
   ui_cof.chart_widget->legend->setSelectedFont(legendFont);
   ui_cof.chart_widget->legend->setSelectableParts(QCPLegend::spItems);
   ui_cof.chart_widget->addGraph();
   ui_cof.chart_widget->graph()->setName("光谱数据");
   ui_cof.chart_widget->rescaleAxes();



};
void CH4_chart::Chart_Cupdata(Ui::configuration ui_cof)
{

};
