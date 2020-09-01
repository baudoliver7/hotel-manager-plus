#ifndef PILOTECOMPAGNONFIDELE_H
#define PILOTECOMPAGNONFIDELE_H

#include "libCpgFdl_global.h"

#include <QGraphicsScene>
#include <QString>
#include <QDateTime>
#include <QList>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QSound>
#include <QTextEdit>
#include <QGraphicsProxyWidget>

#include "Tache.h"
#include "agent.h"
#include "horloge.h"

#define DUREE_AVANT_ENTREE 2000 // ms
#define DUREE_AFFICHAGE 10000 // ms
#define MESSAGE_ATTENTE "Agent Hotel Manager, votre compagnon de service."

class Tache;

class LIBCPGFDLSHARED_EXPORT PiloteCompagnonFidele : public QObject
{
    Q_OBJECT

public:
    PiloteCompagnonFidele(QGraphicsScene * scene, agent * r, QString path);
    ~PiloteCompagnonFidele();

    void planifierUneTache(QString message, QDateTime heure, int dureeExecution = DUREE_AFFICHAGE);
    void planifierUneTache(QString message, int dureeExecution = DUREE_AFFICHAGE);
    inline QGraphicsScene * scene(){return m_scene;};
    void setMuteVolume(bool mute);
    inline bool volumeMuted()const{return m_mute;};
    inline QString derMsgAffiche()const{return m_derMsgAffiche;};

signals:
    void msgAffiche();

public slots:
    void programmerExecutionDeTache();

private:
    QGraphicsScene * m_scene;
    agent * m_recepteur;
    QGraphicsPixmapItem * m_enveloppe;
    QList<Tache *> m_tachesAeffectuer;
    QList<Tache *> m_tachesEnAttente;
    QList<int> m_dureeMSecsTachesEnAttente;
    bool m_affichageEnCours;
    QGraphicsTextItem * m_messageItem;
    QString m_message;
    QSound * m_sonDeMachine;
    QSound * m_sonMsg;
    QTextEdit * m_textEdit;
    QGraphicsProxyWidget * m_proxyWidgetTextEdit;
    int m_dureeAffichage;
    bool m_mute;
    QString m_derMsgAffiche;
    QString m_chemin;

    void ecrireTexte(QString text);
    void afficherMsgAttente();
    Tache * tacheeTerminee();

private slots:
    void executerTacheEnCours();
    void initialiserAffichageEnCours();
    void initialiserEcran();
    void clignoterEnveloppe();
    void afficherIconCompagnon();
    void ecrireTexte();

public:
    static float longueur();
    static float largeur();
};

#endif // PILOTECOMPAGNONFIDELE_H
