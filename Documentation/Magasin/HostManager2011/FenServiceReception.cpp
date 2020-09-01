#include "FenServiceReception.h"
#include "ui_FenServiceReception.h"

FenServiceReception::FenServiceReception(const recepteur * r, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FenServiceReception)
{
    ui->setupUi(this);
    m_recepteur = new recepteur(*r);
    m_fermer = false;
}

FenServiceReception::~FenServiceReception()
{
    delete ui;
    delete m_recepteur;
}

void FenServiceReception::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void FenServiceReception::closeEvent(QCloseEvent *e)
{
    if(!m_fermer)
    {
        if(!seDeconnecter())
        {
            e->ignore();
        }else
        {
            emit closed();
        }
    }
}

bool FenServiceReception::seDeconnecter()
{
    bool deconnecte = false;
    QString title = tr("Déconnection du compte %1").arg(m_recepteur->login());
    if(QMessageBox::question(this, title, "Désirez-vous véritablement vous déconnectez?"
                             , QMessageBox::Ok, QMessageBox::Cancel) == QMessageBox::Ok)
    {
        deconnecte = true;
    }

    return deconnecte;
}
