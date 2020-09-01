# -------------------------------------------------
# Project created by QtCreator 2011-06-03T13:34:38
# -------------------------------------------------
QT += sql
TARGET = HostManager2011
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    DialogConnexion.cpp \
    MdiServiceReception.cpp \
    DialogContact.cpp \
    DialogCalendar.cpp \
    DialogRechercherUnClient.cpp \
    DgRechercherUneOccupation.cpp \
    DgRechercherUneReserv.cpp \
    ListeDeChambres.cpp \
    GraphicsView.cpp \
    Fleche.cpp \
    PiloteChambreGraphicView.cpp \
    Ascenceur.cpp \
    Afficheur.cpp
HEADERS += mainwindow.h \
    DialogConnexion.h \
    MdiServiceReception.h \
    DialogContact.h \
    DialogCalendar.h \
    DialogRechercherUnClient.h \
    DgRechercherUneOccupation.h \
    DgRechercherUneReserv.h \
    GraphicsView.h \
    Fleche.h \
    ListeDeChambres.h \
    PiloteChambreGraphicView.h \
    Afficheur.h \
    Ascenceur.h
FORMS += mainwindow.ui \
    DialogConnexion.ui \
    MdiServiceReception.ui \
    DialogContact.ui \
    DialogCalendar.ui \
    DialogRechercherUnClient.ui \
    DgRechercherUneOccupation.ui \
    DgRechercherUneReserv.ui
RESOURCES += Background.qrc
INCLUDEPATH += $$quote(../MesTables)
LIBS += $$quote(../MesTables/debug/MesTables.dll)

LIBS += ../libCpgFdl/debug/libCpgFdl.dll
INCLUDEPATH += ../libCpgFdl
