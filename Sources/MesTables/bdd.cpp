#include "bdd.h"

BDD::BDD(const QString &type, const QString &connectionName):QSqlDatabase(addDatabase(type, connectionName))
{

}

BDD::BDD(const BDD &db):QSqlDatabase(db)
{

}

bool BDD::seConnecter(const QString & nomDeBDD)
{
    setDatabaseName(nomDeBDD);

    open();
    if(!isOpen())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"), lastError().text());
    }

    return isOpen();
}

BDD::~BDD()
{
    if(isOpen()) close();
}
