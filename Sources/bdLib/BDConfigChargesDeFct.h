#ifndef BDCONFIGCHARGESDEFCT_H
#define BDCONFIGCHARGESDEFCT_H

#include "bdLib_global.h"

#include <QDialog>

#include "MesTables.h"

namespace Ui {
    class BDConfigChargesDeFct;
}

class BDLIBSHARED_EXPORT BDConfigChargesDeFct : public QDialog {
    Q_OBJECT
public:
    BDConfigChargesDeFct(QWidget *parent = 0);
    ~BDConfigChargesDeFct();

    static int chargesDeFctMensuelles();
    static int money(float argent);
    static QList<int> chfct();
    static QList<int> chfctSurPeriode();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDConfigChargesDeFct *ui;

private slots:
    void on_lineEditDiverses_textChanged(QString );
    void on_lineEditFactureDePoste_textChanged(QString );
    void on_lineEditCotisation_textChanged(QString );
    void on_lineEditCANAL_textChanged(QString );
    void on_lineEditCITELCOM_textChanged(QString );
    void on_lineEditEntretien_textChanged(QString );
    void on_lineEditCGA_textChanged(QString );
    void on_lineEditCNPS_textChanged(QString );
    void on_lineEditTablePub_textChanged(QString );
    void on_lineEditTaxesLocaux_textChanged(QString );
    void on_lineEditTimbre_textChanged(QString );
    void on_lineEditFoncier_textChanged(QString );
    void on_lineEditSynthetique_textChanged(QString );
    void on_lineEditLicence_textChanged(QString );
    void on_lineEditAchatProduits_textChanged(QString );
    void on_lineEditSODECI_textChanged(QString );
    void on_lineEditECIE_textChanged(QString );
    void on_lineEditSalaire_textChanged(QString );
    void on_buttonBox_accepted();
};

#endif // BDCONFIGCHARGESDEFCT_H
