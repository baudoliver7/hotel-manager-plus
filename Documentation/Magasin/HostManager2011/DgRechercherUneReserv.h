#ifndef DGRECHERCHERUNERESERV_H
#define DGRECHERCHERUNERESERV_H

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QTableWidgetItem>

#include "InfosSurBD.h"
#include "Client.h"
#include "reservation.h"
#include "initialdechambre.h"

#define NUMERO_RESERV 0
#define CHAMBRE 1
#define DATE_DE_DEMANDE 2
#define DATE_OCCUPATION 3
#define DUREE_EN_JOURS 4
#define DATE_SORTIE 5
#define BENEFICIAIRE 6

namespace Ui {
    class DgRechercherUneReserv;
}

class DgRechercherUneReserv : public QDialog {
    Q_OBJECT
public:
    DgRechercherUneReserv(QWidget *parent = 0);
    ~DgRechercherUneReserv();

signals:
    void remplirOccupation(reservation rv);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DgRechercherUneReserv *ui;

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
