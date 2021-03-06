#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QInputDialog>
#include <QString>
#include <QDir>
#include <QMouseEvent>
#include <QMessageBox>
#include <QFont>
#define INFINITY  0x3f3f3f3f


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gbMenu_1->setVisible(false);
    ui->gbMenu_2->setVisible(false);
    ui->gbMenu_3->setVisible(false);
    ui->gbMenu_4->setVisible(false);
    ui->gbMenu_5->setVisible(false);
    ui->gbMenu_6->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//reloj--------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------
class Dijkstra
{
private:
    int adjMatrix[15][15];
    int predecessor[15],distance[15];
    bool mark[15];
    int source;
    int numOfVertices;
    int fin;
    int home;
    int g=0;
    int run=0;
public:
    QString ways="",wayc;

    Dijkstra(int home,int endf){
        this->home=home;
        this->fin=endf;
    }


void read(int contador,   int *pesos)
{

    numOfVertices = contador;
    int k=0;

    for(int i=0; i<numOfVertices; i++)
    {

        for(int j=0; j<numOfVertices; j++)
        {
            adjMatrix[i][j]=pesos[k] ;
               k++;
        }
    }
    source=home;
    source-=1;
}


void initialize()
{
    for(int i=0; i<numOfVertices; i++)
    {
        mark[i] = false;
        predecessor[i] = -1;
        distance[i] = INFINITY;
    }
    distance[source]= 0;
}


int getClosestUnmarkedNode()
{
    int minDistance = INFINITY;
    int closestUnmarkedNode;
    for(int i=0; i<numOfVertices; i++)
    {
        if((!mark[i]) && ( minDistance >= distance[i]))
        {
            minDistance = distance[i];
            closestUnmarkedNode = i;
        }
    }
    return closestUnmarkedNode;
}


void calculateDistance()
{
    initialize();
    int minDistance = INFINITY;
    int closestUnmarkedNode;
    int count = 0;
    while(count < numOfVertices)
    {
        closestUnmarkedNode = getClosestUnmarkedNode();
        mark[closestUnmarkedNode] = true;
        for(int i=0; i<numOfVertices; i++)
        {
            if((!mark[i]) && (adjMatrix[closestUnmarkedNode][i]>0) )
            {
                if(distance[i] > distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i])
                {
                    distance[i] = distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i];
                    predecessor[i] = closestUnmarkedNode;
                }
            }
        }
        count++;
    }
}


QString num(int i) {
    // int to string
    QString num;
    int temp;
    while(i / 10!=0){
        temp=i%10;
        i= i/10;
        temp =temp + 48;
        num = (char)temp + num;

    }
    i=i+48;
    num = (char)i + num ;
    return num;
}
//hasta llegar a todos los vertices de cada nodo aunque no tengan arista procesara peroo tomara solo el buscado
int printPath(int node){

    if(node == source){
                ways = ways + num(node+1) + "..";
      }
    else if(predecessor[node] == -1){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","No existe camino hacia el destino");
}
    else
    {
        printPath(predecessor[node]);
            ways = ways + num(node+1) + "..";
    }

return node+1;
}


int output()
{
    for(int i=0; i<numOfVertices; i++)
    {
        if(i == source){
                //ways = num(source+1) + ".."+num(source+1); ya no es necesaria thanks
            }
        else

           g =  printPath(i);
            if(g==fin){
                run=distance[i];
                wayc=ways;
            }else{
                ways="";
            }

    }
    return run;
}
};

//class funcionesss------------------------------------------------------------------------------------------------------
class nodo{
   public:
    char nombre;//nombre del vertice o nodo
    nodo *sgte;
    class arista *ady;//puntero hacia la primera arista del nodo
    friend class arista;
};

class arista{

public:
    nodo *destino;//puntero al nodo de llegada
    arista *sgte;
    int peso;
    typedef nodo *Tno;//  Tipo Nodo
    typedef arista *Tarista; //Tipo Arista
    Tno p;
    int asgVertice=0;
    int distancia=0;
    QString ways;


