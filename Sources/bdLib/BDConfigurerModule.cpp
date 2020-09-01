#include "BDConfigurerModule.h"
#include "ui_BDConfigurerModule.h"

BDConfigurerModule::BDConfigurerModule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDConfigurerModule)
{
    ui->setupUi(this);

    m_modified = false;

    // afficher la config par le fichier config.txt
    QFile file("config.txt");

    bool bar = false;
    if (file.open(QIODevice::ReadOnly))
    {
        // afficher par défaut resto-bar
        QDataStream in(&file);
        QStringList d;
        in >> d;

        bar = (bool)d.first().split(" ").last().toInt(); // bar = 0 ou 1
    }

    if(bar)
        ui->rb_bar->setChecked(true);
    else
        ui->rb_restoBar->setChecked(true);

    connect(ui->rb_bar, SIGNAL(toggled(bool)), this, SLOT(setModified()));
}

BDConfigurerModule::~BDConfigurerModule()
{
    delete ui;
}

void BDConfigurerModule::changeEvent(QEvent *e)
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

void BDConfigurerModule::on_btn_ok_clicked()
{
    if(m_modified)
    {
        QFile f("config.txt");
        if(f.open(QIODevice::WriteOnly))
        {
            QStringList donnees;
            donnees << tr("bar = %1").arg(ui->rb_bar->isChecked());

            QDataStream out(&f);
            out << donnees;
        }
    }

    accept();
}

void BDConfigurerModule::on_btn_annuler_clicked()
{
    reject();
}

void BDConfigurerModule::setModified()
{
    m_modified = true;
}

bool BDConfigurerModule::barEstChoisi()const
{
    return ui->rb_bar->isChecked();
}
