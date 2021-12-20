#ifndef DATA_PROCESS_H
#define DATA_PROCESS_H

#include <QDialog>

namespace Ui {
class data_Process;
}

class data_Process : public QDialog
{
    Q_OBJECT

public:
    explicit data_Process(QWidget *parent = nullptr);
    ~data_Process();

private:
    Ui::data_Process *ui;
};

#endif // DATA_PROCESS_H
