#ifndef BDMESSAGERIE_H
#define BDMESSAGERIE_H

#include "bdLib_global.h"

#include <QDialog>
#include <QShowEvent>
#include <QSound>
#include <QDir>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

#include "agent.h"
#include "message.h"
#include "horloge.h"

#define ENVELOPPE_ALERTE ":/images/enveloppe.png"
#define ENVELLOPE_NORM ":/images/enveloppe verte.png"

namespace Ui {
    class BDMessagerie;
}

class BDLIBSHARED_EXPORT BDMessagerie : public QDialog {
    Q_OBJECT
public:
    BDMessagerie(agent * r, Horloge * h, QString path, QPushButton * btnLire = 0, QLabel * enveloppe = 0, QLabel * labelMessageNonLus = 0, QWidget *parent = 0);
    ~BDMessagerie();

protected:
    void changeEvent(QEvent *e);
    void showEvent(QShowEvent *e);

private:
    Ui::BDMessagerie *ui;
    QTimer * m_timeEnveloppe;
    agent * m_agent;
    Horloge * m_horloge;
    QPushButton * m_btnLire;
    QLabel * m_enveloppe;
    QLabel * m_labelMessageNonLus;
    QStringList m_matricules;
    int nbTotalDeMsgNL;
    int m_hauteurG;
    QString m_chemin;
    bool m_groupWidgetExiste;

private slots:
    void avertirMsgNonLus(int nbMsgNonLus);
    void clignoterEnveloppe();
    void on_btn_effacerMsgRecus_clicked();
    void on_msgEcrits_textChanged();
    void on_btn_envoyer_clicked();
    void on_btn_initialiser_clicked();
    void on_btn_effacer_clicked();
    void actualiserConnectes();
    void verifierMsgNonLus();
    void ajouterMsgRecus(message msg);
    void ajouterMsgEnvoye(message msg);
};

#endif // BDMESSAGERIE_H
