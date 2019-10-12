/********************************************************************************
** Form generated from reading UI file 'cancel.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANCEL_H
#define UI_CANCEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_cancel
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *cancel)
    {
        if (cancel->objectName().isEmpty())
            cancel->setObjectName(QStringLiteral("cancel"));
        cancel->resize(400, 212);
        label = new QLabel(cancel);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 50, 131, 21));
        pushButton = new QPushButton(cancel);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 150, 89, 25));
        pushButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(211, 215, 207);border-radius:10px;}\n"
"QPushButton:hover { background-color: rgb(107, 236, 154);}"));
        lineEdit = new QLineEdit(cancel);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(190, 50, 111, 25));
        lineEdit->setStyleSheet(QStringLiteral("QLineEdit { background-color: rgb(211, 215, 207);border-radius:10px;}"));
        pushButton_2 = new QPushButton(cancel);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 150, 89, 25));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(211, 215, 207);border-radius:10px;}\n"
"QPushButton:hover { background-color: rgb(107, 236, 154);}"));
        label_2 = new QLabel(cancel);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 90, 81, 20));
        lineEdit_2 = new QLineEdit(cancel);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 90, 111, 25));
        lineEdit_2->setStyleSheet(QStringLiteral("QLineEdit { background-color: rgb(211, 215, 207);border-radius:10px;}"));
        pushButton_3 = new QPushButton(cancel);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 90, 25, 25));
        pushButton_3->setStyleSheet(QStringLiteral("QPushButton { background-color: rgb(211, 215, 207);border-radius:10px;}"));

        retranslateUi(cancel);

        QMetaObject::connectSlotsByName(cancel);
    } // setupUi

    void retranslateUi(QDialog *cancel)
    {
        cancel->setWindowTitle(QApplication::translate("cancel", "\345\217\226\346\266\210\346\214\202\350\275\275", 0));
        label->setText(QApplication::translate("cancel", "\345\217\226\346\266\210\351\223\276\346\216\245\347\232\204\347\224\250\346\210\267\345\220\215:", 0));
        pushButton->setText(QApplication::translate("cancel", "Ok", 0));
        pushButton_2->setText(QApplication::translate("cancel", "Cancel", 0));
        label_2->setText(QApplication::translate("cancel", "     \346\234\254\346\234\272\345\257\206\347\240\201:", 0));
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cancel: public Ui_cancel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANCEL_H
