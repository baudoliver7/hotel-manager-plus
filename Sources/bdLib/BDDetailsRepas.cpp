#include "BDDetailsRepas.h"
#include "ui_BDDetailsRepas.h"

BDDetailsRepas::BDDetailsRepas(int idRepasCResto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDDetailsRepas)
{
    ui->setupUi(this);

    m_idRepasCResto = idRepasCResto;

    initialiserTableau();
    rafraichirTable();
}

BDDetailsRepas::~BDDetailsRepas()
{
    delete ui;
}

void BDDetailsRepas::changeEvent(QEvent *e)
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

void BDDetailsRepas::afficherElement(int row, int column, const QString &value)
{
    QTableWidgetItem * item = new QTableWidgetItem(value);
    item->setTextAlignment(Qt::AlignCenter);

    ui->tableWidget->setItem(row, column, item);
}

void BDDetailsRepas::rafraichirTable()
{
    QList<QSqlRecord> records;
    records << consoResto::consoResto_records(m_idRepasCResto);

    int somme = 0;
    for(int row = 0; row < records.count(); row++)
    {
        ui->tableWidget->setRowCount(row + 1);
        consoResto cr(records.at(row));
        somme += cr.coutTotal();
        menuResto mr(cr.idMenu());

        afficherElement(row, MENU, mr.libelle());
        afficherElement(row, PRIXUNITAIRE, QString::number(cr.coutTotal() / cr.nbMenu()));
        afficherElement(row, _QUANTITE, QString::number(cr.nbMenu()));
        afficherElement(row, PRIXTOTAL, QString::number(cr.coutTotal()));
    }

    ui->lineEditTotal->setText(QString::number(somme));
}

void BDDetailsRepas::initialiserTableau()
{
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void BDDetailsRepas::on_btn_fermer_clicked()
{
    close();
}

void BDDetailsRepas::on_btn_imprimerFacture_clicked()
{
    repasCompletResto rcr(m_idRepasCResto);

    factureRestoIndividu * facture = new factureRestoIndividu(rcr);

    // impression
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A5);
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
