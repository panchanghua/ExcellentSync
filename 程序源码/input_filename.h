#ifndef INPUT_FILENAME_H
#define INPUT_FILENAME_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include "QMenu"
#include "QMenuBar"
#include "QAction"
#include "QMessageBox"
#include "QFileDialog"
#include "QDebug"
#include <stdio.h>
#include <QIcon>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringList>
#include <QSpinBox>
#include <QMenuBar>
extern QWidget *widget;
class input_filename : public QWidget
{
    Q_OBJECT
public:
    explicit input_filename(QWidget *parent = 0);
    void clear();


signals:
    void sendData(QString);

public slots:
    void sure_click();
    void text_lineEdit();
private:
    QLineEdit text;
    QLabel label;
    QPushButton sure;
    QString text1;

private:
    void closeEvent(QCloseEvent *event);//关闭窗口相应函数
};

#endif // INPUT_FILENAME_H
