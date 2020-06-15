#include "pracownikwindow.h"
#include "ui_pracownikwindow.h"
#include <QDebug>

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
//    QString s_pr_przyj;
//    QString s_pr_wyd;
//    QString s_pr_wyk;
//    QString s_urzadzenie;
//    QString s_usluga;
//    QString s_data_prz;
//    QString s_data_wyk;
//    QString s_data_wyd;
//    QString s_dokumenty;
//    QString s_klient;
//  int i_pr_przyj, i_pr_wyd, i_pr_wyk, i_urzadzenie, i_usluga, i_dokumenty, i_klient;

    QSqlQuery stringi;
    QSqlQueryModel *querymodel = new QSqlQueryModel();
    stringi.prepare("SELECT zlecenia.ID_ZLECENIA, zlecenia.KLIENT, zlecenia.USLUGA, zlecenia.PRACOWNIK_PRZYJMUJACY, zlecenia.PRACOWNIK_WYKONUJACY, zlecenia.PRACOWNIK_WYDAJACY, zlecenia.DATA_PRZYJECIA, zlecenia.DATA_WYKONANIA, zlecenia.DATA_WYDANIA, zlecenia.DOKUMENT_USLUGI, zlecenia.URZADZENIE  FROM zlecenia WHERE zlecenia.KLIENT=:klient OR zlecenia.ID_ZLECENIA=:zlecenie");
    stringi.bindValue(":klient", ui->line_klient->text());
    stringi.bindValue(":zlecenie", ui->line_zlecenie->text());
    stringi.exec();

    while (stringi.next()) {//check that you have next result
          ui->id_aktualizuj->setText(stringi.value(0).toString());
          ui->klient -> setText(stringi.value(1).toString());
          ui->usluga->setText(stringi.value(2).toString());
          ui->pr_przyj->setText(stringi.value(3).toString());
          ui->pr_wyk->setText(stringi.value(4).toString());
          ui->pr_wyd->setText(stringi.value(5).toString());
          ui->data_przyjecia->setText(stringi.value(6).toString());
          ui->data_wykonania->setText(stringi.value(7).toString());
          ui->data_wydania->setText(stringi.value(8).toString());
          ui->dokumenty->setText(stringi.value(9).toString());
          ui->urzadzenie->setText(stringi.value(10).toString());

         // qDebug() << email;
          //qDebug() << numer;
}
    querymodel-> setQuery(stringi);



    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID zlecenia"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("ID klienta"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("ID usługi"));
    querymodel ->setHeaderData(3, Qt::Horizontal, tr("Przyjal"));
    querymodel ->setHeaderData(4, Qt::Horizontal, tr("Wykonal"));
    querymodel ->setHeaderData(5, Qt::Horizontal, tr("Wydal"));
    querymodel ->setHeaderData(6, Qt::Horizontal, tr("Data przyjecia"));
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


    querymodel-> setQuery("SELECT * FROM zlecenia");

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
    querymodel-> setQuery("SELECT klienci.ID_KLIENCI, klienci.DATA_REJESTRACJI, osoby.ID_OSOBY, osoby.IMIE, osoby.NAZWISKO, osoby.NUMER_TELEFONU, osoby.ADRES_EMAIL FROM klienci,osoby WHERE (klienci.ID_KLIENCI = osoby.ID_OSOBY) AND klienci.ID_KLIENCI="+ui->line_klient_2->text());
    ui->tableView_klienci->setModel(querymodel);

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID klienta"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Data rejestracji"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("ID osoby"));

}

void PracownikWindow::on_wyswietl_wszystkich_klientow_clicked()
{

    QSqlQueryModel *querymodel = new QSqlQueryModel();
    //querymodel-> setQuery("SELECT ID_KLIENCI, DATA_REJESTRACJI, OSOBA FROM klienci");
    querymodel-> setQuery("SELECT klienci.ID_KLIENCI, klienci.DATA_REJESTRACJI, osoby.ID_OSOBY, osoby.IMIE, osoby.NAZWISKO, osoby.NUMER_TELEFONU, osoby.ADRES_EMAIL FROM klienci,osoby WHERE klienci.ID_KLIENCI = osoby.ID_OSOBY");
    ui->tableView_klienci->setModel(querymodel);

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID klienta"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Data rejestracji"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("ID osoby"));

}

