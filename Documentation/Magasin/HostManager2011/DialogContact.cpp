#include "DialogContact.h"
#include "ui_DialogContact.h"

DialogContact::DialogContact(QString contact, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogContact)
{
    ui->setupUi(this);

    setWindowTitle("Contacts");
    m_contactVide = getContact();
    afficherContacts(contact);
}

DialogContact::~DialogContact()
{
    delete ui;
}

void DialogContact::changeEvent(QEvent *e)
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

QString DialogContact::getContact()
{
    QString contact = (ui->lineEditCel->text()+ "|"
            +ui->lineEditTel->text()+"|"
            +ui->lineEditEmail->text()+"|"+ui->lineEditBP->text());

    if(contact == contactVide())
    {
        return QString();
    }else
    {
        return contact;
    }
}

void DialogContact::on_btn_OK_clicked()
{
    accept();
}

void DialogContact::on_btn_Annuler_clicked()
{
    reject();
}

void DialogContact::afficherContacts(QString contact)
{
    QStringList listeDeContacts = contact.split("|");
    if(listeDeContacts.first() != contact)
    {
        ui->lineEditCel->setText(listeDeContacts.at(0));
        ui->lineEditTel->setText(listeDeContacts.at(1));
        ui->lineEditEmail->setText(listeDeContacts.at(2));
        ui->lineEditBP->setText(listeDeContacts.at(3));
    }
}

QString DialogContact::contactVide()
{
    return m_contactVide;
}

QString DialogContact::numeroCel()
{
   return ui->lineEditCel->text();
}

QString DialogContact::numeroTel()
{
    return ui->lineEditTel->text();
}

QString DialogContact::email()
{
    return ui->lineEditEmail->text();
}

QString DialogContact::Bp()
{
    return ui->lineEditBP->text();
}

bool DialogContact::estVide()
{
    return getContact() == contactVide();
}

QString DialogContact::contacts(QString cel, QString tel, QString email, QString bp)
{
    return (cel+ "|"
            +tel+"|"
            +email+"|"
            +bp);
}
