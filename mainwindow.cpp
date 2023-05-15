#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>
#include <list>
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
    Enemigo2 = new ENEMY(575,50,25);
    Enemigo3= new ENEMY(25,275,25);
    Enemigo2->setVelocidad(25);
    //hacer que bomber haga parte del acto (scena)
    scene->addItem(Franklin);
    scene->addItem(Enemigo);
    scene->addItem(Enemigo2);
    scene->addItem(Enemigo3);


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
    timer2 =  new QTimer;
    timer3 =  new QTimer;
    connect(timer2,SIGNAL(timeout()),this, SLOT(moverEnemigo2()));
    connect(timer3,SIGNAL(timeout()),this, SLOT(moverBombas()));
    timer2->stop();
     timer3->stop();

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


    for(int cbloq = 0 ; cbloq < 20 ;cbloq++){
        random_1 = rand() % 11 + 1 ;
        if(random_1%2==0){
            random_2 = rand() % 11 +1;
            paredes2.push_back(new pared2(25+50*random_2,25*random_1,50,50));
            scene->addItem(paredes2.back());
            if(cbloq==5){
                Franklin2 = new BOMBER (25+50*random_2,25*random_1,19);
                scene->addItem(Franklin2);
            }

        }else{
            random_2 = rand() % 20 +2;
            paredes2.push_back(new pared2(25*random_2,25*random_1,50,50));
            scene->addItem(paredes2.back());
            if(cbloq==5){
                Franklin2 = new BOMBER (25*random_2,25*random_1,19);
                scene->addItem(Franklin2);
            }



        }


    }
    //musicPlayer = new QMediaPlayer(this);
    //musicPlaylist = new QMediaPlaylist(this);
    //musicPlaylist->addMedia(QUrl(":/Music/RDRFRAudio.mp3"));  // Ruta del archivo de música en tu proyecto
   // musicPlaylist->setPlaybackMode(QMediaPlaylist::Loop);  // Establece el modo de reproducción (en bucle en este caso)
    //musicPlayer->setPlaylist(musicPlaylist);

}


