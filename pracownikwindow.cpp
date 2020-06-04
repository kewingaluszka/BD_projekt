#include "pracownikwindow.h"
#include "ui_pracownikwindow.h"

PracownikWindow::PracownikWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PracownikWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Konto pracownika"));
}

PracownikWindow::~PracownikWindow()
{
    delete ui;
}

void PracownikWindow::on_szukaj_zlecenie_clicked()
{
    QSqlQueryModel *querymodel = new QSqlQueryModel();

    //nie wiem czemu to zakomentowane nie działa, ale tak ma to wygladac
    // querymodel-> setQuery("SELECT ID_ZLECENIA, KLIENT, USLUGA, PRACOWNIK_PRZYJMUJACY, PRACOWNIK_WYKONUJACY, PRACOWNIK_WYDAJACY, DATA_PRZYJECIA, DATA_WYKONANIA, "
    //                     "DATA_WYDANIA, DOKUMENT_USLUGI FROM zlecenia WHERE klient="+ui->line_klient->text()+"OR id_zlecenia="+ui->line_zlecenie->text());

    querymodel-> setQuery("SELECT ID_ZLECENIA, KLIENT, USLUGA, PRACOWNIK_PRZYJMUJACY, PRACOWNIK_WYKONUJACY, PRACOWNIK_WYDAJACY, DATA_PRZYJECIA, DATA_WYKONANIA, "
                          "DATA_WYDANIA, DOKUMENT_USLUGI FROM zlecenia WHERE klient="+ui->line_klient->text());

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID zlecenia"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("ID klienta"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("ID usługi"));
    querymodel ->setHeaderData(3, Qt::Horizontal, tr("Przyjął"));
    querymodel ->setHeaderData(4, Qt::Horizontal, tr("Wykonał"));
    querymodel ->setHeaderData(5, Qt::Horizontal, tr("Wydał"));
    querymodel ->setHeaderData(6, Qt::Horizontal, tr("Data przyjęcia"));
    querymodel ->setHeaderData(7, Qt::Horizontal, tr("Data wykonania"));
    querymodel ->setHeaderData(8, Qt::Horizontal, tr("Data wydania"));
    querymodel ->setHeaderData(9, Qt::Horizontal, tr("Nr dokumentu"));


    ui->tableView_zlecenia->setModel(querymodel);
}

void PracownikWindow::on_zakoncz_button_clicked()
{
    this->close();
}

void PracownikWindow::on_wyswietl_wszystkie_clicked()
{
    QSqlQueryModel *querymodel = new QSqlQueryModel();


    querymodel-> setQuery("SELECT ID_ZLECENIA, KLIENT, USLUGA, PRACOWNIK_PRZYJMUJACY, PRACOWNIK_WYKONUJACY, PRACOWNIK_WYDAJACY, DATA_PRZYJECIA, DATA_WYKONANIA, "
                          "DATA_WYDANIA, DOKUMENT_USLUGI FROM zlecenia");

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID zlecenia"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("ID klienta"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("ID usługi"));
    querymodel ->setHeaderData(3, Qt::Horizontal, tr("Przyjął"));
    querymodel ->setHeaderData(4, Qt::Horizontal, tr("Wykonał"));
    querymodel ->setHeaderData(5, Qt::Horizontal, tr("Wydał"));
    querymodel ->setHeaderData(6, Qt::Horizontal, tr("Data przyjęcia"));
    querymodel ->setHeaderData(7, Qt::Horizontal, tr("Data wykonania"));
    querymodel ->setHeaderData(8, Qt::Horizontal, tr("Data wydania"));
    querymodel ->setHeaderData(9, Qt::Horizontal, tr("Nr dokumentu"));

    ui->tableView_zlecenia->setModel(querymodel);
}







void PracownikWindow::on_szukaj_klienta_clicked()
{

    QSqlQueryModel *querymodel = new QSqlQueryModel();
    querymodel-> setQuery("SELECT ID_KLIENCI, DATA_REJESTRACJI, OSOBA FROM klienci WHERE id_klienci="+ui->line_klient_2->text());
    ui->tableView_klienci->setModel(querymodel);

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID klienta"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Data rejestracji"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("ID osoby"));
}

void PracownikWindow::on_wyswietl_wszystkich_klientow_clicked()
{

    QSqlQueryModel *querymodel = new QSqlQueryModel();
    querymodel-> setQuery("SELECT ID_KLIENCI, DATA_REJESTRACJI, OSOBA FROM klienci");
    ui->tableView_klienci->setModel(querymodel);

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID klienta"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Data rejestracji"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("ID osoby"));
}
