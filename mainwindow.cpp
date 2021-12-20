#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    searchPort();
    CH4 =new CH4_chart;
    CH4->Chart_init(*ui);
    CH4_sp =new CH4_serial;
    CH4_sv =new savethread;

    COF = new configuration();
    DAP = new data_Process();

    connect(ui->system_Set,SIGNAL(triggered()),this,SLOT(open_Configuration()));
    connect(ui->data_Process,SIGNAL(triggered()),this,SLOT(open_Dataprocess()));
    ui->customPlot->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->customPlot, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequest(QPoint)));
    if(smoothdataInitialize())//必须加载
    {
      envelopeInitialize();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::searchPort()
{
    ui->comboBox->clear();
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->comboBox->addItem(serial.portName());
            serial.close();

        }
    }
};
void MainWindow::on_pushButton_clicked()
{
     CH4_sp->openPort(ui->comboBox->currentText(),*ui);

};
void MainWindow::contextMenuRequest(QPoint pos)
{

  QMenu *menu = new QMenu(this);
  menu->setAttribute(Qt::WA_DeleteOnClose);
//  if (ui->customPlot->legend->selectTest(pos, false) >= 0) // context menu on legend requested
//  {
//    menu->addAction("Move to top left", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignLeft));
//    menu->addAction("Move to top center", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignHCenter));
//    menu->addAction("Move to top right", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignRight));
//    menu->addAction("Move to bottom right", this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignRight));
//    menu->addAction("Move to bottom left", this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignLeft));
//  }
//  else  // general context menu on graphs requested
 // {
    menu->addAction("还原", this, SLOT(rescaleGraph()));
 // }

    menu->popup(ui->customPlot->mapToGlobal(pos));
}
void MainWindow::rescaleGraph()
{
    CH4->Chart_updata(*ui);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
};
void MainWindow::open_Configuration()
{
    COF->show();
};
void MainWindow::open_Dataprocess()
{
   DAP->show();
};
