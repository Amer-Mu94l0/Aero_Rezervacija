#include "izmjena.h"
#include "ui_izmjena.h"

izmjena::izmjena(QString id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::izmjena)
{
    ui->setupUi(this);
    QSqlDatabase db;
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

    qry.prepare("select ime,prezime,br_Tel,pravac,klasa,let_K,let_P, let from rezervacije join putovanja ON rezervacije.let_ID=putovanja.let_ID where ID='"+id+"';");
    if(qry.exec())
         {
           while(qry.next())
             {
                    ui->ime->setText(qry.value(0).toString());
                    ui->prezime->setText(qry.value(1).toString());
                    ui->brtel->setText(qry.value(2).toString());
                    ui->checkBox->setChecked(qry.value(3).toBool());
                    ui->id->setText(id);
                    ui->klasa->setText(qry.value(4).toString());

                    ui->dat_p->setText(qry.value(5).toString());
                    ui->dat_k->setText(qry.value(6).toString());
                    ui->putovanje->setText(qry.value(7).toString());




            }
             qry.first();
             ui->upit->setText("Upit se može izvršiti :)");
    }
       else
          {
            ui->upit->setText("Upit se ne može izvršiti!");
    }

}

izmjena::~izmjena()
{
    delete ui;
}

void izmjena::on_izmjeni_clicked()
{
    QString ime, prezime,brTel,klasa,datK,datP,putovanje,id,pravac,z;
    bool i;

    ime=ui->ime->text();
    prezime=ui->prezime->text();
    brTel=ui->brtel->text();
    if(ui->checkBox->isChecked())
        {
        i=1;
    }
    else i=0;
    pravac=QString::number(i);
    id=ui->id->text();
    klasa=ui->klasa->text();
    datK=ui->dat_p->text();
    datP=ui->dat_k->text();
    putovanje=ui->putovanje->text();
    QSqlQuery qry;
    qry.prepare("select let_ID from putovanja where let='"+putovanje+"';");
    if(qry.exec())
         {
           while(qry.next())
             {
                 z=qry.value(0).toString();
                 qDebug()<<z;
            }
             qry.first();
             ui->upit->setText("Upit se može izvršiti :)");
    }
       else
          {
            ui->upit->setText("Upit se ne može izvršiti!");
    }
    QSqlQuery qryy;
    qDebug()<<id<<ime<<prezime<<brTel<<z<<pravac<<datK<<datP<<klasa;
    qryy.prepare("UPDATE rezervacije SET ime='"+ime+"', prezime='"+prezime+"', br_Tel='"+brTel+"', let_ID='"+z+"', pravac='"+pravac+"', let_K='"+datK+"', let_P='"+datP+"', klasa='"+klasa+"' WHERE ID='"+id+"';");
    QMessageBox msgBox;
    msgBox.setText("Izmjena rezervacije.");
    msgBox.setInformativeText("Da li ste sigurni da želite izmjeniti rezervaciju?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
        if(ret==QMessageBox::Yes)
                {
                if(qryy.exec())
                    {
                        QMessageBox::information(this,"", "Slog izmjenjen!");
                        izmjena::close();
                    }
               else
                  {
                    QMessageBox::information(this,"", "Upit se ne može izvršiti!");
                }
                }


}
