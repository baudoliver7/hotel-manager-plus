#ifndef BDIDENTIFIERCLIENTRESTO_H
#define BDIDENTIFIERCLIENTRESTO_H

#include "bdLib_global.h"

#include <QDialog>
#include <QSqlTableModel>

#include "BDFormulaireClientSimple.h"
#include "MesTables.h"

namespace Ui {
    class BDIdentifierClientResto;
}

class BDLIBSHARED_EXPORT BDIdentifierClientResto : public QDialog {
    Q_OBJECT
public:
    BDIdentifierClientResto(bool searchOnly, QWidget *parent = 0);
    ~BDIdentifierClientResto();

    client clientSelectionne()const{return m_clientSelectionne;};
    bool clientEnTantQueLocataire()const{return m_clientEnTantQueLocataire;};
    int numOccupClientLocataire()const{return m_numOccupClientLocataire;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDIdentifierClientResto *ui;
    client m_clientSelectionne;
    QSqlTableModel * m_model;
    QStringList m_chambres;
    bool m_clientEnTantQueLocataire;
    int m_numOccupClientLocataire;

private slots:
    void on_lineEditRechercherCh_textChanged(QString );
    void on_btn_choisir_clicked();
    void updateEtatBtnChoisir(QModelIndex);
    void on_btn_annuler_clicked();
    void on_btn_ok_clicked();
    void initialiserClientSelectionne();
    void updateEtatChampsClientInconnu(bool);
    void updateEtatChampsClientConnu(bool);
    void updateEtatChampsClientLocataire(bool);
    void updateEtatBtnDetails();
    void updateEtatBtnOK();
    void afficherClientSelectionne();
    void initialiserTableau();
    void chargerClientConnu();
    void chargerChambres();
    void on_btn_details_clicked();
    void on_btn_identifier_clicked();
};

#endif // BDIDENTIFIERCLIENTRESTO_H
