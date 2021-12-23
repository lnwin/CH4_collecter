#ifndef DATA_PROCESS_H
#define DATA_PROCESS_H

#include <QDialog>
#include <QFileDialog>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <ch4_chart.h>
#include <qcustomplot.h>
#include <smoothdata.h>
#include <envelope.h>
namespace Ui {
class data_Process;
}

class data_Process : public QDialog
{
    Q_OBJECT

public:
    explicit data_Process(QWidget *parent = nullptr);
    ~data_Process();
    void doProcess();
private slots:
    void on_select_files_clicked();

    void on_select_algorithm_clicked();

    void on_start_process_clicked();

private:
    Ui::data_Process *ui;
    CH4_chart *Pch4;
};

#endif // DATA_PROCESS_H
