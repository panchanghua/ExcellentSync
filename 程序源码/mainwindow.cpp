#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QListWidgetItem>
#include<QTreeWidgetItem>
#include <QPushButton>
#include <QDebug>
#include <QDir>
#include <QByteArray>
#include <time.h>
#include <dirent.h>
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <QWidget>
#include <QVector>
#include "sendthread.h"
#include "QTimer"
#include <QDesktopServices>
#include <QUrl>

QWidget *widget;
int task_num=0;
int task_click=-1;
struct task mytask[100];
QColor mcolor = "#F0F0F0";
QVector<File> fil1;
QVector<File> fil2;
QVector<Sync> Sfile;
int none;
long long int total1,total2;
QString path1;
QString path2;
char localpath[400];
int syni;
int samenum,leftnum,rightnum,bothnum,notnum;
int ret;
MainWindow::MainWindow(QWidget *parent) :               //构造函数
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->treeWidget->header()->setMovable(false);
    //ui->treeWidget->header();
    setWindowIcon(QIcon(":/new/prefix1/pic1/tubiao.png"));
    ui->mainToolBar->hide();
    ui->choice_1->setVisible(false);//按钮吟唱
    ui->choice_2->setVisible(false);
    ui->exchange->setVisible(false);
    //进度条
    ui->progressBar->hide();
    ui->progressBar->setMinimum(0);//最小值
    ui->progressBar->setValue(0);//当前值

    getcwd(localpath,sizeof(localpath));

    connect(&cho,&Choice::mySignal1,this, &MainWindow::dealSub1);
    connect(&cho1,&choice1::mySignal1,this, &MainWindow::dealSub2);

    connect(&cho,&Choice::mySignal2,this, &MainWindow::dealnet1);
    connect(&cho1,&choice1::mySignal2,this, &MainWindow::dealnet2);

    connect(&cho,&Choice::mySignal3,this, &MainWindow::dealusb1);
    connect(&cho1,&choice1::mySignal3,this, &MainWindow::dealusb2);

    connect(&cho,&Choice::mySignal4,this, &MainWindow::dealwifi1);
    connect(&cho1,&choice1::mySignal4,this, &MainWindow::dealwifi2);

    connect(&cho,&Choice::mySignal5,this, &MainWindow::dealcom1);
    connect(&cho1,&choice1::mySignal5,this, &MainWindow::dealcom2);

     QIcon ico1(":/new/prefix1/新建.png");
     ui->pushButton_4->setIconSize(QSize(48,48));
     ui->pushButton_4->setIcon(ico1);
     ui->pushButton_4->setFlat(true);

      QIcon ico2(":/new/prefix1/分析.png");
      ui->pushButton_3->setIconSize(QSize(48,48));
      ui->pushButton_3->setIcon(ico2);
      ui->pushButton_3->setFlat(true);

      QIcon ico3(":/new/prefix1/同步.png");
      ui->pushButton_5->setIconSize(QSize(48,48));
      ui->pushButton_5->setIcon(ico3);
      ui->pushButton_5->setFlat(true);
      this->move(200,20);

      QIcon ico4(":/new/prefix1/删除.png");
      ui->pushButton_6->setIconSize(QSize(48,48));
      ui->pushButton_6->setIcon(ico4);
      ui->pushButton_6->setFlat(true);


      QIcon ico5(":/new/prefix1/computer.png");
      ui->choice_1->setIconSize(QSize(48,48));
      ui->choice_1->setIcon(ico5);
      ui->choice_1->setFlat(true);
      this->move(200,20);

      QIcon ico6(":/new/prefix1/computer.png");
      ui->choice_2->setIconSize(QSize(48,48));
      ui->choice_2->setIcon(ico6);
      ui->choice_2->setFlat(true);

      QIcon ico7(":/new/prefix1/交换.png");
      ui->exchange->setIconSize(QSize(48,48));
      ui->exchange->setIcon(ico7);
      ui->exchange->setFlat(true);


      ui->treeWidget->setColumnWidth(0,150);
      ui->treeWidget->setColumnWidth(1,60);
      ui->treeWidget->setColumnWidth(2,150);
      ui->treeWidget->setColumnWidth(3,30);
      ui->treeWidget->setColumnWidth(4,30);
      ui->treeWidget->setColumnWidth(5,30);
      ui->treeWidget->setColumnWidth(6,60);
      ui->treeWidget->setColumnWidth(7,150);
      ui->treeWidget->setColumnWidth(8,150);

      ui->pushButton_3->setToolTip("分析");
      ui->pushButton_4->setToolTip("新建任务");
      ui->pushButton_5->setToolTip("同步");
      ui->pushButton_6->setToolTip("删除任务");
      ui->exchange->setToolTip("转换");



      connect(&task_text, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));

      //设置信号槽的联接


      //设置菜单兰信号槽的联接


      connect(ui->new_task, SIGNAL(triggered()), this, SLOT(on_pushButton_4_clicked()));
      connect(ui->delete_task, SIGNAL(triggered()), this, SLOT(on_pushButton_6_clicked()));
      connect(ui->change_bj, SIGNAL(triggered()), this, SLOT(change_background()));
      connect(ui->change_y, SIGNAL(triggered()), this, SLOT(change_mode1()));
      connect(ui->change_b, SIGNAL(triggered()), this, SLOT(change_mode2()));
      connect(ui->change_h, SIGNAL(triggered()), this, SLOT(change_mode3()));
      connect(ui->help_t, SIGNAL(triggered()), this, SLOT(printf_text()));

      connect(ui->action_4, SIGNAL(triggered()), this, SLOT(drop()));


      resize(1000,1000);
      ui->splitter->setStretchFactor(0,1);
      ui->splitter->setStretchFactor(1,4);

      //日志
      ui->text_log->hide();
      connect(ui->open_log, SIGNAL(triggered()), this, SLOT(OpenLog()));
      connect(ui->close_log, SIGNAL(triggered()), this, SLOT(CloseLog()));
      connect(ui->clear_log, SIGNAL(triggered()), this, SLOT(ClearLog()));
      ui->splitter_3->setStretchFactor(0,5);
      ui->splitter_3->setStretchFactor(1,2);


      ui->splitter_3->hide();
      ui->notsync->hide();
      ui->left->hide();
      ui->right->hide();
      ui->both->hide();
      ui->same->hide();
      ui->button6->hide();
      //ui->huan->hide();
        ui->same->setIcon(QIcon(":/new/image/3.png"));
        ui->notsync->setIcon(QIcon(":/new/image/1.png"));
        ui->left->setIcon(QIcon(":/new/image/left.png"));
        ui->right->setIcon(QIcon(":/new/image/right.png"));
        ui->both->setIcon(QIcon(":/new/image/2.png"));
        ui->same->setFlat(true);
        ui->notsync->setFlat(true);
        ui->left->setFlat(true);
        ui->right->setFlat(true);
        ui->both->setFlat(true);

        timer= new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(judge_internet()));

        timer1= new QTimer(this);
        connect(timer1,SIGNAL(timeout()),this,SLOT(judge_internet1()));


        readmemory();

}

//xierujiyi
void MainWindow::Writememory()
{
    QString temp="cp /dev/null ";
    temp=temp+ctoQS(localpath)+"/memory.txt";
    char *temp1=QStoc(temp);
    ret = system(temp1);
    QString str1,str2,str3;
    int i=0;
    QFile file(ctoQS(localpath)+"/memory.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text |QIODevice::Truncate);

    for(i=0;i<task_num;++i)
    {
        str1=mytask[i].task_name+"\n";
        str2=mytask[i].file_one+"\n";
        str3=mytask[i].file_two+"\n";
        file.write(str1.toUtf8());
        file.write(str2.toUtf8());
        file.write(str3.toUtf8());
        qDebug()<<task_num<<endl;
    }
    file.close();

}
//duqujiyi
void MainWindow::readmemory()
{
    if(task_num==0){
        int i;
        QString str1,str2,str3;
        QFile file(ctoQS(localpath)+"/memory.txt");
        file.open(QIODevice::ReadOnly|QIODevice::Text );
        while(!file.atEnd())
        {
            str1=file.readLine();
            str2=file.readLine();
            str3=file.readLine();
            mytask[task_num].task_name=str1.left(str1.length()-1);
            mytask[task_num].file_one=str2.left(str2.length()-1);
            mytask[task_num].file_two=str3.left(str3.length()-1);
            task_num+=1;
          }
    //task_num-=1;

        file.close();
        QStringList applications;
        if(task_num!=0)
        {
            ui->choice_1->show();
            ui->choice_2->show();
            ui->exchange->show();
        }

        for(i=task_num-1;i>=0;--i)
        {
            applications.append(mytask[i].task_name);

        }
        ui->listWidget->insertItems(0, applications);
    }
    ui->listWidget->setCurrentRow(0);

}
//open log
void MainWindow::OpenLog()  //打开日志
{
    ui->text_log->show();

}
//close log
void MainWindow::CloseLog() //关闭日志
{
    ui->text_log->hide();
}
//clear log
void MainWindow::ClearLog() //清楚日志
{
    ui->text_log->clear();
}
void MainWindow::Writelog()
{
    QString e = ui->text_log->toPlainText();
    QFile file(ctoQS(localpath)+"/synclog.log");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.write(e.toUtf8());
    file.close();
}
void MainWindow::sopen()
{
        qDebug() << 123;
}
void MainWindow::share1()
{
        sha.show();
}

void MainWindow::judge_internet()
{
    QString temp="timeout 5s ping -c 2 ";
    temp+=IP;
    char *ch;
    ch=QStoc(temp);
    pid_t status1;
    status1=system(ch);
    if(status1 == -1)
    {
        qDebug()<<"error1"<<endl;
    }
    else
    {
        if(WIFEXITED(status1))
        {
            if(0 == WEXITSTATUS(status1))
            {
                qDebug()<<"ping success"<<endl;
            }
            else
            {
                Warning(6);
                timer->stop();
            }
        }
        else
        {
            qDebug()<<"error3"<<endl;
        }
    }
}

void MainWindow::judge_internet1()
{
    QString temp="timeout 5s ping -c 2 ";
    temp+=IP1;
    char *ch;
    ch=QStoc(temp);
    pid_t status1;
    status1=system(ch);
    if(status1 == -1)
    {
        qDebug()<<"error1"<<endl;
    }
    else
    {
        if(WIFEXITED(status1))
        {
            if(0 == WEXITSTATUS(status1))
            {
                qDebug()<<"ping success"<<endl;
            }
            else
            {
                Warning(6);
                timer->stop();
            }
        }
        else
        {
            qDebug()<<"error3"<<endl;
        }
    }
}

void MainWindow::change_background()   //改变背景
{
    int r,g,b;
    r=rand()%360;
    g=rand()%256;
    b=rand()%200;
    qDebug("%d %d %d  \n",r,g,b);
    char str[30];
    sprintf(str,"background-color:rgb(%d,%d,%d)",r,g,b);

    QColor qc=QColor::fromHsl(r,g,b);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background,qc);

    this->setPalette(palette);
    ui->listWidget->setStyleSheet(str);
    ui->treeWidget->setStyleSheet(str);
    //this->setStyleSheet("color:black");
}

