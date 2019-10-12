/********************************************************************************
** Form generated from reading UI file 'computer1.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPUTER1_H
#define UI_COMPUTER1_H

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

class Ui_computer1
{
public:
    QLabel *label_5;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_6;

    void setupUi(QDialog *computer1)
    {
        if (computer1->objectName().isEmpty())
            computer1->setObjectName(QStringLiteral("computer1"));
        computer1->resize(400, 300);
        label_5 = new QLabel(computer1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(100, 210, 81, 21));
        label_4 = new QLabel(computer1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 10, 141, 31));
        lineEdit = new QLineEdit(computer1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(190, 50, 113, 25));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        pushButton_4 = new QPushButton(computer1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(310, 210, 25, 25));
        pushButton_2 = new QPushButton(computer1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 260, 89, 25));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(211, 215, 207);border-radius:10px;}\n"
"QPushButton:hover { background-color: rgb(107, 236, 154);}"));
        lineEdit_4 = new QLineEdit(computer1);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(190, 210, 113, 25));
        lineEdit_4->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        lineEdit_5 = new QLineEdit(computer1);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(190, 170, 113, 25));
        lineEdit_5->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        label_3 = new QLabel(computer1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 130, 131, 21));
        label_2 = new QLabel(computer1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 90, 131, 21));
        pushButton_3 = new QPushButton(computer1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 90, 25, 25));
        pushButton_3->setStyleSheet(QStringLiteral(""));
        lineEdit_3 = new QLineEdit(computer1);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(190, 130, 113, 25));
        lineEdit_3->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        lineEdit_2 = new QLineEdit(computer1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 90, 113, 25));
        lineEdit_2->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        label = new QLabel(computer1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 50, 121, 21));
        pushButton = new QPushButton(computer1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 260, 89, 25));
        pushButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(211, 215, 207);border-radius:10px;}\n"
"QPushButton:hover { background-color: rgb(107, 236, 154);}"));
        label_6 = new QLabel(computer1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(76, 170, 101, 20));

        retranslateUi(computer1);

        QMetaObject::connectSlotsByName(computer1);
    } // setupUi

    void retranslateUi(QDialog *computer1)
    {
        computer1->setWindowTitle(QApplication::translate("computer1", "Linux\344\270\216Windows\351\223\276\346\216\245", 0));
        label_5->setText(QApplication::translate("computer1", " \346\234\254\345\234\260\345\257\206\347\240\201\357\274\232", 0));
        label_4->setText(QApplication::translate("computer1", "  Linux\344\270\216Windows\357\274\232", 0));
        pushButton_4->setText(QString());
        pushButton_2->setText(QApplication::translate("computer1", "Ok", 0));
        label_3->setText(QApplication::translate("computer1", "   Windows IP\345\234\260\345\235\200:", 0));
        label_2->setText(QApplication::translate("computer1", "        Windows\345\257\206\347\240\201:", 0));
        pushButton_3->setText(QString());
        label->setText(QApplication::translate("computer1", " Windows\344\270\273\346\234\272\345\220\215:", 0));
        pushButton->setText(QApplication::translate("computer1", "Cancel", 0));
        label_6->setText(QApplication::translate("computer1", "     \345\205\261\344\272\253\346\226\207\344\273\266\345\244\271:", 0));
    } // retranslateUi

};

namespace Ui {
    class computer1: public Ui_computer1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPUTER1_H
