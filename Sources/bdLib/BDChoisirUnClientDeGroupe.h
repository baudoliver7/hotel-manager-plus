#ifndef BDCHOISIRUNCLIENTDEGROUPE_H
#define BDCHOISIRUNCLIENTDEGROUPE_H

#include "bdLib_global.h"

#include <QDialog>

#include "groupe.h"
#include "groupeLiaison.h"
#include "client.h"
#include "BDIdentifierClientHotel.h"

namespace Ui {
    class BDChoisirUnClientDeGroupe;
}

class BDLIBSHARED_EXPORT BDChoisirUnClientDeGroupe : public QDialog {
    Q_OBJECT
public:
    BDChoisirUnClientDeGroupe(const occupation & oc, QWidget *parent = 0);
    ~BDChoisirUnClientDeGroupe();

    inline client clientChoisi()const{return m_clientChoisi;};
    inline int idGroupe()const{return m_idGroupe;};
    occupation occupationDuClient()const{return m_occup;};
    pieceIdentiteClient pieceDuClient()const{return m_pic;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDChoisirUnClientDeGroupe *ui;
    QList<groupe> m_groupesSelectionnes;
    QList<client> m_clientsSelectionnes;
    client m_clientChoisi;
    int m_idGroupe;
    occupation m_occup;
    pieceIdentiteClient m_pic;
    QList<int> m_id_profiles_client;
    QList<int> m_id_types_client;

    void chargerGroupesEnCours();
    int currentIdGroupe();
    int currentIdClient();

private slots:
    void afficherCategorie(int idProfileClient);
    void chargerProfile(int idTC);
    void on_comboBoxTypeDeClient_currentIndexChanged(int index);
    void on_btn_details_clicked();
    void afficherClient();
    void on_lineEditClientSelectionne_textChanged(QString );
    void on_btn_choisir_clicked();
    void on_btn_fermer_clicked();
    void chargerMembres();
    void updateEtatBtnChoisir();
};

#endif // BDCHOISIRUNCLIENTDEGROUPE_H
