
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene >
#include <QKeyEvent>
#include <QTimer>

#include <bomber.h>

#include <QGraphicsRectItem>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow *ui;// *UI PUNTERO A LA INTERFAZ GRA  // REFERNCIA PARA CADA UNO DE LOS OBJETOS
    QGraphicsScene *scene; // instanciamos scena
    //creamos el objeto B00omberr
    BOMBER *Franklin;
    void keyPressEvent(QKeyEvent *evento);

    QTimer *timer;


};

#endif // MAINWINDOW_H
