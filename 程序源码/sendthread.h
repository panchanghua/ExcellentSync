#ifndef SENDTHREAD_H
#define SENDTHREAD_H
#include "mainwindow.h"
#include <QThread>
extern QVector<Sync> Sfile;
extern int syni;
extern int none;
class sendThread : public QThread
{
    Q_OBJECT
public:
    explicit sendThread(QObject *parent = 0);
protected:
    void run();
signals:
    void isdone();

public slots:
};

#endif // SENDTHREAD_H
