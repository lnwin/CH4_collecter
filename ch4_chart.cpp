#include "ch4_chart.h"

CH4_chart::CH4_chart()
{

}
void CH4_chart::Chart_init(Ui::MainWindow ui)
{

          mainChart =new QChart;
          QChartView *chartView = new QChartView(mainChart);
          chartView->setRubberBand(QChartView::RectangleRubberBand);
          chartView->setRenderHint(QPainter::Antialiasing);
          qlineSerie = new QLineSeries;

          mainChart->addSeries(qlineSerie);
          qlineSerie->setUseOpenGL(true);//openGl 加速
          qDebug()<<qlineSerie->useOpenGL();

          QDateTime now  = QDateTime::currentDateTime();
          QDateTimeAxis  *axisX = new QDateTimeAxis;
          axisX->setFormat("MM-dd-HH:mm:ss");//
         // axisX->setLabelsAngle(60);
          axisX->setRange(now.addMSecs(-100),now);

          QValueAxis *axisY = new QValueAxis;
          axisY->setRange(-5,5);
          axisY->setTitleText("axisY");

          mainChart->legend()->hide();
          mainChart->setTitle("output");
          mainChart->addAxis(axisY, Qt::AlignLeft);
          mainChart->addAxis(axisX, Qt::AlignBottom);
          QVBoxLayout *layout =ui.verticalLayout;
          layout->addWidget(chartView);
          qlineSerie->attachAxis(axisY);// 此二句一定要放在 this->chart()->addAxis 语句之后，不然
          qlineSerie->attachAxis(axisX);// 没有曲线显示
          mainChart->setTheme(QChart::ChartThemeDark);
};
