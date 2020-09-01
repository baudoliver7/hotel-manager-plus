# -------------------------------------------------
# Project created by QtCreator 2012-07-07T14:55:54
# -------------------------------------------------
QT += sql \
    network
TARGET = Impression
TEMPLATE = lib
DEFINES += IMPRESSION_LIBRARY
SOURCES += impression.cpp \
    recu.cpp \
    factureRestoIndividu.cpp \
    factureRestoGroupe.cpp \
    factureHotelGroupe.cpp \
    factureHotelIndividu.cpp \
    factureBarGroupe.cpp
HEADERS += impression.h \
    Impression_global.h \
    recu.h \
    factureRestoIndividu.h \
    factureRestoGroupe.h \
    factureHotelGroupe.h \
    factureHotelGroupe.h \
    factureHotelIndividu.h \
    factureBarGroupe.h
INCLUDEPATH += $$quote(../MesTables)
LIBS += $$quote(../MesTables/debug/MesTables.dll)
RESOURCES += images.qrc
