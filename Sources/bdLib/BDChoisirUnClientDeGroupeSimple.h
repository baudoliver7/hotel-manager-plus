#ifndef BDCHOISIRUNCLIENTDEGROUPESIMPLE_H
#define BDCHOISIRUNCLIENTDEGROUPESIMPLE_H

#include "bdLib_global.h"

#include <QDialog>

#include "groupe.h"
#include "groupeLiaison.h"
#include "client.h"
#include "BDIdentifierClientHotel.h"

namespace Ui {
    class BDChoisirUnClientDeGroupeSimple;
}

class BDLIBSHARED_EXPORT BDChoisirUnClientDeGroupeSimple : public QDialog {
    Q_OBJECT
public:
    BDChoisirUnClientDeGroupeSimple(QWidget *parent = 0);
    ~BDChoisirUnClientDeGroupeSimple();

    inline client clientChoisi()const{return m_clientChoisi;};
    inline int idGroupe()const{return m_idGroupe;};
    inline int idProfileClient()const{return m_idProfileClient;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDChoisirUnClientDeGroupeSimple *ui;
    QList<groupe> m_groupesSelectionnes;
    QList<client> m_clientsSelectionnes;
    client m_clientChoisi;
    int m_idGroupe;
    int m_idProfileClient;
    QList<int> m_id_profiles_client;
    QList<int> m_id_types_client;

    void chargerGroupesEnCours();
    int currentIdGroupe();
    int currentIdClient();

private slots:
    void chargerProfile(int idTC);
    void on_comboBoxTypeDeClient_currentIndexChanged(int index);
    void on_btn_details_clicked();
    void afficherClient();
    void on_lineEditClientSelectionne_textChanged(QString );
    void on_btn_choisir_clicked();
    void on_btn_fermer_clicked();
    void chargerMembres();
    void updateEtatBtnChoisir();
    void afficherCategorie(int idProfileClient);
};

#endif // BDCHOISIRUNCLIENTDEGROUPESIMPLE_H
