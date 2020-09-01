#-------------------------------------------------
#
# Project created by QtCreator 2013-10-24T20:21:05
#
#-------------------------------------------------

QT += sql \
    network
TARGET = AppliHorlogeTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$quote(../MesTables)
LIBS += $$quote(../MesTables/debug/MesTables.dll)

INCLUDEPATH += $$quote(../bdLib)
LIBS += $$quote(../bdLib/debug/bdLib.dll)
