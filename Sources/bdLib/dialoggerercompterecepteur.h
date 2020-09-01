#ifndef DIALOGGERERCOMPTERECEPTEUR_H
#define DIALOGGERERCOMPTERECEPTEUR_H

#include "bdLib_global.h"

/* classes de Qt */
#include <QDialog>
#include <QTableWidgetItem>
#include <QMessageBox>

/* classes personnalisées */
#include "agent.h"
#include "client.h"
#include "service.h"
#include "DialogContact.h"
#include "horloge.h"

/* mes définitions */
#define STATUT 0
#define MATRICULE 1
#define SEXE_PRECIS 2
#define NOM 3
#define PRENOMS 4
#define CEL 5
#define TEL 6
#define EMAIL 7
#define BOITE_POSTALE 8
#define RESIDENCE 9

#define MATRICULEADMIN_MASTER "ADMIN"
#define IDADMINISTRATION 1

namespace Ui {
    class DialogGererCompteRecepteur;
}

class BDLIBSHARED_EXPORT DialogGererCompteRecepteur : public QDialog {
    Q_OBJECT

public:
    enum ColumnsHeader
    {
        Statut = 0, Matricule = 1, SexePrecis = 2, Nom = 3, Prenoms = 4, Cel = 5, Tel = 6, Email = 7, BoitePostale = 8, Residence = 9
    };

public:
    DialogGererCompteRecepteur(agent * ag, QWidget *parent = 0);
    ~DialogGererCompteRecepteur();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogGererCompteRecepteur *ui;
    QString m_sexePrecisEnCours;
    agent * m_admini;

    void initialiser();
    QStringList enregistrement(const QSqlRecord & record);
    agent * currentAgent();
    void initialiserTableau();
    int currentIdService();

private slots:
    void on_btn_editer_clicked();
    void on_btn_contacts_clicked();
    void on_Demoiselle_toggled(bool checked);
    void on_Madame_toggled(bool checked);
    void on_Monsieur_toggled(bool checked);
    void on_btn_initialiser_clicked();
    void on_btn_enregistrer_clicked();
    void miseAjourEtatBtnSuspendu_Actif(QModelIndex);
    void miseAjourEtatBtnEditer(QModelIndex);
    void on_btn_suspendre_activer_clicked();
    void miseAjourEtatBtnSupprimer(QModelIndex index);
    void on_btn_supprimer_clicked();
    void on_btn_actualiser_clicked();
    void on_btn_fermer_clicked();
    void afficherUnAgent(int row, const QSqlRecord & record);
    void afficherUnElement(int row, int column, QString text);
    void updateBtnEnregister();
    void chargerAgents();

};

#endif // DIALOGGERERCOMPTERECEPTEUR_H
