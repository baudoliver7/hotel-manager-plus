# -------------------------------------------------
# Project created by QtCreator 2011-07-22T09:29:25
# -------------------------------------------------
QT += sql\
        network
TARGET = HostManagerAdmin2011
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    MdiBilanActivitesReception.cpp
HEADERS += mainwindow.h \
    MdiBilanActivitesReceptionception.h
FORMS += mainwindow.ui \
    MdiBilanActivitesReception.ui

INCLUDEPATH += $$quote(../MesTables)
LIBS += $$quote(../MesTables/debug/MesTables.dll)
RESOURCES += images.qrc \
    son.qrc

INCLUDEPATH += $$quote(../bdLib)
LIBS += $$quote(../bdLib/debug/bdLib.dll)
LIBS += $$quote(../bdLib/debug/bdLib.dll)
INCLUDEPATH += $$quote(../Impression)
LIBS += $$quote(../Impression/debug/Impression.dll)

RC_FILE = myapp.rc
