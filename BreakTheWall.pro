#-------------------------------------------------
#
# Project created by QtCreator 2014-08-26T12:32:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BreakTheWall
TEMPLATE = app


SOURCES += main.cpp\
        menu.cpp \
    breakthewall.cpp \
    ball.cpp \
    brick.cpp \
    paddle.cpp \
    istructions.cpp

HEADERS  += menu.h \
    breakthewall.h \
    ball.h \
    brick.h \
    paddle.h \
    istructions.h

FORMS    += menu.ui \
    breakthewall.ui \
    istructions.ui
