#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnMenu_1_clicked();

    void on_btnMenu_2_clicked();

    void on_btnMenu_3_clicked();

    void on_btnMenu_4_clicked();



    void on_groupBox_clicked();

    void on_btnMapeo_clicked();

    void on_btnRuta_clicked();

    void on_btnBuscarRuta_clicked();

    void on_btnMenu_5_clicked();

    void on_btnMenu_6_clicked();

    void on_btnEliminarArista_clicked();

    void on_btnEliminarNodo_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H

