#include "klientwindow.h"
#include "ui_klientwindow.h"

KlientWindow::KlientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KlientWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Konto klienta"));
}

KlientWindow::~KlientWindow()
{
    delete ui;
}



void KlientWindow::on_szukaj_zlecenie_clicked()
{
    QSqlQueryModel *querymodel = new QSqlQueryModel();

    querymodel-> setQuery("SELECT PRACOWNIK_PRZYJMUJACY, PRACOWNIK_WYKONUJACY, PRACOWNIK_WYDAJACY, DATA_PRZYJECIA, DATA_WYKONANIA, "
                          "DATA_WYDANIA, DOKUMENT_USLUGI FROM zlecenia WHERE id_zlecenia="+ui->line_zlecenie->text());

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("Przyjął"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Wykonał"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("Wydał"));
    querymodel ->setHeaderData(3, Qt::Horizontal, tr("Data przyjęcia"));
    querymodel ->setHeaderData(4, Qt::Horizontal, tr("Data wykonania"));
    querymodel ->setHeaderData(5, Qt::Horizontal, tr("Data wydania"));
    querymodel ->setHeaderData(6, Qt::Horizontal, tr("Nr dokumentu"));


    ui->tableView->setModel(querymodel);
}

void KlientWindow::on_szukaj_klient_clicked()
{
    QSqlQueryModel *querymodel = new QSqlQueryModel();

    querymodel-> setQuery("SELECT PRACOWNIK_PRZYJMUJACY, PRACOWNIK_WYKONUJACY, PRACOWNIK_WYDAJACY, DATA_PRZYJECIA, DATA_WYKONANIA, "
                          "DATA_WYDANIA, DOKUMENT_USLUGI FROM zlecenia WHERE klient="+ui->line_klient->text());

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("Przyjął"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Wykonał"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("Wydał"));
    querymodel ->setHeaderData(3, Qt::Horizontal, tr("Data przyjęcia"));
    querymodel ->setHeaderData(4, Qt::Horizontal, tr("Data wykonania"));
    querymodel ->setHeaderData(5, Qt::Horizontal, tr("Data wydania"));
    querymodel ->setHeaderData(6, Qt::Horizontal, tr("Nr dokumentu"));


    ui->tableView->setModel(querymodel);
}

void KlientWindow::on_zakoncz_button_clicked()
{
    this->close();
}
