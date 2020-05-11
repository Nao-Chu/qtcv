#-------------------------------------------------
#
# Project created by QtCreator 2020-01-07T20:31:25
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opencv
TEMPLATE = app

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS += $(shell pkg-config opencv4 --cflags --libs)


SOURCES += main.cpp\
        imshow.cpp \
    hsvsegmentation.cpp \
    morph.cpp \
    threshold.cpp \
    blue.cpp \
    qrcode.cpp

HEADERS  += imshow.h \
    hsvsegmentation.h \
    morph.h \
    threshold.h \
    blue.h \
    qrcode.h

FORMS    += imshow.ui

CONFIG += c++11

