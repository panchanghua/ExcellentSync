#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QCloseEvent>
#include "QAbstractButton"

extern QWidget *widget;
namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();
    int link();

public slots:
        void lineEdit_2();

private slots:
     void on_pushButton_clicked();
     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_4_clicked();

signals:
    void signal2();

private:
    Ui::Dialog1 *ui;
    void closeEvent(QCloseEvent *event); //关闭窗口相应函数
};

#endif // DIALOG1_H

