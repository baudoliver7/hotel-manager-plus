#include "BDReglerUneNote.h"
#include "ui_BDReglerUneNote.h"

BDReglerUneNote::BDReglerUneNote(const agent &ag, int idRepasCResto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDReglerUneNote)
{
    ui->setupUi(this);

    m_agent = new agent(ag);
    ui->btn_ok->setEnabled(false);
    m_idRepasCResto = idRepasCResto;
    repasCompletResto rcr(m_idRepasCResto);
    int reste = rcr.reste();
    ui->lineEditMontantRestant->setText(QString::number(reste));

    ui->spinBoxMontantEncaisse->setMaximum(reste);
    ui->spinBoxMontantEncaisse->setMinimum(0);
    ui->spinBoxMontantEncaisse->setValue(0);
}

BDReglerUneNote::~BDReglerUneNote()
{
    delete ui;

    delete m_agent;
}

void BDReglerUneNote::changeEvent(QEvent *e)
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

void BDReglerUneNote::on_btn_annuler_clicked()
{
    reject();
}

void BDReglerUneNote::on_btn_ok_clicked()
{
    int montantEncaisse = ui->spinBoxMontantEncaisse->value();

    // enregistrer la note dans repasCompletResto
    repasCompletResto rcr(m_idRepasCResto);
    rcr.setMontantTotalEncaisse(rcr.montantTotalEncaisse() + montantEncaisse);
    rcr.enregistrer();

    // enregistrer la note dans les opérations
    operationService os;
    os.setCloturee(false);
    os.setDate(Horloge::currentDateTime());
    os.setMatriculeAgent(m_agent->matricule());
    os.setMontantEncaisse(montantEncaisse);

    QString libelle;
    if(montantEncaisse < rcr.totalAPayer())
        libelle = "Réglement total";
    else
        libelle = "Réglement partiel";

    os.setLibelle(libelle);
    os.enregistrer();

    accept();
}

void BDReglerUneNote::on_spinBoxMontantEncaisse_valueChanged(int value)
{
    ui->btn_ok->setEnabled(value != 0);
}
