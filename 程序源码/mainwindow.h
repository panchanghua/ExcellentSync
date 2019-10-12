#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define NOTSYNC 0
#define TOONE 1
#define TOTWO 2
#define BOTH 3
#define ONLYONE 4
#define ONLYTWO 5
#define SDIR 6
#include <QMainWindow>
#include <QIcon>
#include <QPushButton>
#include "choice.h"
#include "choice1.h"
#include <QListWidgetItem>
#include<QTreeWidgetItem>
#include "input_filename.h"
#include "share.h"
#include "dialog.h"
#include "dialog1.h"
#include <QCloseEvent>
#include <QWidget>
#include "help_text.h"
#include "wifi1.h"
#include "wifi2.h"
#include "computer1.h"
#include "computer2.h"
#include "cancel.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
extern QString IP;
extern QString IP1;
typedef struct FILe
{
    int level;
    int flag;
    char path[500];
    char name[200];
    int stat;
    char parents[1000];
    int size;
    char mtime[100];
    char atime[100];
    QTreeWidgetItem* item;
}File;
typedef struct SYNC
{
    char pa1[400];
    char pa2[400];
    int flag;
    int level;
    int only;
    QPushButton *l;
    QPushButton *sy;
    QPushButton *r;
}Sync;
struct task{
    QString task_name;
    QString file_one;
    QString file_two;
};



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString on_file_create();
    QString ctoQS(char*);
    void Shielding_response();
    char* QStoc(QString);
    int level(char*,int);
    void analyze_1(int,int);
    void dir(char*,int);
    void SyStruct(int,int,int);
    void Warning(int);
    bool levelcmp(char*,char*);
    char* jian(char *,QString);
    void Writelog();
    void Writememory();
    void readmemory();
private slots:
    void dealSub1();
    void dealSub2();
    void dealSub3();
    void dealSub4();
    void dealnet1();
    void dealnet2();
    void dealusb1();
    void dealusb2();
    void dealwifi1();
    void dealwifi2();
    void dealcom1();
    void dealcom2();

    void sopen();
    void share1();
    void on_pushButton_4_clicked();
    void on_choice_1_clicked();

    void on_choice_2_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);
    void receiveData(QString data);

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();


    void change_background();
    void change_mode1();
    void change_mode2();
    void change_mode3();
    void on_exchange_clicked();
    void printf_text();
    void OpenLog();
    void CloseLog();
    void ClearLog();



    void on_button6_clicked();

    void judge_internet();
    void judge_internet1();

    void drop();

private:
    Ui::MainWindow *ui;
    Choice cho;
    choice1 cho1;
    QString path;
    input_filename task_text;
    share sha;
    Dialog dia;
    Dialog1 dia1;
    wifi1 wif1;
    wifi2 wif2;
    computer1 com1;
    computer2 com2;
    help_text a;
    cancel b;
    QTimer *timer;
    QTimer *timer1;

private:
    void closeEvent(QCloseEvent *event);

};

#endif // MAINWINDOW_H
