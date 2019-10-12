/********************************************************************************
** Form generated from reading UI file 'wifi1.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIFI1_H
#define UI_WIFI1_H

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

class Ui_wifi1
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLineEdit *lineEdit_5;
    QLabel *label_6;

    void setupUi(QDialog *wifi1)
    {
        if (wifi1->objectName().isEmpty())
            wifi1->setObjectName(QStringLiteral("wifi1"));
        wifi1->resize(400, 300);
        label = new QLabel(wifi1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 40, 71, 21));
        lineEdit = new QLineEdit(wifi1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 40, 113, 25));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        pushButton_4 = new QPushButton(wifi1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(290, 200, 25, 25));
        pushButton_3 = new QPushButton(wifi1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(290, 80, 25, 25));
        lineEdit_4 = new QLineEdit(wifi1);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(170, 200, 113, 25));
        lineEdit_4->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        label_2 = new QLabel(wifi1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 80, 71, 21));
        lineEdit_2 = new QLineEdit(wifi1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 80, 113, 25));
        lineEdit_2->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        pushButton = new QPushButton(wifi1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 250, 89, 25));
        pushButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(211, 215, 207);border-radius:10px;}\n"
"QPushButton:hover { background-color: rgb(107, 236, 154);}"));
        label_4 = new QLabel(wifi1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 10, 111, 31));
        label_5 = new QLabel(wifi1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 200, 81, 21));
        pushButton_2 = new QPushButton(wifi1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 250, 89, 25));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(211, 215, 207);border-radius:10px;}\n"
"QPushButton:hover { background-color: rgb(107, 236, 154);}"));
        lineEdit_3 = new QLineEdit(wifi1);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(170, 120, 113, 25));
        lineEdit_3->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        label_3 = new QLabel(wifi1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 120, 71, 21));
        lineEdit_5 = new QLineEdit(wifi1);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(170, 160, 113, 25));
        lineEdit_5->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        label_6 = new QLabel(wifi1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(80, 160, 67, 17));

        retranslateUi(wifi1);

        QMetaObject::connectSlotsByName(wifi1);
    } // setupUi

    void retranslateUi(QDialog *wifi1)
    {
        wifi1->setWindowTitle(QApplication::translate("wifi1", "\346\211\213\346\234\272\346\227\240\347\272\277", 0));
        label->setText(QApplication::translate("wifi1", "     \345\270\220\345\217\267\357\274\232", 0));
        pushButton_4->setText(QString());
        pushButton_3->setText(QString());
        label_2->setText(QApplication::translate("wifi1", "      \345\257\206\347\240\201\357\274\232", 0));
        pushButton->setText(QApplication::translate("wifi1", "Cancel", 0));
        label_4->setText(QApplication::translate("wifi1", "\346\211\213\346\234\272\346\227\240\347\272\277\351\223\276\346\216\245\357\274\232", 0));
        label_5->setText(QApplication::translate("wifi1", " \346\234\254\345\234\260\345\257\206\347\240\201\357\274\232", 0));
        pushButton_2->setText(QApplication::translate("wifi1", "Ok", 0));
        label_3->setText(QApplication::translate("wifi1", " IP\345\234\260\345\235\200\357\274\232", 0));
        label_6->setText(QApplication::translate("wifi1", "       \347\253\257\345\217\243\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class wifi1: public Ui_wifi1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIFI1_H
