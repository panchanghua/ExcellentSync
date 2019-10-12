/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

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

class Ui_Dialog
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

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 70, 71, 21));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 70, 113, 25));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 110, 113, 25));
        lineEdit_2->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 240, 89, 25));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(211, 215, 207);border-radius:10px;}\n"
"QPushButton:hover { background-color: rgb(107, 236, 154);}"));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 20, 111, 31));
        lineEdit_4 = new QLineEdit(Dialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(170, 190, 113, 25));
        lineEdit_4->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 110, 71, 21));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 150, 71, 21));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 190, 81, 21));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 240, 89, 25));
        pushButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(211, 215, 207);border-radius:10px;}\n"
"QPushButton:hover { background-color: rgb(107, 236, 154);}"));
        lineEdit_3 = new QLineEdit(Dialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(170, 150, 113, 25));
        lineEdit_3->setStyleSheet(QLatin1String("QLineEdit {  border-radius:10px;}\n"
"QLineEdit:hover { background-color: rgb(74, 159, 233); }"));
        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(290, 110, 25, 25));
        pushButton_3->setStyleSheet(QStringLiteral(""));
        pushButton_4 = new QPushButton(Dialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(290, 190, 25, 25));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\347\275\221\347\273\234\351\223\276\346\216\245", 0));
        label->setText(QApplication::translate("Dialog", "   \344\270\273\346\234\272\345\220\215\357\274\232", 0));
        pushButton_2->setText(QApplication::translate("Dialog", "Ok", 0));
        label_4->setText(QApplication::translate("Dialog", "\347\275\221\347\273\234\351\223\276\346\216\245\357\274\232", 0));
        label_2->setText(QApplication::translate("Dialog", "      \345\257\206\347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("Dialog", " IP\345\234\260\345\235\200\357\274\232", 0));
        label_5->setText(QApplication::translate("Dialog", " \346\234\254\345\234\260\345\257\206\347\240\201\357\274\232", 0));
        pushButton->setText(QApplication::translate("Dialog", "Cancel", 0));
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
