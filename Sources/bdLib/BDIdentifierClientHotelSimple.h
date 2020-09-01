#ifndef BDIDENTIFIERCLIENTHOTELSIMPLE_H
#define BDIDENTIFIERCLIENTHOTELSIMPLE_H

#include "bdLib_global.h"

#include <QDialog>
#include <QSqlTableModel>

#include "BDFormulaireClientSimple.h"
#include "MesTables.h"

namespace Ui {
    class BDIdentifierClientHotelSimple;
}

class BDLIBSHARED_EXPORT BDIdentifierClientHotelSimple : public QDialog {
    Q_OBJECT
public:
    BDIdentifierClientHotelSimple(QWidget *parent = 0);
    ~BDIdentifierClientHotelSimple();

    client clientSelectionne()const{return m_clientSelectionne;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDIdentifierClientHotelSimple *ui;
    client m_clientSelectionne;
    QSqlTableModel * m_model;
    bool m_affichage;

private slots:
    void on_btn_choisir_clicked();
    void updateEtatBtnChoisir(QModelIndex);
    void on_btn_annuler_clicked();
    void on_btn_ok_clicked();
    void initialiserClientSelectionne();
    void updateEtatChampsClientInconnu(bool);
    void updateEtatChampsClientConnu(bool);
    void updateEtatBtnDetails();
    void updateEtatBtnOK();
    void initialiserTableau();
    void chargerClientConnu();
    void on_btn_details_clicked();
    void on_btn_identifier_clicked();
};

#endif // BDIDENTIFIERCLIENTHOTELSIMPLE_H
