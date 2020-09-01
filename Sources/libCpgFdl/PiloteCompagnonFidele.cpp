#include "PiloteCompagnonFidele.h"

PiloteCompagnonFidele::PiloteCompagnonFidele(QGraphicsScene *scene, agent *r, QString path)
{
    m_chemin = path;
    m_mute = false;
    m_scene = scene;
    m_recepteur = r;

    m_dureeAffichage = DUREE_AFFICHAGE;
    m_sonDeMachine = new QSound(m_chemin + "son/CLICK.WAV", this);
    m_sonMsg = new QSound(m_chemin + "son/CHIMES.WAV", this);
    QTimer::singleShot(500, this, SLOT(initialiserEcran()));
}

PiloteCompagnonFidele::~PiloteCompagnonFidele()
{
    delete m_sonDeMachine;
    delete m_sonMsg;
}

void PiloteCompagnonFidele::setMuteVolume(bool mute)
{
    m_mute = mute;
}

void PiloteCompagnonFidele::planifierUneTache(QString message, QDateTime heure, int dureeExecution)
{
    // enregistrer la tâche dans la BD
    Tache * t = new Tache(this, message, heure, dureeExecution);

    m_tachesAeffectuer << t;
}

void PiloteCompagnonFidele::planifierUneTache(QString message, int dureeExecution)
{
    planifierUneTache(message, Horloge::currentDateTime().addMSecs(500), dureeExecution);
}


void PiloteCompagnonFidele::programmerExecutionDeTache()
{
    bool tacheSeule = m_tachesEnAttente.isEmpty();

    m_tachesEnAttente << tacheeTerminee();

    if(tacheSeule && !m_affichageEnCours)
    {
        initialiserAffichageEnCours();
    }
}

void PiloteCompagnonFidele::executerTacheEnCours()
{
    Tache * t = m_tachesEnAttente.takeFirst();
    m_dureeAffichage = t->dureeExecution();
    ecrireTexte(t->message());

    delete t;
}

void PiloteCompagnonFidele::initialiserAffichageEnCours()
{
    if(m_tachesEnAttente.isEmpty())
    {
        afficherMsgAttente();
    }else
    {
        if(!m_affichageEnCours)
        {
            m_affichageEnCours = true;  // avant de clignoter
            m_textEdit->setText(QString());
            if(!m_mute)
            {
                m_sonMsg->play();
            }

            clignoterEnveloppe();          
        }

        // appreter un autre affichage
        QTimer::singleShot(DUREE_AVANT_ENTREE, this, SLOT(executerTacheEnCours()));
    }
}

void PiloteCompagnonFidele::clignoterEnveloppe()
{
    static bool visible = true;

    if(m_affichageEnCours)
    {
        m_enveloppe->setVisible(visible);
        visible = !visible; // pour le prochain
        QTimer::singleShot(500, this, SLOT(clignoterEnveloppe()));
    }else
    {
        visible = true; // pour rendre directement visible au prochain tour
        m_enveloppe->setVisible(false);
    }
}

void PiloteCompagnonFidele::afficherIconCompagnon()
{
    QPixmap pixmap2(":/images/compagnon.jpg");
    QGraphicsPixmapItem * compagnon = new QGraphicsPixmapItem(pixmap2);

    compagnon->setScale(0.35);
    float x1 = m_scene->width() - compagnon->sceneBoundingRect().width()   - 5;
    float y1 = m_scene->height() - compagnon->sceneBoundingRect().height() - 5;
    compagnon->setPos(x1, y1);
    m_scene->addItem(compagnon);
}

void PiloteCompagnonFidele::ecrireTexte(QString text)
{
    m_message = text;
    ecrireTexte();
}

void PiloteCompagnonFidele::ecrireTexte()
{
    static QString messageAffiche = QString();
    static int index = -1;

    if(m_message == messageAffiche)
    {
        m_derMsgAffiche = m_message;
        emit msgAffiche();
        messageAffiche = QString();
        index = -1;
        QTimer::singleShot(m_dureeAffichage, this, SLOT(initialiserAffichageEnCours()));
    }else
    {
        index++;
        messageAffiche.append(m_message.at(index));
        m_textEdit->setText(messageAffiche);

//        if(!m_mute)
//        {
//            m_sonDeMachine->stop();
//            m_sonDeMachine->play();
//        }

        QTimer::singleShot(75, this, SLOT(ecrireTexte()));
    }
}

void PiloteCompagnonFidele::initialiserEcran()
{
    QGraphicsView * view = qobject_cast<QGraphicsView *>(m_scene->views().at(0));

    view->setFixedSize(longueur(), largeur());
    view->setAlignment(Qt::AlignCenter);
    view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    view->setResizeAnchor(QGraphicsView::AnchorViewCenter);

    // ajuster la scene
    m_scene->setSceneRect(  0
                          , 0
                          , longueur()  - 5
                          , largeur()   - 5);

    // créer la zone de texte
    m_textEdit = new QTextEdit(QString());
    m_textEdit->setFont(QFont("Comic Sans MS", 11,QFont::Bold));
    m_textEdit->setAlignment(Qt::AlignJustify);
    m_textEdit->setFrameShape(QTextEdit::NoFrame);

    m_proxyWidgetTextEdit = m_scene->addWidget(m_textEdit);
    m_proxyWidgetTextEdit->resize(310, 80);
    float y = (m_scene->height() - m_proxyWidgetTextEdit->size().height()) / 2.0;
    float x = (m_scene->width() - m_proxyWidgetTextEdit->size().width()) / 2.0;
    m_proxyWidgetTextEdit->setPos(x, y);

    // créer l'enveloppe
    QPixmap pixmap(":/images/enveloppe.jpg");
    m_enveloppe = new QGraphicsPixmapItem(pixmap);
    m_enveloppe->setPos(5, 5);
    m_enveloppe->setScale(0.15);
    m_scene->addItem(m_enveloppe);
    m_enveloppe->setVisible(false);

    // afficher l'icon compagnon
    afficherIconCompagnon();

    // afficher message de bienvenue
    QString msg = tr("Salut %1! Bienvenue au service réception et bon service!")
                  .arg(m_recepteur->nom());

    planifierUneTache(msg, Horloge::currentDateTime().addSecs(1));
}

void PiloteCompagnonFidele::afficherMsgAttente()
{
    m_affichageEnCours = false;
    m_textEdit->setText(MESSAGE_ATTENTE);
}

float PiloteCompagnonFidele::longueur()
{
    return 360.0;
}

float PiloteCompagnonFidele::largeur()
{
    return 225.0;
}

Tache * PiloteCompagnonFidele::tacheeTerminee()
{
    for(int i = 0; i < m_tachesAeffectuer.count(); i++)
    {
        if(m_tachesAeffectuer.at(i)->lancee())
        {
            return m_tachesAeffectuer.takeAt(i);
        }
    }

    return 0;
}
