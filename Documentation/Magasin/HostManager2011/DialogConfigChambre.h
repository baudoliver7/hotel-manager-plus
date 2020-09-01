#ifndef DIALOGCONFIGCHAMBRE_H
#define DIALOGCONFIGCHAMBRE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>
#include "InfosSurBD.h"
#include "BDAjouterUneChambree.h"
#include "NomDesQWidgets.h"
#include <QSqlRelationalDelegate>
#include <QCheckBox>
#include "BDModifierUneChambre.h"
#include <QSqlRecord>
#include <QMessageBox>

namespace Ui {
    class DialogConfigChambre;
}

class DialogConfigChambre : public QDialog {
    Q_OBJECT
public:
    DialogConfigChambre(QWidget *parent = 0);
    ~DialogConfigChambre();

    inline bool modified(){return m_modifie;};

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *);

private:
    Ui::DialogConfigChambre *ui;
    QSqlRelationalTableModel * m_model;
    BDAjouterUneChambre * m_bdAjouterUneChambre;
    BDModifierUneChambre * m_bdModifierUneChambre;
    QMessageBox avertisseur;
    bool m_modifie;

private:
    void afficherToutesLesChambres();
    void initialiserTableau();
    void initialiserModel();
    void initialiserBDAjouterUneChambre();
    void initialiserBDModifierUneChambre();
    void chargerDonneesDansModel();
    void chargerDansModelChambresDuType(QString typeDeChambre);
    void chargerTarifsDuType(QString typeDeChambre);
    void enregistrerTarifsDuType(QString typeDeChambre);
    void enregistrerChambre();
    void modifierChambre(int currentIndex);

private slots:
    void on_spinBoxTarifFidelite_valueChanged(int );
    void on_spinBoxTarifPriviligie_valueChanged(int );
    void on_spinBoxTarifNormal_valueChanged(int );
    void on_btn_appliquer_clicked();
    void on_comboBoxTypeTarif_currentIndexChanged(QString );
    void on_btn_modifier_clicked();
    void on_btn_supprimer_clicked();
    void on_tableView_viewportEntered();
    void on_tableView_activated(QModelIndex index);
    void on_tableView_clicked(QModelIndex index);
    void on_btn_ajouter_clicked();
    void on_btn_fermer_clicked();
    void validerAjout();
    void validerModification();
    bool identifiantExisteDeja(QString identifiant);
    bool identifiantExisteDejaModif(QString identifiant);
    void updateEtatBtnSupprEtModif(QModelIndex index);
};

#endif // DIALOGCONFIGCHAMBRE_H
