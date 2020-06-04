#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // ui->line_login->setText("wpisz login");
   // ui->line_haslo->setText("haslo");
    ui->line_login->setText("pracownik");
    ui->line_haslo->setText("pracownik1");
    setWindowTitle(tr("Logowanie"));

}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}


void MainWindow::on_zamknij_button_clicked()
{
    this->close();
    okno_klient.close();
    okno_serwis.close();
    okno_pracownik.close();


}

void MainWindow::on_wyczysc_button_clicked()
{
    ui->line_login->setText("");
    ui->line_haslo->setText("");
}

void MainWindow::on_zaloguj_button_clicked()
{

    QString login, haslo;

    login = ui->line_login->text();
    haslo = ui->line_haslo->text();

    // qDebug() << login ;

    // logowanie do bazy danych
    db.setHostName("127.0.0.1");
    db.setDatabaseName("serwis");
    db.setPassword("hulajnoga");

    db.setUserName(login);
    db.setPassword(haslo);



    if(db.open())
    {

        statusBar()->showMessage("Pomyślnie połączono z bazą danych");
        ui->status_label->setText("Status polaczenia: połączono");

        //****************************** OKNO KLIENTA *****************************************
        if(login == "klient")
        {
            okno_klient.show();
        }

        //****************************** OKNO SERWISU *****************************************
        else if(login == "serwis")
        {
            okno_serwis.show();
        }

        //****************************** OKNO PRACOWNIKA **************************************
        else if(login == "pracownik")
        {
            okno_pracownik.show();
        }


    }

    else
    {
        statusBar()->showMessage("Błąd! Nie połączono z bazą danych");
        ui->status_label->setText("Status polaczenia: nie polaczono");
    }
}
