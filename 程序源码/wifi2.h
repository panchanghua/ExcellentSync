#ifndef WIFI2_H
#define WIFI2_H

#include <QDialog>
#include <QCloseEvent>
#include <QAbstractButton>
extern QWidget *widget;
namespace Ui {
class wifi2;
}

class wifi2 : public QDialog
{
    Q_OBJECT

public:
    explicit wifi2(QWidget *parent = 0);
    ~wifi2();
    int link();

public slots:
        void lineEdit_2();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void signal4();

private:
    Ui::wifi2 *ui;
    void closeEvent(QCloseEvent *event);
};

#endif // WIFI2_H
