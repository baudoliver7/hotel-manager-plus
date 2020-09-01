# -------------------------------------------------
# Project created by QtCreator 2011-11-25T01:21:12
# -------------------------------------------------
QT += sql
TARGET = libCpgFdl
TEMPLATE = lib
DEFINES += LIBCPGFDL_LIBRARY
SOURCES += LibCpgFdl.cpp \
    Tache.cpp \
    PiloteCompagnonFidele.cpp \
    CompagnonFidele.cpp
HEADERS += LibCpgFdl.h \
    libCpgFdl_global.h \
    Tache.h \
    PiloteCompagnonFidele.h \
    TypeDeTache.h \
    CompagnonFidele.h
RESOURCES += sons.qrc \
    images.qrc

INCLUDEPATH += $$quote(../MesTables)
LIBS += $$quote(../MesTables/debug/MesTables.dll)
