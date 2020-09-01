# -------------------------------------------------
# Project created by QtCreator 2012-06-02T23:19:37
# -------------------------------------------------
QT += sql \
    gui \
    network
TARGET = conceptionRecu
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    textItemMoving.cpp
HEADERS += mainwindow.h \
    textItemMoving.h \
    ui_mainwindow.h
FORMS += mainwindow.ui
RESOURCES += images.qrc
INCLUDEPATH += $$quote(../MesTables)
LIBS += $$quote(../MesTables/debug/MesTables.dll)
INCLUDEPATH += $$quote(../bdLib)
LIBS += $$quote(../bdLib/debug/bdLib.dll)
