#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsItem>
#ifndef PARED_H
#define PARED_H

class pared :  public QGraphicsItem
{
    int posx,posy,alto,bajo;
public:
    pared();
    pared(int x, int y , int alto , int bajo);
    QRectF boundingRect() const;//LIMITES DEL RECTANGULO QUE DELIMITA TU OBJETO
    //paint como se mostrara pintado
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget= nullptr);

    int getPosx() const;
    void setPosx(int newPosx);
    int getPosy() const;
    void setPosy(int newPosy);
};

#endif // PARED_H
