
#include "pared2.h"

int pared2::getPosx() const
{
    return posx;
}

void pared2::setPosx(int newPosx)
{
    posx = newPosx;
}

int pared2::getPosy() const
{
    return posy;
}

void pared2::setPosy(int newPosy)
{
    posy = newPosy;
}

pared2::pared2()
{

}

pared2::pared2(int x, int y, int alto, int bajo)
{
    this->posx=x;
    this->posy=y;
    this->alto=alto;
    this->bajo=bajo;
    setPos(posx,posy);
}

QRectF pared2::boundingRect() const
{
    return QRect(posx,posy,alto,bajo);
}

void pared2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::gray);
    //painter->drawRect(boundingRect());
    QPixmap ninja(":/imagen/pared-de-ladrillo.png");
    painter->drawPixmap(boundingRect(),ninja,ninja.rect());

}
