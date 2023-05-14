#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsItem>


#ifndef  BOMBA_H
#define  BOMBA_H






class BOMBA: public QGraphicsItem
{

     int posx,posy,alto,bajo,velocidad=5;

public:
    BOMBA();

    BOMBA(float x, float y , int alto , int bajo);
    QRectF boundingRect() const;//LIMITES DEL RECTANGULO QUE DELIMITA TU OBJETO
    //paint como se mostrara pintado
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget= nullptr);

    float getPosx() const;
    void setPosx(float newPosx);
    float getPosy() const;
    void setPosy(float  newPosy);

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void posicion(float newX, float newY);
    void shot(float velx ,float vel);
};

#endif // BOMBA_H











