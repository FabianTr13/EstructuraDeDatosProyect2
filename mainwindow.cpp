#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
bool cambioMenus[4];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gbMenu_1->setVisible(false);
    ui->gbMenu_2->setVisible(false);
    ui->gbMenu_3->setVisible(false);
    ui->gbMenu_4->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnMenu_1_clicked()
{
    if(cambioMenus[0]==false){
    ui->gbMenu_2->setVisible(false);
    ui->gbMenu_3->setVisible(false);
    ui->gbMenu_4->setVisible(false);
    ui->gbMenu_1->setVisible(true);
    cambioMenus[0]=true;
    cambioMenus[1]=cambioMenus[2]=cambioMenus[3]=false;
    }else{
        ui->gbMenu_1->setVisible(false);
        cambioMenus[0]=false;
    }
}

void MainWindow::on_btnMenu_2_clicked()
{
    if(cambioMenus[1]==false){
    ui->gbMenu_1->setVisible(false);
    ui->gbMenu_3->setVisible(false);
    ui->gbMenu_4->setVisible(false);
    ui->gbMenu_2->setVisible(true);
    cambioMenus[1]=true;
    cambioMenus[0]=cambioMenus[2]=cambioMenus[3]=false;
    }else{
        ui->gbMenu_2->setVisible(false);
        cambioMenus[1]=false;
    }
}

void MainWindow::on_btnMenu_3_clicked()
{
    if(cambioMenus[2]==false){
    ui->gbMenu_1->setVisible(false);
    ui->gbMenu_2->setVisible(false);
    ui->gbMenu_4->setVisible(false);
    ui->gbMenu_3->setVisible(true);
    cambioMenus[2]=true;
    cambioMenus[0]=cambioMenus[1]=cambioMenus[3]=false;
    }else{
        ui->gbMenu_3->setVisible(false);
        cambioMenus[2]=false;
    }
}

void MainWindow::on_btnMenu_4_clicked()
{
    if(cambioMenus[3]==false){
    ui->gbMenu_1->setVisible(false);
    ui->gbMenu_2->setVisible(false);
    ui->gbMenu_3->setVisible(false);
    ui->gbMenu_4->setVisible(true);
    cambioMenus[3]=true;
    cambioMenus[0]=cambioMenus[1]=cambioMenus[2]=false;
    }else{
        ui->gbMenu_4->setVisible(false);
        cambioMenus[3]=false;
    }
}

