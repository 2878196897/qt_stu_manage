#-------------------------------------------------
#
# Project created by QtCreator 2018-11-20T16:10:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stu_manage
TEMPLATE = app


SOURCES += main.cpp\
        addstu.cpp \
    mainwindow.cpp \
    query_stu.cpp

HEADERS  += addstu.h \
    mainwindow.h \
    query_stu.h

FORMS    += addstu.ui \
    mainwindow.ui \
    query_stu.ui
