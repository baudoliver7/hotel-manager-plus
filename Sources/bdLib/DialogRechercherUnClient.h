#ifndef DIALOGRECHERCHERUNCLIENT_H
#define DIALOGRECHERCHERUNCLIENT_H

#include "bdLib_global.h"

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>

#include "InfosSurBD.h"
#include "occupation.h"
#include "libererOccup.h"
#include "MesTables.h"
#include "agent.h"
#include "configServiceCompta.h"

#define FERMERDETAILS "Détails >>"
#define OUVRIRDETAILS "Détails <<"

namespace Ui {
    class DialogRechercherUnClient;
}

class BDLIBSHARED_EXPORT DialogRechercherUnClient : public QDialog {
    Q_OBJECT
public:
    DialogRechercherUnClient(agent * recepteur, QWidget *parent = 0);
    ~DialogRechercherUnClient();

    QSqlRecord clientChoisi();
    bool occuperUneChambre();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogRechercherUnClient *ui;
    QSqlTableModel * m_clients;
    client * m_clientEnCours;
    QList<int> montantsAregler;
    QList<int> numOccupationAModifier;
    agent * m_recepteur;

private slots:
    void on_rb_clientsCrediteurs_clicked();
    void on_spinBoxMR_valueChanged(int );
    void on_btn_appliquer_clicked();
    void updateEtatLineEditMR(QModelIndex);
    void on_btn_details_clicked();
    void on_btn_Annuler_clicked();
    void updateEtatDesWidgets(QModelIndex);
    void on_lineEditNom_textChanged(QString);
    void on_btn_OK_clicked();
    void rafraichirTableau();
    void chargerLocations(QModelIndex index);

private:
    occupation currentLocation();
    bool estDetaillee();
    bool estUnHomme();
    void afficherClients(QString debutNom, bool sexe);
    void initialiserTableau();
    void initialiserModel();
    void detailler(QString textButton);
    void ajouterUneLocation(QSqlRecord occupation_record);
    void ajouterUnElt(int row, int col, QString valeur);
};

#endif // DIALOGRECHERCHERUNCLIENT_H
