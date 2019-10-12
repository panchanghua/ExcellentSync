#ifndef COMPUTER1_H
#define COMPUTER1_H

#include <QDialog>
#include <QCloseEvent>
#include <QAbstractButton>
extern QWidget *widget;
namespace Ui {
class computer1;
}

class computer1 : public QDialog
{
    Q_OBJECT

public:
    explicit computer1(QWidget *parent = 0);
    ~computer1();
    int link();

public slots:
        void lineEdit();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

signals:
    void signal5();

private:
    Ui::computer1 *ui;
    void closeEvent(QCloseEvent *event); //关闭窗口相应函数

};

#endif // COMPUTER1_H
