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

private:
    Ui::PracownikWindow *ui;
};

#endif // PRACOWNIKWINDOW_H