void MainWindow::change_mode1()   //日间模式
{
     mcolor = "#4F4F4F";
    this->setStyleSheet("color:rgb(211, 215, 207)");
   QColor qc=QColor::fromRgb(85, 87, 83);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background,qc);
    this->setPalette(palette);
    ui->listWidget->setStyleSheet("background-color:rgb(46, 52, 54)");
    ui->treeWidget->setStyleSheet("background-color:rgb(46, 52, 54)");
}

void MainWindow::change_mode2()  //夜间模式
{


    ui->listWidget->setStyleSheet("background-color:white");
    ui->treeWidget->setStyleSheet("background-color:white");
    this->setStyleSheet("background-color:none");
}

void MainWindow::change_mode3() //护眼模式
{
     mcolor = "#E0E0E0";
    ui->listWidget->setStyleSheet("background-color:rgb(199,237,204)");
    ui->treeWidget->setStyleSheet("background-color:rgb(199,237,204)");
    this->setStyleSheet("background-color:rgb(204,232,207)");
}

void MainWindow::printf_text()  //帮助文档
{
    QDesktopServices desktopServices;
    QUrl url(QString("index.html"));
   desktopServices.openUrl(url);
}

void MainWindow::drop()
{
    Shielding_response();//打开新窗口时设置屏蔽主窗口按钮
    b.show();
}
MainWindow::~MainWindow()
{
    Writelog();
    Writememory();
    delete ui;
}

void MainWindow::receiveData(QString data)   //接受input_filenam的信息
{
    if(data == NULL)
        return;
    ui->choice_1->setVisible(true);
    ui->choice_2->setVisible(true);
    ui->exchange->setVisible(true);
    int i,flag=0;                            //判断任务名重复
    for(i=0;i<task_num;i++)
    {
        if(mytask[i].task_name==data)
        {
            flag=1;
            break;
        }

    }

    if(1==flag)
    {
        Warning(5);
    }
    else{

        QStringList applications;
        applications.append(data);
        ui->listWidget->insertItems(0, applications);
        ui->choice_1->setText("请选择文件夹1");
        ui->choice_2->setText("请选择文件夹2");
        ui->listWidget->setCurrentRow(0);
        mytask[task_num].task_name=data;
        task_num+=1;
        task_click=-1;
    }
}

void MainWindow::dealSub1()   //打开文本选择框和choice1类相连
{
    MainWindow m;
    QString str;
     cho.hide();
    str=m.on_file_create();

    if(str!=0)
        ui->choice_1->setText(str);
    if(-1==task_click)
    {
        mytask[task_num-1].file_one=str;
    }
    else
    {
        mytask[task_click].file_one=str;
    }
    widget->hide();

}

void MainWindow::dealSub2()    //打开文本选择框和choice2类相连
{
    MainWindow m;
    QString str;
    cho1.hide();
    str=m.on_file_create();

    if(str!=0)
        ui->choice_2->setText(str);
    if(-1==task_click)
    {
        mytask[task_num-1].file_two=str;

    }
    else
    {
        mytask[task_click].file_two=str;

    }
    widget->hide();
}

void MainWindow::dealSub3()   //打开文本选择框和choice1类相连
{
    timer->start(0);
    MainWindow m;
    QString str;
     cho.hide();
    str=m.on_file_create();

    if(str!=0)
        ui->choice_1->setText(str);
    if(-1==task_click)
    {
        mytask[task_num-1].file_one=str;
    }
    else
    {
        mytask[task_click].file_one=str;
    }
    widget->hide();

}

void MainWindow::dealSub4()    //打开文本选择框和choice2类相连
{
    timer->start(0);
    MainWindow m;
    QString str;
    cho1.hide();
    str=m.on_file_create();

    if(str!=0)
        ui->choice_2->setText(str);
    if(-1==task_click)
    {
        mytask[task_num-1].file_two=str;

    }
    else
    {
        mytask[task_click].file_two=str;

    }
    widget->hide();
}

void MainWindow::dealnet1()  //dialog和左侧文本选择框相连
{
    cho.hide();
    dia.show();
    connect(&dia,&Dialog::signal1,this, &MainWindow::dealSub3);

}

void MainWindow::dealnet2()  //dialog1和右侧文本选择框相连
{
    cho1.hide();
    dia1.show();
    connect(&dia1,&Dialog1::signal2,this, &MainWindow::dealSub4);
}

void MainWindow::dealusb1()   //手机有线
{
    cho.hide();
    int nRet = QMessageBox::question(NULL, "提示", "手机正在链接中，请确保手机上已经开启usb传输文件功能", QMessageBox::Ok);
    if (QMessageBox::Ok == nRet) {
        dealSub1();
    }
    widget->hide();
}

void MainWindow::dealusb2()  //手机有线
{
    cho1.hide();
    int nRet = QMessageBox::question(NULL, "提示", "手机正在链接中，请确保手机上已经开启usb传输文件功能", QMessageBox::Ok);
    if (QMessageBox::Ok == nRet) {
        dealSub2();
    }
    widget->hide();
}

void MainWindow::dealwifi1()          //接受手机无线1
{
    cho.hide();
    wif1.show();
    connect(&wif1,&wifi1::signal3,this, &MainWindow::dealSub1);
}

void MainWindow::dealwifi2()          //接受手机无线2
{
    cho1.hide();
    wif2.show();
    connect(&wif2,&wifi2::signal4,this, &MainWindow::dealSub2);
}

void MainWindow::dealcom1()
{
    cho.hide();
    com1.show();
    connect(&com1,&computer1::signal5,this, &MainWindow::dealSub1);
}

void  MainWindow::dealcom2()
{
    cho1.hide();
    com2.show();
    connect(&com2,&computer2::signal6,this, &MainWindow::dealSub2);
}

QString MainWindow::on_file_create()    //打开文本选择框
{
        QFileDialog *fileDialog = new QFileDialog(this);//创建一个QFileDialog对象，构造函数中的参数可以有所添加。
        this->setWindowFlags(Qt::WindowStaysOnTopHint);
        fileDialog->setWindowTitle(tr("选择路径"));//设置文件保存对话框的标题
        fileDialog->setAcceptMode(QFileDialog::AcceptOpen);//设置文件对话框为open模式
        fileDialog->setFileMode(QFileDialog::DirectoryOnly);//设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
        fileDialog->setViewMode(QFileDialog::List);//文件以详细的形式显示，显示文件名，大小，创建日期等信息；

        fileDialog->setGeometry(10,30,500,400);//设置文件对话框的显示位置
        fileDialog->setDirectory("/home");//设置文件对话框打开时初始打开的位置
        if(fileDialog->exec() == QDialog::Accepted)
        {
            //注意使用的是QFileDialog::Accepted或者QDialog::Accepted,不是QFileDialog::Accept
           path = fileDialog->selectedFiles()[0];//得到用户选择的文件名
        }
        return path;
}

void MainWindow::Shielding_response() //打开新窗口时设置屏蔽主窗口按钮
{
    widget = new QWidget(this,Qt::FramelessWindowHint);
    widget->resize(this->size());
    widget->setObjectName("widget");// 设置对象句,相当于css里的id
    widget->setStyleSheet("#widget {background-color:rgba(10, 10, 10,100);}");// 设置id对应元素的背景色
    widget->show();
}

void MainWindow::on_pushButton_4_clicked()         //创建任务
{
        ui->splitter_3->hide();
        ui->same->hide();
        ui->right->hide();
        ui->left->hide();
        ui->notsync->hide();
        ui->both->hide();
        ui->button6->hide();
        ui->text_show->show();

        ui->treeWidget->clear();
        ui->listWidget->setCurrentRow(0);
        Shielding_response(); //打开新窗口时设置屏蔽主窗口按钮
        task_text.clear();
        task_text.show();
}

void MainWindow::on_choice_1_clicked()             //选择文件夹按钮的监听事件1
{
    Shielding_response();//打开新窗口时设置屏蔽主窗口按钮
    cho.move(400,250);
    cho.show();

}

void MainWindow::on_choice_2_clicked()                 //选择文件夹按钮监听事件2
{
    Shielding_response(); //打开新窗口时设置屏蔽主窗口按钮
    cho1.move(400,250);
    cho1.show();
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)       //listwidget的点击事件，让选择路径随不同的选择而改变
{
    ui->splitter_3->hide();
    ui->same->hide();
    ui->right->hide();
    ui->left->hide();
    ui->notsync->hide();
    ui->both->hide();
    ui->button6->hide();
    ui->text_show->show();

     ui->treeWidget->clear();
    int i=0;
    for(i=0;i<task_num;i++)
    {
        if(mytask[i].task_name==item->text())
        {
            task_click=i;
            break;
        }
    }
    if(mytask[task_click].file_one=="")
    {
         ui->choice_1->setText("请选择文件夹1");
    }
    else
    {
        ui->choice_1->setText(mytask[task_click].file_one);
    }
    if(mytask[task_click].file_two=="")
    {
         ui->choice_2->setText("请选择文件夹2");
    }
    else
    {
         ui->choice_2->setText(mytask[task_click].file_two);

    }
    Writelog();
    ClearLog();
}



void MainWindow::on_pushButton_6_clicked()      //任务的删除
{
    if(ui->listWidget->currentItem()!=Q_NULLPTR)
       {
           QListWidgetItem * item = ui->listWidget->takeItem(ui->listWidget->currentRow());
           int i=0,j=0;
           for(i=0;i<task_num;i++)
           {
               if(mytask[i].task_name==item->text())
               {
                   mytask[i].file_one="";
                   mytask[i].file_two="";
                   for(j=i;j<task_num;j++)
                   {
                       mytask[j]=mytask[j+1];
                   }
               }
           }

           task_num-=1;
           if(task_num==0)
           {
               ui->choice_1->setVisible(false);
               ui->choice_2->setVisible(false);
               ui->exchange->setVisible(false);
               ui->choice_1->setText("请选择文件夹1");
               ui->choice_2->setText("请选择文件夹2");
           }
           delete item;
       }
    else
    {
        Warning(1);
        return;
    }
    ui->treeWidget->clear();
    ui->button6->hide();
    ui->both->hide();
    ui->left->hide();
    ui->notsync->hide();
    ui->right->hide();
    ui->same->hide();
    ui->splitter_3->hide();
    ui->text_show->show();
    ui->choice_1->setText("请选择文件夹1");
    ui->choice_2->setText("请选择文件夹2");
}


