# -------------------------------------------------
# Project created by QtCreator 2012-06-04T07:30:11
# -------------------------------------------------
QT += network \
    sql
TARGET = HotelManagerResto
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    MdiService.cpp
HEADERS += mainwindow.h \
    MdiService.h
FORMS += mainwindow.ui \
    MdiService.ui
INCLUDEPATH += $$quote(../MesTables)
LIBS += $$quote(../MesTables/debug/MesTables.dll)
INCLUDEPATH += $$quote(../bdLib)
LIBS += $$quote(../bdLib/debug/bdLib.dll)
RC_FILE = myapp.rc
RESOURCES += images.qrc
