# -------------------------------------------------
# Project created by QtCreator 2012-01-06T12:32:00
# -------------------------------------------------
QT += sql
QT -= gui
TARGET = odbc_plugin
TEMPLATE = lib
DEFINES += ODBC_PLUGIN_LIBRARY
SOURCES += odbc_plugin.cpp \
    qsql_odbc.cpp \
    ODBCDriver.cpp
HEADERS += odbc_plugin.h \
    odbc_plugin_global.h \
    qsql_odbc.h \
    ODBCDriver.h
OTHER_FILES += 
unix:!contains( LIBS, .*odbc.* ):LIBS *= $$QT_LFLAGS_ODBC
win32 { 
    !win32-borland:LIBS *= -lodbc32
    win32-borland:LIBS *= $(BCB)/lib/PSDK/odbc32.lib
}
include(qsqldriverbase.pri)
include(qpluginbase.pri)
include(qt_targets.pri)
