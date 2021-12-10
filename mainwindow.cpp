#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
bool SAVEDATA_0=true;
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
    ui->filelineEdit->setText("D:/CH4_Collecter_DATA");
    connect(this,SIGNAL(sendSaveSig(bool)),CH4_sp,SLOT(receiveSaveSig(bool)));
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
void MainWindow::on_pushButton_fileselect_clicked()
{
    QString  srcDirPath = QFileDialog::getExistingDirectory( this, "Rec path", "/");
    if (srcDirPath.isEmpty())
    {
        return;
    }
    else
    {
        ui->filelineEdit->setText(srcDirPath) ;
        sendFilePath(srcDirPath);
    }
};
void MainWindow::on_checkBox_stateChanged(int a)
{
   // a==2,checked.
    if(a==2)
    {
       SAVEDATA_0=true;
       emit sendSaveSig(SAVEDATA_0);
    }
    else
    {
      SAVEDATA_0=false;
      emit sendSaveSig(SAVEDATA_0);
    }
}
