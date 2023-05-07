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

};

#endif // PARED_H
