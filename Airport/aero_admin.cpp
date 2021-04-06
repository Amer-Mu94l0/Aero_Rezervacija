#include "aero_admin.h"
#include "ui_aero_admin.h"
#include "izmjena.h"
Aero_admin::Aero_admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aero_admin)
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
    QSqlQueryModel *model=new QSqlQueryModel();

    qry.prepare("select ID,ime,prezime,br_Tel,pravac,klasa,let_K,let_P, let, cijena from rezervacije join putovanja ON rezervacije.let_ID=putovanja.let_ID;");
    qry.exec();
    model->setQuery(qry);
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("ime"));
    model->setHeaderData(2, Qt::Horizontal, tr("prezime"));
    model->setHeaderData(3, Qt::Horizontal, tr("br. telefona"));
    model->setHeaderData(4, Qt::Horizontal, tr("pravac"));
    model->setHeaderData(5, Qt::Horizontal, tr("klasa"));
    model->setHeaderData(6, Qt::Horizontal, tr("let_K"));
    model->setHeaderData(7, Qt::Horizontal, tr("let_P"));
    model->setHeaderData(8, Qt::Horizontal, tr("let"));
    model->setHeaderData(9, Qt::Horizontal, tr("cijena"));
    ui->tableView->setModel(model);

    QSqlQuery qryy;
    QSqlQueryModel *modell=new QSqlQueryModel();
    qryy.prepare("select * from putovanja;");
    qryy.exec();
    modell->setQuery(qryy);
    modell->setHeaderData(0, Qt::Horizontal, tr("let_ID"));
    modell->setHeaderData(1, Qt::Horizontal, tr("let"));
    modell->setHeaderData(2, Qt::Horizontal, tr("cijena"));
    ui->tableView_2->setModel(modell);


}

Aero_admin::~Aero_admin()
{
    delete ui;
}

void Aero_admin::on_brisi_clicked()
{
    QString s;
    QModelIndex index = ui->tableView_2->currentIndex();
    QMessageBox msgBox;
    int id = ui->tableView_2->model()->data(index).toInt();
    s=ui->tableView_2->model()->data(index).toString();
    QSqlQuery qry;

    qry.prepare("DELETE FROM putovanja WHERE let_ID=:ID");
    qry.bindValue(":ID",id);
    msgBox.setText("Brisanje destinacije.");
    msgBox.setInformativeText("Da li ste sigurni da želite obrisati destinaciju?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
        if(ret==QMessageBox::Yes)
                {
                    QMessageBox::information(this,"", "Slog obrisan!");
                    qry.exec();
                 }
}

void Aero_admin::on_dodaj_clicked()
{
    QString cj,l;
    l=ui->let->text();
    cj=ui->cj->text();
    QSqlQuery qry;
    qry.prepare("insert into putovanja values(NULL,'"+l+"','"+cj+"');");
    qDebug()<<qry.exec();
    ui->let->setText(NULL);
    ui->cj->setText(NULL);
}

void Aero_admin::on_brisi_R_clicked()
{
    QString s;
    QModelIndex index = ui->tableView->currentIndex();
    QMessageBox msgBox;
    int id = ui->tableView->model()->data(index).toInt();
    s=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;

    qry.prepare("DELETE FROM rezervacije WHERE ID=:ID");
    qry.bindValue(":ID",id);
    msgBox.setText("Brisanje rezervacije.");
    msgBox.setInformativeText("Da li ste sigurni da želite obrisati rezervaciju?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
        if(ret==QMessageBox::Yes)
                {
                    QMessageBox::information(this,"", "Slog obrisan!");
                    qry.exec();
                 }
}

void Aero_admin::on_izmjena_R_clicked()
{
    QString s;
    QModelIndex index = ui->tableView->currentIndex();
    QMessageBox msgBox;
    s=ui->tableView->model()->data(index).toString();

    izmjena i(s);
    i.exec();
}
