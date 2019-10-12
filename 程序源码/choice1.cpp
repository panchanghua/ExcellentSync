#include "choice1.h"
#include <QVBoxLayout>
#include <QMessageBox>

choice1::choice1(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowTitle("选择");
    b1.setParent(this);
    b1.setText("本地              直接链接到本地的电脑");
    //信号与槽是qt对象之间通信的接口
    //按下按钮执行sendslot发送信号
    connect(&b1, &QPushButton::released,this, &choice1::sendSlot1);

    b2.setParent(this);
    b2.move(0,50);
    b2.setText("网络              链接网络用户到本地电脑     ");
    connect(&b2, &QPushButton::released,this, &choice1::sendSlot2);
    resize(300,300);


    b3.setParent(this);
    b3.setText("手机有线     通过数据线链接手机到本地电脑");
    connect(&b3, &QPushButton::released,this, &choice1::sendSlot3);


    b4.setParent(this);
    b4.setText("手机无线     无线链接手机到本地电脑     ");
    connect(&b4, &QPushButton::released,this, &choice1::sendSlot4);

    b5.setParent(this);
    b5.setText("Windows      Linux和Windows的同步");
    connect(&b5, &QPushButton::released,this, &choice1::sendSlot5);


    b1.setMaximumSize(400,50);
    b1.setMinimumSize(400,50);

    b2.setMaximumSize(400,50);
    b2.setMinimumSize(400,50);

    b3.setMaximumSize(400,50);
    b3.setMinimumSize(400,50);

    b4.setMaximumSize(400,50);
    b4.setMinimumSize(400,50);

    b4.setMaximumSize(400,50);
    b4.setMinimumSize(400,50);

    QVBoxLayout *mainLayout = new QVBoxLayout;//布局方式
    mainLayout->addWidget(&b1);
    mainLayout->addWidget(&b2);
    mainLayout->addWidget(&b3);
    mainLayout->addWidget(&b4);
    mainLayout->addWidget(&b5);

    setLayout(mainLayout);


    b1.setIcon(QIcon(":/new/prefix1/本地.png"));
    b2.setIcon(QIcon(":/new/prefix1/网络.png"));
    b3.setIcon(QIcon(":/new/prefix1/有线.png"));
    b4.setIcon(QIcon(":/new/prefix1/无线.png"));
    b5.setIcon(QIcon(":/new/prefix1/Windows.png"));

    b1.setIconSize(QSize(50,50));
    b2.setIconSize(QSize(50,50));
    b3.setIconSize(QSize(50,50));
    b4.setIconSize(QSize(50,50));
    b5.setIconSize(QSize(50,50));

    b1.setStyleSheet("QPushButton { text-align:left; border: none;} QPushButton:hover{ background-color:#ACEBF8;}");
    b2.setStyleSheet("QPushButton { text-align:left; border: none;} QPushButton:hover{ background-color:#ACEBF8;}");
    b3.setStyleSheet("QPushButton { text-align:left; border: none;} QPushButton:hover{ background-color:#ACEBF8;}");
    b4.setStyleSheet("QPushButton { text-align:left; border: none;} QPushButton:hover{ background-color:#ACEBF8;}");
    b5.setStyleSheet("QPushButton { text-align:left; border: none;} QPushButton:hover{ background-color:#ACEBF8;}");
}

//sendslot发送信号
void choice1::sendSlot1()
{
    emit mySignal1();
}

//sendslot发送信号
void choice1::sendSlot2()
{
    emit mySignal2();
}

void choice1::sendSlot3()
{
    emit mySignal3();
}

void choice1::sendSlot4()
{
    emit mySignal4();
}

void choice1::sendSlot5()
{
    emit mySignal5();
}

void choice1::closeEvent(QCloseEvent *event)
{
    switch( QMessageBox::information(this,tr("提示"),tr("你确定关闭该窗口?"),tr("确定"), tr("取消"),0,1))
    {
    case 0:
        event->accept();
        widget->hide();
        break;
    case 1:
    default:
        event->ignore();
        break;
    }
}
