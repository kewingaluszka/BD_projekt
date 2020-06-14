#include "klientwindow.h"
#include "ui_klientwindow.h"
#include <QDebug>

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

//    querymodel-> setQuery("SELECT klienci.ID_KLIENCI, klienci.DATA_REJESTRACJI, osoby.ID_OSOBY, osoby.IMIE, osoby.NAZWISKO, osoby.NUMER_TELEFONU, "
//                          "osoby.ADRES_EMAIL FROM klienci,osoby WHERE (klienci.ID_KLIENCI = osoby.ID_OSOBY) AND klienci.ID_KLIENCI="+ui->line_klient_2->text());
//    ui->tableView_klienci->setModel(querymodel);

    querymodel-> setQuery("SELECT zlecenia.PRACOWNIK_PRZYJMUJACY, zlecenia.PRACOWNIK_WYKONUJACY, zlecenia.PRACOWNIK_WYDAJACY, zlecenia.DATA_PRZYJECIA, zlecenia.DATA_WYKONANIA, "
                          "zlecenia.DATA_WYDANIA, zlecenia.DOKUMENT_USLUGI, dokumenty_uslug.DATA_WYSTAWIENIA FROM zlecenia,dokumenty_uslug WHERE (dokumenty_uslug.ID_DOKUMENTY_USLUG = zlecenia.DOKUMENT_USLUGI) "
                          "AND zlecenia.id_zlecenia="+ui->line_zlecenie->text());

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("Przyjął"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Wykonał"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("Wydał"));
   querymodel ->setHeaderData(3, Qt::Horizontal, tr("Data przyjęcia"));
    querymodel ->setHeaderData(4, Qt::Horizontal, tr("Data wykonania"));
    querymodel ->setHeaderData(5, Qt::Horizontal, tr("Data wydania"));
    querymodel ->setHeaderData(6, Qt::Horizontal, tr("Nr dokumentu"));
 querymodel ->setHeaderData(6, Qt::Horizontal, tr("Data wystawienia"));

    ui->tableView->setModel(querymodel);
}

void KlientWindow::on_szukaj_klient_clicked()
{
    QSqlQueryModel *querymodel = new QSqlQueryModel();

//    querymodel-> setQuery("SELECT klienci.ID_KLIENCI, klienci.DATA_REJESTRACJI, osoby.ID_OSOBY, osoby.IMIE, osoby.NAZWISKO, osoby.NUMER_TELEFONU, "
//                          "osoby.ADRES_EMAIL FROM klienci,osoby WHERE (klienci.ID_KLIENCI = osoby.ID_OSOBY) AND klienci.ID_KLIENCI="+ui->line_klient_2->text());
//    ui->tableView_klienci->setModel(querymodel);

    querymodel-> setQuery("SELECT zlecenia.PRACOWNIK_PRZYJMUJACY, zlecenia.PRACOWNIK_WYKONUJACY, zlecenia.PRACOWNIK_WYDAJACY, zlecenia.DATA_PRZYJECIA, zlecenia.DATA_WYKONANIA, "
                          "zlecenia.DATA_WYDANIA, zlecenia.DOKUMENT_USLUGI, dokumenty_uslug.DATA_WYSTAWIENIA FROM zlecenia,dokumenty_uslug WHERE (dokumenty_uslug.ID_DOKUMENTY_USLUG = zlecenia.DOKUMENT_USLUGI) "
                          "AND zlecenia.KLIENT="+ui->line_klient->text());

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("Przyjął"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Wykonał"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("Wydał"));
   querymodel ->setHeaderData(3, Qt::Horizontal, tr("Data przyjęcia"));
    querymodel ->setHeaderData(4, Qt::Horizontal, tr("Data wykonania"));
    querymodel ->setHeaderData(5, Qt::Horizontal, tr("Data wydania"));
    querymodel ->setHeaderData(6, Qt::Horizontal, tr("Nr dokumentu"));
 querymodel ->setHeaderData(7, Qt::Horizontal, tr("Wystawiono"));

    ui->tableView->setModel(querymodel);

}

void KlientWindow::on_zakoncz_button_clicked()
{
    this->close();
}



void KlientWindow::on_tableView_clicked(const QModelIndex &index)
{
    QString cellText;
    if (index.isValid() && (index.column()== 0 || index.column()== 1 || index.column()== 2)) {
            cellText = index.data().toString();
        }
    //qDebug() << cellText;
    ui->lineEdit ->setText(cellText);
}

void KlientWindow::on_szukaj_zlecenie_2_clicked()
{
    int id;
    int numer;
    QString email;
    QString s;

    QSqlQuery stringi;
    QSqlQueryModel *querymodel = new QSqlQueryModel();
    stringi.prepare("SELECT pracownicy.OSOBA FROM pracownicy WHERE pracownicy.ID_PRACOWNICY=:numerek");
    stringi.bindValue(":numerek", ui->lineEdit ->text());
    stringi.exec();

    while (stringi.next()) {//check that you have next result
          id = stringi.value(0).toInt();
      }
   qDebug() << id;

   QSqlQuery stringi1;
 // QSqlQueryModel *querymodel = new QSqlQueryModel();
   stringi1.prepare("SELECT osoby.NUMER_TELEFONU, osoby.ADRES_EMAIL FROM osoby WHERE osoby.ID_OSOBY=:id_osoby");
   stringi1.bindValue(":id_osoby", id);
   stringi1.exec();

   while (stringi1.next()) {//check that you have next result
         numer = stringi1.value(0).toInt();
         email = stringi1.value(1).toString();
        // qDebug() << email;
         //qDebug() << numer;
          s = QString::number(numer);
         ui->lineEdit_2 ->setText(s);
         ui->lineEdit_3 ->setText(email);

}
}

