#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
#include "klientwindow.h"
#include "pracownikwindow.h"
#include "serwiswindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_zamknij_button_clicked();
    void on_wyczysc_button_clicked();
    void on_zaloguj_button_clicked();

private:
    Ui::MainWindow *ui;
     QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");


     //okna
    KlientWindow okno_klient;
    SerwisWindow okno_serwis;
    PracownikWindow okno_pracownik;
};

#endif // MAINWINDOW_H