    void insertarNodo(char name){
        Tno t,novo=new nodo;
        novo->nombre=name;
        novo->sgte = NULL;
        novo->ady=NULL;

        if(p==NULL)
        {
            p = novo;
        QMessageBox messageBox;
        messageBox.information(0,"listo", "se ha creado");
        }
        else
        {
            t = p;
            while(t->sgte!=NULL)
            {
                t = t->sgte;
            }
            t->sgte = novo;
            QMessageBox messageBox;
        messageBox.information(0,"listo", "se ha creado");
        }

    }


    void agregarArista(Tno &aux, Tno &aux2, Tarista &novo)
    {
        Tarista q;
        if(aux->ady==NULL)
        {
            aux->ady=novo;
            novo->destino=aux2;
            QMessageBox messageBox;
           messageBox.information(0,"Listo", "Se ha creado ruta");
        }
        else
        {
            q=aux->ady;
            while(q->sgte!=NULL)
                q=q->sgte;
            novo->destino=aux2;
            q->sgte=novo;
            QMessageBox messageBox;
            messageBox.information(0,"Listo", "Se ha creado ruta");

        }

    }

    void insertarArista(char inicio, char final, int aPeso)
    {
        int peso;
        int ini, fin;
        Tarista novo=new arista;
        Tno aux, aux2;

        if(p==NULL)
        {
            QMessageBox messageBox;
            messageBox.information(0,"Vacio", "Grafo vacio");
            return;
        }
        novo->sgte=NULL;
        ini=inicio;
        fin=final;

        peso=aPeso;
        novo->peso=peso;
        aux=p;
        aux2=p;
        while(aux2!=NULL)
        {
            if(aux2->nombre==fin)
            {
                break;
            }

            aux2=aux2->sgte;
        }
        while(aux!=NULL)
        {
            if(aux->nombre==ini)
            {
                agregarArista(aux,aux2, novo);
                return;
            }

            aux = aux->sgte;
        }
    }



    int pesoArista(Tno ptr1, Tno ptr2)
    {

        Tarista ar, ar2;

        if(ptr1->ady!=NULL)
        {
            ar=ptr1->ady;
            while(ar!=NULL)
            {

                if (ptr2 !=NULL && ar->destino->nombre==ptr2->nombre)
                {
                    return ar->peso;
                }

                ar=ar->sgte;
            }

        }



        if(ptr2->ady!=NULL)
        {
            ar2=ptr2->ady;
            while(ar2!=NULL)
            {

                if (ptr1 !=NULL && ar2->destino->nombre==ptr1->nombre)
                {
                    return ar2->peso ;
                }

                ar2=ar2->sgte;
            }

        }


        return 0;
    }

    void eliminarNo(char noDel)
    {
        char var;
        Tno aux,ant;
        aux=p;
        if(p==NULL)
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Grafo vacio");
            return;
        }
        var=noDel;

        while(aux!=NULL)
        {
            if(aux->nombre==var)
            {
                if(aux->ady!=NULL)
                    vaciarArista(aux);

                if(aux==p)
                {

                    p=p->sgte;
                    //delete(aux);
                    QMessageBox messageBox;
                    messageBox.information(0,"Eliminado","Nodo Borrado");
                    return;



                }
                else
                {
                    ant->sgte = aux->sgte;
                    //delete(aux);
                    QMessageBox messageBox;
                    messageBox.information(0,"Eliminado","Nodo Borrado");
                    return;
                }
            }
            else
            {
                ant=aux;
                aux=aux->sgte;
            }
        }

    }

    void vaciarArista(Tno &aux)
    {
        Tarista q,r;
        q=aux->ady;
        while(q->sgte!=NULL)
        {
            r=q;
            q=q->sgte;
            delete(r);
        }
    }


    void eliminarArista(char ori, char des)
    {
        char ini, fin;
        Tno aux, aux2;
        Tarista q,r;
        ini=ori;
        fin=des;
        aux=p;
        aux2=p;
        while(aux2!=NULL)
        {
            if(aux2->nombre==fin)
            {
                break;
            }
            else
                aux2=aux2->sgte;
        }
        while(aux!=NULL)
        {
            if(aux->nombre==ini)
            {
                q=aux->ady;
                while(q!=NULL)
                {
                    if(q->destino==aux2)
                    {
                        if(q==aux->ady)
                            aux->ady=aux->ady->sgte;
                        else
                            r->sgte=q->sgte;
                        delete(q);
                        QMessageBox messageBox;
                        messageBox.information(0,"Eliminada" , "Arista Borrada");
                        return;
                    }
                }
                r=q;
                q=q->sgte;
            }
            aux = aux->sgte;
        }
    }


    void dijkstra (int origen,int destino)
    {
        Dijkstra G(origen,destino);
        Tno ptr1, ptr2;

        int contador, j;

        contador = 0;

        j=0;

        ptr1=p;

        while(ptr1!=NULL)
        {
            ptr1=ptr1->sgte;
            contador++;
        }

        int *pesos=(int*) malloc(contador*contador*sizeof(float));


        ptr1=p;

        ptr2=p;

        while(ptr1!=NULL)
        {
            while (ptr2!=NULL)
            {

                pesos[j]=pesoArista(ptr1,ptr2);
                ptr2=ptr2->sgte;
                j++;
            }

            ptr1=ptr1->sgte;
            ptr2=p;
        }


        G.read(contador,pesos);
      G.calculateDistance();
         distancia= G.output();
         this->ways = G.wayc;
    }

};


