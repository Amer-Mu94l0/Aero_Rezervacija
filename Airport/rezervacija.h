#ifndef REZERVACIJA_H
#define REZERVACIJA_H

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
class rezervacija;
}

class rezervacija : public QDialog
{
    Q_OBJECT

public:
    explicit rezervacija(QWidget *parent = nullptr);
    ~rezervacija();

private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_clicked();


    void on_checkBox_windowIconChanged(const QIcon &icon);

private:
    Ui::rezervacija *ui;
    QSqlDatabase db;
};

#endif // REZERVACIJA_H
