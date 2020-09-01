#ifndef BDIDENTIFIERCLIENTOCC_H
#define BDIDENTIFIERCLIENTOCC_H

#include "bdLib_global.h"

#include <QDialog>
#include <QSqlTableModel>

#include "BDFormulaireClientSimple.h"
#include "MesTables.h"

namespace Ui {
    class BDIdentifierClientOcc;
}

class BDLIBSHARED_EXPORT BDIdentifierClientOcc : public QDialog {
    Q_OBJECT
public:
    BDIdentifierClientOcc(const occupation & occ, QWidget *parent = 0);
    ~BDIdentifierClientOcc();

    client clientSelectionne()const{return m_clientSelectionne;};
    occupation occupationDuClient()const{return m_occup;};
    pieceIdentiteClient pieceIdentite()const{return m_pic;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDIdentifierClientOcc *ui;
    client m_clientSelectionne;
    occupation m_occup;
    QSqlTableModel * m_model;
    QList<int> m_id_profiles_client;
    QList<int> m_id_types_client;
    bool m_affichage;
    pieceIdentiteClient m_pic;

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

#endif // BDIDENTIFIERCLIENTOCC_H
