#ifndef RECU_H
#define RECU_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

#include "recuInitial.h"
#include "operationService.h"
#include "MesTables.h"
#include "infosHotel.h"
#include "modeDePayement.h"
#include "operationCompteClient.h"

#define ITEMS_COUNT 16

class recu
{
public:
    enum Champ
    {
        NumFacture = 0, DateFacture = 1, CodeClient = 2, Contact = 3, NomHotel = 4,
        SituationGeo = 5, BPHotel = 6, TelHotel = 7, SiteWeb = 8, NomClient = 9, Matricule = 10,
        Objet = 11, MontantVerse = 12, MontantRestant = 13, ModeDePayement = 14, Profession = 15
    };

public:
    recu(const operationService & op);

    void setText(Champ champ, QString valeur);
    void setText(Champ champ, QString valeur, int position);
    QGraphicsView * view(){return m_view;};
    QGraphicsScene * scene(){return m_scene;};

private:
    void construireRecu();

    infosHotel m_infosHotel;
    repasCompletResto m_rcr;
    operationService m_op;
    QGraphicsView * m_view;
    QGraphicsScene * m_scene;
    QGraphicsPixmapItem * m_image;
    QGraphicsPixmapItem * m_logo;
    qreal m_x0;
    qreal m_y0;
    QList<qreal> m_abscisses;
    QList<qreal> m_ordonnees;
    QGraphicsTextItem * m_items[ITEMS_COUNT];
};

#endif // RECU_H
