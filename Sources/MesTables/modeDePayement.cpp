#include "modeDePayement.h"

modeDePayement::modeDePayement()
{
    constructeur();
}

modeDePayement::modeDePayement(const QSqlRecord &record)
{
    constructeur(record);
}

modeDePayement::modeDePayement(const modeDePayement & s)
{
    constructeur(s);
}

modeDePayement::modeDePayement(int id)
{
    constructeur(id);
}

modeDePayement::modeDePayement(QString mode)
{
    constructeur();

    QString condition = QObject::tr("%1 = '%2'").arg(modeName()).arg(mode);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(tableName(), condition);

    if(!records.isEmpty())
        m_record = records.first();
}

QString modeDePayement::mode()const
{
    return m_record.value(ModeDePayement::Id::Mode).toString();
}

int modeDePayement::idModeDePayement()const
{
    return m_record.value(ModeDePayement::Id::IdModeDePayement).toInt();
}

QVariant modeDePayement::cle() const
{
    return idModeDePayement();
}

QString modeDePayement::libelleDeCle() const
{
    return m_record.fieldName(ModeDePayement::Id::IdModeDePayement);
}

QString modeDePayement::tableName() const
{
    return ModeDePayement::Libelle;
}

void modeDePayement::setMode(QString mode)
{
    m_record.setValue(ModeDePayement::Id::Mode, mode);
    tableModifiee(true);
}

QStringList modeDePayement::chargerModeDePayement()
{
    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(ModeDePayement::Libelle);

    QStringList modes;
    foreach(QSqlRecord r, records)
    {
        modeDePayement mr(r);
        modes << mr.mode();
    }

    return modes;
}

QStringList modeDePayement::chargerModeDePayementSansCompteClient()
{
    QStringList modes = chargerModeDePayement();

    // supprimer compte client
    modes.removeLast();

    return modes;
}
