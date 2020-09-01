#ifndef TACHE_H
#define TACHE_H

#include <QGraphicsScene>
#include <QString>
#include <QDateTime>
#include <QTimer>
#include <QGraphicsTextItem>

#include "PiloteCompagnonFidele.h"
#include "TypeDeTache.h"

#define DUREE_EXECUTION 10000

class PiloteCompagnonFidele;

class Tache : public QObject
{
    Q_OBJECT

public:
    bool operator==(const Tache & t)const;

public:
    Tache(PiloteCompagnonFidele * pilote, QString msg, QDateTime heure, int dureeExecution = DUREE_EXECUTION);

    inline QString message()const{return m_message;};
    inline bool lancee()const{return m_lancee;};
    inline QDateTime heure()const{return m_heure;};
    inline int dureeExecution()const{return m_dureeExecution;};

signals:
    void executer(bool);

private:
    bool m_lancee;
    int m_dureeExecution;
    PiloteCompagnonFidele * m_pilote;
    QString m_message;
    QDateTime m_heure;
    TypeDeTache::TypeDeMsg m_type;

    void planifier();

private slots:
    void lancer();
};

#endif // TACHE_H
