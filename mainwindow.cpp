#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
QString  srcDirPath;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(19);
    ui->lcdNumber->setStyleSheet("border: 0px solid green;color: green; background: black;");
    QTimer *clock =new QTimer(this);
    clock->setInterval(1000);
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
    connect(clock, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    clock->start();
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
void MainWindow::onTimeOut()
{
    QDateTime time = QDateTime::currentDateTime();
    QString timestring=time.toString("yyyy-MM-dd HH:mm:ss");
    ui->lcdNumber->display(timestring);
}
void MainWindow::on_pushButton_fileselect_clicked()
{
    srcDirPath = QFileDialog::getExistingDirectory( this, "Rec path", "/");
    if (srcDirPath.isEmpty())
    {
        return;
    }
    else
    {
        ui->filelineEdit->setText(srcDirPath) ;
    }
}
