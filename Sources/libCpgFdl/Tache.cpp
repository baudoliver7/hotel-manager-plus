#include "Tache.h"

bool Tache::operator ==(const Tache & t) const
{
    return t.m_heure == m_heure;
}

Tache::Tache(PiloteCompagnonFidele *pilote, QString msg, QDateTime heure, int dureeExecution)
{
    m_pilote = pilote;

    m_dureeExecution = dureeExecution;
    m_message = msg;
    m_heure = heure;
    m_type = TypeDeTache::Usuel;

    planifier();
}

void Tache::planifier()
{
    QTime now = Horloge::currentTime();
    if(m_heure.time() > now)
    // on est dans le temps
    {
        int duree = now.msecsTo(m_heure.time());
        QTimer::singleShot(duree, this, SLOT(lancer()));
        m_lancee = false;
    }else
    {
        m_lancee = true;
    }
}

void Tache::lancer()
{
    m_lancee = true;
    m_pilote->programmerExecutionDeTache();
}
