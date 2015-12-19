#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#define INFINITY  0x3f3f3f3f
#include <QMessageBox>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}



