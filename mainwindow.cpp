
#include "mainwindow.h"
#include "ui_mainwindow.h"


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
    Franklin = new BOMBER (25,25,25);
    //hacer que bomber haga parte del acto (scena)
    scene->addItem(Franklin);

    paredes.push_back(new pared(0,0,1200,50));
    scene->addItem(paredes.back());

    paredes.push_back(new pared(0,0,50,650));
    scene->addItem(paredes.back());

    paredes.push_back(new pared(600,0,50,650));
    scene->addItem(paredes.back());

    paredes.push_back(new pared(0,300,1200,50));
    scene->addItem(paredes.back());





}
void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_W)
    {
        if(!EvaluarColision()){
            Franklin->MoveUp();

        }else{
            Franklin->MoveDown();
        }

    }

    else if(evento->key()==Qt::Key_2)
    {
        Franklin->MoveDown();
    }
    else if(evento->key()==Qt::Key_3)
    {
        Franklin->MoveRight();
    }
    else if(evento->key()==Qt::Key_1)
    {
        Franklin->MoveLeft();
    }
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

MainWindow::~MainWindow()
{
    delete ui;
}




