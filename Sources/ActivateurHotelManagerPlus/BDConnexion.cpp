#include "BDConnexion.h"
#include "ui_BDConnexion.h"

BDConnexion::BDConnexion(QSqlDatabase db, QWidget *parent):
    QDialog(parent),
    ui(new Ui::BDConnexion)
{
    ui->setupUi(this);

    m_db = db;
    initialiserModel();
}

BDConnexion::~BDConnexion()
{
    delete ui;
    delete m_model;
}

void BDConnexion::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void BDConnexion::on_btn_annuler_clicked()
{
    reject();
}

void BDConnexion::on_btn_ok_clicked()
{
    QString login = ui->lineEditLogin->text();
    QString password = ui->lineEditPassword->text();

    if(login.isEmpty()
    || password.isEmpty())
    {
        QMessageBox::warning(this, "Compte", "Login ou mot de passe incorrect!");
        return;
    }else
    {
        m_model->setFilter(tr("%1='%2' AND %3='%4'").arg("Login").arg(login).arg("MotDePasse").arg(password));
        m_model->select();

        if(m_model->rowCount() == 0)
        {
            QMessageBox::warning(this, "Compte", "Login ou mot de passe incorrect!");
            return;
        }
    }

    accept();
}

void BDConnexion::initialiserModel()
{
    m_model = new QSqlTableModel(0, m_db);
    m_model->setTable("comptes");
}
