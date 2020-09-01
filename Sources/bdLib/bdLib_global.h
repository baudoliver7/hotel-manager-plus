#ifndef BDLIB_GLOBAL_H
#define BDLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BDLIB_LIBRARY)
#  define BDLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BDLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BDLIB_GLOBAL_H
