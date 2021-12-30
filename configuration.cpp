#include "configuration.h"
#include "ui_configuration.h"
int IDidex=0;
QStringList filenames;
QStringList filepaths;
QStandardItemModel *OriginModel =new QStandardItemModel;
bool showChart;
bool CneedData;
Parameter C_parameter;
configuration::configuration(QWidget *parent) :
    QDialog(parent),
    ui_cof(new Ui::configuration)
{

    ui_cof->setupUi(this);
    ch4 =new CH4_chart();
    //ch4->Chart_Cinit(*ui_cof);
    ch4->Chart_Pinit(*ui_cof);
    readConf();
     OriginModel->setHorizontalHeaderLabels({"文件名"});
     ui_cof->tableView->setModel(OriginModel);  //
     ui_cof->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
     ui_cof->tableView->resizeColumnsToContents();
     ui_cof->tableView->show();

     //this->setAttribute(Qt::WA_DeleteOnClose,true);

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
       C_parameter.USE_SMOOTH=sk.at(15).toDouble();
       qDebug()<<C_parameter.USE_SMOOTH;
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
       if(C_parameter.USE_SMOOTH !=1)
       {
           ui_cof->ifsmooth->setChecked(false);
       }
       else
       {
           ui_cof->ifsmooth->setChecked(true);
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
        confFile.write("\n");
        confFile.write("COCNfilepath");
        confFile.write("\n");
        confFile.write(C_parameter.COCNfilepath.toStdString().data());
        confFile.write("\n");
        confFile.write("use_smooth");
        confFile.write("\n");
        if(ui_cof->ifsmooth->isChecked())
        {
            confFile.write("1");
            C_parameter.USE_SMOOTH=1;
        }
        else
        {
            confFile.write("0");
             C_parameter.USE_SMOOTH=0;
        }
        confFile.write("\n");
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
       CneedData=true;
       emit needData(CneedData);
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
        CneedData=false;
        emit needData(CneedData);
    }

}
void configuration::on_select_files_clicked()
{

     IDidex=0;
     filenames = QFileDialog::getOpenFileNames(this,"选择数据文件",tr(""),tr("*.txt"));

     for(int i=0;i<filenames.count();i++)
     {
         OriginModel->setItem(IDidex, 0, new QStandardItem(filenames[i].split('/').last()));
         IDidex++;
     }
     QString message;
     message = QString::number(IDidex);
     ui_cof->textEdit->append("已选择"+message+"个文件。");

}
void configuration::doProcess()
{
    int elementCntA=500; //元素个数
    double  *originData=new double[elementCntA]; //一维数组，用于C++向 MATLAB数组传递数据
    double  *after_s_e=new double[elementCntA];
    double  *after_s=new double[elementCntA];
   // saveData_0(QString path,QString filename);
   // ***重要***smoothdata(int nargout, mwArray& y, mwArray& winsz, const mwArray& A, const mwArray& varargin); y为处理后输出的数据 A为需要输入的数据，varargin代表输入参数的个数，
       for (int i=0;i<IDidex;i++)
    {
        QString filename = filenames[i];
        QFile datafile(filename);
        if(!datafile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<"Can't open the file!"<<endl;
        }
        else
        {
         int count_N=0;
        while(!datafile.atEnd())
          {
            QByteArray line = datafile.readLine();
            QString str(line);
            originData[count_N]=str.toDouble();
            count_N++;
          }

            mwArray WINSZ(elementCntA,1,mxDOUBLE_CLASS, mxREAL);//需要和output纬度一样
            mwArray outPut(elementCntA,1,mxDOUBLE_CLASS, mxREAL);
            mwArray varargin(1);//输入参数的个数
            mwArray matrixA(elementCntA,1,mxDOUBLE_CLASS, mxREAL);//定义数组，行，列，double类型
            matrixA.SetData(originData,elementCntA); //将C++ 的一维数组arrayA存储到 MATLAB的二维数组matrixA
            smoothdata(1,outPut,WINSZ,matrixA,varargin);//
           // qDebug()<<filename.remove(filename.length()-4,4) ;
           // bool E1 = afterSMfilepath->exists(filename.split('/').)
            QString filesname_after_s=filename.remove(filename.length()-4,4)+"_After_smooth.txt";
            QString filesname_after_s_e=filename+"_After_smooth&envelop.txt";
            qDebug()<<filesname_after_s_e;
            QFile datafile(filesname_after_s);
            QTextStream stream(&datafile);
            if(datafile.open(QIODevice::WriteOnly | QIODevice::Text))
            {


                for (int j=0; j<elementCntA;j++)
                {

                    after_s[j] = outPut.Get(0,j+1);
                    stream<<QString::number(after_s[j])<<"\n";

                }

            }
             datafile.close();
            mwArray d(C_parameter.win_d);//串窗口平滑参数
            mwArray up_01(elementCntA,1,mxDOUBLE_CLASS, mxREAL);
            mwArray lo_01(elementCntA,1,mxDOUBLE_CLASS, mxREAL);
            mwArray method("peak");
            envelope(2,up_01,lo_01,outPut,d,method);//通过测试

            double *mid_01=new double[elementCntA];
            double a,b;

            for (int j=0; j<elementCntA;j++)
            {

                a = up_01.Get(0,j+1);
                b = lo_01.Get(0,j+1);
                mid_01[j]=(a+b)/2;


            }

            QFile datafile1(filesname_after_s_e);
            QTextStream stream1(&datafile1);
            if(datafile1.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                for (int j=0; j<elementCntA;j++)
                {

                    after_s_e[j] = mid_01[j];
                    stream1<<QString::number(after_s_e[j])<<"\n";

                }
            }
            datafile1.close();


        }
    }
    ch4->Chart_Pupdata(*ui_cof,originData,after_s,after_s_e);
    ui_cof->chart_widget->replot();
}
void configuration::on_start_process_clicked()
{
    doProcess();
};
void configuration::on_pushButton_4_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this,"选择处理后数据存储路径");
    ui_cof->textEdit->append("数据输出文件路径："+path);
    qDebug()<<path;
}
void configuration::closeEvent(QCloseEvent *event) //关闭窗体
{
     CneedData=false;
     emit needData(CneedData);
}
void configuration::receiveDataFromS(double *originData,double *after_s,double  *after_s_e)
{

    if(C_parameter.USE_SMOOTH !=1)
    {
        ch4->Chart_Pupdata_1(*ui_cof,originData,after_s_e);
    }
    else
    {
    ch4->Chart_Pupdata(*ui_cof,originData,after_s,after_s_e);
    }
    ui_cof->chart_widget->replot();

};
