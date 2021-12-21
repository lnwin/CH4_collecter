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



private:
    Ui::configuration *ui;
};

#endif // CONFIGURATION_H
