#include "BDAjouterUneChambree.h"
#include "ui_BDAjouterUneChambre.h"

BDAjouterUneChambre::BDAjouterUneChambre(int idTypeDeChambre, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDAjouterUneChambre)
{
    ui->setupUi(this);

    m_idTypeDeChambre = idTypeDeChambre;

    m_niveaux << etage::niveaux();
    ui->comboBoxNiveau->addItems(m_niveaux);
}

BDAjouterUneChambre::~BDAjouterUneChambre()
{
    delete ui;
}

void BDAjouterUneChambre::changeEvent(QEvent *e)
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

QString BDAjouterUneChambre::identifiant()
{
    return ui->lineEditIdentifiant->text();
}

void BDAjouterUneChambre::on_btn_annuler_clicked()
{
    reject();
}

void BDAjouterUneChambre::on_btn_ok_clicked()
{
    if(ui->lineEditIdentifiant->text().isEmpty())
    {
        QMessageBox::information(this, "Ajouter une chambre", "Vous ne pouvez pas entrer un identifiant vide!");
        return;
    }

    chambre ch(ui->lineEditIdentifiant->text());
    if(ch.existe())
    {
        QMessageBox::information(this, "Unicité de l'identifiant", "Cet identifiant existe déjà! \n\n Entrez un autre identifiant!");
        return;
    }

    // enregistrer la nouvelle chambre
    ch.setIdentifiant(ui->lineEditIdentifiant->text());
    ch.setOccupee(false);
    ch.setIdTypeChambre(m_idTypeDeChambre);
    ch.setHorsService(false);
    ch.setIdEtage(ui->comboBoxNiveau->currentIndex() + 1);
    ch.enregistrer();

    accept();
}
