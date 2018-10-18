#-------------------------------------------------
#
# Project created by QtCreator 2018-10-17T10:51:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Msh
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bishop.cpp \
    queen.cpp

HEADERS  += mainwindow.h \
    bishop.h \
    queen.h

FORMS    += mainwindow.ui
