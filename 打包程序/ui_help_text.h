/********************************************************************************
** Form generated from reading UI file 'help_text.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_TEXT_H
#define UI_HELP_TEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_help_text
{
public:
    QHBoxLayout *horizontalLayout;
    QTextBrowser *help;

    void setupUi(QWidget *help_text)
    {
        if (help_text->objectName().isEmpty())
            help_text->setObjectName(QStringLiteral("help_text"));
        help_text->resize(566, 300);
        horizontalLayout = new QHBoxLayout(help_text);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        help = new QTextBrowser(help_text);
        help->setObjectName(QStringLiteral("help"));

        horizontalLayout->addWidget(help);


        retranslateUi(help_text);

        QMetaObject::connectSlotsByName(help_text);
    } // setupUi

    void retranslateUi(QWidget *help_text)
    {
        help_text->setWindowTitle(QApplication::translate("help_text", "\345\270\256\345\212\251\346\226\207\346\241\243", 0));
        help->setHtml(QApplication::translate("help_text", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class help_text: public Ui_help_text {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_TEXT_H
