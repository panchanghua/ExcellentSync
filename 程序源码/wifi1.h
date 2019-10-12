#ifndef WIFI1_H
#define WIFI1_H

#include <QDialog>
#include <QCloseEvent>
#include <QAbstractButton>
extern QWidget *widget;
namespace Ui {
class wifi1;
}

class wifi1 : public QDialog
{
    Q_OBJECT

public:
    explicit wifi1(QWidget *parent = 0);
    ~wifi1();
    int link();

public slots:
        void lineEdit();

private slots:
        void on_pushButton_3_clicked();

        void on_pushButton_4_clicked();

        void on_pushButton_clicked();

        void on_pushButton_2_clicked();

signals:
    void signal3();

private:
    Ui::wifi1 *ui;
    void closeEvent(QCloseEvent *event);
};

#endif // WIFI1_H
