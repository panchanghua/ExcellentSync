#ifndef COMPUTER2_H
#define COMPUTER2_H

#include <QDialog>
#include <QDialog>
#include <QCloseEvent>
#include <QAbstractButton>
extern QWidget *widget;
namespace Ui {
class computer2;
}

class computer2 : public QDialog
{
    Q_OBJECT

public:
    explicit computer2(QWidget *parent = 0);
    ~computer2();
     int link();

public slots:
        void lineEdit_2();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

signals:
    void signal6();

private:
    Ui::computer2 *ui;
    void closeEvent(QCloseEvent *event); //关闭窗口相应函数
};

#endif // COMPUTER2_H
