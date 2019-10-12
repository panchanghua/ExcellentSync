#include "help_text.h"
#include "ui_help_text.h"

help_text::help_text(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::help_text)
{
    ui->setupUi(this);

    ui->help->setText("你好，欢迎来到帮助文档");
    this->move(500,200);
}

help_text::~help_text()
{
    delete ui;
}
