#ifndef BDFORMULAIRECLIENTHOTELSIMPLE_H
#define BDFORMULAIRECLIENTHOTELSIMPLE_H

#include "bdLib_global.h"

#include <QDialog>

#include "client.h"
#include "profileClient.h"
#include "typeDeClient.h"
#include "pieceIdentiteClient.h"
#include "occupation.h"
#include "DialogContact.h"

namespace Ui {
    class BDFormulaireClientHotelSimple;
}

class BDLIBSHARED_EXPORT BDFormulaireClientHotelSimple : public QDialog {
    Q_OBJECT
public:
    BDFormulaireClientHotelSimple(const client & cl, int idProfile, bool readOnly, QWidget *parent = 0);
    ~BDFormulaireClientHotelSimple();

    client clientRenseigne()const{return m_client;};
    int idProfileClient()const{return m_idProfileClient;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDFormulaireClientHotelSimple *ui;
    client m_client;
    pieceIdentiteClient m_piece;
    occupation m_occup;
    QList<profileClient> m_profilesEnCours;
    QList<typeDeClient> m_typesDeClientEnCours;
    QStringList m_profilesStrEnCours;
    QStringList m_typesDeClientStrEnCours;
    bool m_affichage;
    bool m_readOnly;
    int m_idProfileClient;

    void afficherClient(const client & cl, int idProfile);
    void initialiserCategorie();
    void chargerLesTypesClients();
    void chargerLesProfiles(const typeDeClient & t);

private slots:
    void updateEtatBtnOK();
    void on_btn_calendrier_clicked();
    void on_comboBoxTypeDeClient_currentIndexChanged(int index);
    void on_btn_annuler_clicked();
    void on_btn_ok_clicked();
};

#endif // BDFORMULAIRECLIENTHOTELSIMPLE_H
