#ifndef FLECHE_H
#define FLECHE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "ListeDeChambres.h"
#include <QString>
#include "Afficheur.h"
#include <QGraphicsView>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

class Afficheur;

class Fleche : public QGraphicsPixmapItem
{
public:
    enum Etat
    {
        libre, enfonce, inactif
    };

    enum Fonction
    {
        haut, bas
    };

public:
    Fleche(Fonction f, QGraphicsScene * scene, Afficheur * afficheur, bool ChambreLibre);

    void setFonction(Fonction f);
    void setHomologue(Fleche * homologue){this->m_homologue = homologue;};
    void setListeDesChambres(ListeDeChambres<Chambre*> liste);
    inline ListeDeChambres<Chambre*> chambres(){return m_listeDesChambres;};
    inline bool chAfficheeEstLibre(){return this->m_chambreLibre;};
    void setEtat(Etat etat);
    inline int idPremiereCh()const{return m_idPremiereChAffichee;};

private:
    void setEtatChAffichee(bool libre);

private:
    Etat m_etat;
    Afficheur * m_afficheur;
    Fonction m_fonction;
    ListeDeChambres<Chambre*> m_listeDesChambres;
    int m_idPremiereChAffichee;
    bool m_chambreLibre;
    QGraphicsScene * m_scene;
    QMessageBox avertisseur;
    Fleche * m_homologue;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // FLECHE_H
