#ifndef DGRECHERCHERUNERESERV_H
#define DGRECHERCHERUNERESERV_H

#include "bdLib_global.h"

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QTableWidgetItem>

#include "InfosSurBD.h"
#include "client.h"
#include "reservation.h"
#include "emettreReserv.h"
#include "horloge.h"
#include "MesTables.h"
#include "agent.h"
#include "BDRestituerAuClient.h"
#include "configServiceCompta.h"
#include "chambreReservee.h"
#include "typeDeChambre.h"

#define NUMERO_RESERV 0
#define CHAMBRE 1
#define DATE_DE_DEMANDE 2
#define DATE_OCCUPATION 3
#define DUREE_EN_JOURS 4
#define DATE_SORTIE 5
#define PRIXTOTAL 6
#define AVANCE 7
#define MONTANTRESTANT 8
#define BENEFICIAIRE 9

namespace Ui {
    class DgRechercherUneReserv;
}

class BDLIBSHARED_EXPORT DgRechercherUneReserv : public QDialog {
    Q_OBJECT
public:
    DgRechercherUneReserv(agent * ag, QWidget *parent = 0);
    ~DgRechercherUneReserv();

    inline int nbReservAnnulee()const{return m_nbReservAnnulee;};

signals:
    void remplirOccupation(chambreReservee rv);
    void bdModifie();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DgRechercherUneReserv *ui;
    int m_nbReservAnnulee;
    agent * m_recepteur;
    QList<typeDeChambre> m_typesDeChambresDispo;
    QStringList m_typesDeChambresStrDispo;

    void initialiserTypeDeChambre();
    void initialiserTable();
    void afficherElement(int row, int column, const QString & value);
    bool reservationPeutEtreExecuter(int row);

private slots:
    void updateEtatBtnsWidget(QModelIndex);
    void rafraichirTable();
    void executer();
    void supprimer();
};

#endif // DGRECHERCHERUNERESERV_H
