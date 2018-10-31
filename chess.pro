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
    save.cpp \
    infobase.cpp \
    start_page.cpp

HEADERS  += mainwindow.h \
    knight.h \
    pawn.h \
    rook.h \
    king.h \
    bishop.h \
    queen.h \
    save.h \
    infobase.h \
    start_page.h

FORMS    += mainwindow.ui \
    start_page.ui

RESOURCES += \
    icons.qrc \
    chessboard_photo.qrc
