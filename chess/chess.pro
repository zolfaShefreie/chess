#-------------------------------------------------
#
# Project created by QtCreator 2018-10-17T00:22:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    knight.cpp \
    pawn.cpp

HEADERS  += mainwindow.h \
    knight.h \
    pawn.h

FORMS    += mainwindow.ui
