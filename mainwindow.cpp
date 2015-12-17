#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QInputDialog>
#include <QString>
#include <QDir>
#include <QMouseEvent>
#include <QMessageBox>
#include <QFont>
bool cambioMenus[4];
int destinos=0;

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

void MainWindow::on_btnMapeo_clicked()
{
    QPoint p = this->mapFromGlobal(QCursor::pos());
    QString text = QInputDialog::getText(this, tr("Nombre"),tr("Ingrese Nombre del Destino"), QLineEdit::Normal);
    QString text2 = QInputDialog::getText(this, tr("Distintivo"),tr("Ingrese distintivo"), QLineEdit::Normal);
    if(text!=""&&text2!=""){
        QString num = QString::number(++destinos);
        text2=text2.at(0);
        text= num + "'" + text2 +"'"+ " " + text;
        ui->listDestinos->addItem(text);
        QLabel *dis = new QLabel(text2,this);
        QLabel *tmp =new QLabel("",this);
        tmp->setGeometry(p.x(),p.y(),35,35);
        dis->setGeometry(p.x(),p.y()+30,15,15);
        QFont font = dis->font();
        font.setBold(true);
        dis->setFont(font);
        QPixmap pix("/home/arcatech/TraTouMaps/Resources/NodoMapa.png");
        tmp->setPixmap(pix.scaled(tmp->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
        tmp->show();
        dis->show();
    }else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Imposible crear ruta intente nuevamente");

    }

}