void MainWindow:: moverEnemigo(){

    moverEnemigo2();
    moverEnemigo3();
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

void MainWindow:: moverEnemigo2(){




    int numero = std::rand() % 4+1;

    switch(numero) {
    case 1:
        Enemigo2->MoveDown();
        if(Franklin->collidesWithItem(Enemigo2))close();
        if(EvaluarColisionE() or  EvaluarColisionE2()){
            Enemigo2->MoveUp();
            if(Franklin->collidesWithItem(Enemigo2))close();
            Enemigo2->MoveUp();
            if(Franklin->collidesWithItem(Enemigo2))close();
            if(EvaluarColisionE() or  EvaluarColisionE2()){
                Enemigo2->MoveDown();
                if(Franklin->collidesWithItem(Enemigo2))close();


                Enemigo2->MoveLeft();
                if(Franklin->collidesWithItem(Enemigo2))close();
                if(EvaluarColisionE() or  EvaluarColisionE2()){
                    Enemigo2->MoveRight();
                    if(Franklin->collidesWithItem(Enemigo2))close();
                    Enemigo2->MoveRight();
                    if(Franklin->collidesWithItem(Enemigo2))close();
                    if(EvaluarColisionE() or  EvaluarColisionE2()){
                        Enemigo2->MoveLeft();
                        if(Franklin->collidesWithItem(Enemigo2))close();
                    }

                }
           }
        }

        break;
    case 2:
        Enemigo2->MoveUp();
        if(Franklin->collidesWithItem(Enemigo2))close();
        if(EvaluarColisionE() or  EvaluarColisionE2()){
             Enemigo2->MoveDown();
           if(Franklin->collidesWithItem(Enemigo2))close();
            Enemigo2->MoveLeft();
           if(Franklin->collidesWithItem(Enemigo2))close();
            if(EvaluarColisionE() or  EvaluarColisionE2()){
                Enemigo2->MoveRight();
                if(Franklin->collidesWithItem(Enemigo2))close();
                Enemigo2->MoveRight();
                if(Franklin->collidesWithItem(Enemigo2))close();
                if(EvaluarColisionE() or  EvaluarColisionE2()){
                    Enemigo2->MoveLeft();
                    if(Franklin->collidesWithItem(Enemigo2))close();
                }
            }
        }

        break;
    case 3:
         Enemigo2->MoveLeft();
        if(Franklin->collidesWithItem(Enemigo2))close();
        if(EvaluarColisionE() or  EvaluarColisionE2()){
             Enemigo2->MoveRight();
            if(Franklin->collidesWithItem(Enemigo2))close();
            Enemigo2->MoveRight();
            if(Franklin->collidesWithItem(Enemigo2))close();
            if(EvaluarColisionE() or  EvaluarColisionE2()){
                Enemigo2->MoveLeft();
                if(Franklin->collidesWithItem(Enemigo2))close();
                Enemigo2->MoveDown();
                if(Franklin->collidesWithItem(Enemigo2))close();
                if(EvaluarColisionE() or  EvaluarColisionE2()){
                    Enemigo2->MoveUp();
                    if(Franklin->collidesWithItem(Enemigo2))close();
                    Enemigo2->MoveRight();
                    if(Franklin->collidesWithItem(Enemigo2))close();
                    if(EvaluarColisionE() or  EvaluarColisionE2()){
                        Enemigo2->MoveLeft();
                        if(Franklin->collidesWithItem(Enemigo2))close();
                    }
                }
            }
        }
        break;
    case 4:
        Enemigo2->MoveRight();
        if(Franklin->collidesWithItem(Enemigo2))close();
        if(EvaluarColisionE() or  EvaluarColisionE2()){
            Enemigo2->MoveLeft();
            if(Franklin->collidesWithItem(Enemigo2))close();
            Enemigo2->MoveLeft();
            if(Franklin->collidesWithItem(Enemigo2))close();
            if(EvaluarColisionE() or  EvaluarColisionE2()){
                Enemigo2->MoveRight();
                if(Franklin->collidesWithItem(Enemigo2))close();
                Enemigo2->MoveDown();
                if(Franklin->collidesWithItem(Enemigo2))close();

                if(EvaluarColisionE() or  EvaluarColisionE2()){
                    Enemigo2->MoveUp();
                    if(Franklin->collidesWithItem(Enemigo2))close();
                    Enemigo2->MoveRight();
                    if(Franklin->collidesWithItem(Enemigo2))close();
                    if(EvaluarColisionE() or  EvaluarColisionE2()){
                        Enemigo2->MoveLeft();
                        if(Franklin->collidesWithItem(Enemigo2))close();
                    }
                }
            }
        }



        break;



    }
}

void MainWindow::moverEnemigo3()
{
    int xE= 0, yE = 0, xJ= 0, yJ = 0;
    xE= Enemigo3->getPosx();
    yE = Enemigo3->getPosy();
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
            Enemigo3->MoveRight();

        }else{
            Enemigo3->MoveLeft();
        }
    }else{
        if(yE-yJ<0){
            Enemigo3->MoveDown();
        }else{
            Enemigo3->MoveUp();
        }
    }

}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{


    imprimirpPuntaje();
    if(Franklin->collidesWithItem(Enemigo3) or Franklin->collidesWithItem(Enemigo2) or Franklin->collidesWithItem(Franklin2)){
        close();
    }
    if(evento->key()==Qt::Key_W)
    {

        if(!EvaluarColision() and !EvaluarColision2()){
            Franklin->MoveUp();

            if(EvaluarColision() or EvaluarColision2()){
                Franklin->MoveDown();
            }

        }

    }

    else if(evento->key()==Qt::Key_S)
    {
        if(!EvaluarColision() and !EvaluarColision2()){
            Franklin->MoveDown();
            if(EvaluarColision() or EvaluarColision2()){
                Franklin->MoveUp();
            }
        }
    }
    else if(evento->key()==Qt::Key_D)
    {
        if(!EvaluarColision() and !EvaluarColision2()){
            Franklin->MoveRight();
            if(EvaluarColision() or EvaluarColision2()){
                Franklin->MoveLeft();
            }
        }
    }
    else if(evento->key()==Qt::Key_A)
    {
        if(!EvaluarColision() and !EvaluarColision2()){
            Franklin->MoveLeft();
            if(EvaluarColision() or EvaluarColision2()){
                Franklin->MoveRight();
            }
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
        // GRANADAS_EXPLOXION.clear();






        GRANADAS_FUEGO.push_back(new BOMBA(Franklin->getPosx(),Franklin->getPosy(),40,40));
        scene->addItem(GRANADAS_FUEGO.back());
        //INCINERAR();
        QTimer::singleShot(4000,this, SLOT(INCINERAR()));



   }
   if(evento->key()== Qt::Key_M){

        if(timer->isActive()) {timer->stop();
        }else {timer->start(50);
            }

        if(timer2->isActive()) {
            timer2->stop();
        }else{
            timer2->start(3000);

        }

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
bool MainWindow::EvaluarColisionE()
{
    QList<pared*>::Iterator it;
    for(it=paredes.begin();it!= paredes.end();it++){
        if((*it)->collidesWithItem(Enemigo2))
        {
            return true;
        }
    }
    return false;


}

bool MainWindow::EvaluarColisionE2()
{
    QList<pared2*>::Iterator it;
    for(it=paredes2.begin();it!= paredes2.end();it++){
        if((*it)->collidesWithItem(Enemigo2))
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



    for(auto it = GRANADAS_FUEGO.begin(); it != GRANADAS_FUEGO.end();it++){
        //scene->removeItem(*it);
        int x= (*it)->getPosx();
        int y = (*it)->getPosy();
        for(float i = 1.0; i<28.0;i=i+7.5){
            GRANADAS_EXPLOXION.push_front(new BOMBA((x+25+i),y,40,40));
            scene->addItem(GRANADAS_EXPLOXION.front());

            GRANADAS_EXPLOXION.push_front(new BOMBA((x-25-i),y,40,40));
            scene->addItem(GRANADAS_EXPLOXION.front());

            GRANADAS_EXPLOXION.push_front(new BOMBA((x),y+25+i,40,40));
            scene->addItem(GRANADAS_EXPLOXION.front());

            GRANADAS_EXPLOXION.push_front(new BOMBA((x),y-25-i,40,40));
            scene->addItem(GRANADAS_EXPLOXION.front());

        }
    }
     EvaluarColision3();



}

void MainWindow::EvaluarColision3()
{
    QList<pared2*>::Iterator it;
    int contador =0;
    for(it=paredes2.begin();it!= paredes2.end();it++){
        contador =0;
        for(auto it2 =GRANADAS_EXPLOXION.begin();  it2!= GRANADAS_EXPLOXION.end() and contador <16; it2++,contador++){


            if((*it)->collidesWithItem(*it2)){
                scene->removeItem(*it);
                paredes2.removeOne(*it);
                puntaje+=750;

            }
            if((*it2)->collidesWithItem(Enemigo)){

                Enemigo= new ENEMY(0,0,0);
                Enemigo->setVelocidad(0);
                Enemigo->setPos(0,0);
                scene->removeItem(Enemigo); // Elimina el objeto de la escena
                //delete Enemigo; // Elimina el objeto de la memoria
                //Enemigo = nullptr; // Asigna un puntero nulo para evitar problemas de punteros invalidos
                break;

            }

            if((*it2)->collidesWithItem(Enemigo2)){
                Enemigo2= new ENEMY(0,0,0);
                Enemigo2->setVelocidad(0);
                Enemigo2->setPos(0,0);
                scene->removeItem(Enemigo2); // Elimina el objeto de la escena
                //delete Enemigo2; // Elimina el objeto de la memoria
                //Enemigo2 = nullptr; // Asigna un puntero nulo para evitar problemas de punteros invalidos
                break;

                }
        }
    }



    return;




}

void MainWindow::VaciarListas()
{
    for(auto it = GRANADAS_FUEGO.begin(); it != GRANADAS_FUEGO.end();it++){
        scene->removeItem(*it);

        delete *it;
        *it = nullptr;
    }
    GRANADAS_FUEGO.removeAll(nullptr);


}

void MainWindow::VaciarListas2()
{
    for(auto it2 = GRANADAS_EXPLOXION.begin(); it2 != GRANADAS_EXPLOXION.end();it2++){
        scene->removeItem(*it2);
        delete *it2;
        *it2 = nullptr;
    }
    GRANADAS_EXPLOXION.removeAll(nullptr);
}




