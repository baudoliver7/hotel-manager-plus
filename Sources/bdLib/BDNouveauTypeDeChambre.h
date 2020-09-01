#ifndef BDNOUVEAUTYPEDECHAMBRE_H
#define BDNOUVEAUTYPEDECHAMBRE_H

#include "bdLib_global.h"

#include "typeDeChambre.h"
#include "typeDeClient.h"
#include "profileClient.h"

#include <QDialog>

#define TYPEDECHAMBRE 1
#define TYPEDECLIENT 2
#define PROFILECLIENT 3

namespace Ui {
    class BDNouveauTypeDeChambre;
}

class BDLIBSHARED_EXPORT BDNouveauTypeDeChambre : public QDialog {
    Q_OBJECT
public:
    BDNouveauTypeDeChambre(int idType, QWidget *parent = 0, int idTypeClient = 0);
    ~BDNouveauTypeDeChambre();

    QString nouveauType()const;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDNouveauTypeDeChambre *ui;
    int m_idType;
    int m_idTypeDeClient;

private slots:
    void on_btn_annuler_clicked();
    void on_btn_ok_clicked();
};

#endif // BDNOUVEAUTYPEDECHAMBRE_H
