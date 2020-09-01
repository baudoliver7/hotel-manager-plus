#ifndef FACTURERESTOGROUPE_H
#define FACTURERESTOGROUPE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

#include "occupation.h"
#include "client.h"
#include "chambre.h"
#include "typeDeClient.h"
#include "typeDeChambre.h"
#include "profileClient.h"
#include "MesTables.h"
#include "infosHotel.h"
#include "groupe.h"

#define ITEMS_COUNT 27

class factureRestoGroupe
{
public:
    enum Champ
    {
        NumFacture = 0, DateFacture = 1, CodeClient = 2, TypeClient = 3, Contact = 4, Profession = 5,
        NomHotel = 6, SituationGeo = 7, BPHotel = 8, TelHotel = 9, SiteWeb = 10, NomDuRespo = 11,
        NbPersonnes = 12, DateArriveeOff = 13, NbNuitOff = 14, NbChambre = 15,
        FraisRestoHT = 16, Remise = 17, TotalHT = 18, TVA = 19, TotalTTC = 20, PayementRecu = 21,
        NetAPayer = 22, NomClient = 23, UniteMontant = 24, TauxTVA = 25, UniteNetAPayer = 26

    };

public:
    factureRestoGroupe(const groupe & gp);

    void setText(Champ champ, QString valeur);
    void setText(Champ champ, QString valeur, int position);
    QGraphicsView * view(){return m_view;};
    QGraphicsScene * scene(){return m_scene;};

private:
    void construireFacture();

    infosHotel m_infosHotel;
    groupe m_group;
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

#endif // FACTURERESTOGROUPE_H