/* QString 转char* */
char* MainWindow::QStoc(QString str)
{
    qDebug()<<str<<endl;
    char *ch;
    QByteArray ba = str.toLocal8Bit();
    ch=ba.data();
    return ch;
}
/* char* 转Qstring*/
QString MainWindow::ctoQS(char* ch)
{
     QString str = QString::fromLocal8Bit(ch);
     return str;
}
char* MainWindow::jian(char *file_path1,QString file_path2)
{
    char file_path[500] = {0};
    char file_path3[500] = {0};
    strcpy(file_path,QStoc(file_path2));
    qDebug("file_path:%s\n",file_path);
    int i,j,z = 0;
    for(i=0;file_path1[i]!='\0';++i)
    {
        if(file_path1[i]!=file_path[i])
            break;
    }
    for(j=i;file_path1[j]!='\0';++j)
    {
        file_path3[z] = file_path1[j];
        z = z+1;
    }
    file_path3[z] = '\0';
       qDebug()<<file_path2<<"   ";
    qDebug(" %s   %s\n",file_path1,file_path3);
    return file_path3;
}

/*弹窗警告*/
void MainWindow::Warning(int flag)
{
    QMessageBox *msgBox;
    if(flag == 1)
    {
        msgBox=new QMessageBox("警告",		///--这里是设置消息框标题
            "请先新建任务",						///--这里是设置消息框显示的内容
            QMessageBox::Critical,							///--这里是在消息框显示的图标
            QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
            QMessageBox::Cancel ,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
            0);
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->button(QMessageBox::Cancel)->hide();
    }
    else if(flag == 2)
    {
            msgBox = new QMessageBox("警告",		///--这里是设置消息框标题
                "请先选择文件夹",						///--这里是设置消息框显示的内容
                QMessageBox::Critical,							///--这里是在消息框显示的图标
                QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
                QMessageBox::Cancel | QMessageBox::Escape,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
                0);
             msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
             msgBox->button(QMessageBox::Cancel)->hide();
    }
    else if(flag == 3)
    {
        msgBox = new QMessageBox("警告",		///--这里是设置消息框标题
            "还有冲突文件未确定同步方向，请确定同步方向",						///--这里是设置消息框显示的内容
            QMessageBox::Critical,							///--这里是在消息框显示的图标
            QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
            QMessageBox::Cancel | QMessageBox::Escape,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
            0);
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->button(QMessageBox::Cancel)->hide();
    }
    else if(flag == 4)
    {
        msgBox = new QMessageBox("警告",		///--这里是设置消息框标题
            "选择文件已被更改,请重新选择",						///--这里是设置消息框显示的内容
            QMessageBox::Critical,							///--这里是在消息框显示的图标
            QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
            QMessageBox::Cancel | QMessageBox::Escape,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
            0);
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->button(QMessageBox::Cancel)->hide();
    }
    else if(flag==5)
    {
        msgBox = new QMessageBox("警告",		///--这里是设置消息框标题
            "任务已经存在，请重新创建",						///--这里是设置消息框显示的内容
            QMessageBox::Critical,							///--这里是在消息框显示的图标
            QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
            QMessageBox::Cancel | QMessageBox::Escape,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
            0);
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->button(QMessageBox::Cancel)->hide();
    }
    else if(flag==6)
    {
        msgBox = new QMessageBox("警告",		///--这里是设置消息框标题
            "对方已经断开链接，请不要进行任何分析同步操作（或选择本地同步），否则后果自负",						///--这里是设置消息框显示的内容
            QMessageBox::Critical,							///--这里是在消息框显示的图标
            QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
            QMessageBox::Cancel | QMessageBox::Escape,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
            0);
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->button(QMessageBox::Cancel)->hide();
    }
    else if(flag == 7)
    {
        QString A;
        A.sprintf("有%d个文件同步时被删除，请确认",none);
        msgBox = new QMessageBox("警告",		///--这里是设置消息框标题
            A,						///--这里是设置消息框显示的内容
            QMessageBox::Critical,							///--这里是在消息框显示的图标
            QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
            QMessageBox::Cancel | QMessageBox::Escape,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
            0);
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->button(QMessageBox::Cancel)->hide();
    }
    else if(flag == 8)
    {
        msgBox = new QMessageBox("警告",		///--这里是设置消息框标题
            "请先分析或者分析的文件夹为空",						///--这里是设置消息框显示的内容
            QMessageBox::Critical,							///--这里是在消息框显示的图标
            QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
            QMessageBox::Cancel | QMessageBox::Escape,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
            0);
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->button(QMessageBox::Cancel)->hide();
    }
        msgBox->show();
         //widget->hide();
}
/*返回目录级别*/
int MainWindow::level(char* path,int flag)
{

    char* ch;
    int i = 0,num = 0,mflag = 0;
    if(flag == 1)
        ch = QStoc(path1);
    else
        ch = QStoc(path2);
    while (path[i]!='\0')
    {
        if(mflag == 1)
        {
            if(path[i] == '/')
                num=num+1;
        }
        else if(ch[i] != path[i])
            mflag = 1;
        i=i+1;
    }
    return num;

}
/*比较父目录*/
bool MainWindow::levelcmp(char* dir,char* path)
{
    int i = 0;
    while(dir[i]!= '\0' && path[i] !='\0')
    {
        if(path[i] != dir[i])
        {
            return false;
        }
        ++i;
    }
    if(dir[i] == '\0')
        return true;
    else
        return false;
}
/*遍历存储文件夹中文件信息*/
void MainWindow::dir(char* path,int flag)
{
    File fil;
    DIR *dirptr = NULL;
    struct dirent *entry;
    char buf1[400],buf[400];
    long long int *total;
    struct stat stbuf;

    if(flag == 1)
      {
       total = &total1;
    }
    else if(flag == 2)
    {
        total = &total2;
    }
  //  qDebug("%s\n",path);
    int ret = chdir(path);
    if(ret == -1)
    {
        qDebug("chdir error\n");
        Warning(4);
        return ;
    }
    getcwd(buf1,sizeof(buf1));
    dirptr = opendir(buf1);
    while((entry = readdir(dirptr)))
    {
        strcpy(fil.parents,path); //存储父路径
        if(strcmp(".",entry->d_name) == 0 ||
                strcmp("..",entry->d_name) == 0 ||
                strcmp("e.txt",entry->d_name)==0 ||
                strcmp("synclog.log",entry->d_name) == 0 || (entry->d_name[0] == '.') )
        {
            continue;
        }
        else
        {
            strcpy(fil.name,entry->d_name); //储存名字

            sprintf(buf,"%s/%s",buf1,entry->d_name);
            ret = stat(buf,&stbuf);
            if(stbuf.st_mode&S_IRUSR && stbuf.st_mode&S_IWUSR)
            {
                qDebug("mode:1\n");
            }
            else
            {
                continue;
                qDebug("mode:0\n");
            }
            strcpy(fil.path,buf);//储存绝对路径
            fil.level = level(fil.path,flag);
            //qDebug("%s,%d\n",fil[*num].path,fil[*num].level);
            if(ret == -1)
            {
                qDebug("stat error\n");
            }
            if(S_ISDIR(stbuf.st_mode))
            {
                fil.stat = 1; //stat =1 dir
                fil.size = stbuf.st_size;
                strcpy(fil.atime,ctime(&(stbuf.st_atime)));
                 strcpy(fil.mtime,ctime(&(stbuf.st_mtime)));

            //    qDebug("%s\n",fil[*num].mtime);
               if(flag == 1)
                   fil1.append(fil);
               else
                   fil2.append(fil);
               *total = *total + stbuf.st_size;
                dir(buf,flag);
            }
            else
            {
            fil.stat = 0; //stat = 0 file
            fil.size = stbuf.st_size;
            strcpy(fil.atime,ctime(&(stbuf.st_atime)));
            strcpy(fil.mtime,ctime(&(stbuf.st_mtime)));
            *total = *total + stbuf.st_size;
             if(flag == 1)
                 fil1.append(fil);
             else
                 fil2.append(fil);
            }
        }
    }
}
/*int 型转char* */
/*把同步内容放入到同步结构体*/
void MainWindow::SyStruct(int i,int j,int flag)
{
    Sync sy;
    if(i == -1)  //只有右有文件
    {
        int bi=0,mflag = 0,bj = 0;
        char buff[400] = {0},buff1[400] = {0},re[100];
        char *pa,*pa1;
        pa = QStoc(path2);
        strcpy(re,"_repeat");
        /*获得文件名 buff*/
        while(fil2[j].path[bi] !='\0')
        {
            if(mflag == 1)
            {
                buff[bj] = fil2[j].path[bi];
                bj = bj+1;
            }
            if(fil2[j].path[bi] != pa[bi])
                mflag = 1;
            bi = bi+1;
        }
        buff[bi] = '\0';
        /*拼出目的文件绝对路径 buff1*/
        qDebug("%s\n",buff);
        pa1 = QStoc(path1);
        strcpy(buff1,pa1);
        strcat(buff1,"/");
        strcat(buff1,buff);
        qDebug("%s\n",buff1);
        /*存到结构体中*/
        strcpy(sy.pa1,buff1);
        strcpy(sy.pa2,fil2[j].path);
        sy.flag = ONLYONE;
        sy.level = fil2[j].level;
        sy.only = 1;
        if(flag == 1)
            sy.flag = SDIR;
        else
            leftnum = leftnum + 1;
        Sfile.append(sy);
    }
    else if(j == -1) //只有左有文件
    {
        int bi=0,mflag = 0,bj = 0;
        char buff[100],buff1[100],re[100];
        char *pa,*pa1;
        pa = QStoc(path1);
        strcpy(re,"(repeat)");
        /*获得文件名 buff*/
        while(fil1[i].path[bi] !='\0')
        {
            if(mflag == 1)
            {
                buff[bj] = fil1[i].path[bi];
                bj = bj+1;
            }
            if(fil1[i].path[bi] != pa[bi])
                mflag = 1;
            bi = bi+1;
        }
        buff[bj] = '\0';
        /*拼出目的文件绝对路径 buff1*/
        qDebug("%s\n",buff);
        pa1 = QStoc(path2);
        strcpy(buff1,pa1);
        strcat(buff1,"/");
        strcat(buff1,buff);
        qDebug("%s\n",buff1);
        /*存到结构体中*/
        strcpy(sy.pa2,buff1);
        strcpy(sy.pa1,fil1[i].path);
        sy.flag = ONLYTWO;
        sy.level = fil1[i].level;
        sy.only = 2;
        if(flag == 1)
            sy.flag = SDIR;
        else
            rightnum = rightnum + 1;
        Sfile.append(sy);
    }
    else //两边都有文件
    {
        strcpy(sy.pa1,fil1[i].path);
        strcpy(sy.pa2,fil2[j].path);
        sy.flag = BOTH;
        sy.level = fil1[i].level;
        sy.only = 0;
        if(flag == 1)
            sy.flag = SDIR;
        else
            bothnum = bothnum + 1;

        Sfile.append(sy);
    }

}
/*分析并显示到树状图*/
void MainWindow::analyze_1(int i,int j)
{
    int butt = 0;
    QTreeWidgetItem* item;
    item = new QTreeWidgetItem();
    if(i == -1) //只在fil2存在
    {
        QIcon dir = QIcon(":/new/image/dir.png");
        QIcon file = QIcon(":/new/image/file.png");
        qDebug("analyze fil2:%s,%d",fil2[j].path,fil2[j].stat);
        if(fil2[j].stat == 0)
        {
            item->setText(1,"none");
            item->setText(6,QString::number(fil2[j].size));
            item->setText(7,ctoQS(fil2[j].mtime));
            item->setText(8,"right");
            qDebug("file %s\n",fil2[j].name);
            item->setIcon(0,file);
            SyStruct(i,j,0);
        }
        else
        {
            SyStruct(i,j,1);
            for(int z=0;z<9;z++)
                item->setBackgroundColor(z,mcolor);
            item->setIcon(0,dir);
        }
        int si;
        for(si=0;si<Sfile.size();si++)
        {
            if(strcmp(fil2[j].path,Sfile[si].pa2) == 0 )
            {
                break;
            }
        }

        Sfile[si].l = new QPushButton();
        Sfile[si].l->setIcon(QIcon(":/new/image/left_empty.png"));
        Sfile[si].l->setFlat(true);
        Sfile[si].l->setIconSize(QSize(20,20));
        Sfile[si].sy = new QPushButton();
        Sfile[si].sy->setIcon(QIcon(":/new/image/3.png"));
        Sfile[si].sy->setFlat(true);

        Sfile[si].r= new QPushButton();
        Sfile[si].r->setIcon(QIcon(":/new/image/right_empty.png"));
        Sfile[si].r->setFlat(true);
        Sfile[si].r->setIconSize(QSize(20,20));
       // qDebug("i=-1,%s,%d,%s\n",fil2[j].name,fil2[j].level,fil2[j].parents);

        QString name = ctoQS(fil2[j].name);
         item->setText(0,name);

        if(fil2[j].level == 0)
                ui->treeWidget->addTopLevelItem(item);
        else
        {
            for(int z=0;z<fil2.size();z++)
            {
                if(strcmp(fil2[j].parents,fil2[z].path) == 0)
                {
                    fil2[z].item->addChild(item);
                    break;
                }
            }
        }
        if(fil2[j].stat == 0) //文件
        {
            Sfile[si].l->setIcon(QIcon(":/new/image/left.png"));
            ui->treeWidget->setItemWidget(item,3,Sfile[si].l);
            ui->treeWidget->setItemWidget(item,4,Sfile[si].sy);
            ui->treeWidget->setItemWidget(item,5,Sfile[si].r);
            connect(Sfile[si].l,&QPushButton::released, //监听向左同步按钮
                [=](){
            Sfile[si].sy->setIcon(QIcon(":/new/image/3.png"));
            Sfile[si].l->setIcon(QIcon(":/new/image/left.png"));

            if(Sfile[si].flag == NOTSYNC)
            {
                notnum = notnum - 1;
                leftnum = leftnum + 1;
            }
            QString num = QString::number(leftnum);
            QString str = "左同步(";
            str = str + num + ")";
            ui->left->setText(str);
            str = "不同步(";
            num = QString::number(notnum);
            str = str + num + ")";
            ui->notsync->setText(str);
            Sfile[si].flag = TOONE;

        });
        connect(Sfile[si].sy,&QPushButton::released,  //监听不同步按钮
                [=](){
            Sfile[si].sy->setIcon(QIcon(":/new/image/1.png"));
            Sfile[si].l->setIcon(QIcon(":/new/image/left_empty.png"));

            QString str,num;
            if(Sfile[si].flag == TOONE ||Sfile[si].flag == ONLYONE)
            {
                notnum = notnum + 1;
                leftnum = leftnum - 1;
            }
             num = QString::number(notnum);
             str = "不同步(";
            str = str + num + ")";
            ui->notsync->setText(str);
             num = QString::number(leftnum);
             str = "左同步(";
            str = str + num + ")";
            ui->left->setText(str);
            Sfile[si].flag = NOTSYNC;
         //   qDebug("%s %s %d",Sfile[si].pa1,Sfile[si].pa2,Sfile[si].flag);
        });
        }
          else //文件夹
        {
            ui->treeWidget->setItemWidget(item,3,Sfile[si].l);
            ui->treeWidget->setItemWidget(item,4,Sfile[si].sy);
            ui->treeWidget->setItemWidget(item,5,Sfile[si].r);
            connect(Sfile[si].l,&QPushButton::released,  //监听向左同步按钮
                    [=](){
                Sfile[si].l->setIcon(QIcon(":/new/image/left.png"));
                Sfile[si].r->setIcon(QIcon(":/new/image/right_empty.png"));
                Sfile[si].sy->setIcon(QIcon(":/new/image/3.png"));
                int sj = si+1;
                QString num,str;
                while (sj <Sfile.size())
                {
                    if(Sfile[sj].level > Sfile[si].level
                            && levelcmp(Sfile[si].pa1,Sfile[sj].pa1))
                    {
                        if(Sfile[sj].only!=2
                                && Sfile[sj].flag != TOONE
                                && Sfile[sj].flag != ONLYONE
                                 && Sfile[sj].flag != SDIR)
                        {

                            if(Sfile[sj].flag == NOTSYNC)
                            {
                                notnum = notnum - 1;
                                leftnum = leftnum + 1;
                            }
                            num = QString::number(leftnum);
                            str = "左同步(";
                           str = str + num + ")";
                           ui->left->setText(str);
                           num = QString::number(notnum);
                           str = "不同步(";
                          str = str + num + ")";
                          ui->notsync->setText(str);

                            Sfile[sj].flag = TOONE;
                            qDebug("%s %d",Sfile[sj].pa1,Sfile[sj].flag);
                            Sfile[sj].l->setIcon(QIcon(":/new/image/left.png"));
                            Sfile[sj].sy->setIcon(QIcon(":/new/image/3.png"));
                            Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                        }
                        else if(Sfile[sj].flag == SDIR)
                        {
                            Sfile[sj].l->setIcon(QIcon(":/new/image/left.png"));
                            Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                            Sfile[sj].sy->setIcon(QIcon(":/new/image/3.png"));
                        }
                    }
                        ++sj;
                }
            });
            connect(Sfile[si].r,&QPushButton::released,  //监听向右同步按钮
                    [=](){
                Sfile[si].l->setIcon(QIcon(":/new/image/left_empty.png"));
                Sfile[si].r->setIcon(QIcon(":/new/image/right.png"));
                Sfile[si].sy->setIcon(QIcon(":/new/image/3.png"));
                int sj = si+1;
                while (sj < Sfile.size())
                {
                    if(Sfile[sj].level > Sfile[si].level
                            && levelcmp(Sfile[si].pa1,Sfile[sj].pa1))
                    {
                        if(Sfile[sj].flag != SDIR)
                        {

                            QString str,num;
                            if(Sfile[sj].flag == TOONE ||Sfile[sj].flag == ONLYONE)
                            {
                                notnum = notnum + 1;
                                leftnum = leftnum - 1;
                            }
                            num = QString::number(notnum);
                            str = "不同步(";
                           str = str + num + ")";
                           ui->notsync->setText(str);
                           num = QString::number(leftnum);
                           str = "左同步(";
                          str = str + num + ")";
                          ui->left->setText(str);
                            Sfile[sj].flag = NOTSYNC;
                            Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                            Sfile[sj].sy->setIcon(QIcon(":/new/image/1.png"));
                            Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                        }
                        else if(Sfile[sj].flag == SDIR)
                        {
                            Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                            Sfile[sj].r->setIcon(QIcon(":/new/image/right.png"));
                            Sfile[sj].sy->setIcon(QIcon(":/new/image/3.png"));
                        }
                    }
                        ++sj;
                }
            });
            connect(Sfile[si].sy,&QPushButton::released,  //监听不同步按钮
                    [=](){
                Sfile[si].l->setIcon(QIcon(":/new/image/left_empty.png"));
                Sfile[si].r->setIcon(QIcon(":/new/image/right_empty.png"));
                Sfile[si].sy->setIcon(QIcon(":/new/image/1.png"));
                int sj = si+1;
                while (sj < Sfile.size())
                {
                    if(Sfile[sj].level > Sfile[si].level
                            && levelcmp(Sfile[si].pa1,Sfile[sj].pa1))
                    {
                    if(Sfile[sj].flag != NOTSYNC && Sfile[sj].flag != SDIR)
                    {
                        QString str,num;
                        if(Sfile[sj].flag == TOONE ||Sfile[sj].flag == ONLYONE)
                        {
                            notnum = notnum + 1;
                            leftnum = leftnum - 1;
                        }
                        num = QString::number(notnum);
                        str = "不同步(";
                       str = str + num + ")";
                       ui->notsync->setText(str);
                       num = QString::number(leftnum);
                       str = "左同步(";
                      str = str + num + ")";
                      ui->left->setText(str);

                        Sfile[sj].flag = NOTSYNC;
                        Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                        Sfile[sj].sy->setIcon(QIcon(":/new/image/1.png"));
                        Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                    }
                        else if(Sfile[sj].flag == SDIR)
                        {
                            Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                            Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                            Sfile[sj].sy->setIcon(QIcon(":/new/image/1.png"));
                        }
                    }
                        ++sj;
                }
            });
        }
        fil2[j].item = item;
    }  
    else if(j == -1)//只在fil1存在
    {
        item = new QTreeWidgetItem();
         item->setText(0,ctoQS(fil1[i].name));

        QIcon dir = QIcon(":/new/image/dir.png");
        QIcon file = QIcon(":/new/image/file.png");
        //qDebug("analyze:%s,%d",fil1[i].path,fil1[i].stat);
        if(fil1[i].stat == 0)
        {

         item->setText(6,"none");
         item->setText(8,"left");
         item->setText(1,QString::number(fil1[i].size));
         item->setText(2,ctoQS(fil1[i].mtime));
         qDebug("file %s,%d\n",fil1[i].path,fil1[i].stat);
         item->setIcon(0,file);
         SyStruct(i,j,0);
         }
         else
         {
            SyStruct(i,j,1);
            for(int z=0;z<9;z++)
                item->setBackgroundColor(z,mcolor);
             item->setIcon(0,dir);
         }

        int si;
        for(si=0;si<Sfile.size();si++)
        {
            if(strcmp(fil1[i].path,Sfile[si].pa1) == 0 )
            {
                break;
            }
        }
        //qDebug("j=-1\n");

        Sfile[si].l = new QPushButton();
        Sfile[si].l->setIcon(QIcon(":/new/image/left_empty.png"));
        Sfile[si].l->setFlat(true);
        Sfile[si].l->setIconSize(QSize(20,20));
        Sfile[si].sy = new QPushButton();
        Sfile[si].sy->setIcon(QIcon(":/new/image/3.png"));
        Sfile[si].sy->setFlat(true);
        Sfile[si].r= new QPushButton();
        Sfile[si].r->setIcon(QIcon(":/new/image/right_empty.png"));
        Sfile[si].r->setFlat(true);
        Sfile[si].r->setIconSize(QSize(20,20));

        if(fil1[i].level == 0)
                ui->treeWidget->addTopLevelItem(item);
        else
        {
            for(int z=0;z<fil1.size();z++)
            {
                if(strcmp(fil1[i].parents,fil1[z].path) == 0)
                {
                    fil1[z].item->addChild(item);
                    break;
                }
            }
        }
        if(fil1[i].stat == 0) //文件
        {
            /*只有fil1存在 只能更改为不同步（=）*/
            Sfile[si].r->setIcon(QIcon(":/new/image/right.png"));
            ui->treeWidget->setItemWidget(item,3,Sfile[si].l);
            ui->treeWidget->setItemWidget(item,4,Sfile[si].sy);
        connect(Sfile[si].sy,&QPushButton::released,  //监听不同步按钮
                [=](){
            Sfile[si].sy->setIcon(QIcon(":/new/image/1.png"));
            Sfile[si].r->setIcon(QIcon(":/new/image/right_empty.png"));

            QString str,num;
            if(Sfile[si].flag == TOTWO ||Sfile[si].flag == ONLYTWO)
            {
                notnum = notnum + 1;
                rightnum = rightnum - 1;
            }
            num = QString::number(notnum);
            str = "不同步(";
           str = str + num + ")";
           ui->notsync->setText(str);
           num = QString::number(rightnum);
           str = "右同步(";
          str = str + num + ")";
          ui->right->setText(str);

                    Sfile[si].flag = NOTSYNC;
        });
        ui->treeWidget->setItemWidget(item,5,Sfile[si].r);
        connect(Sfile[si].r,&QPushButton::released, //监听向右同步按钮
                [=](){
       //     qDebug("pushbutton  %d,%d",i,j);
            Sfile[si].sy->setIcon(QIcon(":/new/image/3.png"));
            Sfile[si].r->setIcon(QIcon(":/new/image/right.png"));

            QString str,num;
            if(Sfile[si].flag == NOTSYNC)
            {
                notnum = notnum - 1;
                rightnum = rightnum + 1;
            }
            num = QString::number(notnum);
            str = "不同步(";
           str = str + num + ")";
           ui->notsync->setText(str);
           num = QString::number(rightnum);
           str = "右同步(";
          str = str + num + ")";
          ui->right->setText(str);
            Sfile[si].flag = TOTWO;
        //   qDebug("%s %s %d",Sfile[si].pa1,Sfile[si].pa2,Sfile[si].flag);
        });
        }

        else  //文件夹
        {
            ui->treeWidget->setItemWidget(item,3,Sfile[si].l);
            ui->treeWidget->setItemWidget(item,4,Sfile[si].sy);
            ui->treeWidget->setItemWidget(item,5,Sfile[si].r);
            connect(Sfile[si].l,&QPushButton::released,  //监听向左同步按钮
                    [=](){
                Sfile[si].l->setIcon(QIcon(":/new/image/left.png"));
                Sfile[si].r->setIcon(QIcon(":/new/image/right_empty.png"));
                Sfile[si].sy->setIcon(QIcon(":/new/image/3.png"));
                int sj = si+1;
                while (sj < Sfile.size()){
                    if(Sfile[sj].level > Sfile[si].level
                            && levelcmp(Sfile[si].pa1,Sfile[sj].pa1))
                    {

                        if(Sfile[sj].flag != SDIR)
                        {
                            if(Sfile[sj].flag == ONLYTWO || Sfile[sj].flag == TOTWO)
                            {
                                notnum = notnum +1;
                                rightnum = rightnum - 1;
                            }
                            QString str,num;
                            num = QString::number(notnum);
                            str = "不同步(";
                            str = str + num + ")";
                            ui->notsync->setText(str);
                            num = QString::number(rightnum);
                            str = "右同步(";
                            str = str + num + ")";
                            ui->right->setText(str);

                            Sfile[sj].flag = NOTSYNC;
                            Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                            Sfile[sj].sy->setIcon(QIcon(":/new/image/1.png"));
                            Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                        }
                        else if(Sfile[sj].flag == SDIR)
                        {
                            Sfile[sj].l->setIcon(QIcon(":/new/image/left.png"));
                            Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                            Sfile[sj].sy->setIcon(QIcon(":/new/image/3.png"));
                        }
                    }
                        ++sj;
                }
            });
            connect(Sfile[si].r,&QPushButton::released,  //监听向右同步按钮
                    [=](){
                Sfile[si].l->setIcon(QIcon(":/new/image/left_empty.png"));
                Sfile[si].r->setIcon(QIcon(":/new/image/right.png"));
                Sfile[si].sy->setIcon(QIcon(":/new/image/3.png"));
                int sj = si+1;
                while (sj < Sfile.size()) {
                    if(Sfile[sj].level > Sfile[si].level
                            && levelcmp(Sfile[si].pa1,Sfile[sj].pa1))
                    {
                        if(Sfile[sj].only != 1
                                && Sfile[sj].flag != TOTWO
                                && Sfile[sj].flag != ONLYTWO
                                && Sfile[sj].flag != SDIR)
                        {
                            QString str,num;
                            if(Sfile[sj].flag == NOTSYNC)
                            {
                                notnum = notnum - 1;
                                rightnum = rightnum + 1;
                            }

                            num = QString::number(notnum);
                            str = "不同步(";
                            str = str + num + ")";
                            ui->notsync->setText(str);
                            num = QString::number(rightnum);
                            str = "右同步(";
                            str = str + num + ")";
                            ui->right->setText(str);

                            Sfile[sj].flag = TOTWO;
                            qDebug("%s %d",Sfile[sj].pa1,Sfile[sj].flag);
                            Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                            Sfile[sj].sy->setIcon(QIcon(":/new/image/3.png"));
                            Sfile[sj].r->setIcon(QIcon(":/new/image/right.png"));
                        }
                        else if(Sfile[sj].only == 1)
                        {
                            Sfile[sj].flag = NOTSYNC;
                            Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                            Sfile[sj].sy->setIcon(QIcon(":/new/image/1.png"));
                            Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                        }
                        else if(Sfile[sj].flag == SDIR)
                        {
                            Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                            Sfile[sj].r->setIcon(QIcon(":/new/image/right.png"));
                            Sfile[sj].sy->setIcon(QIcon(":/new/image/3.png"));
                        }
                    }
                    ++sj;
                }
            });
            connect(Sfile[si].sy,&QPushButton::released,  //监听不同步按钮
                    [=](){
                Sfile[si].l->setIcon(QIcon(":/new/image/left_empty.png"));
                Sfile[si].r->setIcon(QIcon(":/new/image/right_empty.png"));
                Sfile[si].sy->setIcon(QIcon(":/new/image/1.png"));
                int sj = si+1;
                while (sj < Sfile.size())
                        {
                    if(Sfile[sj].level > Sfile[si].level
                            && levelcmp(Sfile[si].pa1,Sfile[sj].pa1))
                    {
                    if(Sfile[sj].flag != NOTSYNC && Sfile[sj].flag != SDIR)
                    {
                        QString str,num;
                        if(Sfile[sj].flag == TOTWO ||Sfile[sj].flag == ONLYTWO)
                        {
                            notnum = notnum + 1;
                            rightnum = rightnum - 1;
                        }
                        num = QString::number(notnum);
                        str = "不同步(";
                        str = str + num + ")";
                        ui->notsync->setText(str);
                        num = QString::number(rightnum);
                        str = "右同步(";
                        str = str + num + ")";
                        ui->right->setText(str);

                        Sfile[sj].flag = NOTSYNC;
                        Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                        Sfile[sj].sy->setIcon(QIcon(":/new/image/1.png"));
                        Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                    }
                        else if(Sfile[sj].flag == SDIR)
                        {
                            Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                            Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                            Sfile[sj].sy->setIcon(QIcon(":/new/image/1.png"));
                        }
                    }
                          ++sj;
                }
            });
        }
        fil1[i].item = item;
    }
    else   //都存在需要对比
    {
        QIcon dir = QIcon(":/new/image/dir.png");
        QIcon file = QIcon(":/new/image/file.png");
        qDebug("analyze1:%s,%d",fil1[i].path,fil1[i].stat);
        qDebug("analyze2:%s,%d",fil2[j].path,fil2[j].stat);
        item = new QTreeWidgetItem();
        item->setText(0,ctoQS(fil1[i].name));
        if(fil1[i].stat != fil2[j].stat)
        {
            char buff[100];
            char buff1[100];
            fil1[i].flag = 0;
            fil2[j].flag = 0;
            if(fil1[i].stat == 0)
            {
                strcpy(buff1,fil1[i].path);
                strcat(buff1,"_repeat");
                sprintf(buff,"mv %s %s",fil1[i].path,buff1);
                ret = system(buff);
                strcpy(fil1[i].path,buff1);

            }
            else
            {
                strcpy(buff1,fil2[j].path);
                strcat(buff1,"_repeat");
                sprintf(buff,"mv %s %s",fil2[j].path,buff1);
                ret = system(buff);
                strcpy(fil2[j].path,buff1);
            }
            return ;
        }
        if(fil1[i].stat == 0)   //类型为文件
        {

            char cmd[1024]={0};
            struct stat st;
            memset(cmd,0,sizeof(cmd));
            ret = system("rm e.txt");
            sprintf(cmd,"diff %s %s  >>e.txt",fil1[i].path,fil2[j].path);
            ret = system(cmd);
            if(access("e.txt",F_OK)!=0)
                qDebug()<<"file isnot existence"<<endl;
            else
            {
                    int fd = open("e.txt",O_RDWR);
                    fstat(fd,&st);

                    if(st.st_size)
                      {
                        butt = 1;
          //              qDebug()<<"two file are diffenert!"<<endl;
                        item->setText(8,"change");
                        SyStruct(i,j,0);
                       }
                    else
                        {
                            item->setText(8,"the same");
            //                qDebug()<<"two file same OK!"<<endl;
                            samenum = samenum + 1;
                        }
            }

            item->setText(1,QString::number(fil1[i].size));
            item->setText(2,ctoQS(fil1[i].mtime));
            item->setText(6,QString::number(fil2[j].size));
            item->setText(7,ctoQS(fil2[j].mtime));
            item->setIcon(0,file);
        }
        else //类型为目录
        {

            SyStruct(i,j,1);
            for(int z=0;z<9;z++)
                item->setBackgroundColor(z,mcolor);
             item->setIcon(0,dir);
            butt = 2;
        }


        if(fil1[i].level == 0)  //在第一级目录
             ui->treeWidget->addTopLevelItem(item);
        else   // 不在第一级
        {
            //qDebug("%s\n",fil1[i].parents);
           // qDebug("%s\n",fil2[j].parents);
            for(int x=0;x<fil1.size();x++)
            {
                //找父目录
                if(strcmp(fil1[i].parents,fil1[x].path) == 0)
                {

                    fil1[x].item->addChild(item);
                }
        }
    }
      if(butt == 0)  //两文件相同
      {
              QPushButton *r = new QPushButton();
              QPushButton *l = new QPushButton();
              QPushButton *sy = new QPushButton();
              l->setIcon(QIcon(":/new/image/left_empty.png"));
              r->setIcon(QIcon(":/new/image/right_empty.png"));
              sy->setIcon(QIcon(":/new/image/3.png"));
              ui->treeWidget->setItemWidget(item,3,l);
              l->setFlat(true);
              l->setIconSize(QSize(20,20));
              ui->treeWidget->setItemWidget(item,4,sy);
              sy->setFlat(true);
              ui->treeWidget->setItemWidget(item,5,r);
              r->setFlat(true);
              r->setIconSize(QSize(20,20));
      }
      else //两文件不相同或为文件夹
      {
          int si;
          for(si=0;si<Sfile.size();++si)
          {
              if(strcmp(fil1[i].path,Sfile[si].pa1) == 0 )
              {
                  break;
              }
          }
          Sfile[si].l = new QPushButton();
          Sfile[si].l->setFlat(true);
          Sfile[si].l->setIconSize(QSize(20,20));
          Sfile[si].sy = new QPushButton();
          Sfile[si].sy->setFlat(true);
          Sfile[si].r = new QPushButton();
          Sfile[si].r->setFlat(true);
          Sfile[si].r->setIconSize(QSize(20,20));
          Sfile[si].l->setIcon(QIcon(":/new/image/left_empty.png"));
          Sfile[si].r->setIcon(QIcon(":/new/image/right_empty.png"));
          Sfile[si].sy->setIcon(QIcon(":/new/image/2.png"));
            if(butt == 1)  //butt=1 两个文件不同
            {
                ui->treeWidget->setItemWidget(item,3,Sfile[si].l);

                connect(Sfile[si].l,&QPushButton::released,  //监听向右同步按钮
                    [=](){
                    Sfile[si].sy->setIcon(QIcon(":/new/image/3.png"));
                    Sfile[si].r->setIcon(QIcon(":/new/image/right_empty.png"));
                    Sfile[si].l->setIcon(QIcon(":/new/image/left.png"));

                    QString str,num;
                    if(Sfile[si].flag == BOTH)
                    {
                        bothnum = bothnum - 1;
                        leftnum = leftnum + 1;
                    }
                    else if(Sfile[si].flag == TOTWO)
                    {
                        rightnum = rightnum - 1;
                        leftnum = leftnum + 1;
                    }
                    else if(Sfile[si].flag == NOTSYNC)
                    {
                        notnum = notnum - 1;
                        leftnum = leftnum + 1;
                    }
                    num = QString::number(notnum);
                    str = "不同步(";
                    str = str + num + ")";
                    ui->notsync->setText(str);
                    num = QString::number(rightnum);
                    str = "右同步(";
                    str = str + num + ")";
                    ui->right->setText(str);
                    num = QString::number(leftnum);
                    str = "左同步(";
                    str = str + num + ")";
                    ui->left->setText(str);
                    num = QString::number(bothnum);
                    str = "冲突(";
                    str = str + num + ")";
                    ui->both->setText(str);

                    Sfile[si].flag = TOONE;
                 //   qDebug("%s %s %d",Sfile[si].pa1,Sfile[si].pa2,Sfile[si].flag);
                });
                ui->treeWidget->setItemWidget(item,4,Sfile[si].sy);

                 connect(Sfile[si].sy ,&QPushButton::released,  //监听不同步按钮
                 [=](){
                //    qDebug("%d,%d",i,j);
                    Sfile[si].sy->setIcon(QIcon(":/new/image/1.png"));
                    Sfile[si].r->setIcon(QIcon(":/new/image/right_empty.png"));
                    Sfile[si].l->setIcon(QIcon(":/new/image/left_empty.png"));

                    QString str,num;
                    if(Sfile[si].flag == BOTH)
                    {
                        bothnum = bothnum - 1;
                        notnum = notnum + 1;
                    }
                    else if(Sfile[si].flag == TOTWO)
                    {
                         notnum = notnum + 1;
                        rightnum = rightnum - 1;
                    }
                    else if(Sfile[si].flag == TOONE)
                    {
                        notnum = notnum + 1;
                        leftnum = leftnum - 1;

                    }
                    num = QString::number(notnum);
                    str = "不同步(";
                    str = str + num + ")";
                    ui->notsync->setText(str);
                    num = QString::number(rightnum);
                    str = "右同步(";
                    str = str + num + ")";
                    ui->right->setText(str);
                    num = QString::number(leftnum);
                    str = "左同步(";
                    str = str + num + ")";
                    ui->left->setText(str);
                    num = QString::number(bothnum);
                    str = "冲突(";
                    str = str + num + ")";
                    ui->both->setText(str);
                            Sfile[si].flag = NOTSYNC;
                 });
                ui->treeWidget->setItemWidget(item,5,Sfile[si].r);

                connect(Sfile[si].r,&QPushButton::released,   //监听向右同步按钮
                [=](){
                 //   qDebug("totwo %d,%d",i,j);
                    Sfile[si].sy->setIcon(QIcon(":/new/image/3.png"));
                    Sfile[si].r->setIcon(QIcon(":/new/image/right.png"));
                    Sfile[si].l->setIcon(QIcon(":/new/image/left_empty.png"));

                    QString str,num;
                    if(Sfile[si].flag == BOTH)
                    {
                        bothnum = bothnum - 1;
                        rightnum = rightnum + 1;
                    }
                    else if(Sfile[si].flag == TOONE)
                    {
                        rightnum = rightnum + 1;
                        leftnum = leftnum - 1;
                    }
                    else if(Sfile[si].flag == NOTSYNC)
                    {
                        notnum = notnum - 1;
                        rightnum = rightnum + 1;
                    }
                    num = QString::number(notnum);
                    str = "不同步(";
                    str = str + num + ")";
                    ui->notsync->setText(str);
                    num = QString::number(rightnum);
                    str = "右同步(";
                    str = str + num + ")";
                    ui->right->setText(str);
                    num = QString::number(leftnum);
                    str = "左同步(";
                    str = str + num + ")";
                    ui->left->setText(str);
                    num = QString::number(bothnum);
                    str = "冲突(";
                    str = str + num + ")";
                    ui->both->setText(str);
                    Sfile[si].flag = TOTWO;
                });
            }

            else if(butt == 2)  //文件夹
            {
                Sfile[si].l->setIcon(QIcon(":/new/image/left_empty.png"));
                Sfile[si].r->setIcon(QIcon(":/new/image/right_empty.png"));
                Sfile[si].sy->setIcon(QIcon(":/new/image/3.png"));
                ui->treeWidget->setItemWidget(item,3,Sfile[si].l);
                ui->treeWidget->setItemWidget(item,4,Sfile[si].sy);
                ui->treeWidget->setItemWidget(item,5,Sfile[si].r);
                connect(Sfile[si].l,&QPushButton::released,  //监听向左同步按钮
                        [=](){
                    Sfile[si].l->setIcon(QIcon(":/new/image/left.png"));
                    Sfile[si].r->setIcon(QIcon(":/new/image/right_empty.png"));
                    Sfile[si].sy->setIcon(QIcon(":/new/image/3.png"));
                    int sj = si+1;
                    while (sj < Sfile.size()) {
                        if(Sfile[sj].level > Sfile[si].level
                                && levelcmp(Sfile[si].pa1,Sfile[sj].pa1))
                        {
                            if(Sfile[sj].only!=2
                                    && Sfile[sj].flag != TOONE
                                    && Sfile[sj].flag != ONLYONE
                                     && Sfile[sj].flag != SDIR)
                            {
                                QString str,num;
                                if(Sfile[sj].flag == BOTH)
                                {
                                    bothnum = bothnum - 1;
                                    leftnum = leftnum + 1;
                                }
                                else if(Sfile[sj].flag == TOTWO)
                                {
                                    rightnum = rightnum - 1;
                                    leftnum = leftnum + 1;
                                }
                                else if(Sfile[sj].flag == NOTSYNC)
                                {
                                    notnum = notnum - 1;
                                    leftnum = leftnum + 1;
                                }
                                num = QString::number(notnum);
                                str = "不同步(";
                                str = str + num + ")";
                                ui->notsync->setText(str);
                                num = QString::number(rightnum);
                                str = "右同步(";
                                str = str + num + ")";
                                ui->right->setText(str);
                                num = QString::number(leftnum);
                                str = "左同步(";
                                str = str + num + ")";
                                ui->left->setText(str);
                                num = QString::number(bothnum);
                                str = "冲突(";
                                str = str + num + ")";
                                ui->both->setText(str);

                                Sfile[sj].flag = TOONE;
                                qDebug("%s %d",Sfile[sj].pa1,Sfile[sj].flag);
                                Sfile[sj].l->setIcon(QIcon(":/new/image/left.png"));
                                Sfile[sj].sy->setIcon(QIcon(":/new/image/3.png"));
                                Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                            }
                            else if(Sfile[sj].only == 2)
                            {
                                QString str,num;
                                if(Sfile[sj].flag == TOTWO || Sfile[sj].flag == ONLYTWO)
                                {
                                    notnum = notnum + 1;
                                    rightnum = rightnum + 1;
                                }
                                num = QString::number(rightnum);
                                str = "右同步";
                                str = str + num + ")";
                                ui->right->setText(str);
                                num = QString::number(notnum);
                                str = "不同步(";
                                str = str + num + ")";
                                ui->notsync->setText(str);
                                Sfile[sj].flag = NOTSYNC;
                                Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                                Sfile[sj].sy->setIcon(QIcon(":/new/image/1.png"));
                                Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                            }
                            else if(Sfile[sj].flag == SDIR)
                            {
                                Sfile[sj].l->setIcon(QIcon(":/new/image/left.png"));
                                Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                                Sfile[sj].sy->setIcon(QIcon(":/new/image/3.png"));
                            }

                        }
                         ++sj;
                    }
                });
                connect(Sfile[si].r,&QPushButton::released,   //监听向右同步按钮
                        [=](){
                    Sfile[si].l->setIcon(QIcon(":/new/image/left_empty.png"));
                    Sfile[si].r->setIcon(QIcon(":/new/image/right.png"));
                    Sfile[si].sy->setIcon(QIcon(":/new/image/3.png"));
                    int sj = si+1;
                    while (sj < Sfile.size()) {
                        if(Sfile[sj].level > Sfile[si].level
                                && levelcmp(Sfile[si].pa1,Sfile[sj].pa1))
                        {
                            if(Sfile[sj].only != 1
                                    && Sfile[sj].flag != TOTWO
                                    && Sfile[sj].flag != ONLYTWO
                                    && Sfile[sj].flag != SDIR)
                            {
                                QString str,num;
                                if(Sfile[sj].flag == BOTH)
                                {
                                    bothnum = bothnum - 1;
                                    rightnum = rightnum + 1;
                                }
                                else if(Sfile[sj].flag == TOONE)
                                {
                                    rightnum = rightnum + 1;
                                    leftnum = leftnum - 1;
                                }
                                else if(Sfile[sj].flag == NOTSYNC)
                                {
                                    notnum = notnum - 1;
                                    rightnum = rightnum + 1;
                                }
                                num = QString::number(notnum);
                                str = "不同步(";
                                str = str + num + ")";
                                ui->notsync->setText(str);
                                num = QString::number(rightnum);
                                str = "右同步(";
                                str = str + num + ")";
                                ui->right->setText(str);
                                num = QString::number(leftnum);
                                str = "左同步(";
                                str = str + num + ")";
                                ui->left->setText(str);
                                num = QString::number(bothnum);
                                str = "冲突(";
                                str = str + num + ")";
                                ui->both->setText(str);

                                Sfile[sj].flag = TOTWO;
                                qDebug("%s %d",Sfile[sj].pa1,Sfile[sj].flag);
                                Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                                Sfile[sj].sy->setIcon(QIcon(":/new/image/3.png"));
                                Sfile[sj].r->setIcon(QIcon(":/new/image/right.png"));
                            }
                            else if(Sfile[sj].only == 1)
                            {
                                QString str,num;
                                if(Sfile[sj].flag == ONLYONE || Sfile[sj].flag == TOONE)
                                {
                                    notnum = notnum + 1;
                                    leftnum = leftnum - 1;
                                }
                                num = QString::number(leftnum);
                                str = "左同步(";
                                str = str + num + ")";
                                ui->left->setText(str);
                                num = QString::number(notnum);
                                str = "不同步(";
                                str = str + num + ")";
                                ui->notsync->setText(str);
                                Sfile[sj].flag = NOTSYNC;
                                Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                                Sfile[sj].sy->setIcon(QIcon(":/new/image/1.png"));
                                Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                            }
                            else if(Sfile[sj].flag == SDIR)
                            {
                                Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                                Sfile[sj].r->setIcon(QIcon(":/new/image/right.png"));
                                Sfile[sj].sy->setIcon(QIcon(":/new/image/3.png"));
                            }
                        }
                         ++sj;
                    }
                });
                connect(Sfile[si].sy,&QPushButton::released,   //监听不同步按钮
                        [=](){
                    Sfile[si].l->setIcon(QIcon(":/new/image/left_empty.png"));
                    Sfile[si].r->setIcon(QIcon(":/new/image/right_empty.png"));
                    Sfile[si].sy->setIcon(QIcon(":/new/image/1.png"));
                    int sj = si+1;
                    while (sj < Sfile.size()) {
                        if(Sfile[sj].level > Sfile[si].level
                                && levelcmp(Sfile[si].pa1,Sfile[sj].pa1))
                        {
                        if(Sfile[sj].flag != NOTSYNC && Sfile[sj].flag != SDIR)
                        {
                            QString str,num;
                            if(Sfile[sj].flag == BOTH)
                            {
                                bothnum = bothnum - 1;
                                notnum = notnum + 1;
                            }
                            else if(Sfile[sj].flag == TOTWO || Sfile[sj].flag == ONLYTWO)
                            {
                                 notnum = notnum + 1;
                                rightnum = rightnum - 1;
                            }
                            else if(Sfile[sj].flag == TOONE || Sfile[sj].flag == ONLYONE)
                            {
                                notnum = notnum + 1;
                                leftnum = leftnum - 1;

                            }
                            num = QString::number(notnum);
                            str = "不同步(";
                            str = str + num + ")";
                            ui->notsync->setText(str);
                            num = QString::number(rightnum);
                            str = "右同步(";
                            str = str + num + ")";
                            ui->right->setText(str);
                            num = QString::number(leftnum);
                            str = "左同步(";
                            str = str + num + ")";
                            ui->left->setText(str);
                            num = QString::number(bothnum);
                            str = "冲突(";
                            str = str + num + ")";
                            ui->both->setText(str);

                            Sfile[sj].flag = NOTSYNC;
                            Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                            Sfile[sj].sy->setIcon(QIcon(":/new/image/1.png"));
                            Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                        }
                            else if(Sfile[sj].flag == SDIR)
                            {
                                Sfile[sj].l->setIcon(QIcon(":/new/image/left_empty.png"));
                                Sfile[sj].r->setIcon(QIcon(":/new/image/right_empty.png"));
                                Sfile[sj].sy->setIcon(QIcon(":/new/image/1.png"));
                            }

                        }
                         ++sj;
                    }
                 });
                }
    }
      qDebug("test\n");
    //把tree变量赋值到结构体
       fil1[i].item = item;
       fil2[j].item = item;
    }

}
void MainWindow::on_pushButton_3_clicked()   //分析按钮的监听
{
    QString str,num;
    time_t t1,t2;
    if(fil1.size()!=0 || fil2.size() != 0)
    {
    fil1.clear();
    fil2.clear();
    Sfile.clear();
    leftnum = 0;
    rightnum = 0;
    bothnum = 0;
    notnum = 0;
    samenum = 0;
    }
    total1 = 0;
    total2 = 0;
    ui->treeWidget->clear();

    int i,j;
   path1 = ui->choice_1->text();
   path2 = ui->choice_2->text();
   if(task_num == 0)
   {
       Warning(1);
       return ;
   }
   if(path1 == "请选择文件夹1" || path2 == "请选择文件夹2")
   {
       Warning(2);
       return ;
   }

   ui->splitter_3->show();

   ui->button6->show();
   ui->text_show->hide();
//write log
   t1=time(NULL);
   ui->text_log->append(ctoQS(ctime(&t1))+"\n\n\n分析开始      ");
   ui->text_log->append(ctoQS(ctime(&t1))+"left :"+path1+"    right:"+path2);

   qDebug() << path1 << path2;
   char*  path_1;
   QByteArray ba1 = path1.toLocal8Bit(); // must
   path_1=ba1.data();

   char*  path_2;
   QByteArray ba2 = path2.toLocal8Bit(); // must
   path_2=ba2.data();
   dir(path_1,1);
   dir(path_2,2);

   ret = chdir(localpath);

   /*qDebug("that debug test\n");
   qDebug("fil1 num = %d\n",fil1.size());
   for(i=0;i<fil1.size();++i)
   {
       qDebug("path:%s\n",fil1[i].path);
   }
   for(j=0;j<fil2.size();++j)
   {
       qDebug("path:%s\n",fil2[j].path);
   }*/

   QTreeWidgetItem* item;
   item = new QTreeWidgetItem();
    item->setText(0,"项目");
    for(int z=0;z<9;z++)
        item->setBackgroundColor(z,mcolor);
   QPushButton *r = new QPushButton();
   r->setIcon(QIcon(":/new/image/right_empty.png"));
   r->setFlat(true);
   r->setIconSize(QSize(20,20));
   QPushButton *l = new QPushButton();
   l->setIcon(QIcon(":/new/image/left_empty.png"));
   l->setFlat(true);
   l->setIconSize(QSize(20,20));
   QPushButton *n = new QPushButton();
   n->setIcon(QIcon(":/new/image/3.png"));
   n->setFlat(true);
   ui->treeWidget->addTopLevelItem(item);
   ui->treeWidget->setItemWidget(item,3,l);
   ui->treeWidget->setItemWidget(item,4,n);
   ui->treeWidget->setItemWidget(item,5,r);
   //qDebug("num1,num2:%d,%d\n",num1,num2);
   //进行分析

   for(i=0;i<fil1.size();++i)
       fil1[i].flag = 0;
   for(j=0;j<fil2.size();++j)
       fil2[j].flag = 0;

  for(i=0;i<fil1.size();++i)
  {
     for(j=0;j<fil2.size();++j)
      {
         char p1[400],p2[400];
         strcpy(p1,jian(fil1[i].path,path1));
         strcpy(p2,jian(fil2[j].path,path2));
         qDebug("hahah %s %s\n",p1,p2);
        if(strcmp(p1,p2) == 0)
        {
            // fil1,fil2都有且在同一子目录下

            fil1[i].flag = 1;
            fil2[j].flag = 1;
            analyze_1(i,j);
         }
       //  qDebug("%s,%d,%d,%d\n",fil1[i].path,fil1[i].level,fil1[i].stat,i);
      //   qDebug("%s,%d,%d,%d\n",fil2[j].path,fil2[j].level,fil2[j].stat,j);
       }
   }
  qDebug("fil2num:%d\n",fil2.size());
  for(j=0;j<fil2.size();++j)
  {

      if(fil2[j].flag == 0)
      {
          //只有fil2有
          qDebug("onlyfil2\n");
          analyze_1(-1,j);
      }
  }
  for(i=0;i<fil1.size();++i)
  {
      if(fil1[i].flag == 0)
          analyze_1(i,-1);
  }
  num = QString::number(notnum);
  str = "不同步(";
  str = str + num + ")";
  ui->notsync->setText(str);
  num = QString::number(rightnum);
  str = "右同步(";
  str = str + num + ")";
  ui->right->setText(str);
  num = QString::number(leftnum);
  str = "左同步(";
  str = str + num + ")";
  ui->left->setText(str);
  num = QString::number(bothnum);
  str = "冲突(";
  str = str + num + ")";
  ui->both->setText(str);
  num = QString::number(samenum);
  qDebug()<<"num ="<<samenum<<"qstring"<<num<<endl;
  str = "相同(";
  str = str + num + ")";
  ui->same->setText(str);

  ui->same->show();
  ui->left->show();
  ui->right->show();
  ui->notsync->show();
  ui->both->show();
  connect(r,&QPushButton::released,
          [=](){
      r->setIcon(QIcon(":/new/image/right.png"));
      l->setIcon(QIcon(":/new/image/left_empty.png"));
      n->setIcon(QIcon(":/new/image/3.png"));
      int i;
      for(i=0;i<Sfile.size();++i)
      {
          if(Sfile[i].only != 1
                  && Sfile[i].flag != TOTWO
                  && Sfile[i].flag != ONLYTWO
                  && Sfile[i].flag != SDIR)
          {
              QString str,num;
              if(Sfile[i].flag == TOONE)
              {
                  rightnum = rightnum + 1;
                  leftnum = leftnum - 1;
              }
              else if(Sfile[i].flag == NOTSYNC)
              {
                  rightnum = rightnum + 1;
                  notnum = notnum - 1;
              }
              else if(Sfile[i].flag == BOTH)
              {
                  rightnum = rightnum + 1;
                  bothnum = bothnum - 1;
              }
              num = QString::number(notnum);
              str = "不同步(";
              str = str + num + ")";
              ui->notsync->setText(str);
              num = QString::number(rightnum);
              str = "右同步(";
              str = str + num + ")";
              ui->right->setText(str);
              num = QString::number(leftnum);
              str = "左同步(";
              str = str + num + ")";
              ui->left->setText(str);
              num = QString::number(bothnum);
              str = "冲突(";
              str = str + num + ")";
              ui->both->setText(str);

              Sfile[i].flag = TOTWO;
              Sfile[i].l->setIcon(QIcon(":/new/image/left_empty.png"));
              Sfile[i].sy->setIcon(QIcon(":/new/image/3.png"));
              Sfile[i].r->setIcon(QIcon(":/new/image/right.png"));
          }
          else if(Sfile[i].only == 1)
          {
              QString str,num;
              if(Sfile[i].flag == TOONE || Sfile[i].flag == ONLYONE)
                  {
                  notnum = notnum + 1;
                  leftnum = leftnum - 1;
              }
              num = QString::number(notnum);
              str = "不同步(";
              str = str + num + ")";
              ui->notsync->setText(str);
              num = QString::number(leftnum);
              str = "左同步(";
              str = str + num + ")";
              ui->left->setText(str);

              Sfile[i].flag = NOTSYNC;
              Sfile[i].l->setIcon(QIcon(":/new/image/left_empty.png"));
              Sfile[i].sy->setIcon(QIcon(":/new/image/1.png"));
              Sfile[i].r->setIcon(QIcon(":/new/image/right_empty.png"));
          }
          else if(Sfile[i].flag == SDIR)
          {
              Sfile[i].l->setIcon(QIcon(":/new/image/left_empty.png"));
              Sfile[i].sy->setIcon(QIcon(":/new/image/3.png"));
              Sfile[i].r->setIcon(QIcon(":/new/image/right.png"));
          }
      }
  });
  connect(l,&QPushButton::released,
          [=](){
      r->setIcon(QIcon(":/new/image/right_empty.png"));
      l->setIcon(QIcon(":/new/image/left.png"));
      n->setIcon(QIcon(":/new/image/3.png"));
      int i;
      for(i=0;i<Sfile.size();++i)
      {
          if(Sfile[i].only!=2
                  && Sfile[i].flag != TOONE
                  && Sfile[i].flag != ONLYONE
                   && Sfile[i].flag != SDIR)
          {
              QString str,num;
              if(Sfile[i].flag == TOTWO )
              {
                  leftnum = leftnum + 1;
                  rightnum  = rightnum - 1;
              }
              else if(Sfile[i].flag == NOTSYNC)
              {
                  leftnum = leftnum + 1;
                  notnum = notnum - 1;
              }
              else if(Sfile[i].flag == BOTH)
              {
                  leftnum = leftnum + 1;
                  bothnum = bothnum - 1;
              }
              num = QString::number(notnum);
              str = "不同步(";
              str = str + num + ")";
              ui->notsync->setText(str);
              num = QString::number(rightnum);
              str = "右同步(";
              str = str + num + ")";
              ui->right->setText(str);
              num = QString::number(leftnum);
              str = "左同步(";
              str = str + num + ")";
              ui->left->setText(str);
              num = QString::number(bothnum);
              str = "冲突(";
              str = str + num + ")";
              ui->both->setText(str);
              Sfile[i].flag = TOONE;
              qDebug("%s %d",Sfile[i].pa1,Sfile[i].flag);
              Sfile[i].l->setIcon(QIcon(":/new/image/left.png"));
              Sfile[i].sy->setIcon(QIcon(":/new/image/3.png"));
              Sfile[i].r->setIcon(QIcon(":/new/image/right_empty.png"));
          }
          else if(Sfile[i].only == 2)
          {
              QString str,num;
              if(Sfile[i].flag == TOTWO || Sfile[i].flag == ONLYTWO)
                  {
                  notnum = notnum + 1;
                  rightnum = rightnum - 1;

              }
              num = QString::number(notnum);
              str = "不同步(";
              str = str + num + ")";
              ui->notsync->setText(str);
              num = QString::number(rightnum);
              str = "右同步(";
              str = str + num + ")";
              ui->right->setText(str);

              Sfile[i].flag = NOTSYNC;
              Sfile[i].l->setIcon(QIcon(":/new/image/left_empty.png"));
              Sfile[i].sy->setIcon(QIcon(":/new/image/1.png"));
              Sfile[i].r->setIcon(QIcon(":/new/image/right_empty.png"));
          }
          else if(Sfile[i].flag == SDIR)
          {
              Sfile[i].l->setIcon(QIcon(":/new/image/left.png"));
              Sfile[i].sy->setIcon(QIcon(":/new/image/3.png"));
              Sfile[i].r->setIcon(QIcon(":/new/image/right_empty.png"));
          }
      }
  });
  connect(n,&QPushButton::released,[=](){
      r->setIcon(QIcon(":/new/image/right_empty.png"));
      l->setIcon(QIcon(":/new/image/left_empty.png"));
      n->setIcon(QIcon(":/new/image/1.png"));
      int i;
      for(i=0;i<Sfile.size();++i)
      {
          if(Sfile[i].flag != NOTSYNC && Sfile[i].flag != SDIR)
          {
              QString str,num;
              if(Sfile[i].flag == TOTWO || Sfile[i].flag == ONLYTWO)
              {
                  notnum = notnum + 1;
                  rightnum  = rightnum - 1;
              }
              else if(Sfile[i].flag == TOONE || Sfile[i].flag == ONLYONE)
              {
                  leftnum = leftnum - 1;
                  notnum = notnum + 1;
              }
              else if(Sfile[i].flag == BOTH)
              {
                  notnum = notnum + 1;
                  bothnum = bothnum - 1;
              }
              num = QString::number(notnum);
              str = "不同步(";
              str = str + num + ")";
              ui->notsync->setText(str);
              num = QString::number(rightnum);
              str = "右同步(";
              str = str + num + ")";
              ui->right->setText(str);
              num = QString::number(leftnum);
              str = "左同步(";
              str = str + num + ")";
              ui->left->setText(str);
              num = QString::number(bothnum);
              str = "冲突(";
              str = str + num + ")";
              ui->both->setText(str);

              Sfile[i].flag = NOTSYNC;
              Sfile[i].l->setIcon(QIcon(":/new/image/left_empty.png"));
              Sfile[i].sy->setIcon(QIcon(":/new/image/1.png"));
              Sfile[i].r->setIcon(QIcon(":/new/image/right_empty.png"));
          }
          else if(Sfile[i].flag == SDIR)
          {
              Sfile[i].l->setIcon(QIcon(":/new/image/left_empty.png"));
              Sfile[i].sy->setIcon(QIcon(":/new/image/1.png"));
              Sfile[i].r->setIcon(QIcon(":/new/image/right_empty.png"));
          }
      }
  });
  qDebug("sfile num = %d\n",Sfile.size());
  for(i=0;i<Sfile.size();++i)
  {
      qDebug("synum:%s,%d\n",Sfile[i].pa1,Sfile[i].level);
  }
  t2=time_t(NULL);
  ui->text_log->append(ctoQS(ctime(&t2))+"分析结束");

}

