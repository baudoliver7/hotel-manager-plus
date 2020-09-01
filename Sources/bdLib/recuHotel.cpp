#include "recuHotel.h"

recuHotel::recuHotel(QString logo)
{
    m_view = new QGraphicsView();

    m_scene = new QGraphicsScene();
    m_view->setScene(m_scene);

    m_image = new QGraphicsPixmapItem(QPixmap(":/images/Facture vierge 2.png"));
    m_scene->addItem(m_image);

    m_logo = new QGraphicsPixmapItem(QPixmap(logo));
    m_scene->addItem(m_logo);
    qreal scale = 100 / m_logo->boundingRect().width();

    m_logo->setScale(scale);
    m_logo->setPos(40, 60);

    m_view->setFixedSize(m_scene->width() + 15, m_scene->height() + 15);

    m_x0 = m_image->x();
    m_y0 = m_image->y();

    m_abscisses << 60
                << 365
                << 365
                << 60
                << 365
                << 365
                << 365
                << 365
                << 265
                << 265
                << 265
                << 265
                << 467
                << 467
                << 467
                << 467
                << 150
                << 326
                << 210
                << 174
                << 480
                << 0 // à calculer
                << 140; // à calculer

    m_ordonnees << 273
                << 273
                << 370
                << 370
                << 443
                << 461
                << 480
                << 499
                << 603
                << 620
                << 639
                << 657
                << 657
                << 639
                << 620
                << 603
                << 717
                << 60
                << 80
                << 101
                << 169
                << 920
                << 30;

    for(int i = 0; i < m_abscisses.count(); i++)
    {
        m_items[i] = new QGraphicsTextItem();

        if((Champ)i == NumFacture)
        {
            // agrandir le caractère
            QFont f;
            f.setPointSize(18);
            m_items[i]->setFont(f);
        }

        if((Champ)i == NomHotel)
        {
            // agrandir le caractère
            QFont f;
            f.setPointSize(14);
            f.setFamily("Helvetica [Cronyx]");
            m_items[i]->setFont(f);
        }

        m_scene->addItem(m_items[i]);
        m_items[i]->setPos(m_x0 + m_abscisses.at(i), m_y0 + m_ordonnees.at(i));
    }
}

recuHotel::recuHotel(QPixmap p)
{
    m_view = new QGraphicsView();

    m_scene = new QGraphicsScene();
    m_view->setScene(m_scene);

    m_image = new QGraphicsPixmapItem(QPixmap(":/images/Facture vierge 2.png"));
    m_scene->addItem(m_image);

    m_logo = new QGraphicsPixmapItem(p);
    m_scene->addItem(m_logo);
    qreal scale = 100 / m_logo->boundingRect().width();

    m_logo->setScale(scale);
    m_logo->setPos(40, 60);

    m_view->setFixedSize(m_scene->width() + 15, m_scene->height() + 15);

    m_x0 = m_image->x();
    m_y0 = m_image->y();

    m_abscisses << 60
                << 365
                << 365
                << 60
                << 365
                << 365
                << 365
                << 365
                << 265
                << 265
                << 265
                << 265
                << 467
                << 467
                << 467
                << 467
                << 150
                << 326
                << 210
                << 174
                << 480
                << 0 // à calculer
                << 140; // à calculer

    m_ordonnees << 273
                << 273
                << 370
                << 370
                << 443
                << 461
                << 480
                << 499
                << 603
                << 620
                << 639
                << 657
                << 657
                << 639
                << 620
                << 603
                << 717
                << 60
                << 80
                << 101
                << 169
                << 920
                << 30;

    for(int i = 0; i < m_abscisses.count(); i++)
    {
        m_items[i] = new QGraphicsTextItem();

        if((Champ)i == NumFacture)
        {
            // agrandir le caractère
            QFont f;
            f.setPointSize(18);
            m_items[i]->setFont(f);
        }

        if((Champ)i == NomHotel)
        {
            // agrandir le caractère
            QFont f;
            f.setPointSize(14);
            f.setFamily("Helvetica [Cronyx]");
            m_items[i]->setFont(f);
        }

        m_scene->addItem(m_items[i]);
        m_items[i]->setPos(m_x0 + m_abscisses.at(i), m_y0 + m_ordonnees.at(i));
    }
}

void recuHotel::setText(Champ champ, QString valeur)
{
    m_items[champ]->setPlainText(valeur);

    if(champ == FaitA)
    {
        // calculer
        qreal x = m_image->boundingRect().width() - m_items[champ]->boundingRect().width() - 50; // marge
        m_items[champ]->setX(m_x0 + x);
    }
}

void recuHotel::setLogo(QString fileName)
{
    m_logo->setPixmap(QPixmap(fileName));
}
