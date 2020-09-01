#-------------------------------------------------
#
# Project created by QtCreator 2011-12-28T13:00:08
#
#-------------------------------------------------

QT       += sql

QT       += gui

TARGET = TestConsole
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp
INCLUDEPATH += $$quote(../MesTables)
LIBS += $$quote(../MesTables/debug/MesTables.dll)