void MainWindow::on_pushButton_5_clicked()   //同步按钮的监听
{

    none = 0;

     time_t t1;
    ui->text_log->append("\n\n\n\n"+ctoQS(ctime(&t1))+"同步开始");

    int i,warin = 0;

    if(task_num == 0)
    {
        Warning(1);
        return ;
    }
    path1 = ui->choice_1->text();
    path2 = ui->choice_2->text();
    if(path1 == "请选择文件夹1" || path2 == "请选择文件夹2")
    {
        Warning(2);

        return ;
    }
    for(i=0;i<Sfile.size();++i)
    {
        if(Sfile[i].flag == BOTH)
        {
            warin = 1;
            break;
        }
    }
    if(warin != 0)
    {
        Warning(3);

        return ;
    }
    if(fil1.size() ==0 && fil2.size()==0 )
    {
        Warning(8);
        return;
    }
    if(total1 > 1073741824 || total2 > 1073741824)
    {
        int flag = QMessageBox::warning(this,tr("警告"),
                                        QString("文件夹大于1G 是否继续同步"),
                                        QMessageBox::Yes,QMessageBox::No);
        switch(flag)

        {

            case QMessageBox::Yes:

            {

                break;

            }

            case QMessageBox::No:

                return;

        }
    }

    ui->progressBar->setMaximum(Sfile.size());//最大值
    if(path1 != "请选择文件夹1" && path2 != "请选择文件夹2")
        ui->progressBar->show();
    usleep(1);
    for(syni = 0;syni < Sfile.size();++syni)
    {
        ui->progressBar->setValue(syni);
        qDebug("main syni:%d\n",syni);
        sendThread t;
        t.start();
        t1=time(NULL);
        ui->text_log->append(ctoQS(ctime(&t1))+Sfile[syni].pa2+"  ->  "+Sfile[syni].pa1);
        t.wait();

    }

     ui->progressBar->setValue(i);//当前值
    for(int a = 0;a<Sfile.size();++a)
    {
        Sfile[a].sy->setIcon(QIcon(":/new/image/1.png"));
        Sfile[a].r->setIcon(QIcon(":/new/image/right_empty.png"));
        Sfile[a].l->setIcon(QIcon(":/new/image/left_empty.png"));
    }
    t1=time(NULL);
    ui->text_log->append(ctoQS(ctime(&t1))+"同步结束");
    ui->progressBar->setValue(Sfile.size());
    sleep(1);
    ui->progressBar->setValue(0);
    ui->progressBar->hide();
    if(none != 0)
    {
        Warning(7);
    }
//    fclose(fp);
}

//关闭窗口相应函数
void MainWindow::closeEvent(QCloseEvent *event)
{
    switch( QMessageBox::information(this,tr("提示"),tr("你确定退出该软件?"),tr("确定"), tr("取消"),0,1))
    {
    case 0:
        event->accept();
        break;
    case 1:
    default:
        event->ignore();
        break;
    }
}

void MainWindow::on_exchange_clicked()    //转换按钮的监听
{
    QString str1,str2;
    str1=ui->choice_1->text();
    str2=ui->choice_2->text();
    ui->choice_1->setText(str2);
    ui->choice_2->setText(str1);

}

void MainWindow::on_button6_clicked()
{
    ui->treeWidget->clear();
    ui->button6->hide();
    ui->both->hide();
    ui->left->hide();
    ui->notsync->hide();
    ui->right->hide();
    ui->same->hide();
    if(fil1.size()!=0 || fil2.size() != 0)
    {
    fil1.clear();
    fil2.clear();
    Sfile.clear();
    leftnum = 0;
    rightnum = 0;
    bothnum = 0;
    notnum = 0;
    samenum = 0;
    }
}

