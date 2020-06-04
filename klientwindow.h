#ifndef KLIENTWINDOW_H
#define KLIENTWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class KlientWindow;
}

class KlientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit KlientWindow(QWidget *parent = 0);
    ~KlientWindow();

private slots:

    void on_szukaj_zlecenie_clicked();
    void on_szukaj_klient_clicked();
    void on_zakoncz_button_clicked();

private:
    Ui::KlientWindow *ui;
    // QSqlDatabase db_klient = QSqlDatabase::addDatabase("QMYSQL");
};

#endif // KLIENTWINDOW_H
