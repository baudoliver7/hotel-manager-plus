#include "MdiService.h"
#include "ui_MdiService.h"

MdiService::MdiService(agent *r, Horloge *h, QString path, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MdiService)
{
    ui->setupUi(this);

    m_fermer = false;
    m_chemin = path;
    m_horloge = h;
    m_agent = r;
    m_parent = parent;

    initialiserMessagerie();
    connect(m_horloge, SIGNAL(minuteOvered()), this, SLOT(afficherHorloge()));

    afficherHorloge();
    afficherDateDeConnection();
}

MdiService::~MdiService()
{
    delete ui;

    delete m_bdMessagerie;
}

void MdiService::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MdiService::closeEvent(QCloseEvent *e)
{
    if(!m_fermer)
    {
        emit closed();
    }
}

bool MdiService::seDeconnecter()
{
    bool deconnecte = false;
    QString title = tr("Se déconnecter du compte %1").arg(m_agent->login());
    if(QMessageBox::question(this, title, "Désirez-vous vous déconnecter?"
                             , "Oui", "Non") == 0)
    {
        //updateHeureFin();
        m_agent->setConnecte(false);
        m_agent->setEtatFinConnection(false);
        m_agent->setCodeDeSortie(0);
        m_agent->enregistrer();
        deconnecte = true;
        m_fermer = true;
    }

    return deconnecte;
}

void MdiService::initialiserMessagerie()
{
    m_bdMessagerie = new BDMessagerie( m_agent
                                      , m_horloge
                                      , m_chemin
                                      , ui->btn_lire
                                      , ui->labelEnveloppe
                                      , ui->labelNbMsgNonLus
                                      , m_parent);

    m_bdMessagerie->setWindowModality(Qt::NonModal);
    m_bdMessagerie->setWindowTitle("Envoyez et/ou recevoir des messages");

    connect(ui->btn_lire, SIGNAL(clicked()), m_bdMessagerie, SLOT(show()));
}

void MdiService::afficherHorloge()
{
    QTime now = Horloge::currentTime();
    QStringList heure;
    heure = now.toString(Qt::ISODate).split(":");

    ui->label_horloge->setText(tr("Heure du serveur: %1 h %2 min").arg(heure.first()).arg(heure.at(1)));
}

void MdiService::afficherDateDeConnection()
{
    QString message = tr("Vous êtes connecté depuis le %1").arg(Horloge::currentDateTime().toString(Qt::SystemLocaleLongDate));
    ui->label_heureDeConnection->setText(message);
}
