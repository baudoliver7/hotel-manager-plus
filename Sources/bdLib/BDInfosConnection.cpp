#include "BDInfosConnection.h"
#include "ui_BDInfosConnection.h"

BDInfosConnection::BDInfosConnection(QStringList dsn_l, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDInfosConnection)
{
    ui->setupUi(this);

    QStringList dsn = dsn_l;
    // on affiche la dsn
    int reste = 6 - dsn.count();

    if(reste > 0)
    {
        for(int i = 1; i <= reste; i++)
        {
            dsn << QString();
        }
    }

    ui->lineEditServeur->setText( dsn.at(IDSERVER));
    ui->lineEditNomBD->setText(   dsn.at(IDBDNAME));
    ui->lineEditUser->setText(    dsn.at(IDUSER));
    ui->lineEditPassword->setText(dsn.at(IDPASSWORD));
    ui->lineEditPort->setText(    dsn.at(IDPORT));
}

BDInfosConnection::~BDInfosConnection()
{
    delete ui;
}

void BDInfosConnection::changeEvent(QEvent *e)
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

int BDInfosConnection::port()const
{
    return ui->lineEditPort->text().toInt();
}

QString BDInfosConnection::user()const
{
    return ui->lineEditUser->text();
}

QString BDInfosConnection::serveur()const
{
    return ui->lineEditServeur->text();
}

QString BDInfosConnection::databaseName()const
{
    return ui->lineEditNomBD->text();
}

QString BDInfosConnection::password()const
{
    return ui->lineEditPassword->text();
}

