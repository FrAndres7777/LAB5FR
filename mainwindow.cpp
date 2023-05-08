
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();//LA INICIALIZAMOS COMO OBJETO
    //ahora lo asociamos al grafics view
    ui->graphicsView->setScene(scene);
    // los valores de la scena respecro a grafic view
    scene->setSceneRect(0,0,1200,650);
    //CREAMOS EL BOMBER
    Franklin = new BOMBER (25,25,20);
    Enemigo = new ENEMY(575,275,25);
    //hacer que bomber haga parte del acto (scena)
    scene->addItem(Franklin);
    scene->addItem(Enemigo);


    paredes.push_back(new pared(0,0,1200,50));
    scene->addItem(paredes.back());

    paredes.push_back(new pared(0,0,50,650));
    scene->addItem(paredes.back());

    paredes.push_back(new pared(600,0,50,650));
    scene->addItem(paredes.back());

    paredes.push_back(new pared(0,300,1200,50));
    scene->addItem(paredes.back());

    timer =  new QTimer;
    connect(timer,SIGNAL(timeout()),this, SLOT(moverEnemigo()));
    timer->stop();






    for(int i = 0 ; i < 7 ; i++){
        for(int j = 0 ; j< 13 ;j++){
            paredes.push_back(new pared(50*j,50*i,50,50));
            scene->addItem(paredes.back());

        }
    }


    // Generamos mapa aleatorio

    srand(time(NULL));


    // Generar un número aleatorio en el rango de __ a __
    int random_1 = 0;
    int random_2 = 0;


    for(int cbloq = 0 ; cbloq < 45 ;cbloq++){
        random_1 = rand() % 11 + 1 ;
        if(random_1%2==0){
            random_2 = rand() % 11 +1;
            paredes2.push_back(new pared2(25+50*random_2,25*random_1,50,50));
            scene->addItem(paredes2.back());
        }else{
            random_2 = rand() % 21 +2;
            paredes2.push_back(new pared2(25*random_2,25*random_1,50,50));
            scene->addItem(paredes2.back());


        }

    }








}


void MainWindow:: moverEnemigo(){
    int xE= 0, yE = 0, xJ= 0, yJ = 0;
    xE= Enemigo->getPosx();
    yE = Enemigo->getPosy();
    xJ= Franklin->getPosx();
    yJ = Franklin->getPosy();
    int Dx=0,Dy=0;
    if(xE-xJ<0){
        Dx=(xE-xJ)*(-1);
    }else{
        Dx=(xE-xJ);
    }

    if(yE-yJ<0){
        Dy=(yE-yJ)*(-1);
    }else{
        Dy=(yE-yJ);
    }
    if(Dx>Dy){
        if(xE-xJ<0){
            Enemigo->MoveRight();

        }else{
            Enemigo->MoveLeft();
        }
    }else{
        if(yE-yJ<0){
            Enemigo->MoveDown();
        }else{
            Enemigo->MoveUp();
        }
    }





}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{

    //int x,y;
    //x=Franklin->getPosx();
    //y=Franklin->getPosy();
    imprimirpPuntaje();

    if(evento->key()==Qt::Key_W)
    {
        if(!EvaluarColision() and !EvaluarColision2()){
            Franklin->MoveUp();

        }else{
            Franklin->MoveDown();
            //Franklin->setPos(x,y+10);

        }

    }

    else if(evento->key()==Qt::Key_S)
    {
        if(!EvaluarColision() and !EvaluarColision2()){
            Franklin->MoveDown();

        }else{
            Franklin->MoveUp();
        }

    }
    else if(evento->key()==Qt::Key_D)
    {
        if(!EvaluarColision() and !EvaluarColision2()){
            Franklin->MoveRight();

        }else{
            Franklin->MoveLeft();
        }

    }
    else if(evento->key()==Qt::Key_A)
    {
        if(!EvaluarColision() and !EvaluarColision2()){

            Franklin->MoveLeft();






        }else{

            Franklin->MoveRight();


        }

   }else if(evento->key()==Qt::Key_Space){
        for(auto it = GRANADAS_FUEGO.begin(); it != GRANADAS_FUEGO.end();it++){
            scene->removeItem(*it);
        }
        GRANADAS_FUEGO.clear();

        for(auto it2 = GRANADAS_EXPLOXION.begin(); it2 != GRANADAS_EXPLOXION.end();it2++){
            scene->removeItem(*it2);
        }
        GRANADAS_EXPLOXION.clear();

        GRANADAS_FUEGO.push_back(new BOMBA(Franklin->getPosx(),Franklin->getPosy(),40,40));
        scene->addItem(GRANADAS_FUEGO.back());
        //INCINERAR();
        QTimer::singleShot(4000,this, SLOT(INCINERAR()));






   }
   if(evento->key()== Qt::Key_M){
        if(timer->isActive()) timer->stop();
        else timer->start(50);

   }
}

