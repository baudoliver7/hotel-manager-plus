#include "BDInfosHotels.h"
#include "ui_BDInfosHotels.h"

BDInfosHotels::BDInfosHotels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDInfosHotels)
{
    ui->setupUi(this);

    m_ih = new infosHotel(1);

    ui->lineEditContacts->setText(m_ih->contacts());
    ui->lineEditNom->setText(m_ih->nom());
    ui->lineEditQuartier->setText(m_ih->situationGeo());
    ui->lineEditSiteWeb->setText(m_ih->siteWeb());

    m_pixmap = m_ih->logo();
    ui->labelLogo->setPixmap(m_pixmap);
    ui->lineEditVille->setText(m_ih->ville());
}

BDInfosHotels::~BDInfosHotels()
{
    delete ui;
    delete m_ih;
}

void BDInfosHotels::changeEvent(QEvent *e)
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

void BDInfosHotels::on_btn_annuler_clicked()
{
    reject();
}

void BDInfosHotels::on_btn_contacts_clicked()
{
    DialogContact bd(ui->lineEditContacts->text(), this);
    bd.setWindowTitle("Contacts de l'hôtel");

    if(bd.exec() == QDialog::Accepted)
    {
        ui->lineEditContacts->setText(bd.getContact());
    }
}

void BDInfosHotels::on_btn_insererLogo_clicked()
{
    m_fileName = QFileDialog::getOpenFileName(this,
         tr("Ouvrir une image"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));

    if(!m_fileName.isEmpty())
    {
        m_pixmap.load(m_fileName);

        // afficher
        ui->labelLogo->setPixmap(QPixmap());
        ui->labelLogo->setPixmap(m_pixmap);
        ui->labelLogo->update();
    }
}

void BDInfosHotels::on_btn_ok_clicked()
{
    // on enregistre
    m_ih->setNom(ui->lineEditNom->text());
    m_ih->setVille(ui->lineEditVille->text());
    m_ih->setSituationGeo(ui->lineEditQuartier->text());
    m_ih->setContacts(ui->lineEditContacts->text());
    m_ih->setSiteWeb(ui->lineEditSiteWeb->text());

    if(!m_fileName.isEmpty())
        m_ih->setLogo(m_fileName);

    m_ih->enregistrer();

    accept();
}
