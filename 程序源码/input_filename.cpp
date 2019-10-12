#include "input_filename.h"
#include <QHBoxLayout>
#include <QShortcut>
#include <QTimer>
#include <QCloseEvent>
#include <QMessageBox>
#include <QLineEdit>
input_filename::input_filename(QWidget *parent) : QWidget(parent)
{
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    sure.setEnabled(false);//没有输入内容之前按钮不可用

   QTimer *timer= new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(text_lineEdit()));
   timer->start(0);
     this->setWindowTitle("命名");
      label.setText("请输入任务名称：");
      label.resize(100,20);
      label.move(0,0);
      text.setMaxLength(20);
      text.resize(100,40);
      text.move(200,0);

      sure.resize(40,40);
      sure.move(300,0);
      sure.setParent(this);
      sure.setText("确认");
      //sure->setShortcut(QT::Key_Enter);

      label.setParent(this);
      text.setParent(this);
      QHBoxLayout *mainLayout = new QHBoxLayout;
      mainLayout->addWidget(&label);
     mainLayout->addWidget(&text);

     mainLayout->addWidget(&sure);


      setLayout(mainLayout);
      connect(&sure,SIGNAL(clicked()),this,SLOT(sure_click()));
      QShortcut *key=new QShortcut(QKeySequence(Qt::Key_Return),this); //创建一个快捷键"Key_Return"键
      connect(key,SIGNAL(activated()),this,SLOT(sure_click()));//连接到指定槽函数


      QShortcut *key1=new QShortcut(QKeySequence(Qt::Key_Enter),this); //创建一个快捷键"Key_Return"键
      connect(key1,SIGNAL(activated()),this,SLOT(sure_click()));//连接到指定槽函数


      this->resize(500,200);
      this->move(400,250);

}
void input_filename::sure_click()
{
    text1 =text.text();
    emit sendData(text1);  //获取lineEdit的输入并且传递出去
    this->hide();
    widget->hide();
}
void input_filename::clear()
{
    text.setText("");
}
void input_filename::text_lineEdit()
{
    QString NAME = text.text();
    if(NULL != NAME)
    {
        sure.setEnabled(true);
    }

    if(NULL == NAME)
    {
        sure.setEnabled(false);
    }
   // sure.setEnabled(text.hasAcceptableInput());
}
void input_filename::closeEvent(QCloseEvent *event)
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

