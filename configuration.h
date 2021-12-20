#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QDialog>
#include <ch4_serial.h>
namespace Ui {
class configuration;
}

class configuration : public QDialog
{
    Q_OBJECT

public:
    explicit configuration(QWidget *parent = nullptr);
    ~configuration();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_fileselect_clicked();

private:
    Ui::configuration *ui;
};

#endif // CONFIGURATION_H
