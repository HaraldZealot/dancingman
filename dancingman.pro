#-------------------------------------------------
#
# Project created by QtCreator 2014-01-14T15:53:07
#
#-------------------------------------------------

QMAKE_CXXFLAGS += -D_GLIBCXX_DEBUG
CONFIG += c++11
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dancingman
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    centralwidget.cpp \
    manscreen.cpp \
    dancingman.cpp \
    sinusoida.cpp \
    terms.cpp \
    formula.cpp

HEADERS  += mainwindow.h \
    centralwidget.h \
    manscreen.h \
    dancingman.h \
    abstractformula.h \
    sinusoida.h \
    abstractterm.h \
    terms.h \
    formula.h
