#include "BDRechercherUnGroupe.h"
#include "ui_BDRechercherUnGroupe.h"

BDRechercherUnGroupe::BDRechercherUnGroupe(bool searchOnly, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDRechercherUnGroupe)
{
    ui->setupUi(this);

    m_bdWaiting = new BDWaiting(this);

    ui->btn_contacts->setEnabled(false);
    ui->btn_choisir->setEnabled(false);
    ui->btn_imprimerHotel->setEnabled(false);
    ui->btn_imprimerResto->setEnabled(false);

    if(searchOnly)
        ui->btn_annuler->setText("Fermer");

    ui->btn_choisir->setVisible(!searchOnly);

    ui->treeWidgetGroupes->setColumnHidden(0, true);

    connect(ui->treeWidgetGroupes->selectionModel()
            , SIGNAL(selectionChanged(QItemSelection,QItemSelection))
            , this
            , SLOT(updateEtatBtnChoisir()));

    connect(ui->rb_en_cours, SIGNAL(toggled(bool)), this, SLOT(updateEtatGroupeRech()));
    connect(ui->btn_rechercherGroupe, SIGNAL(clicked()), this, SLOT(afficherGroupes()));

    ui->rb_en_cours->setChecked(true);
    afficherGroupes();
}

BDRechercherUnGroupe::~BDRechercherUnGroupe()
{
    delete ui;
    delete m_bdWaiting;
}

void BDRechercherUnGroupe::changeEvent(QEvent *e)
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

void BDRechercherUnGroupe::chargerGroupes()
{
    ui->treeWidgetGroupes->clear();

    QList<QSqlRecord> records;

    groupe gp;
    if(ui->rb_tout->isChecked())
    {
        QString condition;
        if(ui->lineEditNomGroupe->text().isEmpty())
        {
            condition = tr("%1 = %2").arg(gp.idGroupeName()).arg(-1);
        }else
        {
            condition = tr("%1 LIKE '%2%'").arg(gp.libelleName()).arg(ui->lineEditNomGroupe->text());
        }

        records = InfosSurBD::enregistrements(Groupe::Libelle, condition);
    }else
    {
        // en cours
        records = InfosSurBD::enregistrements(Groupe::Libelle, tr("%1 = %2")
                                              .arg(gp.termineeName())
                                              .arg(false));
    }

    foreach(QSqlRecord r, records)
    {
        groupe gr(r);

        QStringList data;
        data << QString::number(gr.idGroupe())
             << gr.libelle()
             << client(gr.idResponsable()).nomComplet()
             << typeDeClient(profileClient(gr.idProfileClient()).idTypeClient()).type()
             << QString::number(gr.nbPersPrevues())
             << QString::number(gr.nbPersEnregistrees())
             << typeDeChambre(gr.idTypeDeChambreMaj()).type()
             << gr.dateOccupation().toString(Qt::SystemLocaleDate)
             << MesTables::convertirAnMoisSemaineJour(gr.dureeOccupation())
             << MesTables::moneyToString(gr.avance())
             << MesTables::moneyToString(gr.coutTotalGlobal())
             << MesTables::moneyToString(gr.sommePayeeGlobale())
             << MesTables::moneyToString(gr.coutTotalGlobal() - gr.sommePayeeGlobale());

        ui->treeWidgetGroupes->addTopLevelItem(new QTreeWidgetItem(data));
    }

    m_bdWaiting->close();
}

void BDRechercherUnGroupe::updateEtatBtnChoisir()
{
    bool itemSelected = !ui->treeWidgetGroupes->selectedItems().isEmpty();
    ui->btn_choisir->setEnabled(itemSelected);

    groupe gp(currentIdGroupe());

    QList<QSqlRecord> records;
    records = gp.occupations_des_membres_records();

    if(!records.isEmpty())
    {
        ui->btn_imprimerResto->setEnabled(gp.fraisRestoTotal() != 0);
        ui->btn_imprimerBar->setEnabled(gp.fraisBarTotal() != 0);
        ui->btn_imprimerHotel->setEnabled(true);
    }else
    {
        ui->btn_imprimerResto->setEnabled(false);
        ui->btn_imprimerHotel->setEnabled(false);
    }

    // pour btn_contact
    ui->btn_contacts->setEnabled(itemSelected);
}

void BDRechercherUnGroupe::on_btn_annuler_clicked()
{
    reject();
}

void BDRechercherUnGroupe::on_btn_choisir_clicked()
{
    m_groupeSelectionne = groupe(currentIdGroupe());
    accept();
}

int BDRechercherUnGroupe::currentIdGroupe()
{
    int row = ui->treeWidgetGroupes->currentIndex().row();
    return ui->treeWidgetGroupes->topLevelItem(row)->text(0).toInt();
}

void BDRechercherUnGroupe::on_btn_imprimerHotel_clicked()
{
    groupe gp(currentIdGroupe());
    factureHotelGroupe * facture = new factureHotelGroupe(gp);

    // impression
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    QPrintDialog printDialog(&printer, this);

    // éventuelle pensée
    if(printDialog.exec() == QDialog::Accepted)
    {
        QPainter painter(&printer);

        // print, fitting the viewport contents into a full page
        facture->view()->render(&painter);
    }

    delete facture;
}

void BDRechercherUnGroupe::on_btn_imprimerResto_clicked()
{
    groupe gp(currentIdGroupe());
    factureRestoGroupe * facture = new factureRestoGroupe(gp);

    // impression
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    QPrintDialog printDialog(&printer, this);

    // éventuelle pensée
    if(printDialog.exec() == QDialog::Accepted)
    {
        QPainter painter(&printer);

        // print, fitting the viewport contents into a full page
        facture->view()->render(&painter);
    }

    delete facture;
}

void BDRechercherUnGroupe::on_btn_contacts_clicked()
{
    groupe gp(currentIdGroupe());
    DialogContact bd(gp.contacts(), this, true);

    bd.exec();
}

void BDRechercherUnGroupe::updateEtatGroupeRech()
{
    bool enabled = ui->rb_tout->isChecked();
    ui->labelNomGroupe->setEnabled(enabled);
    ui->lineEditNomGroupe->setEnabled(enabled);
}

void BDRechercherUnGroupe::afficherGroupes()
{
    m_bdWaiting->show();
    QTimer::singleShot(5, this, SLOT(chargerGroupes()));
}

void BDRechercherUnGroupe::on_btn_imprimerBar_clicked()
{
    groupe gp(currentIdGroupe());
    factureBarGroupe * facture = new factureBarGroupe(gp);

    // impression
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    QPrintDialog printDialog(&printer, this);

    // éventuelle pensée
    if(printDialog.exec() == QDialog::Accepted)
    {
        QPainter painter(&printer);

        // print, fitting the viewport contents into a full page
        facture->view()->render(&painter);
    }

    delete facture;
}
