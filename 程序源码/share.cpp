#include "share.h"
#include <QLineEdit>
share::share(QWidget *parent) :
    QWidget(parent)
{
    QLineEdit *name=new QLineEdit(this);
    name->setText("输入对方IP地址和分享文件的路径");
    resize(400,300);
}
