#-------------------------------------------------
#
# Project created by QtCreator 2014-01-28T10:25:16
#
#-------------------------------------------------

CONFIG += c++11
QT       += testlib

QT       -= gui

TARGET = tst_termtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_termtest.cpp \
    ../../terms.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../terms.h \
    ../../abstractterm.h
