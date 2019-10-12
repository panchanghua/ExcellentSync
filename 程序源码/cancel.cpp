#include "cancel.h"
#include "ui_cancel.h"
#include "QMessageBox"
#include <QPushButton>
#include <unistd.h>
#include "QDebug"
#include <QTimer>

int passwd_count=1;
cancel::cancel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cancel)
{
    ui->setupUi(this);
    ui->pushButton_3->setToolTip("查看密码");
    QIcon icon(":/new/prefix1/显示.png");
    ui->pushButton_3->setIcon(icon);
    ui->pushButton_3->setFlat(true);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    QTimer *timer= new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(lineEdit()));
    timer->start(0);
}

cancel::~cancel()
{
    delete ui;
}

void cancel::lineEdit()
{
    QString NAME1 = ui->lineEdit->text();
    QString NAME2 = ui->lineEdit_2->text();
    if((NULL != NAME1) && (NULL != NAME2) )
    {
        ui->pushButton->setEnabled(true);
    }
    else
    {
        ui->pushButton->setEnabled(false);
    }
}
void cancel::closeEvent(QCloseEvent *event)
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

void cancel::on_pushButton_clicked()
{
    QString temp=ui->lineEdit->text();
    QString passwd=ui->lineEdit_2->text();
    temp="/home/"+temp;
    char *ch;
    QByteArray ba = temp.toLocal8Bit();
    ch=ba.data();
    if( access(ch,F_OK) != 0 )
    {
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        QMessageBox *msgBox;
        msgBox=new QMessageBox("警告",		///--这里是设置消息框标题
            "未挂载此用户，请重新输入",						///--这里是设置消息框显示的内容
            QMessageBox::Critical,							///--这里是在消息框显示的图标
            QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
            QMessageBox::Cancel ,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
            0);
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->button(QMessageBox::Cancel)->hide();
        msgBox->show();
    }
    else
    {
        //判断本机密码是否有错
        QString judge;
        judge=judge+"echo "+passwd+"|"+"sudo -S cat /etc/passwd>/dev/null";
        char *ch;
        QByteArray ba = judge.toLocal8Bit();
        ch=ba.data();
        pid_t status1;
        status1=system(ch);
        if(status1 == -1)
        {
            qDebug()<<"error"<<endl;
        }
        else
        {
            if(WIFEXITED(status1))
            {
                if(0 == WEXITSTATUS(status1))//密码正确
                {
                    //取消挂载
                    QString str1="echo ";
                    str1=str1+passwd+'|'+"sudo -S umount "+temp;
                    char *ch1;
                    QByteArray ba1 = str1.toLocal8Bit();
                    ch1=ba1.data();
                    system(ch1);
                    qDebug()<<str1<<endl;

                    //删除文件
                    QString str2="echo ";
                    str2=str2+passwd+'|'+"sudo -S rm -r "+temp;
                    char *ch2;
                    QByteArray ba2 = str2.toLocal8Bit();
                    ch2=ba2.data();
                    system(ch2);
                    qDebug()<<str2<<endl;

                    this->accept();
                    widget->hide();
                    usleep(10);
                    QMessageBox *msgBox2;
                    msgBox2=new QMessageBox("提示","成功取消链接",
                                            QMessageBox::Critical,
                                            QMessageBox::Ok | QMessageBox::Default,
                                            QMessageBox::Cancel,
                                            0);
                    msgBox2->setWindowFlags(Qt::WindowStaysOnTopHint);
                    msgBox2->button(QMessageBox::Cancel)->hide();
                    msgBox2->show();
                    ui->lineEdit->clear();          //清空链接对话框里面的内容
                    ui->lineEdit_2->clear();
                }
                else
                {
                    ui->lineEdit->clear();          //清空链接对话框里面的内容
                    ui->lineEdit_2->clear();
                    QMessageBox *msgBox1;
                    msgBox1=new QMessageBox("警告",		///--这里是设置消息框标题
                        "本机密码输入有误,请确认",						///--这里是设置消息框显示的内容
                        QMessageBox::Critical,							///--这里是在消息框显示的图标
                        QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
                        QMessageBox::Cancel ,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
                        0);
                        msgBox1->setWindowFlags(Qt::WindowStaysOnTopHint);
                        msgBox1->button(QMessageBox::Cancel)->hide();
                    msgBox1->show();
                }
            }
            else
            {
                qDebug("exit code %d \n",WEXITSTATUS(status1));
            }
        }
    }
}

void cancel::on_pushButton_2_clicked()
{
    widget->hide();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    this->close();
}

void cancel::on_pushButton_3_clicked()
{
    if(passwd_count%2 == 1)
    ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    else
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    passwd_count+=1;
}
