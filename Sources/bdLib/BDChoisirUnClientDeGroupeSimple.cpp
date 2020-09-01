#include "BDChoisirUnClientDeGroupeSimple.h"
#include "ui_BDChoisirUnClientDeGroupeSimple.h"

BDChoisirUnClientDeGroupeSimple::BDChoisirUnClientDeGroupeSimple(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDChoisirUnClientDeGroupeSimple)
{
    ui->setupUi(this);

    m_idGroupe = 0;
    m_idProfileClient = 0;

    ui->comboBoxProfile->setEnabled(false);
    ui->comboBoxTypeDeClient->setEnabled(false);

    ui->treeWidgetMembres->setColumnHidden(0, true);
    ui->treeWidgetGroupesEnCours->setColumnHidden(0, true);
    ui->groupBoxMembres->setTitle(tr("Membres du groupe (%1)").arg(0));
    chargerGroupesEnCours();

    connect(ui->treeWidgetGroupesEnCours->selectionModel()
            , SIGNAL(selectionChanged(QItemSelection,QItemSelection))
            , this
            , SLOT(chargerMembres()));

    connect(ui->treeWidgetMembres->selectionModel()
            , SIGNAL(selectionChanged(QItemSelection,QItemSelection))
            , this
            , SLOT(afficherClient()));

    on_lineEditClientSelectionne_textChanged(QString());

    // afficher types de client
    QList<typeDeClient> types_de_clients = typeDeClient::typeDeClientDisponibles(true);
    QStringList types_de_clients_str;
    foreach(typeDeClient t, types_de_clients)
    {
        m_id_types_client << t.idTypeDeClient();
        types_de_clients_str << t.type();
    }

    ui->comboBoxTypeDeClient->addItems(types_de_clients_str);
}

BDChoisirUnClientDeGroupeSimple::~BDChoisirUnClientDeGroupeSimple()
{
    delete ui;
}

void BDChoisirUnClientDeGroupeSimple::changeEvent(QEvent *e)
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

void BDChoisirUnClientDeGroupeSimple::chargerGroupesEnCours()
{
    ui->treeWidgetGroupesEnCours->clear();
    m_groupesSelectionnes.clear();
    QString condition = tr("%1 = %2").arg(groupe().termineeName()).arg(false);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Groupe::Libelle, condition);

    foreach(QSqlRecord r, records)
    {
        groupe gr(r);
        client cl(gr.idResponsable());
        QStringList data;
        data << QString::number(gr.idGroupe())
             << gr.libelle()
             << cl.nomComplet()
             << QString::number(gr.nbPersEnregistrees());

        m_groupesSelectionnes << gr;
        ui->treeWidgetGroupesEnCours->addTopLevelItem(new QTreeWidgetItem(data));
    }
}

void BDChoisirUnClientDeGroupeSimple::chargerMembres()
{
    ui->treeWidgetMembres->clear();
    m_clientsSelectionnes.clear();

    if(ui->treeWidgetGroupesEnCours->selectedItems().isEmpty())
    {
        // titre du groupe
        ui->groupBoxMembres->setTitle(tr("Membres du groupe (%1)").arg(0));
        return;
    }

    groupeLiaison grl;
    QString condition = tr("%1 = %2")
                        .arg(grl.idGroupeName())
                        .arg(currentIdGroupe());

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(GroupeLiaison::Libelle, condition);

    foreach(QSqlRecord r, records)
    {
        groupeLiaison grl(r);
        client cl(grl.codeClient());

        occupation oc;
        QString condition1 = tr("%1 = %2 AND %3 = %4")
                             .arg(oc.codeClientName())
                             .arg(cl.codeDuClient())
                             .arg(oc.idGroupeName())
                             .arg(grl.idGroupe());

        QList<QSqlRecord> records1;
        records1 << InfosSurBD::enregistrements(Occupation::Libelle, condition1);

        QString estLoge = "Non";
        if(!records1.isEmpty())
        {
            occupation oc1(records1.first());

            if(oc1.terminee())
                estLoge = "Logé et terminé";
            else
                estLoge = "Oui";
        }

        QStringList data;
        data << QString::number(cl.codeDuClient())
             << cl.nomComplet()
             << estLoge;

        m_clientsSelectionnes << cl;
        ui->treeWidgetMembres->addTopLevelItem(new QTreeWidgetItem(data));
    }

    // titre du groupe
    groupe gr(currentIdGroupe());
    ui->groupBoxMembres->setTitle(tr("Membres du groupe de %1 (%2)")
                                  .arg(gr.libelle())
                                  .arg(m_clientsSelectionnes.count()));
}