void PracownikWindow::on_dodaj_klienta_clicked()
{
    QSqlQuery klient;
    QSqlQueryModel *querymodel = new QSqlQueryModel();

    klient.prepare("INSERT INTO osoby (IMIE, NAZWISKO, NUMER_TELEFONU, ADRES_EMAIL) VALUES (:imie, :nazwisko, :tel, :email)");
    klient.bindValue(":imie", ui->imie->text());
    klient.bindValue(":nazwisko", ui->nazwisko->text());
    klient.bindValue(":tel", ui->numer_telefonu->text());
    klient.bindValue(":email", ui->adres_klienta->text());
    klient.exec();
    querymodel-> setQuery(klient);
    int id = klient.lastInsertId().toInt();
    klient.prepare("INSERT INTO klienci (DATA_REJESTRACJI, OSOBA) VALUES (:data, :idd)");
    klient.bindValue(":data", ui->data_rejestracji->text());
    klient.bindValue(":idd", id);
    klient.exec();
    querymodel-> setQuery(klient);

    //querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID zlecenia"));

}



void PracownikWindow::on_dodaj_zlecenie_clicked()
{

    QSqlQuery klient;
    QSqlQueryModel *querymodel = new QSqlQueryModel();

    klient.prepare("INSERT INTO zlecenia (KLIENT, USLUGA, PRACOWNIK_PRZYJMUJACY, PRACOWNIK_WYKONUJACY, PRACOWNIK_WYDAJACY, DATA_PRZYJECIA, DATA_WYKONANIA, DATA_WYDANIA, DOKUMENT_USLUGI, URZADZENIE) VALUES (:klient, :usluga, :prac1, :prac2, :prac3, :data1, :data2, :data3, :dok, :urzadzenie)");
    klient.bindValue(":klient", ui->klient->text());
    klient.bindValue(":usluga", ui->usluga->text());
    klient.bindValue(":prac1", ui->pr_przyj->text());
    klient.bindValue(":prac2", ui->pr_wyk->text());
    klient.bindValue(":prac3", ui->pr_wyd->text());
    klient.bindValue(":data1", ui->data_przyjecia->text());
    klient.bindValue(":data2", ui->data_wykonania->text());
    klient.bindValue(":data3", ui->data_wydania->text());
    klient.bindValue(":dok", ui->dokumenty->text());
    klient.bindValue(":urzadzenie", ui->urzadzenie->text());
    klient.exec();
    querymodel-> setQuery(klient);


}

void PracownikWindow::on_aktualizuj_zlecenie_clicked()
{
    QSqlQuery klient;
    QSqlQueryModel *querymodel = new QSqlQueryModel();
    int a = (ui->id_aktualizuj->text()).toInt();
    klient.prepare("UPDATE zlecenia SET KLIENT=:klient, USLUGA=:usluga, PRACOWNIK_PRZYJMUJACY=:prac1, PRACOWNIK_WYKONUJACY=:prac2, PRACOWNIK_WYDAJACY=:prac3, DATA_PRZYJECIA=:data1, DATA_WYKONANIA=:data2, DATA_WYDANIA=:data3, DOKUMENT_USLUGI=:dok, URZADZENIE=:urzadzenie WHERE ID_ZLECENIA=:id_a");
    klient.bindValue(":klient", ui->klient->text());
    klient.bindValue(":usluga", ui->usluga->text());
    klient.bindValue(":prac1", ui->pr_przyj->text());
    klient.bindValue(":prac2", ui->pr_wyk->text());
    klient.bindValue(":prac3", ui->pr_wyd->text());
    klient.bindValue(":data1", ui->data_przyjecia->text());
    klient.bindValue(":data2", ui->data_wykonania->text());
    klient.bindValue(":data3", ui->data_wydania->text());
    klient.bindValue(":dok", ui->dokumenty->text());
    klient.bindValue(":urzadzenie", ui->urzadzenie->text());
    klient.bindValue(":id_a", a);
    klient.exec();
    querymodel-> setQuery(klient);
}



void PracownikWindow::on_dodaj_dokument_clicked()
{

    QSqlQuery klient;
    QSqlQueryModel *querymodel = new QSqlQueryModel();

    klient.prepare("INSERT INTO dokumenty_uslug (RODZAJ_DOKUMENTU, DATA_WYSTAWIENIA) VALUES (:rodz, :dat)");
    klient.bindValue(":rodz", ui->rodzaj_dokumentu->text());
    klient.bindValue(":dat", ui->data_wys->text());

    klient.exec();
    querymodel-> setQuery(klient);


}

void PracownikWindow::on_wyswietl_wszystkie_urzadzenia_clicked()
{
    QSqlQueryModel *querymodel = new QSqlQueryModel();


    querymodel-> setQuery("SELECT * FROM urzadzenia");

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID Urzadzenia"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Model urzadzenia"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("Marka urzadzenia"));


    ui->pokaz_uslugi->setModel(querymodel);
}

