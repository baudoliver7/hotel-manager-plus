#include "Ascenceur.h"

Ascenceur::Ascenceur(QGraphicsScene *scene, Afficheur *afficheur, bool ChambreLibre)
{
    QGraphicsPixmapItem::setPixmap(QPixmap(":/images/tableau des flèches.png"));
    this->m_scene = scene;
    m_afficheur = afficheur;
    this->m_scene->addItem(this);
    this->m_flecheHaute = new Fleche(Fleche::haut, m_scene, afficheur, ChambreLibre);
    this->m_flecheBasse = new Fleche(Fleche::bas, m_scene, afficheur, ChambreLibre);
    this->m_flecheHaute->setHomologue(this->m_flecheBasse);
    this->m_flecheBasse->setHomologue(this->m_flecheHaute);
    m_scene->addItem(this->m_flecheHaute);
    m_scene->addItem(this->m_flecheBasse);

    setPos(x(), y());
}

void Ascenceur::setPos(qreal x, qreal y)
{
    QGraphicsPixmapItem::setPos(x,y);
    this->m_flecheHaute->setPos(this->x(), this->y() + 3 * scale());
    this->m_flecheBasse->setPos(this->x(), this->y() + this->sceneBoundingRect().height() - 49 * scale());
}

void Ascenceur::setScale(qreal scale)
{
    QGraphicsPixmapItem::setScale(scale);
    m_flecheBasse->setScale(scale);
    m_flecheHaute->setScale(scale);
}

void Ascenceur::setListeDesChambres(ListeDeChambres<Chambre *> liste)
{
    this->m_flecheBasse->setListeDesChambres(liste);
    this->m_flecheHaute->setListeDesChambres(liste);

    int idPremiereChAffichee = 0;
    int iFin = liste.getNbreDeChambresLibres()-1;
    if(!this->m_flecheHaute->chAfficheeEstLibre())
    {
       idPremiereChAffichee = liste.getNbreDeChambresLibres();
       iFin = liste.size()-1;
    }

    m_afficheur->afficherDesChambres(idPremiereChAffichee, liste, this->m_flecheHaute->chAfficheeEstLibre());

    this->m_flecheHaute->setEtat(Fleche::inactif);
    if(iFin - idPremiereChAffichee + 1 <= 15)
    {
        this->m_flecheBasse->setEtat(Fleche::inactif);
    }
}

void Ascenceur::setPixmap(const QPixmap &pixmap)
{
    QGraphicsPixmapItem::setPixmap(pixmap);
}

int Ascenceur::idPremiereCh()const
{
    return m_flecheBasse->idPremiereCh();
}

ListeDeChambres<Chambre *> Ascenceur::chambres()
{
    return m_flecheBasse->chambres();
}
