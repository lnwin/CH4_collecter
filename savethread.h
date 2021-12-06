#ifndef SAVETHREAD_H
#define SAVETHREAD_H
#include <ui_mainwindow.h>
#include <QObject>
#include <qthread.h>
class savethread: public QThread
{
    Q_OBJECT
public:
    savethread();
};

#endif // SAVETHREAD_H
