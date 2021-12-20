#include "configuration.h"
#include "ui_configuration.h"
QString  srcDirPath;
configuration::configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configuration)
{
    ui->setupUi(this);
}

configuration::~configuration()
{
    delete ui;
}

void configuration::on_buttonBox_accepted()
{

}

void configuration::on_pushButton_fileselect_clicked()
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