void PracownikWindow::on_szukaj_urzadzenie_clicked()
{
    QSqlQuery urzadzenie;
    QSqlQueryModel *querymodel = new QSqlQueryModel();

    urzadzenie.prepare("SELECT ID_URZADZENIA, MODEL_URZADZENIA, MARKA_URZADZENIA FROM urzadzenia WHERE ID_URZADZENIA=:id");
    urzadzenie.bindValue(":id", ui->line_urzadzenie_4->text());
    urzadzenie.exec();
    querymodel-> setQuery(urzadzenie);

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID Urzadzenia"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Model urzadzenia"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("Marka urzadzenia"));
     ui->pokaz_uslugi->setModel(querymodel);
}

void PracownikWindow::on_dodaj_urzadzenie_clicked()
{
    QSqlQuery urz;
    QSqlQueryModel *querymodel = new QSqlQueryModel();

    urz.prepare("INSERT INTO urzadzenia (MODEL_URZADZENIA, MARKA_URZADZENIA) VALUES (:model, :marka)");
    urz.bindValue(":model", ui->model->text());
    urz.bindValue(":marka", ui->marka->text());

    urz.exec();
    querymodel-> setQuery(urz);
}

void PracownikWindow::on_dodaj_usluge_clicked()
{
    QSqlQuery usluga;
    QSqlQueryModel *querymodel = new QSqlQueryModel();

    usluga.prepare("INSERT INTO uslugi (OPIS_USLUGI, LICZBA_ROBOCZOGODZIN, KOSZT_DLA_KLIENTA, URZADZENIE) VALUES (:opis, :liczba, :koszt, :id_u)");
    usluga.bindValue(":opis", ui->opis->text());
    usluga.bindValue(":liczba", ui->roboczogodziny->text());
    usluga.bindValue(":koszt", ui->koszt_klienta->text());
    usluga.bindValue(":id_u", ui->id_urzadzenia->text());

    usluga.exec();
    querymodel-> setQuery(usluga);
}

void PracownikWindow::on_aktualizacja_uslugi_clicked()
{
    QSqlQuery klient;
    QSqlQueryModel *querymodel = new QSqlQueryModel();
    int a = (ui->id_aktualizuj_2->text()).toInt();
    klient.prepare("UPDATE uslugi SET OPIS_USLUGI=:opis, LICZBA_ROBOCZOGODZIN=:liczba, KOSZT_DLA_KLIENTA=:koszt, URZADZENIE=:id_u WHERE ID_USLUGI=:id_a");
    klient.bindValue(":opis", ui->opis->text());
    klient.bindValue(":liczba", ui->roboczogodziny->text());
    klient.bindValue(":koszt", ui->koszt_klienta->text());
    klient.bindValue(":id_u", ui->id_urzadzenia->text());
    klient.bindValue(":id_a", a);
    klient.exec();
    querymodel-> setQuery(klient);
}

void PracownikWindow::on_wyswietl_uslugi_clicked()
{
    QSqlQueryModel *querymodel = new QSqlQueryModel();


    querymodel-> setQuery("SELECT * FROM uslugi");

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID uslugi"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Opis uslugi"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("Liczba roboczogodzin"));
    querymodel ->setHeaderData(3, Qt::Horizontal, tr("Koszt dla klienta"));
    querymodel ->setHeaderData(4, Qt::Horizontal, tr("ID urzadzenia"));


    ui->pokaz_uslugi->setModel(querymodel);
}


void PracownikWindow::on_szukaj_usluge_clicked()
{
    QSqlQuery string;
    QSqlQueryModel *querymodel = new QSqlQueryModel();

    string.prepare("SELECT ID_USLUGI, OPIS_USLUGI, LICZBA_ROBOCZOGODZIN, KOSZT_DLA_KLIENTA, URZADZENIE FROM uslugi WHERE ID_USLUGI=:id_uslugi OR URZADZENIE=:id_urzadzenia");
    string.bindValue(":id_uslugi", ui->line_usluga->text());
    string.bindValue(":id_urzadzenia", ui->line_urzadzenia->text());
    string.exec();
    querymodel-> setQuery(string);
    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID uslugi"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Opis uslugi"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("Liczba roboczogodzin"));
    querymodel ->setHeaderData(3, Qt::Horizontal, tr("Koszt dla klienta"));
    querymodel ->setHeaderData(4, Qt::Horizontal, tr("ID urzadzenia"));


    ui->pokaz_uslugi->setModel(querymodel);
}

void PracownikWindow::on_wyswietl_element_clicked()
{
    QSqlQueryModel *querymodel = new QSqlQueryModel();


    querymodel-> setQuery("SELECT * FROM elementy");

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID elementu"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Nazwa elementu"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("Koszt elementu"));
    querymodel ->setHeaderData(3, Qt::Horizontal, tr("ID uslugi"));
    querymodel ->setHeaderData(4, Qt::Horizontal, tr("ID urzadzenia"));


    ui->pokaz_elementy->setModel(querymodel);
}

