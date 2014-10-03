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
    src/main.cpp \
    src/menu.cpp \
    src/paddle.cpp \
    src/topscores.cpp \
    src/save_load.cpp \
    src/bonusitem.cpp \
    src/instructions.cpp \
    src/missile.cpp

HEADERS  += src/ball.h \
    src/breakthewall.h \
    src/brick.h \
    src/menu.h \
    src/paddle.h \
    src/topscores.h \
    src/save_load.h \
    src/bonusitem.h \
    src/instructions.h \
    src/missile.h

FORMS    += src/menu.ui \
    src/breakthewall.ui \
    src/topscores.ui \
    src/instructions.ui
