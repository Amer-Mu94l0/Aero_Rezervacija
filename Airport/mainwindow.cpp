#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aero_admin.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString i, l;
    i=ui->ime->text();
    l=ui->lozinka->text();
    QMessageBox m;
 if(i=="admin" && l=="1234")
     {
        m.setText("logovanje....");
        m.exec();
        Aero_admin a;
        a.setModal(true);
        a.exec();

     }
 else  ui->label_3->setText("pogresna lozinka ili ussername");

}

void MainWindow::on_pushButton_clicked()
{
    rezervacija r;
    r.setModal(true);
    r.exec();
}

void MainWindow::on_pregled_clicked()
{
    pregled p(ui->ime_P->text(),ui->Prezime_P->text());
    p.exec();
}
