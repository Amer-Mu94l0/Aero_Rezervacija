#ifndef PREGLED_H
#define PREGLED_H

#include <QDialog>
#include <QDialog>
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
class pregled;
}

class pregled : public QDialog
{
    Q_OBJECT

public:
    explicit pregled(QString ime, QString prezime,QWidget *parent = nullptr);
    ~pregled();

private:
    Ui::pregled *ui;
    QSqlDatabase db;
};

#endif // PREGLED_H
