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
     void readConf();


signals:
     void sendCof2serial(Parameter);

private slots:

     void on_pushButton_3_clicked();

private:
    Ui::configuration *ui;
};

#endif // CONFIGURATION_H
