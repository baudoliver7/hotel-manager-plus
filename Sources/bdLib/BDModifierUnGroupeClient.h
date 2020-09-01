#ifndef BDMODIFIERUNGROUPECLIENT_H
#define BDMODIFIERUNGROUPECLIENT_H

#include "bdLib_global.h"

#include <QDialog>

#include "groupe.h"
#include "groupeLiaison.h"
#include "client.h"
#include "BDIdentifierClientHotelSimple.h"

#define IDGROUPE 0
#define LIBELLE 1
#define RESPONSABLE 2
#define NBPERSONNE 3

namespace Ui {
    class BDModifierUnGroupeClient;
}

class BDLIBSHARED_EXPORT BDModifierUnGroupeClient : public QDialog {
    Q_OBJECT
public:
    BDModifierUnGroupeClient(bool choisirUnClient, QWidget *parent = 0);
    ~BDModifierUnGroupeClient();

    inline client clientChoisi()const{return m_clientChoisi;};
    inline int idGroupe()const{return m_idGroupe;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDModifierUnGroupeClient *ui;
    QList<groupe> m_groupesSelectionnes;
    QList<client> m_clientsSelectionnes;
    bool m_choisirUnClient;
    client m_clientChoisi;
    int m_idGroupe;

    void chargerGroupesEnCours();
    int currentIdGroupe();
    int currentIdClient();

private slots:
    void actualiserCurrentGroupe();
    void updateEtatBtnAjouter();
    void on_btn_terminer_clicked();
    void on_btn_choisir_clicked();
    void on_btn_fermer_clicked();
    void on_btn_ajouter_clicked();
    void on_btn_retirer_clicked();
    void chargerMembres();
    void updateEtatBtnRetirer();
    void updateEtatBtnChoisir();
    void updateEtatBtnTerminer();
};

#endif // BDMODIFIERUNGROUPECLIENT_H
