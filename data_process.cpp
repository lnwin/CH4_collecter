#include "data_process.h"
#include "ui_data_process.h"

data_Process::data_Process(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::data_Process)
{
    ui->setupUi(this);
}

data_Process::~data_Process()
{
    delete ui;
}
