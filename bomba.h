#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsItem>


#ifndef  BOMBA_H
#define  BOMBA_H






class BOMBA: public QGraphicsItem
{

     int posx,posy,alto,bajo;

public:
    BOMBA();

    BOMBA(int x, int y , int alto , int bajo);
    QRectF boundingRect() const;//LIMITES DEL RECTANGULO QUE DELIMITA TU OBJETO
    //paint como se mostrara pintado
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget= nullptr);

    int getPosx() const;
    void setPosx(int newPosx);
    int getPosy() const;
    void setPosy(int newPosy);
};

#endif // BOMBA_H











