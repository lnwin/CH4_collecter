#include "ch4_chart.h"
QVector<double> X(500),Y(500);
CH4_chart::CH4_chart()
{

}
void CH4_chart::Chart_init(Ui::MainWindow ui)
{

    ui.customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                    QCP::iSelectLegend | QCP::iSelectPlottables);
    ui.customPlot->xAxis->setRange(-100, 100);
    ui.customPlot->yAxis->setRange(-100, 100);
    ui.customPlot->axisRect()->setupFullAxesBox();
    ui.customPlot->plotLayout()->insertRow(0);
    QCPTextElement *title = new QCPTextElement(ui.customPlot, "Interaction Example", QFont("sans", 17, QFont::Bold));
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
    ui.customPlot->graph()->setName("光谱曲线");
    Chart_updata(ui);
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
void CH4_chart::Chart_updata(Ui::MainWindow ui)
{
    for (int i=0; i<50; i++)
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

