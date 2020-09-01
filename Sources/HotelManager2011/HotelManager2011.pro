# -------------------------------------------------
# Project created by QtCreator 2011-12-17T04:51:55
# -------------------------------------------------
QT += sql \
    network
TARGET = HotelManager2011
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp
HEADERS += mainwindow.h
FORMS += mainwindow.ui
INCLUDEPATH += $$quote(../MesTables)
LIBS += $$quote(../MesTables/debug/MesTables.dll)
LIBS += ../libCpgFdl/debug/libCpgFdl.dll
INCLUDEPATH += ../libCpgFdl
INCLUDEPATH += $$quote(../bdLib)
LIBS += $$quote(../bdLib/debug/bdLib.dll)
INCLUDEPATH += $$quote(../Impression)
LIBS += $$quote(../Impression/debug/Impression.dll)
RESOURCES += images.qrc
RC_FILE = myapp.rc
