#ifndef MDISERVICE_H
#define MDISERVICE_H

#include <QWidget>
#include <QCloseEvent>

#include "agent.h"
#include "horloge.h"
#include "BDMessagerie.h"

namespace Ui {
    class MdiService;
}

class MdiService : public QWidget {
    Q_OBJECT
public:
    MdiService(agent * r, Horloge * h, QString path, QWidget *parent = 0);
    ~MdiService();

    bool seDeconnecter();
    BDMessagerie * bdMessagerie()const{return m_bdMessagerie;};

signals:
    void closed();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent * e);

private:
    void initialiserMessagerie();
    void afficherDateDeConnection();

private:
    Ui::MdiService *ui;
    QWidget * m_parent;
    agent * m_agent;
    bool m_fermer;
    QString m_chemin;
    Horloge * m_horloge;
    BDMessagerie * m_bdMessagerie;

private slots:
    void afficherHorloge();
};

#endif // MDISERVICE_H
