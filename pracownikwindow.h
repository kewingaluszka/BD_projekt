#ifndef PRACOWNIKWINDOW_H
#define PRACOWNIKWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class PracownikWindow;
}

class PracownikWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PracownikWindow(QWidget *parent = 0);
    ~PracownikWindow();

private slots:
    void on_szukaj_zlecenie_clicked();
    void on_zakoncz_button_clicked();
    void on_wyswietl_wszystkie_clicked();




    void on_szukaj_klienta_clicked();

    void on_wyswietl_wszystkich_klientow_clicked();

    void on_dodaj_klienta_clicked();

    void on_dodaj_zlecenie_clicked();

    void on_aktualizuj_zlecenie_clicked();

    void on_dodaj_dokument_clicked();

    void on_wyswietl_wszystkie_urzadzenia_clicked();

    void on_szukaj_urzadzenie_clicked();

    void on_dodaj_urzadzenie_clicked();

    void on_dodaj_usluge_clicked();

    void on_aktualizacja_uslugi_clicked();

    void on_wyswietl_uslugi_clicked();

    void on_szukaj_usluge_clicked();

    void on_wyswietl_element_clicked();

    void on_szukaj_element_clicked();

    void on_dodaj_element_clicked();

    void on_aktualizacja_elementu_clicked();

    void on_wyswietl_dokumenty_clicked();

    void on_szukaj_dokumentu_clicked();

    void on_tableView_zlecenia_activated(const QModelIndex &index);

    void on_usun_button_clicked();

private:
    Ui::PracownikWindow *ui;
};

#endif // PRACOWNIKWINDOW_H
