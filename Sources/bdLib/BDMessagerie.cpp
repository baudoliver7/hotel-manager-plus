#include "BDMessagerie.h"
#include "ui_BDMessagerie.h"

BDMessagerie::BDMessagerie(agent *r, Horloge *h, QString path, QPushButton *btnLire, QLabel *enveloppe, QLabel *labelMessageNonLus, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDMessagerie)
{
    ui->setupUi(this);

    m_chemin = path;
    m_agent = r;
    nbTotalDeMsgNL = 0;
    m_timeEnveloppe = 0;
    m_horloge = h;
    m_btnLire = btnLire;
    m_enveloppe = enveloppe;
    m_labelMessageNonLus = labelMessageNonLus;

    m_groupWidgetExiste = m_btnLire && m_enveloppe && m_labelMessageNonLus;

    connect(m_horloge, SIGNAL(fiveSecsOvered()), this, SLOT(actualiserConnectes()));
    connect(m_horloge, SIGNAL(twoSecsOvered()), this, SLOT(verifierMsgNonLus()));

    ui->groupBox->setTitle(tr("Ecrire un message (%1/160 caractères)").arg(0));
    on_btn_initialiser_clicked();
    actualiserConnectes();

    if(m_groupWidgetExiste)
    {
        m_timeEnveloppe = new QTimer();
        m_timeEnveloppe->setInterval(500);

        connect(m_timeEnveloppe, SIGNAL(timeout()), this, SLOT(clignoterEnveloppe()));
        connect(m_btnLire, SIGNAL(clicked()), this, SLOT(show()));

        clignoterEnveloppe();
    }
}

BDMessagerie::~BDMessagerie()
{
    delete ui;

    if(m_timeEnveloppe) delete m_timeEnveloppe;
}

void BDMessagerie::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void BDMessagerie::showEvent(QShowEvent *e)
{
    QDialog::showEvent(e);
    nbTotalDeMsgNL = 0;
    avertirMsgNonLus(nbTotalDeMsgNL);
}

void BDMessagerie::actualiserConnectes() // rafraichir chaque 10 secondes
{
    QString currentPseudo = ui->comboBoxPseudo->currentText();

    ui->comboBoxPseudo->clear();
    m_matricules.clear();

    QList<QSqlRecord> recepteurs;
    recepteurs << agent::agentsConnectes();

    QStringList connectes;
    for(int i = 0; i < recepteurs.count(); i++)
    {
        agent r1(recepteurs.at(i));
        if(r1.matricule() != m_agent->matricule())
        {
            connectes << r1.login();
            m_matricules << r1.matricule();
        }
    }

    ui->comboBoxPseudo->addItems(connectes);

    if(connectes.contains(currentPseudo))
    {
        ui->comboBoxPseudo->setCurrentIndex(connectes.indexOf(currentPseudo));
    }
}

void BDMessagerie::verifierMsgNonLus()
{
    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Message::Libelle, tr("%1 = '%2' AND %3 = %4")
                                .arg(message().destinataireName()).arg(m_agent->matricule())
                                .arg(message().lueName()).arg(false));

    for(int i = 0; i < records.count(); i++)
    {
        message msg(records.at(i));
        msg.setLue(true);
        msg.enregistrer();
        ajouterMsgRecus(msg);
        nbTotalDeMsgNL++;
    }

    if(!records.isEmpty())
    {
        ui->tabWidget->setCurrentIndex(0);
        if(isHidden())
        {
            avertirMsgNonLus(nbTotalDeMsgNL);
        }else
        {
            nbTotalDeMsgNL = 0; // plus besoin
        }

        QSound::play(m_chemin + "son/CHIMES.WAV");
    }
}

void BDMessagerie::ajouterMsgRecus(message msg)
{
    agent r(msg.expediteur());
    QString l_msg = tr("%1 - De %2 \n-> message: \n%3 \n").arg(msg.heuredEnvoi().toString(Qt::SystemLocaleLongDate))
                                                         .arg(r.login()).arg(msg.contenu());
    ui->msgNonLus->append(l_msg);
}

void BDMessagerie::ajouterMsgEnvoye(message msg)
{
    QString l_msg = tr("%1 - A %2 \n-> message: \n%3 \n").arg(msg.heuredEnvoi().toString(Qt::SystemLocaleLongDate))
                                                         .arg(ui->comboBoxPseudo->itemText(m_matricules.indexOf(msg.destinateur()))).arg(msg.contenu());
    ui->historique->append(l_msg);
}

void BDMessagerie::on_btn_effacer_clicked()
{
    ui->historique->clear();
}

void BDMessagerie::on_btn_initialiser_clicked()
{
    ui->msgEcrits->clear();
}

void BDMessagerie::on_btn_envoyer_clicked()
{
    message msg;
    msg.setContenu(ui->msgEcrits->toPlainText());
    msg.setExpediteur(m_agent->matricule());
    msg.setDestinateur(m_matricules.at(ui->comboBoxPseudo->currentIndex()));
    msg.setHeuredEnvoi(Horloge::currentDateTime());
    msg.setLue(false);
    msg.enregistrer();
    ajouterMsgEnvoye(msg);

    on_btn_initialiser_clicked();
    ui->tabWidget->setCurrentIndex(1);
}

void BDMessagerie::on_msgEcrits_textChanged()
{
    QString text = ui->msgEcrits->toPlainText();
    bool disabled = text.isEmpty() || ui->comboBoxPseudo->currentText().isEmpty();
    ui->btn_envoyer->setDisabled(disabled);

    if(text.count() > 160)
    {
        text.resize(160);
        ui->msgEcrits->setText(text);
    }

    ui->groupBox->setTitle(tr("Ecrire un message (%1/160 caractères)").arg(text.count()));
}


void BDMessagerie::on_btn_effacerMsgRecus_clicked()
{
    ui->msgNonLus->clear();
}

void BDMessagerie::avertirMsgNonLus(int nbMsgNonLus)
{
    if(m_groupWidgetExiste)
    {
        if(nbMsgNonLus > 0 && m_timeEnveloppe->isActive())
            return;

        if(nbMsgNonLus > 0 && !m_timeEnveloppe->isActive())
        {
            m_enveloppe->setPixmap(QPixmap(":/images/enveloppe.png"));
            m_btnLire->setText("Lire message(s)");
        }

        // sinon = 0
        clignoterEnveloppe();
    }
}

void BDMessagerie::clignoterEnveloppe()
{
    if(m_groupWidgetExiste)
    {
        static QString fileName = ENVELLOPE_NORM;

        if(nbTotalDeMsgNL > 0)
        {
            m_enveloppe->setPixmap(QPixmap(fileName));
            if(nbTotalDeMsgNL == 1)
            {
                m_labelMessageNonLus->setText(tr("%1 message non lu").arg(1));
            }else
            {
                m_labelMessageNonLus->setText(tr("%1 messages non lus").arg(nbTotalDeMsgNL));
            }

           if(fileName.isEmpty())
               fileName = ENVELOPPE_ALERTE;
           else
               fileName = QString();// pour le prochain

            m_timeEnveloppe->start();
        }else
        {
            fileName = ENVELLOPE_NORM; // pour rendre directement visible au prochain tour
            m_enveloppe->setVisible(true);
            m_enveloppe->setPixmap(QPixmap(fileName));
            m_labelMessageNonLus->setText(tr("%1 message").arg(0));
            m_btnLire->setText("Ecrire un message");
            m_btnLire->resize(120, 23);
            m_timeEnveloppe->stop();
        }
    }
}
