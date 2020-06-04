#ifndef SERWISWINDOW_H
#define SERWISWINDOW_H

#include <QMainWindow>

namespace Ui {
class SerwisWindow;
}

class SerwisWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SerwisWindow(QWidget *parent = 0);
    ~SerwisWindow();

private:
    Ui::SerwisWindow *ui;
};

#endif // SERWISWINDOW_H
