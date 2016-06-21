#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T18:38:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HungryHorses
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    jugador.cpp

HEADERS  += mainwindow.hpp \
    game.hpp \
    jugador.hpp

FORMS    += mainwindow.ui
