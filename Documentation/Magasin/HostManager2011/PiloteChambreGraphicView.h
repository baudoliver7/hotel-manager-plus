#ifndef PILOTECHAMBREGRAPHICVIEW_H
#define PILOTECHAMBREGRAPHICVIEW_H

#include <QGraphicsScene>
#include <QString>

#include "occupation.h"
#include "Afficheur.h"
#include "ListeDeChambres.h"

class PiloteChambreGraphicView
{
public:
    PiloteChambreGraphicView(QGraphicsScene * scene);
    ~PiloteChambreGraphicView();

    Afficheur * afficheur()const {return m_afficheur;};
    void afficher(ListeDeChambres<Chambre *> chambres);
    void rafraichir();

private:
    QGraphicsScene * m_scene;
    Afficheur * m_afficheur;

    void rangerParOrdreCroissant(ListeDeChambres<Chambre *> chambres);
};

#endif // PILOTECHAMBREGRAPHICVIEW_H