//-----------------------------------------------------------------------------------------------------
//


bool cambioMenus[6];
int destinos=0;
int distancia=0;
arista ar;

void MainWindow::on_btnMenu_1_clicked()
{

    if(cambioMenus[0]==false){
    ui->gbMenu_2->setVisible(false);
    ui->gbMenu_3->setVisible(false);
    ui->gbMenu_4->setVisible(false);
    ui->gbMenu_5->setVisible(false);
    ui->gbMenu_6->setVisible(false);
    ui->gbMenu_1->setVisible(true);
    cambioMenus[0]=true;
    cambioMenus[1]=cambioMenus[2]=cambioMenus[3]=cambioMenus[4]=cambioMenus[5]=false;
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
    ui->gbMenu_5->setVisible(false);
    ui->gbMenu_6->setVisible(false);
    ui->gbMenu_2->setVisible(true);
    cambioMenus[1]=true;
    cambioMenus[0]=cambioMenus[2]=cambioMenus[3]=cambioMenus[4]=cambioMenus[5]=false;
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
    ui->gbMenu_5->setVisible(false);
    ui->gbMenu_6->setVisible(false);
    ui->gbMenu_3->setVisible(true);
    cambioMenus[2]=true;
    cambioMenus[0]=cambioMenus[1]=cambioMenus[3]=cambioMenus[4]=cambioMenus[5]=false;
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
    ui->gbMenu_5->setVisible(false);
    ui->gbMenu_6->setVisible(false);
    ui->gbMenu_4->setVisible(true);
    cambioMenus[3]=true;
    cambioMenus[0]=cambioMenus[1]=cambioMenus[2]=cambioMenus[4]=cambioMenus[5]=false;
    }else{
        ui->gbMenu_4->setVisible(false);
        cambioMenus[3]=false;
    }
}

void MainWindow::on_btnMenu_5_clicked()
{
    if(cambioMenus[4]==false){
    ui->gbMenu_1->setVisible(false);
    ui->gbMenu_2->setVisible(false);
    ui->gbMenu_3->setVisible(false);
    ui->gbMenu_4->setVisible(false);
    ui->gbMenu_6->setVisible(false);
    ui->gbMenu_5->setVisible(true);
    cambioMenus[4]=true;
    cambioMenus[0]=cambioMenus[1]=cambioMenus[2]=cambioMenus[3]=cambioMenus[5]=false;
    }else{
        ui->gbMenu_5->setVisible(false);
        cambioMenus[4]=false;
    }
}


void MainWindow::on_btnMenu_6_clicked()
{
    if(cambioMenus[5]==false){
    ui->gbMenu_1->setVisible(false);
    ui->gbMenu_2->setVisible(false);
    ui->gbMenu_3->setVisible(false);
    ui->gbMenu_4->setVisible(false);
    ui->gbMenu_5->setVisible(false);
    ui->gbMenu_6->setVisible(true);
    cambioMenus[5]=true;
    cambioMenus[0]=cambioMenus[1]=cambioMenus[2]=cambioMenus[3]=cambioMenus[4]=false;
    }else{
        ui->gbMenu_6->setVisible(false);
        cambioMenus[5]=false;
    }
}

