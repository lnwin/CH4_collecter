#ifndef SAVETHREAD_H
#define SAVETHREAD_H
#include <ui_mainwindow.h>
#include <QObject>
#include <qthread.h>
#include <qfile.h>
#include <qfiledialog.h>
#include <QTextStream>
#include <QDebug>
class savethread: public QThread
{
    Q_OBJECT
public:
    savethread();

    void run();
    void saveData_1(QString,QString);
    void SVD(QString,QString);

public slots:

};

#endif // SAVETHREAD_H
