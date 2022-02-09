﻿#include "mainwindow.h"
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

    CH4_sv =new savethread;

    seriai_thread =new QThread();
    CH4_sp =new CH4_serial();
   // CH4_sp =new CH4_serial("COM2");
    connect(this,SIGNAL(ToSerialThread()),CH4_sp,SLOT (openPort()));
    connect(this,SIGNAL(m_senADconf(ADC_CONFIG)),CH4_sp,SLOT (setADconf(ADC_CONFIG)));
    connect(this,SIGNAL(sendCof2serial(Parameter)),CH4_sp,SLOT(receiveCof(Parameter)));
    connect(CH4_sp,SIGNAL(sendData2M(double,double)),this,SLOT(receiveDataFromS(double,double)));
    connect(CH4_sp,SIGNAL(sendSSig2Main(bool)),this,SLOT(receiveSSigFromS(bool)));
   // CH4_sp->moveToThread(seriai_thread);
   // seriai_thread->start();
    //=====================================================

    COF = new configuration();
    connect(COF,SIGNAL(sendCof2serial(Parameter)),CH4_sp,SLOT(receiveCof(Parameter)));
    connect(COF,SIGNAL(sendSerialSIG2Main(Parameter)),this,SLOT(receiveSerialSIGFromConf(Parameter)));
    connect(CH4_sp,SIGNAL(sendSSig2Conf(bool)),COF,SLOT(receiveSSig(bool)));
    connect(COF,SIGNAL(needData(bool)),CH4_sp,SLOT(receiveNeedSIG(bool)));
    connect(CH4_sp,SIGNAL(sendData2C(double*,double*,double*)),COF,SLOT(receiveDataFromS(double*,double*,double*)));

    //=====================================================

    connect(ui->system_Set,SIGNAL(triggered()),this,SLOT(open_Configuration()));    

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
    comboxinit();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::comboxinit()
{
    QStringList list;
    list.append("us");
    list.append("ms");
    ui->comboBox->addItems(list);
    list.clear();
    list.append("IO触发");
    list.append("周期");
    list.append("触发+周期");
    ui->comboBox_2->addItems(list);
    list.clear();
    list.append("上升沿");
    list.append("下降沿");
    list.append("均包括");
    ui->comboBox_3->addItems(list);
    list.clear();
    list.append("正负5V");
    list.append("正负10V");
    ui->comboBox_4->addItems(list);
    list.clear();
    list.append("NO");
    list.append("2");
    list.append("4");
    list.append("8");
    list.append("16");
    list.append("32");
    list.append("64");
    list.append("invalid");
    ui->comboBox_5->addItems(list);



}
void MainWindow::searchPort()
{
//    ui->comboBox->clear();
//    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
//    {
//        QSerialPort serial;
//        serial.setPort(info);
//        if(serial.open(QIODevice::ReadWrite))
//        {
//            ui->comboBox->addItem(serial.portName());
//            serial.close();

//        }
//    }
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
    // M_parameter.portname =ui->comboBox->currentText();
//     emit sendCof2serial(M_parameter);
//   //  Delay_MSec(50);
     emit ToSerialThread();





};
void MainWindow::on_pushButton_2_clicked()//采集数据
{

}
void MainWindow::on_pushButton_3_clicked()//配置参数
{
        ADC_CONFIG tmpcfg;

        BYTE index;


        tmpcfg.wTrigSize = ui->lineEdit->text().toInt() ;

        tmpcfg.dwMaxCycles = ui->lineEdit_2->text().toInt();

        tmpcfg.wPeriod =ui->lineEdit_3->text().toInt();
        tmpcfg.byADCOptions &= 0xC8;
        index = ui->comboBox->currentIndex() << 5;
        tmpcfg.byADCOptions += index;
        index = ui->comboBox_2->currentIndex();
        index = index << 4;
        tmpcfg.byADCOptions += index;
        index = ui->comboBox_3->currentIndex();
        tmpcfg.byADCOptions += index;
        index = 0;
        index = ui->comboBox_4->currentIndex();
        index += ui->comboBox_5->currentIndex() << 2;
        tmpcfg.byTrigOptions = index;
        emit m_senADconf(tmpcfg);


}
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
void MainWindow::receiveSerialSIGFromConf(Parameter sk)
{
    M_parameter=sk;
    on_pushButton_clicked();
}
void MainWindow::receiveDataFromS(double time, double data)
{

   CH4->Chart_Mupdata(*ui,time,data);   
   ui->lcdNumber_2->display(QString::number(data,'f',2));

}
void MainWindow::receiveSSigFromS(bool isopen)
{
   if(isopen)
   {
               //ui->comboBox->setEnabled(false);
               ui->pushButton->setText("设备已连接");
               ui->pushButton_fileselect->setEnabled(false);
               ui->saveCOCN->setEnabled(false);
               ui->COCN_interval->setEnabled(false);
                ui->pushButton_3->setEnabled(true);
               serialisopen=true;
               ui->label_5->clear();
   }
   else
   {
               //ui->comboBox->setEnabled(true);
               ui->pushButton_fileselect->setEnabled(true);
               ui->saveCOCN->setEnabled(true);
               ui->pushButton->setText("连接设备");
               ui->pushButton_3->setEnabled(false);
               ui->COCN_interval->setEnabled(true);
               serialisopen=false;
   }
}
void MainWindow::Delay_MSec(unsigned int msec)
{

        QTime _Timer = QTime::currentTime().addMSecs(msec);

        while( QTime::currentTime() < _Timer )

        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);

};
