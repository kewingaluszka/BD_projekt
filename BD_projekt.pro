#-------------------------------------------------
#
# Project created by QtCreator 2020-06-04T21:11:55
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BD_projekt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    klientwindow.cpp \
    serwiswindow.cpp \
    pracownikwindow.cpp

HEADERS  += mainwindow.h \
    klientwindow.h \
    serwiswindow.h \
    pracownikwindow.h

FORMS    += mainwindow.ui \
    klientwindow.ui \
    serwiswindow.ui \
    pracownikwindow.ui
