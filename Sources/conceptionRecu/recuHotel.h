#ifndef RECUHOTEL_H
#define RECUHOTEL_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

class recuHotel
{
public:
    enum Champ
    {
        MatriculeAgent = 0, NomAgent = 1, Profession = 2, NomClient = 3, TypeDeChambre = 4, IdentifiantDeChambre = 5,
        PrixDuJour = 6, DureeDeLocation = 7, LocationAPayer = 8, RestaurantAPayer = 9, PenaliteAPayer = 10,
        TotalAPayer = 11, TotalPaye = 12, PenalitePaye = 13, RestaurantPaye = 14, LocationPayee = 15, ResteAPayer = 16,
        SituationGeo = 17, Adresse = 18, Tel = 19, NumFacture = 20, FaitA = 21, NomHotel = 22
    };

public:
    recuHotel(QString logo);
    recuHotel(QPixmap p);

    void setText(Champ champ, QString valeur);
    void setLogo(QString fileName);
    QGraphicsView * view(){return m_view;};

private:
    QGraphicsView * m_view;
    QGraphicsScene * m_scene;
    QGraphicsPixmapItem * m_logo;
    QGraphicsPixmapItem * m_image;
    qreal m_x0;
    qreal m_y0;
    QList<qreal> m_abscisses;
    QList<qreal> m_ordonnees;
    QGraphicsTextItem * m_items[17];
};

#endif // RECUHOTEL_H
