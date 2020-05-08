#-------------------------------------------------
#
# Project created by QtCreator 2020-02-20T19:13:17
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS += $(shell pkg-config opencv4 --cflags --libs)


SOURCES += main.cpp\
        mywidget.cpp

HEADERS  += mywidget.h

FORMS    += mywidget.ui

CONFIG   += C++11
