#include "Fleche.h"

Fleche::Fleche(Fonction f, QGraphicsScene *scene, Afficheur *afficheur, bool ChambreLibre)
{
    m_scene = scene;
    setFonction(f);
    m_chambreLibre = ChambreLibre;
    m_listeDesChambres.clear();
    setCursor(Qt::ArrowCursor);
    setEtat(libre);
    m_afficheur = afficheur;
}

void Fleche::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->button() == Qt::LeftButton) && (m_etat != inactif))
    {
        this->setEtat(enfonce);

        int idDeb;
        int idFin;
        if(m_chambreLibre)
        {
            idDeb = 0;
            idFin = this->m_listeDesChambres.getNbreDeChambresLibres() - 1;
        }else
        {
            idDeb = this->m_listeDesChambres.getNbreDeChambresLibres();
            idFin = this->m_listeDesChambres.size() - 1;
        }

        if(m_fonction == haut)
        {
            if((m_idPremiereChAffichee - Afficheur::nbreMaxDeChambresSurUneLigne)>= idDeb)
            {
                m_idPremiereChAffichee -= Afficheur::nbreMaxDeChambresSurUneLigne;

                if(m_idPremiereChAffichee == idDeb)
                {
                    setEtat(inactif);
                }
                if(idFin - m_idPremiereChAffichee+1 >= Afficheur::nbreChambresMaxAffichees)
                {
                    m_homologue->setEtat(libre);
                }

                m_afficheur->afficherDesChambres(m_idPremiereChAffichee, m_listeDesChambres, m_chambreLibre);
            }

        }else
        {

            if((idFin - m_idPremiereChAffichee + 1 >= Afficheur::nbreChambresMaxAffichees) && (m_idPremiereChAffichee + Afficheur::nbreMaxDeChambresSurUneLigne) <= idFin)
            {
                m_idPremiereChAffichee += Afficheur::nbreMaxDeChambresSurUneLigne;

                if(idFin - m_idPremiereChAffichee+1 < Afficheur::nbreChambresMaxAffichees)
                {
                    setEtat(inactif);
                }

                if(m_idPremiereChAffichee > idDeb)
                {
                    m_homologue->setEtat(libre);
                }

                m_afficheur->afficherDesChambres(m_idPremiereChAffichee, m_listeDesChambres, m_chambreLibre);
            }
        }

        m_homologue->m_idPremiereChAffichee = m_idPremiereChAffichee;
    }
}

void Fleche::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton && m_etat != inactif)
    {
        this->setEtat(libre);
    }
}

void Fleche::setEtat(Etat etat)
{
    this->m_etat = etat;

    if(this->m_fonction == haut)
    {
        if(etat == libre)
        {
            this->setPixmap(QPixmap(":/images/flèche haut libre.png"));
            return;
        }

        if(etat == enfonce)
        {
            this->setPixmap(QPixmap(":/images/flèche haut clickée.png"));
            return;
        }

        if(etat == inactif)
        {
            this->setPixmap(QPixmap(":/images/flèche haut inactive.png"));
            return;
        }
    }else
    {
        if(etat == libre)
        {
            this->setPixmap(QPixmap(":/images/flèche bas libre.png"));
            return;
        }

        if(etat ==enfonce)
        {
            this->setPixmap(QPixmap(":/images/flèche bas clickée.png"));
            return;
        }

        if(etat == inactif)
        {
            this->setPixmap(QPixmap(":/images/flèche bas inactive.png"));
            return;
        }
    }

}

void Fleche::setFonction(Fonction f)
{
    this->m_fonction = f;

    if(this->m_fonction == haut)
    {
        this->setPixmap(QPixmap(":/images/flèche haut libre.png"));
        return;
    }

    if(this->m_fonction == bas)
    {
        this->setPixmap(QPixmap(":/images/flèche bas libre.png"));
    }
}

void Fleche::setListeDesChambres(ListeDeChambres<Chambre *> liste)
{
    m_listeDesChambres.clear();
    m_listeDesChambres.append(liste);

    m_idPremiereChAffichee = 0;
    if(!m_chambreLibre)
    {
        m_idPremiereChAffichee = liste.getNbreDeChambresLibres();
    }
    this->setEtat(libre);
}

void Fleche::setEtatChAffichee(bool libre)
{
    this->m_chambreLibre = libre;
}
