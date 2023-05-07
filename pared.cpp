
#include "pared.h"

pared::pared()
{

}

pared::pared(int x, int y, int alto, int bajo)
{
    this->posx=x;
    this->posy=y;
    this->alto=alto;
    this->bajo=bajo;
    setPos(posx,posy);
}

QRectF pared::boundingRect() const
{
    return QRect(posx,posy,alto,bajo);
}

void pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::gray);
    painter->drawRect(boundingRect());
}

