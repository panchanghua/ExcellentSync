#ifndef HELP_TEXT_H
#define HELP_TEXT_H

#include <QWidget>

namespace Ui {
class help_text;
}

class help_text : public QWidget
{
    Q_OBJECT

public:
    explicit help_text(QWidget *parent = 0);
    ~help_text();

private:
    Ui::help_text *ui;
};

#endif // HELP_TEXT_H
