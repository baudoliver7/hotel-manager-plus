#include "InfosSurBD.h"

QStringList InfosSurBD::fieldsNames(const QSqlTableModel *model)
{
    QStringList liste;

    for(int i = 0; i < model->record().count(); i++)
    {
        liste.append(model->record().fieldName(i));
    }

    return liste;
}

QStringList InfosSurBD::fieldsNames(QString tableName)
{
    QSqlTableModel model;
    model.setTable(tableName);

    QStringList liste;

    for(int i = 0; i < model.record().count(); i++)
    {
        liste.append(model.record().fieldName(i));
    }

    return liste;
}

QList<QSqlRecord> InfosSurBD::enregistrements(QString tableName, QString conditionDeSelection)
{
    QSqlTableModel model;
    model.setTable(tableName);

    model.setFilter(conditionDeSelection);
    model.select();

    QList<QSqlRecord> liste;
    if(model.select())
    {
        for(int i = 0; i < model.rowCount(); i++)
        {
            liste << model.record(i);

            if(i + 1 == model.rowCount())
            {
                model.fetchMore();
            }
        }
    }

    return liste;
}

QList<QSqlRecord> InfosSurBD::enregistrements(QString tableName)
{
    QSqlTableModel model;
    model.setTable(tableName);
    model.select();

    QList<QSqlRecord> liste;
    for(int i = 0; i < model.rowCount(); i++)
    {
        liste << model.record(i);

        if(i + 1 == model.rowCount())
        {
            model.fetchMore();
        }
    }

    return liste;
}
