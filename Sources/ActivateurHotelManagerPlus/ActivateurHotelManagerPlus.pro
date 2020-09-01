# -------------------------------------------------
# Project created by QtCreator 2012-01-27T11:54:27
# -------------------------------------------------
QT += network \
    sql
TARGET = ActivateurHotelManagerPlus
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    MdiModeDiffere.cpp \
    BDConnexion.cpp \
    DialogContact.cpp \
    BDRechercherUtil.cpp \
    BDStatutProduit.cpp
HEADERS += mainwindow.h \
    MdiModeDiffere.h \
    BDConnexion.h \
    DialogContact.h \
    BDRechercherUtil.h \
    BDStatutProduit.h
FORMS += mainwindow.ui \
    MdiModeDiffere.ui \
    BDConnexion.ui \
    DialogContact.ui \
    BDRechercherUtil.ui \
    BDStatutProduit.ui
INCLUDEPATH += $$quote(../MesTables)
LIBS += $$quote(../MesTables/debug/MesTables.dll)
RESOURCES += images.qrc
