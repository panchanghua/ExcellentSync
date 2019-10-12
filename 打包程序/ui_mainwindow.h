/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *change_bj;
    QAction *change_y;
    QAction *new_task;
    QAction *change_b;
    QAction *delete_task;
    QAction *change_h;
    QAction *help_t;
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *open_log;
    QAction *close_log;
    QAction *clear_log;
    QAction *action_4;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QSplitter *splitter;
    QSplitter *splitter_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QListWidget *listWidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_5;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *choice_1;
    QPushButton *exchange;
    QPushButton *choice_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *same;
    QPushButton *notsync;
    QPushButton *left;
    QPushButton *right;
    QPushButton *both;
    QSpacerItem *huan;
    QPushButton *button6;
    QProgressBar *progressBar;
    QSplitter *splitter_3;
    QTreeWidget *treeWidget;
    QTextBrowser *text_log;
    QTextBrowser *text_show;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1086, 606);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8("\347\275\221\347\273\234.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        change_bj = new QAction(MainWindow);
        change_bj->setObjectName(QStringLiteral("change_bj"));
        change_y = new QAction(MainWindow);
        change_y->setObjectName(QStringLiteral("change_y"));
        new_task = new QAction(MainWindow);
        new_task->setObjectName(QStringLiteral("new_task"));
        change_b = new QAction(MainWindow);
        change_b->setObjectName(QStringLiteral("change_b"));
        delete_task = new QAction(MainWindow);
        delete_task->setObjectName(QStringLiteral("delete_task"));
        change_h = new QAction(MainWindow);
        change_h->setObjectName(QStringLiteral("change_h"));
        help_t = new QAction(MainWindow);
        help_t->setObjectName(QStringLiteral("help_t"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        open_log = new QAction(MainWindow);
        open_log->setObjectName(QStringLiteral("open_log"));
        close_log = new QAction(MainWindow);
        close_log->setObjectName(QStringLiteral("close_log"));
        clear_log = new QAction(MainWindow);
        clear_log->setObjectName(QStringLiteral("clear_log"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setMinimumSize(QSize(200, 0));
        splitter->setBaseSize(QSize(120, 0));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setChildrenCollapsible(false);
        splitter_2 = new QSplitter(splitter);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setMinimumSize(QSize(130, 0));
        splitter_2->setMaximumSize(QSize(16777215, 16777215));
        splitter_2->setSizeIncrement(QSize(100, 0));
        splitter_2->setBaseSize(QSize(100, 0));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setOpaqueResize(false);
        splitter_2->setChildrenCollapsible(false);
        verticalLayoutWidget = new QWidget(splitter_2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(50, 50));
        pushButton_4->setMaximumSize(QSize(50, 50));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton {  border: none;background-repeat: no-repeat;}\n"
"QPushButton:hover { background-color: white; }"));

        verticalLayout->addWidget(pushButton_4);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 15));
        label->setMaximumSize(QSize(16777215, 15));

        verticalLayout->addWidget(label, 0, Qt::AlignVCenter);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(50, 50));
        pushButton_6->setMaximumSize(QSize(50, 50));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton {  border: none;background-repeat: no-repeat;}\n"
"QPushButton:hover { background-color: white; border-radius:25px;}"));

        verticalLayout_2->addWidget(pushButton_6);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(16777215, 15));

        verticalLayout_2->addWidget(label_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_6->addLayout(horizontalLayout_3);

        listWidget = new QListWidget(verticalLayoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setMinimumSize(QSize(120, 0));
        listWidget->setMaximumSize(QSize(1000, 16777215));
        listWidget->setSizeIncrement(QSize(100, 0));
        listWidget->setBaseSize(QSize(120, 0));

        verticalLayout_6->addWidget(listWidget);

        splitter_2->addWidget(verticalLayoutWidget);
        splitter->addWidget(splitter_2);
        verticalLayoutWidget_2 = new QWidget(splitter);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, -1, -1);
        pushButton_3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_3->setMaximumSize(QSize(50, 50));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {  border: none;background-repeat: no-repeat;}\n"
"QPushButton:hover { background-color: white; border-radius:25px;}"));

        verticalLayout_3->addWidget(pushButton_3);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(16777215, 15));

        verticalLayout_3->addWidget(label_3);


        horizontalLayout_5->addLayout(verticalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, -1, -1);
        pushButton_5 = new QPushButton(verticalLayoutWidget_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(50, 50));
        pushButton_5->setMaximumSize(QSize(50, 50));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton {  border: none;background-repeat: no-repeat;}\n"
