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
    pawn.cpp \
    rook.cpp \
    king.cpp \
    bishop.cpp \
    queen.cpp \
    winner.cpp \
    save.cpp

HEADERS  += mainwindow.h \
    knight.h \
    pawn.h \
    rook.h \
    king.h \
    bishop.h \
    queen.h \
    winner.h \
    save.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
