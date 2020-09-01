#include "HeureLimite.h"

HeureLimite::HeureLimite()
{
    constructeur();
}

HeureLimite::HeureLimite(const HeureLimite &s)
{
    constructeur(s);
}

HeureLimite::HeureLimite(const QSqlRecord &record)
{
    constructeur(record);
}

HeureLimite::HeureLimite(int numHeure)
{
    constructeur(numHeure);
}

QVariant HeureLimite::cle() const
{
    return numHeure();
}

QString HeureLimite::libelleDeCle() const
{
    return m_record.fieldName(HeureBD::Id::NumHeure);
}

QString HeureLimite::tableName() const
{
    return HeureBD::Libelle;
}

int HeureLimite::numHeure()const
{
    return m_record.value(HeureBD::Id::NumHeure).toInt();
}

QTime HeureLimite::heureFinOccupation()const
{
    return m_record.value(HeureBD::Id::HeureFinOccupation).toTime();
}

int HeureLimite::tempsTolerance()const
{
    return m_record.value(HeureBD::Id::TempsDeTol).toInt();
}

QDateTime HeureLimite::lastHourSyst()const
{
    return m_record.value(HeureBD::Id::LastHourSys).toDateTime();
}

QDateTime HeureLimite::currentHourSyst()
{
    HeureLimite hl(1);
    int valeur = hl.valeurModifiee();

    if(valeur == 0)
    {
        hl.setValeurModifiee(1);
    }else
    {
        hl.setValeurModifiee(0);
    }

    hl.enregistrer();

    return HeureLimite(1).lastHourSyst(); // pour recharger
}

QDateTime HeureLimite::debutActivation()const
{
    return m_record.value(HeureBD::Id::DebutActivation).toDateTime();
}

int HeureLimite::dureeActivation()const
{
    return m_record.value(HeureBD::Id::DureeActivation).toInt();
}

QDateTime HeureLimite::finActivation()const
{
    return debutActivation().addDays(dureeActivation());
}

bool HeureLimite::utilEnregistre()const
{
    return m_record.value(HeureBD::Id::Enregistre).toBool();
}

int HeureLimite::dureeRestante()const
{
    return m_record.value(HeureBD::Id::DureeRestante).toInt();
}

int HeureLimite::dureeTolerance()const
{
    return m_record.value(HeureBD::Id::DureeTolerance).toInt();
}

int HeureLimite::valeurModifiee()const
{
    return m_record.value(HeureBD::Id::ValeurModifiee).toInt();
}

int HeureLimite::tempsLocAnnulation()const
{
    return m_record.value(HeureBD::Id::TempsLocAnnulation).toInt();
}

QDateTime HeureLimite::debutActivites()const
{
    return m_record.value(HeureBD::Id::DebutActivites).toDateTime();
}

long HeureLimite::IID()const
{
    return (long)m_record.value(HeureBD::Id::InstallationID).toLongLong();
}

void HeureLimite::setHeureFinOccupation(QTime time)
{
    m_record.setValue(HeureBD::Id::HeureFinOccupation, time);
    tableModifiee(true);
}

void HeureLimite::setLastHourSyst(QDateTime hourSyst)
{
    m_record.setValue(HeureBD::Id::LastHourSys, hourSyst);
    tableModifiee(true);
}

void HeureLimite::setTempsTolerance(int minutes)
{
    m_record.setValue(HeureBD::Id::TempsDeTol, minutes);
    tableModifiee(true);
}

void HeureLimite::setDebutActivation(QDateTime debut)
{
    m_record.setValue(HeureBD::Id::DebutActivation, debut);
    tableModifiee(true);
}

void HeureLimite::setDureeActivation(int duree)
{
    m_record.setValue(HeureBD::Id::DureeActivation, duree);
    tableModifiee(true);
}

void HeureLimite::setDureeRestante(int duree)
{
    m_record.setValue(HeureBD::Id::DureeRestante, duree);
    tableModifiee(true);
}

void HeureLimite::setDureeTolerance(int duree)
{
    m_record.setValue(HeureBD::Id::DureeTolerance, duree);
    tableModifiee(true);
}

void HeureLimite::setValeurModifiee(int valeur)
{
    m_record.setValue(HeureBD::Id::ValeurModifiee, valeur);
    tableModifiee(true);
}

void HeureLimite::setTempsLocAnnulation(int nbMinutes)
{
    m_record.setValue(HeureBD::Id::TempsLocAnnulation, nbMinutes);
    tableModifiee(true);
}

void HeureLimite::setDebutActivites(QDateTime date)
{
    m_record.setValue(HeureBD::Id::DebutActivites, date);
    tableModifiee(true);
}

void HeureLimite::setIID(long iid)
{
    m_record.setValue(HeureBD::Id::InstallationID, (qlonglong)iid);
    tableModifiee(true);
}

void HeureLimite::setUtilEnregistrer(bool enregistrer)
{
    m_record.setValue(HeureBD::Id::Enregistre, enregistrer);
    tableModifiee(true);
}
