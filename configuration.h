#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QDialog>
#include <ch4_serial.h>
#include <ch4_chart.h>
#include <QCloseEvent>
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
     void doProcess();
     void closeEvent(QCloseEvent *);

signals:
     void sendCof2serial(Parameter);
     void sendSerialSIG2Main();
     void needData(bool);

private slots:

     void on_pushButton_3_clicked();
     void on_pushButton_2_clicked();
     void on_read_Button_clicked();
     void receiveSSig(bool);
     void on_select_files_clicked();
     void on_start_process_clicked();   
     void on_pushButton_4_clicked();
     void receiveDataFromS(double *originData,double  *after_s_e,double  *after_s);

private:
    Ui::configuration *ui_cof;
    CH4_chart *ch4;
};

#endif // CONFIGURATION_H
