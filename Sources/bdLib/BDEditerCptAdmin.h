#ifndef BDEDITERCPTADMIN_H
#define BDEDITERCPTADMIN_H

#include "bdLib_global.h"

#include <QDialog>
#include <QCloseEvent>
#include "DialogContact.h"
#include "typeDeClient.h"
#include "horloge.h"
#include "agent.h"

#define IDADMINI 1

namespace Ui {
    class BDEditerCptAdmin;
}

class BDLIBSHARED_EXPORT BDEditerCptAdmin : public QDialog {
    Q_OBJECT
public:
    BDEditerCptAdmin(agent * r, QWidget *parent = 0);
    ~BDEditerCptAdmin();
    inline bool fermer()const{return m_fermer;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDEditerCptAdmin *ui;
    agent * m_admin;
    QString m_sexePrecisEnCours;
    bool m_fermer;
    QString m_matricule;

    void afficherAdmin();

private slots:
    void updateBtnOK();
    void on_buttonBox_rejected();
    void on_Demoiselle_clicked();
    void on_Madame_clicked();
    void on_Monsieur_clicked();
    void on_buttonBox_accepted();
    void on_btn_contact_clicked();
};

#endif // BDEDITERCPTADMIN_H
