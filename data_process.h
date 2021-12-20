#ifndef DATA_PROCESS_H
#define DATA_PROCESS_H

#include <QDialog>
#include <QFileDialog>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
namespace Ui {
class data_Process;
}

class data_Process : public QDialog
{
    Q_OBJECT

public:
    explicit data_Process(QWidget *parent = nullptr);
    ~data_Process();

private slots:
    void on_select_files_clicked();

    void on_select_algorithm_clicked();

    void on_start_process_clicked();

private:
    Ui::data_Process *ui;
};

#endif // DATA_PROCESS_H
