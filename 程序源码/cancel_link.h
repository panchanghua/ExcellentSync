#ifndef CANCEL_LINK_H
#define CANCEL_LINK_H

#include <QDialog>

namespace Ui {
class cancel_link;
}

class cancel_link : public QDialog
{
    Q_OBJECT

public:
    explicit cancel_link(QWidget *parent = 0);
    ~cancel_link();

private:
    Ui::cancel_link *ui;
};

#endif // CANCEL_LINK_H
