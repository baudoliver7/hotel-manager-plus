#ifndef BDCREERUNGROUPE_H
#define BDCREERUNGROUPE_H

#include "bdLib_global.h"

#include <QDialog>

#include "agent.h"
#include "client.h"
#include "BDIdentifierClientHotelSimple.h"
#include "DialogCalendar.h"
#include "HeureLimite.h"
#include "groupe.h"
#include "groupeLiaison.h"
#include "modeDePayement.h"
#include "DialogContact.h"
#include "bdd.h"

namespace Ui {
    class BDCreerUnGroupe;
}

class BDLIBSHARED_EXPORT BDCreerUnGroupe : public QDialog {
    Q_OBJECT
public:
    BDCreerUnGroupe(BDD * db, const agent & ag, QWidget *parent = 0);
    ~BDCreerUnGroupe();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDCreerUnGroupe *ui;
    BDD * m_db;
    QList<profileClient> m_profilesEnCours;
    QList<typeDeClient> m_typesDeClientEnCours;
    QStringList m_profilesStrEnCours;
    QStringList m_typesDeClientStrEnCours;
    QStringList m_types_de_chambres_str;
    QList<typeDeChambre> m_type_de_chambres;
    agent m_agent;
    client m_client;
    QDateTime m_datedEntree;
    bool m_affichage;

    void initialiserCategorie();

private slots:
    void on_btn_rechercher_clicked();
    void on_spinBoxDuree_valueChanged(int );
    void on_spinBoxNbPersPrevues_valueChanged(int );
    void on_comboBoxProfile_currentIndexChanged(int index);
    void on_comboBoxTypeDeChambre_currentIndexChanged(int index);
    void chargerTypesDeChambre();
    void chargerLesTypesClients();
    void chargerLesProfiles(const typeDeClient &t);
    void on_comboBoxTypeDeClient_currentIndexChanged(int index);
    void on_btn_contact_clicked();
    void on_spinBoxAvance_valueChanged(int );
    void on_btn_annuler_clicked();
    void on_btn_creer_clicked();
    void on_lineEditDateEntree_textChanged(QString );
    void on_btn_dateEntree_clicked();
    void on_lineEditLibelle_textChanged(QString );
    void on_btn_identifierRespo_clicked();
    void updateEtatBtnCreer();
    void afficherPrix();
    void afficherNbChDispo();
};

#endif // BDCREERUNGROUPE_H
