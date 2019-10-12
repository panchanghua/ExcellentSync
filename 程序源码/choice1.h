#ifndef CHOICE1_H
#define CHOICE1_H

#include <QWidget>
#include <QPushButton>
#include <QCloseEvent>
extern QWidget *widget;
class choice1 : public QWidget
{
    Q_OBJECT
public:
    explicit choice1(QWidget *parent = 0);
    void sendSlot1();
    void sendSlot2();
    void sendSlot3();
    void sendSlot4();
    void sendSlot5();

signals:
    void mySignal1();
    void mySignal2();
    void mySignal3();
    void mySignal4();
    void mySignal5();

public slots:


private:
    QPushButton b1;
    QPushButton b2;
    QPushButton b3;
    QPushButton b4;
    QPushButton b5;

private:
    void closeEvent(QCloseEvent *event);//关闭窗口相应函数
};

#endif // CHOICE1_H
