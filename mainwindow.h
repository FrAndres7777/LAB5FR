
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene >
#include <QKeyEvent>
#include <QTimer>
#include <enemy.h>
#include <bomber.h>
#include <pared.h>
#include <pared2.h>
#include <QList>
#include <bomba.h>
#include <QDebug>

#include <QGraphicsRectItem>

#include <QMediaPlayer>
#include <QFileInfo>
#include <QFile>


//#include <QMediaPlaylist>





QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class  QMediaPlayer;

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void INCINERAR();
    void moverEnemigo();
    void moverEnemigo2();
    void moverEnemigo3();


    void on_Abrir_clicked();

    void on_Pause_clicked();

    void on_Play_clicked();

    void on_Stop_clicked();

    void on_verticalSlider_valueChanged(int value);

private:

    Ui::MainWindow *ui;// *UI PUNTERO A LA INTERFAZ GRA  // REFERNCIA PARA CADA UNO DE LOS OBJETOS
    QGraphicsScene *scene; // instanciamos scena
    //creamos el objeto B00omberr
    BOMBER *Franklin;// jugador principal
    BOMBER *Franklin2;//compañero a encontar
    ENEMY  *Enemigo;// neas fantasmas
    ENEMY  *Enemigo2;// nea 2
     ENEMY  *Enemigo3;// nea 3

    void keyPressEvent(QKeyEvent *evento);
    QList<pared*> paredes;

    QTimer *timer;
    QTimer *timer2;
    QTimer *timer3;

    QList<pared2*> paredes2;
    void imprimirpPuntaje();
    bool EvaluarColision();
    bool EvaluarColision2();
    void EvaluarColision3();
    bool EvaluarColisionE();
    bool EvaluarColisionE2();
    void VaciarListas();
    void VaciarListas2();
    void moverBombas();

    //sonido
    //QMediaPlayer *sound;

    QMediaPlayer *sound;

    //QMediaPlaylist *musicPlaylist;


    int puntaje=0;



    QList<BOMBA*> GRANADAS_FUEGO;
    QList<BOMBA*> GRANADAS_EXPLOXION;



};

#endif // MAINWINDOW_H
