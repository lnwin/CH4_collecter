#include "configuration.h"
#include "ui_configuration.h"
bool showChart;
Parameter C_parameter;
configuration::configuration(QWidget *parent) :
    QDialog(parent),
    ui_cof(new Ui::configuration)
{
    ui_cof->setupUi(this);
    ch4 =new CH4_chart();
    ch4->Chart_Cinit(*ui_cof);
    readConf();

}

configuration::~configuration()
{
    delete ui_cof;
}
void configuration::readConf()
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

       C_parameter.acc =sk.at(1).toDouble();
       C_parameter.win_d=sk.at(3).toDouble();
       C_parameter.a =sk.at(5).toDouble();
       C_parameter.b =sk.at(7).toDouble();
       C_parameter.saveSpectrum =sk.at(9).toDouble();
       C_parameter.spectrumfilepath =sk.at(11);
       C_parameter.COCNfilepath =sk.at(13);
       ui_cof->add_lin->setText(sk.at(1));
       ui_cof->win_n->setText(sk.at(3));
       ui_cof->a_n->setText(sk.at(5));
       ui_cof->b_n->setText(sk.at(7));
       if(C_parameter.saveSpectrum!=1)
       {
           ui_cof->ifSave->setChecked(false);
       }
       else
       {
           ui_cof->ifSave->setChecked(true);
       }
       ui_cof->Spectrumline->setText(sk.at(11));
       confFile.close();

  }
   else
   {
      QMessageBox msgBox ;
      msgBox.setText("配置文件缺失！");
      msgBox.exec();
   }



};
void configuration::on_pushButton_3_clicked()
{
    QFile confFile (QApplication::applicationDirPath()+"/configuration.txt");

    if(confFile.open(QIODevice::ReadWrite|QIODevice::Text))
    {

        confFile.write("accumulation");
        confFile.write("\n");
        confFile.write(ui_cof->add_lin->text().toLatin1().data());
        confFile.write("\n");
        confFile.write("filter");
        confFile.write("\n");
        confFile.write(ui_cof->win_n->text().toLatin1().data());
        confFile.write("\n");
        confFile.write("a");
        confFile.write("\n");
        confFile.write(ui_cof->a_n->text().toLatin1().data());
        confFile.write("\n");
        confFile.write("b");
        confFile.write("\n");
        confFile.write(ui_cof->b_n->text().toLatin1().data());
        confFile.write("\n");
        confFile.write("saveSpectrum");
        confFile.write("\n");
        if(ui_cof->ifSave->isChecked())
        {
            confFile.write("1");
            C_parameter.saveSpectrum=1;
        }
        else
        {
            confFile.write("0");
             C_parameter.saveSpectrum=0;
        }
        confFile.write("\n");
        confFile.write("spectrumfilepath");
        confFile.write("\n");
        confFile.write(ui_cof->Spectrumline->text().toLatin1().data());
        C_parameter.acc =ui_cof->add_lin->text().toDouble();
        C_parameter.win_d=ui_cof->win_n->text().toDouble();
        C_parameter.a =ui_cof->a_n->text().toDouble();
        C_parameter.b =ui_cof->b_n->text().toDouble();
        C_parameter.spectrumfilepath =ui_cof->Spectrumline->text();
        emit sendCof2serial(C_parameter);



   }
    else
    {

       QMessageBox msgBox ;
       msgBox.setText("打开配置文件失败！");
       msgBox.exec();
       confFile.close();
    }



}
void configuration::on_pushButton_2_clicked()
{
   QString srcDirPath = QFileDialog::getExistingDirectory( this, "Rec path", "/");
    if (srcDirPath.isEmpty())
    {
        return;
    }
    else
    {
        ui_cof->Spectrumline->setText(srcDirPath);

    }
}
void configuration::on_read_Button_clicked()
{
    emit sendSerialSIG2Main();
}
void configuration::receiveSSig(bool isopen)
{
    if(isopen)
    {
       ui_cof->a_n->setEnabled(false);
       ui_cof->b_n->setEnabled(false);
       ui_cof->Spectrumline->setEnabled(false);
       ui_cof->win_n->setEnabled(false);
       ui_cof->ifSave->setEnabled(false);
       ui_cof->add_lin->setEnabled(false);
       ui_cof->pushButton_2->setEnabled(false);
       ui_cof->read_Button->setText("停止读取光谱数据");
       showChart=true;
    }
    else
    {
        ui_cof->a_n->setEnabled(true);
        ui_cof->b_n->setEnabled(true);
        ui_cof->Spectrumline->setEnabled(true);
        ui_cof->win_n->setEnabled(true);
        ui_cof->ifSave->setEnabled(true);
        ui_cof->add_lin->setEnabled(true);
        ui_cof->pushButton_2->setEnabled(true);
        ui_cof->read_Button->setText("开始读取光谱数据");
        showChart=false;
    }

}
