#include "pregled.h"
#include "ui_pregled.h"

pregled::pregled(QString ime, QString prezime,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pregled)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("c:/roba/rezervation.db");

    if (db.open())
     {
        ui->status->setText("Baza je povezana");

     }
     else
     {
         ui->status->setText("Baza nije povezana");
     }
    QSqlQuery qry;
    int cj, i=2, ii=1.5;
    qry.prepare("select ime,prezime,br_Tel,pravac,klasa,let_K,let_P, let, cijena from rezervacije join putovanja ON rezervacije.let_ID=putovanja.let_ID where ime='"+ime+"' and prezime='"+prezime+"';");
    if(qry.exec())
         {
           while(qry.next())
             {
                    ui->ime->setText(qry.value(0).toString());
                    ui->prezime->setText(qry.value(1).toString());
                    ui->brtel->setText(qry.value(2).toString());
                    ui->checkBox->setChecked(qry.value(3).toBool());
                    if(ui->checkBox->isChecked()) i=1;
                    ui->klasa->setText(qry.value(4).toString());
                    if(ui->klasa->text()=="Economy calss") ii=1;
                    ui->dat_p->setText(qry.value(5).toString());
                    ui->dat_k->setText(qry.value(6).toString());
                   // ui->dat_k->text()
                    ui->putovanje->setText(qry.value(7).toString());
                    cj=qry.value(8).toInt()*i*ii;
                    ui->cijena->setText(QString::number(cj));



            }
             qry.first();
             ui->upit->setText("Upit se može izvršiti :)");
    }
       else
          {
            ui->upit->setText("Upit se ne može izvršiti!");
    }

}

pregled::~pregled()
{
    delete ui;
}