void MainWindow::imprimirpPuntaje()
{
   QString score =QString( "POINTSS %1 ").arg(puntaje);
   ui->lblPuntaje->setText(score);
}

bool MainWindow::EvaluarColision()
{
    QList<pared*>::Iterator it;
    for(it=paredes.begin();it!= paredes.end();it++){
        if((*it)->collidesWithItem(Franklin))
        {
            return true;
        }
    }
    return false;
}

bool MainWindow::EvaluarColision2()
{
    QList<pared2*>::Iterator it;
    for(it=paredes2.begin();it!= paredes2.end();it++){
        if((*it)->collidesWithItem(Franklin))
        {

            //scene->removeItem(*it);
            //paredes2.removeOne(*it);
            return true;
        }
    }
    return false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::INCINERAR()
{
    //GRANADAS_EXPLOXION.push_back( new BOMBA(25,50,10,10));
    //scene->addItem(GRANADAS_EXPLOXION.back());
    for(auto it = GRANADAS_FUEGO.begin(); it != GRANADAS_FUEGO.end();it++){
        //scene->removeItem(*it);
        int x= (*it)->getPosx();
        int y = (*it)->getPosy();
        for(float i = 1.0; i<28.0;i=i+7.5){
            GRANADAS_EXPLOXION.push_back(new BOMBA((x+25+i),y,40,40));
            scene->addItem(GRANADAS_EXPLOXION.back());

            GRANADAS_EXPLOXION.push_back(new BOMBA((x-25-i),y,40,40));
            scene->addItem(GRANADAS_EXPLOXION.back());

            GRANADAS_EXPLOXION.push_back(new BOMBA((x),y+25+i,40,40));
            scene->addItem(GRANADAS_EXPLOXION.back());

            GRANADAS_EXPLOXION.push_back(new BOMBA((x),y-25-i,40,40));
            scene->addItem(GRANADAS_EXPLOXION.back());
        }
    }
    EvaluarColision3();
    //QTimer::singleShot(1000,this, SLOT(VaciarListas()));

}

void MainWindow::EvaluarColision3()
{
    QList<pared2*>::Iterator it;
    for(it=paredes2.begin();it!= paredes2.end();it++){
        for(auto it2 =GRANADAS_EXPLOXION.begin();  it2!= GRANADAS_EXPLOXION.end(); it2++){
            if((*it)->collidesWithItem(*it2)){
                scene->removeItem(*it);
                paredes2.removeOne(*it);
                puntaje+=750;

            }
        }
    }
    // QTimer::singleShot(500,this, SLOT(VaciarListas()));




    return ;

}

void MainWindow::VaciarListas()
{
    for(auto it = GRANADAS_FUEGO.begin(); it != GRANADAS_FUEGO.end();it++){
        scene->removeItem(*it);
    }
    //GRANADAS_FUEGO.clear();

    for(auto it2 = GRANADAS_EXPLOXION.begin(); it2 != GRANADAS_EXPLOXION.end();it2++){
        scene->removeItem(*it2);
    }
    //GRANADAS_EXPLOXION.clear();
}


//scene->removeItem(*it);
//paredes2.removeOne(*it);




