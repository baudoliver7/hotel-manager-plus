# -------------------------------------------------
# Project created by QtCreator 2011-11-24T07:42:22
# -------------------------------------------------
QT += sql
TARGET = CompagnonFidele
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp
HEADERS += mainwindow.h
FORMS += mainwindow.ui
LIBS += ../libCpgFdl/debug/libCpgFdl.dll
INCLUDEPATH += ../libCpgFdl
RESOURCES += 

INCLUDEPATH += $$quote(../MesTables)
LIBS += $$quote(../MesTables/debug/MesTables.dll)
