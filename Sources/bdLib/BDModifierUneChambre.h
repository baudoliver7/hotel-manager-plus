#ifndef BDMODIFIERUNECHAMBRE_H
#define BDMODIFIERUNECHAMBRE_H

#include "bdLib_global.h"

#include <QDialog>
#include <QMessageBox>
#include "chambre.h"

namespace Ui {
    class BDModifierUneChambre;
}

class BDLIBSHARED_EXPORT BDModifierUneChambre : public QDialog {
    Q_OBJECT
public:
    BDModifierUneChambre(QSqlRecord record, QWidget *parent = 0);
    ~BDModifierUneChambre();

    QString initial();
    int numero();
    QString identifiant();
    QString ancienIdentifiant();

protected:
    void changeEvent(QEvent *e);


private:
    Ui::BDModifierUneChambre *ui;
    QString m_typeDeChambre;
    QString m_ancienIdentifiant;
    QMessageBox avertisseur;

private:
    void initialiserModel();
    void afficherChambre(QSqlRecord record);

private slots:

};

#endif // BDMODIFIERUNECHAMBRE_H
