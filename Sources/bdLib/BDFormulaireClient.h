#ifndef BDFORMULAIRECLIENT_H
#define BDFORMULAIRECLIENT_H

#include "bdLib_global.h"

#include <QDialog>

#include "client.h"
#include "profileClient.h"
#include "typeDeClient.h"
#include "pieceIdentiteClient.h"
#include "occupation.h"
#include "DialogContact.h"

namespace Ui {
    class BDFormulaireClient;
}

class BDLIBSHARED_EXPORT BDFormulaireClient : public QDialog {
    Q_OBJECT
public:
    BDFormulaireClient(const client & cl, const pieceIdentiteClient & piece, bool readOnly, const occupation & occ, QWidget *parent = 0);
    ~BDFormulaireClient();

    client clientRenseigne()const{return m_client;};
    pieceIdentiteClient piece()const{return m_piece;};
    occupation occup()const{return m_occup;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDFormulaireClient *ui;
    client m_client;
    pieceIdentiteClient m_piece;
    occupation m_occup;
    QList<profileClient> m_profilesEnCours;
    QList<typeDeClient> m_typesDeClientEnCours;
    QStringList m_profilesStrEnCours;
    QStringList m_typesDeClientStrEnCours;
    bool m_affichage;
    bool m_readOnly;

    void afficherClient(const client & cl, const pieceIdentiteClient & p, const occupation & occup);
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

#endif // BDFORMULAIRECLIENT_H
