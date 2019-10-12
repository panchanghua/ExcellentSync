#ifndef CANCEL_H
#define CANCEL_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QCloseEvent>

extern QWidget *widget;
namespace Ui {
class cancel;
}

class cancel : public QDialog
{
    Q_OBJECT

public:
    explicit cancel(QWidget *parent = 0);
    ~cancel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void lineEdit();

    void on_pushButton_3_clicked();

private:
    Ui::cancel *ui;
    void closeEvent(QCloseEvent *event); //关闭窗口相应函数
};

#endif // CANCEL_H
