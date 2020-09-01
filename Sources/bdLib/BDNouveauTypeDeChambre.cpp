#include "BDNouveauTypeDeChambre.h"
#include "ui_BDNouveauTypeDeChambre.h"

BDNouveauTypeDeChambre::BDNouveauTypeDeChambre(int idType, QWidget *parent, int idTypeClient) :
    QDialog(parent),
    ui(new Ui::BDNouveauTypeDeChambre)
{
    ui->setupUi(this);
    m_idType = idType;
    m_idTypeDeClient = idTypeClient;
}

BDNouveauTypeDeChambre::~BDNouveauTypeDeChambre()
{
    delete ui;
}

void BDNouveauTypeDeChambre::changeEvent(QEvent *e)
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

void BDNouveauTypeDeChambre::on_btn_ok_clicked()
{
    if(ui->lineEditDesignation->text().isEmpty())
    {
        QMessageBox::information(this, "Enregistrer un type", "Vous devez entrer un type non vide!");
        return;
    }

    QString tableName;
    QString condition;

    if(m_idType == TYPEDECHAMBRE)
    {
        condition = tr("%1 = '%2'")
                            .arg(typeDeChambre().typeName())
                            .arg(ui->lineEditDesignation->text().replace("'", "''"));

        tableName = TypeDeChambre::Libelle;
    }else
    {
        if(m_idType == TYPEDECLIENT)
        {
            condition = tr("%1 = '%2'")
                                .arg(typeDeClient().typeName())
                                .arg(ui->lineEditDesignation->text().replace("'", "''"));

            tableName = TypeDeClient::Libelle;
        }else
        {
            condition = tr("%1 = '%2'")
                                .arg(profileClient().profileName())
                                .arg(ui->lineEditDesignation->text().replace("'", "''"));

            tableName = ProfileClient::Libelle;
        }
    }

    if(!InfosSurBD::enregistrements(tableName, condition).isEmpty())
    {
        QMessageBox::information(this, "Unicité du type", "Le type que vous entré existe déjà! \n\n Veuillez entrer un autre type.");
    }else
    {
        // enregistrer dans la bd
        QString type = ui->lineEditDesignation->text();
        if(m_idType == TYPEDECHAMBRE)
        {
            typeDeChambre t;
            t.setType(type);
            t.setDisponible(true);
            t.enregistrer();
        }else
        {
            if(m_idType == TYPEDECLIENT)
            {
                typeDeClient t;
                t.setType(type);
                t.setDisponible(true);
                t.enregistrer();
            }else
            {
                profileClient t;
                t.setProfile(type);
                t.setDisponible(true);
                t.setIdTypeClient(m_idTypeDeClient);
                t.enregistrer();
            }
        }

        accept();
    }
}

void BDNouveauTypeDeChambre::on_btn_annuler_clicked()
{
    reject();
}

QString BDNouveauTypeDeChambre::nouveauType()const
{
    return ui->lineEditDesignation->text();
}
