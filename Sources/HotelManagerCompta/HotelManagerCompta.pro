# -------------------------------------------------
# Project created by QtCreator 2011-12-25T23:25:37
# -------------------------------------------------
QT += sql \
    network
TARGET = HotelManagerCompta
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    MdiServiceComptable.cpp \
    compteform.cpp \
    BDConfigCpt.cpp \
    BDExecuterNlleOperation.cpp \
    BDEditerUnMvt.cpp \
    BDConfigComptaService.cpp \
    BDChoixConfigServiceCompta.cpp \
    BDCompteResultat.cpp \
    BDEditerClotures.cpp
HEADERS += mainwindow.h \
    MdiServiceComptable.h \
    compteform.h \
    BDConfigCpt.h \
    BDExecuterNlleOperation.h \
    BDEditerUnMvt.h \
    BDConfigComptaService.h \
    BDChoixConfigServiceCompta.h \
    BDCompteResultat.h \
    BDEditerClotures.h
FORMS += mainwindow.ui \
    MdiServiceComptable.ui \
    compteform.ui \
    BDConfigCpt.ui \
    BDExecuterNlleOperation.ui \
    BDEditerUnMvt.ui \
    BDConfigComptaService.ui \
    BDChoixConfigServiceCompta.ui \
    BDCompteResultat.ui \
    BDEditerClotures.ui
INCLUDEPATH += $$quote(../MesTables)
LIBS += $$quote(../MesTables/debug/MesTables.dll)
RESOURCES += images.qrc
INCLUDEPATH += $$quote(../bdLib)
LIBS += $$quote(../bdLib/debug/bdLib.dll)
INCLUDEPATH += $$quote(../Impression)
LIBS += $$quote(../Impression/debug/Impression.dll)
RC_FILE = myapp.rc