int BDChoisirUnClientDeGroupeSimple::currentIdGroupe()
{
    int row = ui->treeWidgetGroupesEnCours->currentIndex().row();
    int idGroupe = ui->treeWidgetGroupesEnCours->topLevelItem(row)->text(0).toInt();
    return idGroupe;
}

int BDChoisirUnClientDeGroupeSimple::currentIdClient()
{
    int row = ui->treeWidgetMembres->currentIndex().row();
    int idClient = ui->treeWidgetMembres->topLevelItem(row)->text(0).toInt();
    return idClient;
}

void BDChoisirUnClientDeGroupeSimple::updateEtatBtnChoisir()
{
    QModelIndex index = ui->treeWidgetMembres->currentIndex();

    if(index.isValid())
    {
        ui->btn_choisir->setEnabled(true);
    }else
    {
        ui->btn_choisir->setEnabled(false);
    }
}

void BDChoisirUnClientDeGroupeSimple::on_btn_fermer_clicked()
{
    reject();
}

void BDChoisirUnClientDeGroupeSimple::on_btn_choisir_clicked()
{
    m_idGroupe = currentIdGroupe();

    // renseigner profile du client sélectionné
    m_idProfileClient = m_id_profiles_client.at(ui->comboBoxProfile->currentIndex());

    accept();
}

void BDChoisirUnClientDeGroupeSimple::on_lineEditClientSelectionne_textChanged(QString text)
{
    bool enabled = !text.isEmpty();

    ui->btn_details->setEnabled(enabled);
    ui->btn_choisir->setEnabled(enabled);

    ui->comboBoxProfile->setEnabled(enabled);
    ui->comboBoxTypeDeClient->setEnabled(enabled);
}

void BDChoisirUnClientDeGroupeSimple::afficherClient()
{
    int row = ui->treeWidgetMembres->currentIndex().row();
    QString estLoge = ui->treeWidgetMembres->topLevelItem(row)->text(2);

    if(estLoge == "Non")
    {
        m_clientChoisi = client(currentIdClient());
        ui->lineEditClientSelectionne->setText(m_clientChoisi.nomComplet());

        // afficher catégorie du groupe
        groupe gr(currentIdGroupe());
        afficherCategorie(gr.idProfileClient());
    }
}

void BDChoisirUnClientDeGroupeSimple::on_btn_details_clicked()
{
    BDFormulaireClientSimple bd(m_clientChoisi, true, this);
    bd.setWindowTitle("Identifier un client");

    bd.exec();
}

void BDChoisirUnClientDeGroupeSimple::on_comboBoxTypeDeClient_currentIndexChanged(int index)
{
    if(index < 0)
        return;

    // charger profile
    typeDeClient t(m_id_types_client.at(index));

    chargerProfile(t.idTypeDeClient());
}

void BDChoisirUnClientDeGroupeSimple::chargerProfile(int idTC)
{
    QList<profileClient> profiles_client;
    profiles_client << profileClient::profilesClientDisponibles(true, idTC);

    QStringList profiles_client_str;

    m_id_profiles_client.clear();
    foreach(profileClient p, profiles_client)
    {
        m_id_profiles_client << p.idProfile();
        profiles_client_str << p.profile();
    }

    ui->comboBoxProfile->clear();
    ui->comboBoxProfile->addItems(profiles_client_str);
}

void BDChoisirUnClientDeGroupeSimple::afficherCategorie(int idProfileClient)
{
    if(m_id_types_client.isEmpty() || idProfileClient == 0)
        return;

    profileClient p(idProfileClient);

    // afficher type de client
    typeDeClient t(p.idTypeClient());
    int indexT = 0;
    if(m_id_types_client.contains(t.idTypeDeClient()))
        indexT = m_id_types_client.indexOf(t.idTypeDeClient());

    ui->comboBoxTypeDeClient->setCurrentIndex(indexT);

    // afficher profile
    chargerProfile(t.idTypeDeClient());

    int indexProfile = 0;
    if(m_id_profiles_client.contains(p.idProfile()))
        indexProfile = m_id_profiles_client.indexOf(p.idProfile());

    ui->comboBoxProfile->setCurrentIndex(indexProfile);
}