void PracownikWindow::on_szukaj_element_clicked()
{
    QSqlQuery string;
    QSqlQueryModel *querymodel = new QSqlQueryModel();

    string.prepare("SELECT * FROM elementy WHERE ID_ELEMENTY=:id_el");
    string.bindValue(":id_el", ui->line_element->text());
    string.exec();
    querymodel-> setQuery(string);
    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID elementu"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Nazwa elementu"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("Koszt elementu"));
    querymodel ->setHeaderData(3, Qt::Horizontal, tr("ID uslugi"));
    querymodel ->setHeaderData(4, Qt::Horizontal, tr("ID urzadzenia"));
      ui->pokaz_elementy->setModel(querymodel);
}


void PracownikWindow::on_dodaj_element_clicked()
{
    QSqlQuery element;
    QSqlQueryModel *querymodel = new QSqlQueryModel();

    element.prepare("INSERT INTO elementy (NAZWA_ELEMENTU, KOSZT_ELEMENTU, USLUGA, URZADZENIE) VALUES (:naz, :koszt, :id_us, :id_urz)");
    element.bindValue(":naz", ui->nazwa_elementu->text());
    element.bindValue(":koszt", ui->koszt_elementu_5->text());
    element.bindValue(":id_us", ui->id_uslugi_3->text());
    element.bindValue(":id_urz", ui->id_urzadzenia_5->text());

    element.exec();
    querymodel-> setQuery(element);
}

void PracownikWindow::on_aktualizacja_elementu_clicked()
{
    QSqlQuery element;
    QSqlQueryModel *querymodel = new QSqlQueryModel();
    int a = (ui->id_aktualizuj_3->text()).toInt();
    element.prepare("UPDATE elementy SET NAZWA_ELEMENTU=:naz, KOSZT_ELEMENTU=:koszt, USLUGA=:id_us, URZADZENIE=:id_urz WHERE ID_ELEMENTY=:id_a");
    element.bindValue(":naz", ui->nazwa_elementu->text());
    element.bindValue(":koszt", ui->koszt_elementu_5->text());
    element.bindValue(":id_us", ui->id_uslugi_3->text());
    element.bindValue(":id_urz", ui->id_urzadzenia_5->text());
    element.bindValue(":id_a", a);
    element.exec();
    querymodel-> setQuery(element);
}

void PracownikWindow::on_wyswietl_dokumenty_clicked()
{
    QSqlQueryModel *querymodel = new QSqlQueryModel();


    querymodel-> setQuery("SELECT * FROM dokumenty_uslug");

    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID dokumentu"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Rodzaj_dokumentu"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("Data_wystawienia"));
    ui->tableView_zlecenia->setModel(querymodel);
}

void PracownikWindow::on_szukaj_dokumentu_clicked()
{
    QSqlQuery string;
    QSqlQueryModel *querymodel = new QSqlQueryModel();

    string.prepare("SELECT * FROM dokumenty_uslug WHERE ID_DOKUMENTY_USLUG=:id_d");
    string.bindValue(":id_d", ui->line_dokument->text());
    string.exec();
    querymodel-> setQuery(string);
    querymodel ->setHeaderData(0, Qt::Horizontal, tr("ID dokumentu"));
    querymodel ->setHeaderData(1, Qt::Horizontal, tr("Rodzaj_dokumentu"));
    querymodel ->setHeaderData(2, Qt::Horizontal, tr("Data_wystawienia"));
    ui->tableView_zlecenia->setModel(querymodel);
}

void PracownikWindow::on_tableView_zlecenia_activated(const QModelIndex &index)
{

//    QString s_pr_przyj, s_pr_wyd, s_pr_wyk, s_urzadzenie, s_usluga, s_data_wyd, s_data_wyk, s_data_wyk, s_dokumenty;
//    int i_pr_przyj, i_pr_wyd, i_pr_wyk, i_urzadzenie, i_usluga, i_dokumenty;

//    if (index.isValid() && (index.column()== 0 || index.column()== 1 || index.column()== 2)) {
//        i_pr_przyj
//                i_pr_wyd
//                i_pr_wyk
//                i_urzadzenie
//                i_usluga
//                i_dokumenty;


//        cellText = index.data().toString();
//        }
//    //qDebug() << cellText;
//    ui->klient ->setText();
}

void PracownikWindow::on_usun_button_clicked()
{
    QSqlQuery element;
    QSqlQueryModel *querymodel = new QSqlQueryModel();
    int a = (ui->usun_line->text()).toInt();


    element.prepare("DELETE FROM zlecenia WHERE zlecenia.ID_ZLECENIA=:id_z");
    element.bindValue(":id_z", a);
    element.exec();
    querymodel-> setQuery(element);
}
