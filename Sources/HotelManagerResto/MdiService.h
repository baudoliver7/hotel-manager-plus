#ifndef MDISERVICE_H
#define MDISERVICE_H

#include <QWidget>
#include <QCloseEvent>
#include <QListWidgetItem>
#include <QSqlRelationalTableModel>
#include <QPrintDialog>
#include <QPrinter>

#include "agent.h"
#include "horloge.h"
#include "BDMessagerie.h"
#include "consoResto.h"
#include "menuResto.h"
#include "client.h"
#include "DialogCalendar.h"
#include "MesTables.h"
#include "repasCompletResto.h"
#include "tableResto.h"
#include "BDDetailsRepas.h"
#include "factureInitial.h"
#include "BDIdentifierClientResto.h"
#include "operationService.h"
#include "modeDePayement.h"
#include "recuInitial.h"
#include "clotureService.h"
#include "compteClient.h"
#include "factureRestoIndividu.h"
#include "recu.h"
#include "categorieMenu.h"
#include "BDWaiting.h"
#include "bdd.h"

#define l_FACTURE 0
#define l_CLIENT 1
#define l_DATEARRIVEE 2
#define l_DATEDEPART 3
#define l_DUREE 4
#define l_TOTALAPAYER 5
#define l_MONTANTENCAISSE 6
#define l_MONTANTRESTANT 7
#define l_MATRICULECAISSIER 8
#define l_ID 9

#define ONGLET_TABLEAUDEBORD 2

namespace Ui {
    class MdiService;
}

class MdiService : public QWidget {
    Q_OBJECT
public:
    MdiService(BDD * db, agent * r, Horloge * h, QString path, QWidget *parent = 0);
    ~MdiService();

    bool seDeconnecter();
    inline bool estBar()const{return m_bar;};

signals:
    void closed();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent * e);

private:
    void initialiserTableau();
    void initialiserTableauActivites();
    void initialiserCategorie();
    void initialiserMenu();
    void afficherElement(int row, int column, const QString &value);
    void afficherConsosChoisies();
    int  currentIdRepasCResto();

private:
    BDD * m_db;
    Ui::MdiService *ui;
    QWidget * m_parent;
    agent * m_agent;
    bool m_fermer;
    QString m_chemin;
    Horloge * m_horloge;
    QSqlRelationalTableModel * m_modelActivites;
    QSqlTableModel * m_modelCategorie;
    QSqlTableModel * m_modelMenu;
    BDWaiting * m_bdWaiting;
    client m_clientEnCours;
    QList<consoResto> m_consos_resto_choisies;
    QList<repasCompletResto> m_repasCRestoEnCours;
    QList<compteClient> m_comptesClients;
    QStringList m_menusStr;
    QStringList m_chambresOccupees;
    bool m_affichage;
    bool m_bar;

    int currentIdMenu();
    int currentIdCategorie();
    tableResto strToTable(const QString & table);

private slots:
    void actualiserOngletActif();
    void cloturer();
    void setConfigModule(bool bar);
    void updateBtnEtatSuppMenu();
    void on_btn_supprimerMenu_clicked();
    void on_btn_imprimerRecu_clicked();
    void on_btn_imprimerFacture_clicked();
    void on_comboBoxCompteClient_currentIndexChanged(int index);
    void on_comboBoxModeDePaye_currentIndexChanged(int index);
    void on_btn_imprimer_tab_bord_clicked();
    void updateEtatBtnImprimerRecu(QModelIndex);
    void updateEtatBtnImprimerFacture(QModelIndex);
    void updateEtatBtnCloturer();
    void on_btn_cloturer_clicked();
    void on_btn_identifierClient_clicked();
    void on_btn_details_clicked();
    void updateEtatBtnConso(QModelIndex);
    void on_treeWidgetTablesOccupees_doubleClicked(QModelIndex index);
    void on_btn_enregistrer_clicked();
    void updateDureeOccupation();
    void afficherConsommations(int idRepasCResto);
    void afficherTableauDeBord(QString table);
    void updateEtatBtnOccuper(QModelIndex);
    void on_btn_terminer_clicked();
    void on_btn_occuper_clicked();
    void on_btn_ajouter_clicked();
    void on_listWidget_currentRowChanged(int currentRow);
    void on_listWidget_itemPressed(QListWidgetItem* item);
    void on_btn_initialiser_clicked();
    void on_btn_supprimer_clicked();
    void on_checkBoxModifierPrix_toggled(bool checked);
    void on_spinBoxQuantite_valueChanged(int );
    void on_spinBoxPrixUnitaire_valueChanged(int );
    void actualiserFenetre();
    void actualiserConsoDeCeJour();
    void actualiserActivites();
    void actualiserTableauDeBord();
    void chargerMenus();
    void chargerCategorie();
    void afficherPrix();
    void chargerTables();
    void chargerActivites();
    void initialiser();
    void on_comboBoxMenu_currentIndexChanged(QString );
    void on_btn_fin_clicked();
    void on_btn_debut_clicked();
    void updateEtatGroupPeriode(bool);
    void rafraichirTable();
    void chargerModeDePayement();
};

#endif // MDISERVICE_H
