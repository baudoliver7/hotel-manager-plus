#ifndef ASCENCEUR_H
#define ASCENCEUR_H

#include <QGraphicsPixmapItem>
#include "ListeDeChambres.h"
#include <QGraphicsScene>
#include "Fleche.h"
#include "Afficheur.h"
#include <QString>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

class Afficheur;
class Fleche;

class Ascenceur : public QGraphicsPixmapItem
{
public:
    Ascenceur(QGraphicsScene * scene, Afficheur * afficheur, bool ChambreLibre);

    void setPos(qreal x, qreal y);
    void setScale(qreal scale);
    void setListeDesChambres(ListeDeChambres<Chambre*> liste);
    void setPixmap(const QPixmap &pixmap);

   int idPremiereCh()const;
   ListeDeChambres<Chambre *> chambres();

private:
    Fleche * m_flecheHaute;
    Fleche * m_flecheBasse;
    Afficheur * m_afficheur;
    QGraphicsScene * m_scene;
    QMessageBox avertisseur;
};

#endif // ASCENCEUR_H
