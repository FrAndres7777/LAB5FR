
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
    scene->setSceneRect(0,0,1400,750);
    //CREAMOS EL BOMBER
    Franklin = new BOMBER (100,100,25);
    //hacer que bomber haga parte del acto (scena)
    scene->addItem(Franklin);


}
void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_W)
    {
        Franklin->MoveUp();
    }

    else if(evento->key()==Qt::Key_S)
        Franklin->MoveDown();
    else if(evento->key()==Qt::Key_D)
        Franklin->MoveRight();
    else if(evento->key()==Qt::Key_A)
        Franklin->MoveLeft();
}

MainWindow::~MainWindow()
{
    delete ui;
}




