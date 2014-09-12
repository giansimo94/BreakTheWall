#-------------------------------------------------
#
# Project created by QtCreator 2014-08-26T12:32:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BreakTheWall
TEMPLATE = app


SOURCES += src/ball.cpp \
    src/breakthewall.cpp \
    src/brick.cpp \
    src/istructions.cpp \
    src/main.cpp \
    src/menu.cpp \
    src/paddle.cpp

HEADERS  += src/ball.h \
    src/breakthewall.h \
    src/brick.h \
    src/istructions.h \
    src/menu.h \
    src/paddle.h

FORMS    += src/menu.ui \
    src/breakthewall.ui \
    src/istructions.ui
