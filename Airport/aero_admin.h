#ifndef AERO_ADMIN_H
#define AERO_ADMIN_H

#include <QDialog>
#include <rezervacija.h>
#include "pregled.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QSqlTableModel>
namespace Ui {
class Aero_admin;
}

class Aero_admin : public QDialog
{
    Q_OBJECT

public:
    explicit Aero_admin(QWidget *parent = nullptr);
    ~Aero_admin();

private slots:
    void on_brisi_clicked();

    void on_dodaj_clicked();

    void on_brisi_R_clicked();

    void on_izmjena_R_clicked();

private:
    Ui::Aero_admin *ui;
};

#endif // AERO_ADMIN_H
