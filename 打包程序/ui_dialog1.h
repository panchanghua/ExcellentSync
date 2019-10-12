/********************************************************************************
** Form generated from reading UI file 'dialog1.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG1_H
#define UI_DIALOG1_H

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

class Ui_Dialog1
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *pushButton;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *Dialog1)
    {
        if (Dialog1->objectName().isEmpty())
            Dialog1->setObjectName(QStringLiteral("Dialog1"));
        Dialog1->resize(400, 300);
        label = new QLabel(Dialog1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 80, 71, 21));
        lineEdit = new QLineEdit(Dialog1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 80, 113, 25));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        lineEdit_2 = new QLineEdit(Dialog1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 120, 113, 25));
        lineEdit_2->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        pushButton_2 = new QPushButton(Dialog1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 250, 89, 25));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(211, 215, 207);border-radius:10px;}\n"
"QPushButton:hover { background-color: rgb(107, 236, 154);}"));
        label_4 = new QLabel(Dialog1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 30, 111, 31));
        lineEdit_4 = new QLineEdit(Dialog1);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(170, 200, 113, 25));
        lineEdit_4->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        label_2 = new QLabel(Dialog1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 120, 71, 21));
        label_3 = new QLabel(Dialog1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 160, 71, 21));
        label_5 = new QLabel(Dialog1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 200, 81, 21));
        pushButton = new QPushButton(Dialog1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 250, 89, 25));
        pushButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(211, 215, 207);border-radius:10px;}\n"
"QPushButton:hover { background-color: rgb(107, 236, 154);}"));
        lineEdit_3 = new QLineEdit(Dialog1);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(170, 160, 113, 25));
        lineEdit_3->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        pushButton_3 = new QPushButton(Dialog1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(290, 120, 25, 25));
        pushButton_4 = new QPushButton(Dialog1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(290, 200, 25, 25));

        retranslateUi(Dialog1);

        QMetaObject::connectSlotsByName(Dialog1);
    } // setupUi

    void retranslateUi(QDialog *Dialog1)
    {
        Dialog1->setWindowTitle(QApplication::translate("Dialog1", "\347\275\221\347\273\234\351\223\276\346\216\245", 0));
        label->setText(QApplication::translate("Dialog1", "   \344\270\273\346\234\272\345\220\215\357\274\232", 0));
        pushButton_2->setText(QApplication::translate("Dialog1", "Ok", 0));
        label_4->setText(QApplication::translate("Dialog1", "\347\275\221\347\273\234\351\223\276\346\216\245\357\274\232", 0));
        label_2->setText(QApplication::translate("Dialog1", "      \345\257\206\347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("Dialog1", " IP\345\234\260\345\235\200\357\274\232", 0));
        label_5->setText(QApplication::translate("Dialog1", " \346\234\254\345\234\260\345\257\206\347\240\201\357\274\232", 0));
        pushButton->setText(QApplication::translate("Dialog1", "Cancel", 0));
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog1: public Ui_Dialog1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG1_H
