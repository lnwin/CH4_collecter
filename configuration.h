#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QDialog>
#include <ch4_serial.h>
#include <ch4_chart.h>
namespace Ui {
class configuration;
}

class configuration : public QDialog
{
    Q_OBJECT

public:
    explicit configuration(QWidget *parent = nullptr);
    ~configuration();
     void readConf();


signals:
     void sendCof2serial(Parameter);
     void sendSerialSIG2Main();

private slots:

     void on_pushButton_3_clicked();
     void on_pushButton_2_clicked();
     void on_read_Button_clicked();
     void receiveSSig(bool);

private:
    Ui::configuration *ui_cof;
    CH4_chart *ch4;
};

#endif // CONFIGURATION_H
