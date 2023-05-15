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

    BOMBA(int x, int y , int alto , int bajo);
    QRectF boundingRect() const;//LIMITES DEL RECTANGULO QUE DELIMITA TU OBJETO
    //paint como se mostrara pintado
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget= nullptr);

    float getPosx() const;
    void setPosx(int newPosx);
    float getPosy() const;
    void setPosy(int  newPosy);

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void posicion(int newX,int newY);
    void shot(int velx ,int vel);
};

#endif // BOMBA_H











