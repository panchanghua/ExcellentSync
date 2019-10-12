#-------------------------------------------------
#
# Project created by QtCreator 2018-12-28T15:42:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = first_project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    choice.cpp \
    choice1.cpp \
    input_filename.cpp \
    share.cpp \
    dialog.cpp \
    dialog1.cpp \
    help_text.cpp \
    wifi1.cpp \
    wifi2.cpp \
    sendthread.cpp \
    computer1.cpp \
    computer2.cpp \
    cancel.cpp

HEADERS += \
        mainwindow.h \
    choice.h \
    choice1.h \
    input_filename.h \
    share.h \
    dialog.h \
    dialog1.h \
    help_text.h \
    wifi1.h \
    wifi2.h \
    sendthread.h \
    computer1.h \
    computer2.h \
    cancel.h

FORMS += \
        mainwindow.ui \
    dialog.ui \
    dialog1.ui \
    help_text.ui \
    wifi1.ui \
    wifi2.ui \
    computer1.ui \
    computer2.ui \
    cancel.ui

RESOURCES += \
    resource.qrc

CONFIG += c++11