void MainWindow::on_btnMapeo_clicked()
{
    QPoint p = this->mapFromGlobal(QCursor::pos());
    QString text = QInputDialog::getText(this, tr("Nombre"),tr("Ingrese Nombre del Destino"), QLineEdit::Normal);
    QString text2 = QInputDialog::getText(this, tr("Distintivo"),tr("Ingrese distintivo"), QLineEdit::Normal);
    if(text!=""&&text2!=""){
        QString num = QString::number(++destinos);
        text2=text2.at(0).toLower();
        ar.insertarNodo(text2.data()->toLatin1());
        text="'" + text2 + "'" + " " + num +"  "+ text;
        ui->cbDestinosFin->addItem(text);
        ui->cbDestinosIni->addItem(text);
        ui->cbM3DestinoFin->addItem(text);
        ui->cbM3DestinoIni->addItem(text);
        ui->cbDestinosIniDelAris->addItem(text);
        ui->cbDestinosFinDelAris->addItem(text);
        ui->cbDestinosDelNode->addItem(text);
        ui->listDestinos->addItem(text);
        QLabel *dis = new QLabel(num+" "+text2,this);
        QLabel *tmp =new QLabel("",this);
        tmp->setGeometry(p.x()-11,p.y()-34,35,35);
        dis->setGeometry(p.x()-11,p.y(),34,20);
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


void MainWindow::on_btnRuta_clicked()
{
   char p ,f;
   int peso;
   QString c1,c2;
   c1=ui->cbDestinosIni->currentText();
   c2=ui->cbDestinosFin->currentText();
   if(c1 == "Eliminado" || c2 == "Eliminado"){
       QMessageBox messageBox;
       messageBox.critical(0,"Error", "Imposible crear ruta");
   }else{
       p = c1.at(1).toLatin1();
       f = c2.at(1).toLatin1();
       c1=c1.at(1);
       c2=c2.at(1);
       QString adRuta =c1 + "    ->     " + c2 + "      " + ui->spbDistancia->text() + "Millas";
       peso = ui->spbDistancia->value();
       ar.insertarArista(f,p,peso);
       ui->listRutas->addItem(adRuta);
       }
}

void MainWindow::on_btnBuscarRuta_clicked()
{
    int p, f;
    int walk, driver;
    QString walking, drive;
    QString distancia;
    p=ui->cbM3DestinoIni->currentIndex()+1;
    f=ui->cbM3DestinoFin->currentIndex()+1;
    ar.dijkstra(p,f);
    distancia = distancia.number(ar.distancia);
    ui->lbM3PuntosRecorridos->setText(ar.ways);
    ui->lbM3Millas->setText(distancia + " Millas");
    driver = ar.distancia / 0.9;
    walk = ar.distancia / 0.31;
    walking = walking.number(walk);
    drive = drive.number(driver);
    ui->lbM3EnAuto->setText(drive + "Min");
    ui->lbM3Caminando->setText(walking + "Min");
}




void MainWindow::on_btnEliminarArista_clicked()
{
    char ini, fin;
    ini=ui->cbDestinosIniDelAris->currentText().at(1).toLatin1();
    fin=ui->cbDestinosFinDelAris->currentText().at(1).toLatin1();
    ar.eliminarArista(ini,fin);

}

void MainWindow::on_btnEliminarNodo_clicked()
{
    int node;
    char noDel;
    noDel = ui->cbDestinosDelNode->currentText().at(1).toLatin1();
    node = ui->cbDestinosDelNode->currentIndex();
    ar.eliminarNo(noDel);
    ui->cbDestinosFin->setItemText(node,"Eliminado");
    ui->cbDestinosIni->setItemText(node,"Eliminado");
    ui->cbM3DestinoFin->setItemText(node,"Eliminado");
    ui->cbM3DestinoIni->setItemText(node,"Eliminado");
    ui->cbDestinosIniDelAris->setItemText(node,"Eliminado");
    ui->cbDestinosFinDelAris->setItemText(node,"Eliminado");
    ui->cbDestinosDelNode->setItemText(node,"Eliminar");



}
