#include "data_process.h"
#include "ui_data_process.h"
int IDidex=0;
QStandardItemModel *OriginModel =new QStandardItemModel;
QStandardItemModel *AfterModel =new QStandardItemModel;
data_Process::data_Process(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::data_Process)
{

    ui->setupUi(this);

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
     QStringList filenames;
     QStringList filepaths;
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

}
