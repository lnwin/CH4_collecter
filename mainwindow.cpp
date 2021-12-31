#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
QString  srcDirPath;
Parameter M_parameter;
bool serialisopen;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);  
    QStringList intercal_List;
    intercal_List<<"1分钟"<<"10分钟"<<"20分钟"<<"30分钟"<<"40分钟"<<"50分钟";
    ui->COCN_interval->addItems(intercal_List);
    ui->lcdNumber->setDigitCount(19);
    ui->lcdNumber->setStyleSheet("border: 0px solid green;color: green; background: black;");   
    ui->lcdNumber_2->setDigitCount(7);
    ui->lcdNumber_2->setStyleSheet("border: 0px solid green;color: green; background: black;");
    QTimer *clock =new QTimer(this);
    clock->setInterval(1000);

    searchPort();
    CH4 =new CH4_chart;
    CH4->Chart_Minit(*ui);
    CH4_sp =new CH4_serial(ui->comboBox->currentText());
    CH4_sv =new savethread;

    connect(ui->system_Set,SIGNAL(triggered()),this,SLOT(open_Configuration()));    
    connect(this,SIGNAL(sendCof2serial(Parameter)),CH4_sp,SLOT(receiveCof(Parameter)));
    connect(CH4_sp,SIGNAL(sendData2M(double,double)),this,SLOT(receiveDataFromS(double,double)));
     connect(CH4_sp,SIGNAL(sendSSig2Main(bool)),this,SLOT(receiveSSigFromS(bool)));
    ui->customPlot->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->customPlot, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequest(QPoint)));
    QMessageBox msgBox ;
   // msgBox.setIcon(QMessageBox::Icon::Warning);
    msgBox.setWindowIcon(QIcon(":/image/image/001.jpg"));
    msgBox.setText("开始加载配置，点击OK继续");
    msgBox.exec();
    if(smoothdataInitialize()&&envelopeInitialize())//必须加载
    {

        QMessageBox msgBox ;
       // msgBox.setIcon(QMessageBox::Icon::Warning);
        msgBox.setWindowIcon(QIcon(":/image/image/001.jpg"));
        msgBox.setText("配置加载完毕");
        msgBox.exec();
    }
    connect(clock, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    clock->start();
    readConf();
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

     M_parameter.COCNfilepath =ui->COCN_filepath->text();
    if(ui->saveCOCN->isChecked())
   {
       M_parameter.saveCOCN =1;
   }
    else
   {
       M_parameter.saveCOCN =0;
   }

     M_parameter.COCN_intercal=ui->COCN_interval->currentIndex();
     M_parameter.portname =ui->comboBox->currentText();
     emit sendCof2serial(M_parameter);

     CH4_sp->start();


//     if(CH4_sp->openPort(ui->comboBox->currentText(),*ui))
//     {
//              serialisopen=true;
//              ui->pushButton_fileselect->setEnabled(false);
//              ui->saveCOCN->setEnabled(false);


//     }
//     else
//     {
//              serialisopen=false;
//              ui->pushButton_fileselect->setEnabled(true);
//              ui->saveCOCN->setEnabled(true);
//     }



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
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
};
void MainWindow::open_Configuration()
{
    if(serialisopen)
    {
        QMessageBox ms;
        ms.setIcon(QMessageBox::Icon::Warning);
        ms.setWindowIcon(QIcon(":/image/image/001.jpg"));
        ms.setWindowTitle("注意");
        ms.setText("串口未关闭！");
        ms.exec();
    }


     else
      {
        bool ok;
         QString text = QInputDialog::getText(this, tr("后台管理"),tr("请输入配置密码"), QLineEdit::Password,0, &ok);
         if (ok && !text.isEmpty())
         {
             if(text=="1023")
             {
                  COF = new configuration();
                  connect(COF,SIGNAL(sendCof2serial(Parameter)),CH4_sp,SLOT(receiveCof(Parameter)));
                  connect(COF,SIGNAL(sendSerialSIG2Main()),this,SLOT(receiveSerialSIGFromConf()));
                  connect(CH4_sp,SIGNAL(sendSSig2Conf(bool)),COF,SLOT(receiveSSig(bool)));
                  connect(COF,SIGNAL(needData(bool)),CH4_sp,SLOT(receiveNeedSIG(bool)));
                  connect(CH4_sp,SIGNAL(sendData2C(double*,double*,double*)),COF,SLOT(receiveDataFromS(double*,double*,double*)));
                  COF->show();

             }
             else
             {
                QMessageBox ms;
                ms.setIcon(QMessageBox::Icon::Warning);
                ms.setWindowIcon(QIcon(":/image/image/001.jpg"));
                ms.setWindowTitle("注意");
                ms.setText("密码错误！");
                ms.exec();

             }
         }
         else
         {
             QMessageBox ms;
             ms.setIcon(QMessageBox::Icon::Warning);
             ms.setWindowIcon(QIcon(":/image/image/001.jpg"));
             ms.setWindowTitle("注意");
             ms.setText("密码不能为空！");
             ms.exec();
         }
      }




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
        ui->COCN_filepath->setText(srcDirPath) ;
        M_parameter.COCNfilepath =srcDirPath;
        emit sendCof2serial(M_parameter);

    }
}
void MainWindow::readConf()
{
    QFile confFile (QApplication::applicationDirPath()+"/configuration.txt");

    if(confFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QList<QString> sk;
        while(!confFile.atEnd())
        {
            QByteArray line = confFile.readLine();
            QString str(line);
            sk.append(str.split("\n").first());
        }

        M_parameter.acc =sk.at(1).toDouble();
        M_parameter.win_d=sk.at(3).toDouble();
        M_parameter.a =sk.at(5).toDouble();
        M_parameter.b =sk.at(7).toDouble();
        M_parameter.saveSpectrum =sk.at(9).toDouble();
        M_parameter.spectrumfilepath =sk.at(11);
        M_parameter.COCNfilepath =sk.at(13);
        ui->COCN_filepath->setText(sk.at(13));
        M_parameter.USE_SMOOTH=sk.at(15).toDouble();
        if(sk.at(15)=="0")
        {
            M_parameter.USE_SMOOTH=0;
        }
        else
        {
            M_parameter.USE_SMOOTH=1;
        }
        M_parameter.saveCOCN =sk.at(17).toDouble();
        if(sk.at(17)=="0")
        {
            ui->saveCOCN->setChecked(false);
        }
        else
        {
            ui->saveCOCN->setChecked(true);
        }
        M_parameter.COCN_intercal=sk.at(19).toDouble();
        ui->COCN_interval->setCurrentIndex(sk.at(19).toDouble());
        emit sendCof2serial(M_parameter);
        confFile.close();

   }
    else
    {
       QMessageBox msgBox ;
       msgBox.setIcon(QMessageBox::Icon::Warning);
       msgBox.setWindowIcon(QIcon(":/image/image/001.jpg"));
       msgBox.setText("配置文件缺失！");
       msgBox.exec();
    }
};
void MainWindow::receiveSerialSIGFromConf()
{
     CH4_sp->start();
}
void MainWindow::receiveDataFromS(double time, double data)
{

   CH4->Chart_Mupdata(*ui,time,data);   
   ui->lcdNumber_2->display(QString::number(data,'f',1));

}
void MainWindow::receiveSSigFromS(bool isopen)
{
   if(isopen)
   {
               ui->comboBox->setEnabled(false);
               ui->pushButton->setText("停止读取");
               ui->pushButton_fileselect->setEnabled(false);
               ui->saveCOCN->setEnabled(false);
               serialisopen=true;
   }
   else
   {
               ui->comboBox->setEnabled(true);
               ui->pushButton_fileselect->setEnabled(true);
               ui->saveCOCN->setEnabled(true);
               ui->pushButton->setText("开始读取");
               serialisopen=false;
   }
}
