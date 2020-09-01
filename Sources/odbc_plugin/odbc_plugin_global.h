#ifndef ODBC_PLUGIN_GLOBAL_H
#define ODBC_PLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ODBC_PLUGIN_LIBRARY)
#  define ODBC_PLUGINSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ODBC_PLUGINSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ODBC_PLUGIN_GLOBAL_H