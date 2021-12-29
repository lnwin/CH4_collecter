#include "ch4_chart.h"
QVector<double> X(500),Y(500),origin_y(500),origin_x(500),after_p_y(500),after_p_x(500),after_p_s_e_y(500),after_p_s_e_x(500),COCNt,COCNd;
CH4_chart::CH4_chart()
{

}
void CH4_chart::Chart_Minit(Ui::MainWindow ui)
{

    ui.customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                    QCP::iSelectLegend | QCP::iSelectPlottables);
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("hh:mm:ss");
    ui.customPlot->xAxis->setTicker(dateTicker);
   // ui.customPlot->xAxis->setRange(-100, 100);
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
   // Chart_Mupdata(ui);
    ui.customPlot->rescaleAxes();
};
void CH4_chart::receiveDataFromS(double *originData,double  *after_s,double  *after_s_e)
{
   //Chart_Pupdata(originData,after_s,after_s_e);
};
void CH4_chart::Chart_Mupdata(Ui::MainWindow ui,double time,double data)
{

   if(COCNd.length()>500)
   {
       COCNt.removeAt(0);
       COCNd.removeAt(0);
       COCNt.append(time);
       COCNd.append(data);
   }
   else
   {
       COCNt.append(time);
       COCNd.append(data);
   }
   ui.customPlot->graph()->setData(COCNt,COCNd);
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
   ui.customPlot->rescaleAxes();
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
void CH4_chart::Chart_Pinit(Ui::configuration ui)
{

    ui.chart_widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                                      QCP::iSelectLegend | QCP::iSelectPlottables);

    ui.chart_widget->xAxis->setRange(0, 500);
    ui.chart_widget->yAxis->setRange(0, 500);

    ui.chart_widget->axisRect()->setupFullAxesBox();
    ui.chart_widget->plotLayout()->insertRow(0);
    QCPTextElement *title = new QCPTextElement( ui.chart_widget, "光谱信号曲线图", QFont("sans", 10, QFont::Bold));
    ui.chart_widget->plotLayout()->addElement(0, 0, title);
    ui.chart_widget->xAxis->setLabel("数据个数");
    ui.chart_widget->yAxis->setLabel("光谱信号");
    ui.chart_widget->legend->setVisible(true);
    QFont legendFont("Times", 10, QFont::Bold);
    legendFont.setPointSize(10);
    ui.chart_widget->legend->setFont(legendFont);
    ui.chart_widget->legend->setSelectedFont(legendFont);
    ui.chart_widget->legend->setSelectableParts(QCPLegend::spItems);
//=======================================================================
    ui.chart_widget->addGraph();
    ui.chart_widget->graph(0)->setName("origin data");
   // ui.chart_widget->graph(0)->setData(origin_x,origin_y);
    ui.chart_widget->graph(0)->setLineStyle((QCPGraph::lsLine));
    ui.chart_widget->graph(0)->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ssNone)));
    QPen graphPen;
    graphPen.setColor(QColor(16,1,171));
 //   qDebug()<<r<<"---"<<g<<"---"<<b;
    graphPen.setWidthF(2);
    ui.chart_widget->graph(0)->setPen(graphPen);


    ui.chart_widget->addGraph();
    ui.chart_widget->graph(1)->setName("after smooth");
   // ui.chart_widget->graph(1)->setData(after_p_x,after_p_y);
    ui.chart_widget->graph(1)->setLineStyle((QCPGraph::lsLine));
    ui.chart_widget->graph(1)->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ssNone)));
    QPen graphPen1;
    graphPen1.setColor(QColor(1,222,5));
 //   qDebug()<<r<<"---"<<g<<"---"<<b;
    graphPen1.setWidthF(2);
    ui.chart_widget->graph(1)->setPen(graphPen1);

    ui.chart_widget->addGraph();
    ui.chart_widget->graph(2)->setName("after smooth&envelop");
  //  ui.chart_widget->graph(2)->setData(after_p_s_e_x,after_p_s_e_y);
    ui.chart_widget->graph(2)->setLineStyle((QCPGraph::lsLine));
    ui.chart_widget->graph(2)->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ssNone)));
    QPen graphPen2;
    graphPen2.setColor(QColor(222,2,222));
 //   qDebug()<<r<<"---"<<g<<"---"<<b;
    graphPen2.setWidthF(2);
    ui.chart_widget->graph(2)->setPen(graphPen2);
    ui.chart_widget->rescaleAxes();
    qDebug()<<"chart_Int ok";
}
void CH4_chart::Chart_Pupdata(Ui::configuration ui,double *origin,double*after_s,double *after_s_e)
{
    Max_Min MN_B;
    MN_B=coutMaxMin(origin,500);
    ui.chart_widget->yAxis->setRange(MN_B.Min-500, MN_B.Max+500);
   // ui.chart_widget->clearGraphs();
    for (int i=0; i<500; i++)
    {
      origin_y[i] = origin[i];
      origin_x[i] =i;
      after_p_y[i] = after_s[i];
      after_p_x[i] =i;
      after_p_s_e_y[i]=after_s_e[i];
      after_p_s_e_x[i]=i;
    }
//    ui.chart_widget->addGraph();
//    ui.chart_widget->graph()->setName("origin data");
    ui.chart_widget->graph(0)->setData(origin_x,origin_y);
//    ui.chart_widget->graph()->setLineStyle((QCPGraph::lsLine));
//    ui.chart_widget->graph()->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ssNone)));
//    QPen graphPen;
//    graphPen.setColor(QColor(16,1,171));
// //   qDebug()<<r<<"---"<<g<<"---"<<b;
//    graphPen.setWidthF(2);
//    ui.chart_widget->graph()->setPen(graphPen);
//    ui.chart_widget->replot();
    //==========================
//    ui.chart_widget->addGraph();
//    ui.chart_widget->graph()->setName("after smooth");
    ui.chart_widget->graph(1)->setData(after_p_x,after_p_y);
//    ui.chart_widget->graph()->setLineStyle((QCPGraph::lsLine));
//    ui.chart_widget->graph()->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ssNone)));
//    QPen graphPen1;
//    graphPen1.setColor(QColor(1,222,5));
// //   qDebug()<<r<<"---"<<g<<"---"<<b;
//    graphPen1.setWidthF(2);
//    ui.chart_widget->graph()->setPen(graphPen1);
//    ui.chart_widget->replot();
//    ui.chart_widget->addGraph();
//    ui.chart_widget->graph()->setName("after smooth&envelop");
    ui.chart_widget->graph(2)->setData(after_p_s_e_x,after_p_s_e_y);
//    ui.chart_widget->graph()->setLineStyle((QCPGraph::lsLine));
//    ui.chart_widget->graph()->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ssNone)));
//    QPen graphPen2;
//    graphPen2.setColor(QColor(222,2,222));
// //   qDebug()<<r<<"---"<<g<<"---"<<b;
//    graphPen2.setWidthF(2);
//    ui.chart_widget->graph()->setPen(graphPen2);
    ui.chart_widget->replot();
   // ui.chart_widget->rescaleAxes();

}
Max_Min CH4_chart::coutMaxMin(double *dataIn,double n)
{
    Max_Min mn;
    mn.Max=dataIn[0];
    mn.Min=dataIn[0];
    for(int i=0;i<n;i++ )
    {


        if(dataIn[i]> mn.Max)
        {
           mn.Max =dataIn[i];
         // qDebug()<<Max;
        }
        if(dataIn[i]<mn.Min)
        {
          mn.Min=dataIn[i];
        }

    }
    return mn;

}
