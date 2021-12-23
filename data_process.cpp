#include "data_process.h"
#include "ui_data_process.h"
int IDidex=0;
QStringList filenames;
QStringList filepaths;
QStandardItemModel *OriginModel =new QStandardItemModel;
QStandardItemModel *AfterModel =new QStandardItemModel;
data_Process::data_Process(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::data_Process)
{

    ui->setupUi(this);
    Pch4 = new CH4_chart();
    Pch4->Chart_Pinit(*ui);
    OriginModel->setHorizontalHeaderLabels({"文件名"});
    ui->tableView->setModel(OriginModel);  //
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

data_Process::~data_Process()
{
    delete ui;
}

void data_Process::on_select_files_clicked()
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
     ui->textEdit->append("已选择"+message+"个文件。");

}

void data_Process::on_select_algorithm_clicked()
{

}

void data_Process::on_start_process_clicked()
{

        doProcess();

}
void data_Process::doProcess()
{
    int elementCntA=500; //元素个数
    double  *originData=new double[elementCntA]; //一维数组，用于C++向 MATLAB数组传递数据
    double  *after_s_e=new double[elementCntA];
    double *after_s=new double[elementCntA];
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
            QString filesname_after_s=filename.remove(filename.length()-4,4)+"_After_smooth.txt";
            QString filesname_after_s_e=filename+"_After_smooth&envelop.txt";
            //qDebug()<<filesname_after_s_e;
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
            mwArray d(5);//串窗口平滑参数
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
    Pch4->Chart_Pupdata(*ui,originData,after_s,after_s_e);
    ui->p_chart->replot();
}
