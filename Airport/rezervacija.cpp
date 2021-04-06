#include "rezervacija.h"
#include "ui_rezervacija.h"
#include  <QtDebug>
#include <QSqlQuery>
#include "pregled.h"
rezervacija::rezervacija(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rezervacija)
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

    ui->klasa->addItem("Economy calss");
     ui->klasa->addItem("Buisness class");


      ui->let->addItem(QString::number(1)+"-"+"Dubai");
       ui->let->addItem(QString::number(2)+"-"+"Beograd");
         ui->let->addItem(QString::number(3)+"-"+"Sidney");
           ui->let->addItem(QString::number(4)+"-"+"Phenix");


}

rezervacija::~rezervacija()
{
    delete ui;
}



void rezervacija::on_pushButton_clicked()
{
    QString Ime,Prezime,br_Tel,letK, letP, klasa,s,i;

    int smjer;
    bool pravac;

    if(ui->checkBox->isChecked())
        {
        pravac=1;
    }
    else pravac=0;

    i=QString::number(pravac);

    smjer=ui->let->currentIndex();
    smjer++;

    s=QString::number(smjer);

    klasa=ui->klasa->currentText();
    Ime=ui->ime->text();
    Prezime=ui->prezime->text();
    br_Tel=ui->brtel->text();
    letK=ui->dateTimeEdit->text();
    letP=ui->dateTimeEdit_2->text();
    qDebug()<<s<<" "<<klasa<<" "<<Ime<<" "<<Prezime<<" "<<br_Tel<<" "<<letK<<" "<<letP<<" "<<i;
    if(pravac==true)
        {
        letP="NULL";
    }
    QSqlQuery qry;
    qry.prepare("insert into rezervacije values(null,'"+Ime+"','"+Prezime+"','"+br_Tel+"','"+s+"','"+i+"','"+letK+"','"+letP+"','"+klasa+"');");
    qDebug()<<qry.exec()<<endl;
    qDebug()<<qry.lastError();
    pregled p(Ime,Prezime);
    p.exec();
    rezervacija::close();
}


