#ifndef ODBCDRIVER_H
#define ODBCDRIVER_H

#include "odbc_plugin_global.h"

#include <QODBCDriver>

class ODBC_PLUGIN_GLOBAL_H ODBCDriver : public QODBCDriver
{
public:
    ODBCDriver();
};

#endif // ODBCDRIVER_H
