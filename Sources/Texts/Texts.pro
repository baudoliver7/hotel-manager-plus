# -------------------------------------------------
# Project created by QtCreator 2011-11-26T10:50:19
# -------------------------------------------------
QT += phonon\
        sql\
        network

TARGET = Texts
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp
HEADERS += mainwindow.h
FORMS += mainwindow.ui
RESOURCES += son.qrc
INCLUDEPATH += $$quote(../MesTables)
LIBS += $$quote(../MesTables/debug/MesTables.dll)
