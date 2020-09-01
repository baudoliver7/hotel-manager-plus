#-------------------------------------------------
#
# Project created by QtCreator 2012-06-07T07:27:50
#
#-------------------------------------------------

QT       += sql\
    network

TARGET = TestDeMesTables
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$quote(../MesTables)
LIBS += $$quote(../MesTables/debug/MesTables.dll)
