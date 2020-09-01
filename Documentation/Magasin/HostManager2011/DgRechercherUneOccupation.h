#ifndef DGRECHERCHERUNEOCCUPATION_H
#define DGRECHERCHERUNEOCCUPATION_H

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QTableWidgetItem>

#include "InfosSurBD.h"
#include "Client.h"
#include "occupation.h"
#include "initialdechambre.h"

#define NUMERO_RESERV 0
#define CHAMBRE 1
#define DATE_ENTREE 2
#define DUREE_EN_JOURS 3
#define DATE_SORTIE 4
#define OCCUPANT 5

namespace Ui {
    class DgRechercherUneOccupation;
}

class DgRechercherUneOccupation : public QDialog {
    Q_OBJECT
public:
    DgRechercherUneOccupation(QWidget *parent = 0);
    ~DgRechercherUneOccupation();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DgRechercherUneOccupation *ui;

    void initialiserTypeDeChambre();
    void initialiserTable();
    void afficherElement(int row, int column, const QString & value);
    void liberer();

private slots:
    void updateEtatBtnLiberer(QModelIndex);
    void rafraichirTable();
    void on_btn_annuler_clicked();
    void on_btn_liberer_clicked();
};

#endif // DGRECHERCHERUNEOCCUPATION_H
