#ifndef DIALOGCONFIGCHAMBRE_H
#define DIALOGCONFIGCHAMBRE_H

#include "bdLib_global.h"

#include <QDialog>
#include <QCheckBox>
#include <QSqlRecord>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QCloseEvent>
#include <QSqlRelationalTableModel>

#include "InfosSurBD.h"
#include "chambre.h"
#include "BDNouveauTypeDeChambre.h"
#include "typeDeChambre.h"
#include "typeDeClient.h"
#include "profileClient.h"
#include "BDAjouterUneChambree.h"
#include "prixChambreTTC.h"
#include "etage.h"
#include "chambreReservee.h"
#include "occupation.h"
#include "BDWaiting.h"

#define HORS_SERVICE "Hors service"

namespace Ui {
    class DialogConfigChambre;
}

class BDLIBSHARED_EXPORT DialogConfigChambre : public QDialog {
    Q_OBJECT
public:
    DialogConfigChambre(QWidget *parent = 0);
    ~DialogConfigChambre();


protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogConfigChambre *ui;
    QSqlTableModel * m_modelTypeDeCh;
    QSqlTableModel * m_modelTypeDeClient;
    QSqlTableModel * m_modelProfiles;
    QSqlRelationalTableModel * m_modelChambres;
    BDWaiting * m_bdWaiting;
    QList<QSqlRecord> m_profile_records;

    void initialiserProfiles();
    void initialiserTypeDeClient();
    void initialiserTypeDeChambre();
    void initialiserChambres();
    int currentIdTypeDeCh();
    int currentIdTypeDeClient();
    QString currentIdentiteCh();

private slots:
    void updateEtatBtnAppliquer();
    void enregistrerTarifs();
    void afficherTarifs();
    void construireTableauTarifs();
    void chargerTypeDeClient();
    void chargerProfiles();
    void updateLibelleBtnMettreHS();
    void ajouterUnTypeDeClient();
    void ajouterUnProfile();
    void ajouterUnTypeDeCh();
    void ajouterUneChambre();
    void modifierUneChambre();
    void mettreHorService();
    void supprimerUneChambre();
    void updateEtatBtnOfTypeDeCh(QModelIndex);
    void setTypeDeChDispo(bool disponible);
    void updateCheckBoxDispoTypeDeCh();
    void chargerTypesDeChambre();
    void chargerChambres();
    void on_btn_fermer_clicked();
};

#endif // DIALOGCONFIGCHAMBRE_H
