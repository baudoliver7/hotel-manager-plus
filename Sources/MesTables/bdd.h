#ifndef BDD_H
#define BDD_H

#include "MesTables_global.h"

/* classes qt */
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

/* classes personnalisées */


class MESTABLESSHARED_EXPORT BDD: public QSqlDatabase
{
public:
    BDD(const QString & type, const QString & connectionName = QLatin1String(BDD::defaultConnection));
    BDD(const BDD & db);
    ~BDD();

    bool seConnecter(const QString & nomDeBDD);
};

#endif // BDD_H