"QPushButton:hover { background-color: white; \n"
"border-radius:25px;}"));

        verticalLayout_4->addWidget(pushButton_5);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMaximumSize(QSize(16777215, 15));

        verticalLayout_4->addWidget(label_4);


        horizontalLayout_5->addLayout(verticalLayout_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        choice_1 = new QPushButton(verticalLayoutWidget_2);
        choice_1->setObjectName(QStringLiteral("choice_1"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(choice_1->sizePolicy().hasHeightForWidth());
        choice_1->setSizePolicy(sizePolicy2);
        choice_1->setMinimumSize(QSize(0, 50));
        choice_1->setMaximumSize(QSize(300, 50));
        choice_1->setStyleSheet(QLatin1String("QPushButton {  border: none;background-repeat: no-repeat;}\n"
"QPushButton:hover { background-color: rgb(211, 215, 207); }"));

        horizontalLayout_5->addWidget(choice_1);

        exchange = new QPushButton(verticalLayoutWidget_2);
        exchange->setObjectName(QStringLiteral("exchange"));
        exchange->setMinimumSize(QSize(50, 50));
        exchange->setMaximumSize(QSize(50, 50));
        exchange->setStyleSheet(QLatin1String("QPushButton {  border: none;background-repeat: no-repeat;}\n"
"QPushButton:hover { background-color: white;border-radius:25px; }"));

        horizontalLayout_5->addWidget(exchange);

        choice_2 = new QPushButton(verticalLayoutWidget_2);
        choice_2->setObjectName(QStringLiteral("choice_2"));
        sizePolicy2.setHeightForWidth(choice_2->sizePolicy().hasHeightForWidth());
        choice_2->setSizePolicy(sizePolicy2);
        choice_2->setMinimumSize(QSize(0, 50));
        choice_2->setMaximumSize(QSize(300, 50));
        choice_2->setStyleSheet(QLatin1String("QPushButton {  border: none;background-repeat: no-repeat;}\n"
"QPushButton:hover { background-color: rgb(211, 215, 207); }"));

        horizontalLayout_5->addWidget(choice_2);


        verticalLayout_7->addLayout(horizontalLayout_5);

        line = new QFrame(verticalLayoutWidget_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        same = new QPushButton(verticalLayoutWidget_2);
        same->setObjectName(QStringLiteral("same"));
        same->setMinimumSize(QSize(60, 40));
        same->setBaseSize(QSize(0, 0));

        horizontalLayout->addWidget(same);

        notsync = new QPushButton(verticalLayoutWidget_2);
        notsync->setObjectName(QStringLiteral("notsync"));
        notsync->setMinimumSize(QSize(60, 40));

        horizontalLayout->addWidget(notsync);

        left = new QPushButton(verticalLayoutWidget_2);
        left->setObjectName(QStringLiteral("left"));
        left->setMinimumSize(QSize(60, 40));

        horizontalLayout->addWidget(left);

        right = new QPushButton(verticalLayoutWidget_2);
        right->setObjectName(QStringLiteral("right"));
        right->setMinimumSize(QSize(60, 40));

        horizontalLayout->addWidget(right);

        both = new QPushButton(verticalLayoutWidget_2);
        both->setObjectName(QStringLiteral("both"));
        both->setMinimumSize(QSize(60, 40));

        horizontalLayout->addWidget(both);

        huan = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(huan);

        button6 = new QPushButton(verticalLayoutWidget_2);
        button6->setObjectName(QStringLiteral("button6"));
        button6->setMinimumSize(QSize(100, 40));
        button6->setStyleSheet(QLatin1String("QPushButton {  border: none;background-repeat: no-repeat;background-color:rgb(186, 189, 182)}\n"
"QPushButton:hover { background-color: rgb(107, 236, 154)}"));

        horizontalLayout->addWidget(button6);


        verticalLayout_7->addLayout(horizontalLayout);

        progressBar = new QProgressBar(verticalLayoutWidget_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        verticalLayout_7->addWidget(progressBar);

        splitter_3 = new QSplitter(verticalLayoutWidget_2);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        treeWidget = new QTreeWidget(splitter_3);
        treeWidget->headerItem()->setText(4, QString());
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(8, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(7, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(6, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(5, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(4, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(3, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(2, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(1, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy3);
        treeWidget->setMinimumSize(QSize(50, 0));
        treeWidget->setMaximumSize(QSize(16777215, 16777215));
        splitter_3->addWidget(treeWidget);
        text_log = new QTextBrowser(splitter_3);
        text_log->setObjectName(QStringLiteral("text_log"));
        splitter_3->addWidget(text_log);

        verticalLayout_7->addWidget(splitter_3);

        text_show = new QTextBrowser(verticalLayoutWidget_2);
        text_show->setObjectName(QStringLiteral("text_show"));

        verticalLayout_7->addWidget(text_show);

        splitter->addWidget(verticalLayoutWidget_2);

        horizontalLayout_4->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1086, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(new_task);
        menu->addAction(delete_task);
        menu->addAction(action_4);
        menu_2->addAction(change_bj);
        menu_2->addAction(change_y);
        menu_2->addAction(change_b);
        menu_2->addAction(change_h);
        menu_2->addAction(open_log);
        menu_2->addAction(close_log);
        menu_2->addAction(clear_log);
        menu_3->addAction(help_t);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ExcellentSync", 0));
        change_bj->setText(QApplication::translate("MainWindow", "\346\233\264\346\224\271\350\203\214\346\231\257", 0));
        change_bj->setShortcut(QApplication::translate("MainWindow", "Shift+Right", 0));
        change_y->setText(QApplication::translate("MainWindow", "\345\244\234\351\227\264\346\250\241\345\274\217", 0));
        new_task->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\344\273\273\345\212\241", 0));
        change_b->setText(QApplication::translate("MainWindow", "\346\227\245\351\227\264\346\250\241\345\274\217", 0));
        delete_task->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\344\273\273\345\212\241", 0));
        change_h->setText(QApplication::translate("MainWindow", "\346\212\244\347\234\274\346\250\241\345\274\217", 0));
        help_t->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251\346\226\207\346\241\243", 0));
        help_t->setShortcut(QApplication::translate("MainWindow", "Shift+F5", 0));
        action->setText(QApplication::translate("MainWindow", "\345\210\206\346\236\220", 0));
        action_2->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245", 0));
        action_3->setText(QApplication::translate("MainWindow", "\345\210\206\346\236\220\345\212\240\345\220\214\346\255\245", 0));
        open_log->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\227\245\345\277\227", 0));
        open_log->setShortcut(QApplication::translate("MainWindow", "Ctrl+`", 0));
        close_log->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\227\245\345\277\227", 0));
        clear_log->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\227\245\345\277\227", 0));
        action_4->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210\351\223\276\346\216\245", 0));
        pushButton_4->setText(QString());
        label->setText(QApplication::translate("MainWindow", "  \346\226\260\345\273\272", 0));
        pushButton_6->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "  \345\210\240\351\231\244", 0));
        pushButton_3->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "  \345\210\206\346\236\220", 0));
        pushButton_5->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "   \345\220\214\346\255\245", 0));
        choice_1->setText(QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\346\226\207\344\273\266\345\244\2711", 0));
        exchange->setText(QString());
        choice_2->setText(QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\346\226\207\344\273\266\345\244\2712", 0));
        same->setText(QApplication::translate("MainWindow", "\347\233\270\345\220\214(0)", 0));
        notsync->setText(QApplication::translate("MainWindow", "\344\270\215\345\220\214\346\255\245(0)", 0));
        left->setText(QApplication::translate("MainWindow", "\345\267\246\345\220\214\346\255\245(0)", 0));
        right->setText(QApplication::translate("MainWindow", "\345\217\263\345\220\214\346\255\245(0)", 0));
        both->setText(QApplication::translate("MainWindow", "\345\206\262\347\252\201(0)", 0));
        button6->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\240\221\347\212\266\347\273\223\346\236\204\345\233\276", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(8, QApplication::translate("MainWindow", "\347\212\266\346\200\201", 0));
        ___qtreewidgetitem->setText(7, QApplication::translate("MainWindow", "\345\217\263\344\276\247\346\227\245\346\234\237", 0));
        ___qtreewidgetitem->setText(6, QApplication::translate("MainWindow", "\345\217\263\344\276\247\345\244\247\345\260\217", 0));
        ___qtreewidgetitem->setText(5, QApplication::translate("MainWindow", "\345\217\263\344\276\247", 0));
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "\345\267\246\344\276\247", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "\345\267\246\344\276\247\346\227\245\346\234\237", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "\345\267\246\344\276\247\345\244\247\345\260\217", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\220\215", 0));
        text_show->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:72pt; color:#d3d7cf;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:72pt; color:#d3d7cf;\">    \347\202\271\345\207\273\345\210\206\346\236\220\345\274\200\345\247\213</span></p></body></html>", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
