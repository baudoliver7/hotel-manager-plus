#include "DialogConnexion.h"
#include "ui_DialogConnexion.h"

DialogConnexion::DialogConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnexion)
{
    ui->setupUi(this);
    m_recepteur = 0;

    setWindowTitle("Se connecter au service Réception");
}

DialogConnexion::~DialogConnexion()
{
    delete ui;
    if(m_recepteur) delete m_recepteur;
}

void DialogConnexion::changeEvent(QEvent *e)
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

QString DialogConnexion::login()
{
   return ui->lineEditLogin->text();
}

QString DialogConnexion::password()
{
    return ui->lineEditPassword->text();
}

void DialogConnexion::on_btn_OK_clicked()
{
    recepteur r;

    QString condition = tr("%2='%3' AND %4='%5'")
                        .arg(r.loginName()).arg(login())
                        .arg(r.passwordName()).arg(password());

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(r.tableName(), condition);

    if(!records.isEmpty())
    {
        m_recepteur = new recepteur(records.at(0));
        accept();
    }else
    {
        QMessageBox::warning(this, "Paramètres incorrectes", "Pseudo et/ou mot de passe incorrect(es)!");
        ui->lineEditLogin->setText(QString());
        ui->lineEditPassword->setText(QString());
    }
}

void DialogConnexion::on_btn_Annuler_clicked()
{
    reject();
}

void DialogConnexion::on_btn_passer_clicked()
{
    ui->lineEditLogin->setText("AigleRoyal7");
    ui->lineEditPassword->setText("foi");

    on_btn_OK_clicked();
}
