#include "configuration.h"
#include "ui_configuration.h"
Parameter C_parameter;
configuration::configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configuration)
{
    ui->setupUi(this);

    readConf();

}

configuration::~configuration()
{
    delete ui;
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
       ui->add_lin->setText(sk.at(1));
       ui->win_n->setText(sk.at(3));
       ui->a_n->setText(sk.at(5));
       ui->b_n->setText(sk.at(7));
       if(C_parameter.saveSpectrum!=1)
       {
           ui->ifSave->setChecked(false);
       }
       else
       {
           ui->ifSave->setChecked(true);
       }
       ui->Spectrumline->setText(sk.at(11));
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
        confFile.write(ui->add_lin->text().toLatin1().data());
        confFile.write("\n");
        confFile.write("filter");
        confFile.write("\n");
        confFile.write(ui->win_n->text().toLatin1().data());
        confFile.write("\n");
        confFile.write("a");
        confFile.write("\n");
        confFile.write(ui->a_n->text().toLatin1().data());
        confFile.write("\n");
        confFile.write("b");
        confFile.write("\n");
        confFile.write(ui->b_n->text().toLatin1().data());
        confFile.write("\n");
        confFile.write("saveSpectrum");
        confFile.write("\n");
        if(ui->ifSave->isChecked())
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
        confFile.write(ui->Spectrumline->text().toLatin1().data());
        C_parameter.acc =ui->add_lin->text().toDouble();
        C_parameter.win_d=ui->win_n->text().toDouble();
        C_parameter.a =ui->a_n->text().toDouble();
        C_parameter.b =ui->b_n->text().toDouble();
        C_parameter.spectrumfilepath =ui->Spectrumline->text();
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
