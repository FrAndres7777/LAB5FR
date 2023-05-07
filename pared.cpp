
#include "pared.h"

int pared::getPosx() const
{
    return posx;
}

void pared::setPosx(int newPosx)
{
    posx = newPosx;
}

int pared::getPosy() const
{
    return posy;
}

void pared::setPosy(int newPosy)
{
    posy = newPosy;
}

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
    QColor myGray(50, 50, 50);
    painter->setBrush(myGray);
    //painter->setBrush(Qt::gray);
    painter->drawRect(boundingRect());
}

