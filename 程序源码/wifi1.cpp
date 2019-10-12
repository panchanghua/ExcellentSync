#include "wifi1.h"
#include "ui_wifi1.h"
#include "QDebug"
#include "QString"
#include "QByteArray"
#include "QIODevice"
#include "QTextStream"
#include "QFile"
#include "QMessageBox"
#include "QCoreApplication"
#include "QTime"
#include "unistd.h"
#include "QAbstractButton"
#include "QPushButton"
#include "QTimer"
#include "QDialog"
#include "QMessageBox"
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int show_count_1_1=1;
int show_count_3_3=1;
wifi1::wifi1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wifi1)
{
    ui->setupUi(this);
    ui->pushButton_3->setToolTip("查看密码");
    ui->pushButton_4->setToolTip("查看密码");
    QIcon icon(":/new/prefix1/显示.png");
    ui->pushButton_3->setIcon(icon);
    ui->pushButton_3->setIconSize(QSize(24,24));
    ui->pushButton_3->setFlat(true);

    QIcon icon1(":/new/prefix1/显示.png");
    ui->pushButton_4->setIcon(icon1);
    ui->pushButton_4->setIconSize(QSize(24,24));
    ui->pushButton_4->setFlat(true);

    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    ui->pushButton_2->setEnabled(false);
    QTimer *timer= new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(lineEdit()));
    timer->start(0);
}
void wifi1::lineEdit()
{
    QString NAME1 = ui->lineEdit->text();
    QString NAME2 = ui->lineEdit_2->text();
    QString NAME3 = ui->lineEdit_3->text();
    QString NAME4 = ui->lineEdit_4->text();
    QString NAME5 = ui->lineEdit_5->text();
    if((NULL != NAME1) && (NULL != NAME2) && (NULL != NAME3) && (NULL != NAME4) && (NULL != NAME5))
    {
        ui->pushButton_2->setEnabled(true);
    }
    else
    {
        ui->pushButton_2->setEnabled(false);
    }
}

int wifi1::link()
{
    QString temp;
    QString user,passwd,address,local_passwd,port;
    QString fin_str;
    QString judge;
    QString rm;
    QString str="sudo -S curlftpfs -o rw,allow_other,uid=1000,gid=1000 ftp://";

    user=ui->lineEdit->text();
    passwd=ui->lineEdit_2->text();
    address=ui->lineEdit_3->text();
    local_passwd=ui->lineEdit_4->text();
    port=ui->lineEdit_5->text();

    //删除未成功挂载而创建的文件夹
    rm=rm+"echo "+local_passwd+"|"+"sudo -S rm -r"+" /home/"+user;
    qDebug()<<rm<<endl;
    char *delet;
    QByteArray baa = rm.toLocal8Bit();
    delet=baa.data();

    //判断本机密码是否有错
    judge=judge+"echo "+local_passwd+"|"+"sudo -S cat /etc/passwd>/dev/null";
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
            if(0 == WEXITSTATUS(status1))
            {
                qDebug()<<"run  successfully..."<<endl;
            }
            else
            {
                qDebug("run failed %d \n",WEXITSTATUS(status1));//密码错误
                ui->lineEdit->clear();          //清空链接对话框里面的内容
                ui->lineEdit_2->clear();
                ui->lineEdit_3->clear();
                ui->lineEdit_4->clear();
                ui->lineEdit_5->clear();
                system(delet);
                return 1;
            }
        }
        else
        {
            qDebug("exit code %d \n",WEXITSTATUS(status1));
        }
    }

    //合成挂载的命令
    str=str+user+":"+passwd+"@"+address+":"+port;
    qDebug()<<str<<endl;

    //合成创建的命令
    temp="echo "+local_passwd+"|"+"sudo -S mkdir"+" /home/"+user;
    qDebug()<<temp<<endl;

    //合成挂载的命令
    fin_str="echo "+local_passwd+"|"+str+" /home/"+user;
    qDebug()<<fin_str<<endl;

        char *ch2;
        QByteArray ba2 = temp.toLocal8Bit();
        ch2=ba2.data();
        system(ch2);

        char *ch3;
        QByteArray ba3 = fin_str.toLocal8Bit();
        ch3=ba3.data();
        pid_t status=system(ch3);
        //判断是否能挂载成功
        if(status == -1)
        {
           qDebug()<<"system error..."<<endl;
        }
        else
        {
           if(WIFEXITED(status))
           {
               if(0 == WEXITSTATUS(status))
               {
                   qDebug()<<"run  successfully..."<<endl;
               }
               else
               {
                    qDebug("run failed %d \n",WEXITSTATUS(status));//密码错误

                    ui->lineEdit->clear();          //清空链接对话框里面的内容
                    ui->lineEdit_2->clear();
                    ui->lineEdit_3->clear();
                    ui->lineEdit_4->clear();
                    ui->lineEdit_5->clear();
                    system(delet);
                    return 2;
               }
           }
           else
           {
               qDebug("exit code %d \n",WEXITSTATUS(status));
           }
        }

    ui->lineEdit->clear();          //清空链接对话框里面的内容
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    return 3;
}

void wifi1::closeEvent(QCloseEvent *event)
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
    ui->lineEdit->clear();          //清空链接对话框里面的内容
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}

wifi1::~wifi1()
{
    delete ui;
}

void wifi1::on_pushButton_3_clicked()
{
    if(show_count_1_1%2 == 1)
    ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    else
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    show_count_1_1+=1;
}

void wifi1::on_pushButton_4_clicked()
{
    if(show_count_3_3%2 == 1)
    ui->lineEdit_4->setEchoMode(QLineEdit::Normal);
    else
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    show_count_3_3+=1;
}

void wifi1::on_pushButton_clicked()
{
    widget->hide();
    ui->lineEdit->clear();          //清空链接对话框里面的内容
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    this->close();
}

void wifi1::on_pushButton_2_clicked()
{
    int a;
    a=link();
    widget->hide();
    wifi1::accept();
    usleep(10);
    if(a == 1)
    {
        QMessageBox *msgBox;
        msgBox = new QMessageBox("警告",		///--这里是设置消息框标题
        "本机密码输入有误，请重新尝试",						///--这里是设置消息框显示的内容
        QMessageBox::Critical,							///--这里是在消息框显示的图标
        QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
        QMessageBox::Cancel | QMessageBox::Escape,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
        0);
        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox->button(QMessageBox::Cancel)->hide();
        msgBox->show();
    }
    else if(a == 2)
    {
        QMessageBox *msgBox;
        msgBox = new QMessageBox("警告",		///--这里是设置消息框标题
        "挂载信息有误，请重新尝试",						///--这里是设置消息框显示的内容
        QMessageBox::Critical,							///--这里是在消息框显示的图标
        QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
        QMessageBox::Cancel | QMessageBox::Escape,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
        0);
        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox->button(QMessageBox::Cancel)->hide();
        msgBox->show();
    }
    else if(a == 3)
    {
        emit signal3();
    }
}
