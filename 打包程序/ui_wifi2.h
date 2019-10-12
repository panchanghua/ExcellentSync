/********************************************************************************
** Form generated from reading UI file 'wifi2.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIFI2_H
#define UI_WIFI2_H

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

class Ui_wifi2
{
public:
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_5;
    QLabel *label_5;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QLabel *label_6;

    void setupUi(QDialog *wifi2)
    {
        if (wifi2->objectName().isEmpty())
            wifi2->setObjectName(QStringLiteral("wifi2"));
        wifi2->resize(400, 300);
        label_4 = new QLabel(wifi2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 10, 111, 31));
        label_3 = new QLabel(wifi2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 120, 71, 21));
        lineEdit_4 = new QLineEdit(wifi2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(160, 200, 113, 25));
        lineEdit_4->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        label_2 = new QLabel(wifi2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 80, 71, 21));
        lineEdit = new QLineEdit(wifi2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 40, 113, 25));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        pushButton_4 = new QPushButton(wifi2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(280, 200, 25, 25));
        pushButton = new QPushButton(wifi2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 250, 89, 25));
        pushButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(211, 215, 207);border-radius:10px;}\n"
"QPushButton:hover { background-color: rgb(107, 236, 154);}"));
        pushButton_2 = new QPushButton(wifi2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 250, 89, 25));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(211, 215, 207);border-radius:10px;}\n"
"QPushButton:hover { background-color: rgb(107, 236, 154);}"));
        lineEdit_2 = new QLineEdit(wifi2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(160, 80, 113, 25));
        lineEdit_2->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        pushButton_3 = new QPushButton(wifi2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(280, 80, 25, 25));
        lineEdit_5 = new QLineEdit(wifi2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(160, 160, 113, 25));
        lineEdit_5->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        label_5 = new QLabel(wifi2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 200, 81, 21));
        label = new QLabel(wifi2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 40, 71, 21));
        lineEdit_3 = new QLineEdit(wifi2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(160, 120, 113, 25));
        lineEdit_3->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        label_6 = new QLabel(wifi2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 160, 67, 17));

        retranslateUi(wifi2);

        QMetaObject::connectSlotsByName(wifi2);
    } // setupUi

    void retranslateUi(QDialog *wifi2)
    {
        wifi2->setWindowTitle(QApplication::translate("wifi2", "\346\211\213\346\234\272\346\227\240\347\272\277", 0));
        label_4->setText(QApplication::translate("wifi2", "\346\211\213\346\234\272\346\227\240\347\272\277\351\223\276\346\216\245\357\274\232", 0));
        label_3->setText(QApplication::translate("wifi2", " IP\345\234\260\345\235\200\357\274\232", 0));
        label_2->setText(QApplication::translate("wifi2", "      \345\257\206\347\240\201\357\274\232", 0));
        pushButton_4->setText(QString());
        pushButton->setText(QApplication::translate("wifi2", "Cancel", 0));
        pushButton_2->setText(QApplication::translate("wifi2", "Ok", 0));
        pushButton_3->setText(QString());
        label_5->setText(QApplication::translate("wifi2", " \346\234\254\345\234\260\345\257\206\347\240\201\357\274\232", 0));
        label->setText(QApplication::translate("wifi2", "     \345\270\220\345\217\267\357\274\232", 0));
        label_6->setText(QApplication::translate("wifi2", "       \347\253\257\345\217\243\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class wifi2: public Ui_wifi2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIFI2_H
