#include "cancel_link.h"
#include "ui_cancel_link.h"

cancel_link::cancel_link(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cancel_link)
{
    ui->setupUi(this);
}

cancel_link::~cancel_link()
{
    delete ui;
}
