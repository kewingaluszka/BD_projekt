#include "serwiswindow.h"
#include "ui_serwiswindow.h"

SerwisWindow::SerwisWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerwisWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Konto główne"));
}

SerwisWindow::~SerwisWindow()
{
    delete ui;
}
