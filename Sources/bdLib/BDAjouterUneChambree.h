#ifndef BDAJOUTERUNECHAMBREE_H
#define BDAJOUTERUNECHAMBREE_H

#include "bdLib_global.h"

#include <QDialog>
#include <QMessageBox>

#include "InfosSurBD.h"
#include "chambre.h"
#include "etage.h"

namespace Ui {
    class BDAjouterUneChambre;
}

class BDLIBSHARED_EXPORT BDAjouterUneChambre : public QDialog {
    Q_OBJECT
public:
    BDAjouterUneChambre(int idTypeDeChambre, QWidget *parent = 0);
    ~BDAjouterUneChambre();

    QString identifiant();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDAjouterUneChambre *ui;
    QMessageBox avertisseur;
    int m_idTypeDeChambre;
    QStringList m_niveaux;

private slots:
    void on_btn_annuler_clicked();
    void on_btn_ok_clicked();
};

#endif // BDAJOUTERUNECHAMBREE_H
