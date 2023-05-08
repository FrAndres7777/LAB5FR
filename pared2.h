
#ifndef PARED2_H
#define PARED2_H
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsItem>


class pared2 : public QGraphicsItem
{
    int posx,posy,alto,bajo;
public:
    pared2();
    pared2(int x, int y , int alto , int bajo);//ancho el back
    QRectF boundingRect() const;//LIMITES DEL RECTANGULO QUE DELIMITA TU OBJETO
    //paint como se mostrara pintado
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget= nullptr);

    int getPosx() const;
    void setPosx(int newPosx);
    int getPosy() const;
    void setPosy(int newPosy);
};

#endif // PARED2_H
