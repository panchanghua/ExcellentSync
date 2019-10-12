#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QAbstractButton>
extern QWidget *widget;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    int link();

public slots:
        void lineEdit();

private slots:
     void on_pushButton_clicked();
     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_4_clicked();

signals:
    void signal1();

private:
    Ui::Dialog *ui;
    void closeEvent(QCloseEvent *event); //关闭窗口相应函数
};

#endif // DIALOG_H

