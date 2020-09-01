#ifndef BDIDENTIFIERCLIENTHOTEL_H
#define BDIDENTIFIERCLIENTHOTEL_H

#include "bdLib_global.h"

#include <QDialog>
#include <QSqlTableModel>

#include "BDFormulaireClientSimple.h"
#include "MesTables.h"

namespace Ui {
    class BDIdentifierClientHotel;
}

class BDLIBSHARED_EXPORT BDIdentifierClientHotel : public QDialog {
    Q_OBJECT
public:
    BDIdentifierClientHotel(QWidget *parent = 0);
    ~BDIdentifierClientHotel();

    client clientSelectionne()const{return m_clientSelectionne;};
    int idProfileClient()const{return m_idProfileClient;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDIdentifierClientHotel *ui;
    client m_clientSelectionne;
    QSqlTableModel * m_model;
    QList<int> m_id_profiles_client;
    QList<int> m_id_types_client;
    bool m_affichage;
    int m_idProfileClient;

private slots:
    void on_comboBoxTypeDeClient_currentIndexChanged(int index);
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
    void afficherCategorie(int idProfileClient);
    void chargerProfile(int indexTC);
};

#endif // BDIDENTIFIERCLIENTHOTEL_H
