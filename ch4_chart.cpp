#include "ch4_chart.h"
QVector<double> X(500),Y(500),origin_y(500),origin_x(500),after_p_y(500),after_p_x(500),after_p_s_e_y(500),after_p_s_e_x(500);
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
    QCPTextElement *title = new QCPTextElement(ui.customPlot, "气体浓度曲线", QFont("sans", 17, QFont::Bold));
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
    ui.customPlot->graph()->setName("气体浓度");
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
void CH4_chart::Chart_Pinit(Ui::data_Process ui)

{


    ui.p_chart->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                                        QCP::iSelectLegend | QCP::iSelectPlottables);

    ui.p_chart->xAxis->setRange(-1000, 1000);
    ui.p_chart->yAxis->setRange(-1000, 1000);
    ui.p_chart->axisRect()->setupFullAxesBox();
    ui.p_chart->plotLayout()->insertRow(0);
    QCPTextElement *title = new QCPTextElement( ui.p_chart, "光谱信号曲线图", QFont("sans", 10, QFont::Bold));
    ui.p_chart->plotLayout()->addElement(0, 0, title);
    ui.p_chart->xAxis->setLabel("数据个数");
    ui.p_chart->yAxis->setLabel("光谱信号");
    ui.p_chart->legend->setVisible(true);
    QFont legendFont("Times", 10, QFont::Bold);
    legendFont.setPointSize(10);
    ui.p_chart->legend->setFont(legendFont);
    ui.p_chart->legend->setSelectedFont(legendFont);
    ui.p_chart->legend->setSelectableParts(QCPLegend::spItems);
    ui.p_chart->rescaleAxes();
};
void CH4_chart::Chart_Pupdata(Ui::data_Process ui,double *origin,double*after_s,double *after_s_e)
{
    ui.p_chart->clearGraphs();
    for (int i=0; i<500; i++)
    {
      origin_y[i] = origin[i];
      origin_x[i] =i;
      after_p_y[i] = after_s[i];
      after_p_x[i] =i;
      after_p_s_e_y[i]=after_s_e[i];
      after_p_s_e_x[i]=i;
    }
    ui.p_chart->addGraph();
    ui.p_chart->graph()->setName("origin data");
    ui.p_chart->graph()->setData(origin_x,origin_y);
    ui.p_chart->graph()->setLineStyle((QCPGraph::lsLine));
    ui.p_chart->graph()->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ssNone)));
    QPen graphPen;
    graphPen.setColor(QColor(16,1,171));
 //   qDebug()<<r<<"---"<<g<<"---"<<b;
    graphPen.setWidthF(2);
    ui.p_chart->graph()->setPen(graphPen);
    ui.p_chart->replot();
    //==========================
    ui.p_chart->addGraph();
    ui.p_chart->graph()->setName("after smooth");
    ui.p_chart->graph()->setData(after_p_x,after_p_y);
    ui.p_chart->graph()->setLineStyle((QCPGraph::lsLine));
    ui.p_chart->graph()->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ssNone)));
    QPen graphPen1;
    graphPen1.setColor(QColor(1,222,5));
 //   qDebug()<<r<<"---"<<g<<"---"<<b;
    graphPen1.setWidthF(2);
    ui.p_chart->graph()->setPen(graphPen1);
    ui.p_chart->replot();
    ui.p_chart->addGraph();
    ui.p_chart->graph()->setName("after smooth&envelop");
    ui.p_chart->graph()->setData(after_p_s_e_x,after_p_s_e_y);
    ui.p_chart->graph()->setLineStyle((QCPGraph::lsLine));
    ui.p_chart->graph()->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ssNone)));
    QPen graphPen2;
    graphPen2.setColor(QColor(222,2,222));
 //   qDebug()<<r<<"---"<<g<<"---"<<b;
    graphPen2.setWidthF(2);
    ui.p_chart->graph()->setPen(graphPen2);
    ui.p_chart->replot();
    ui.p_chart->rescaleAxes();

}
