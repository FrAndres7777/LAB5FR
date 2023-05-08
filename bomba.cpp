
#include "bomba.h"

BOMBA::BOMBA()
{

}
int BOMBA::getPosx() const
{
    return posx;
}

void BOMBA::setPosx(int newPosx)
{
    posx = newPosx;
}

int BOMBA::getPosy() const
{
    return posy;
}

void BOMBA::setPosy(int newPosy)
{
    posy = newPosy;
}



BOMBA::BOMBA(int x, int y, int alto, int bajo)
{
    this->posx=x;
    this->posy=y;
    this->alto=alto;
    this->bajo=bajo;
    setPos(posx,posy);
}

QRectF BOMBA::boundingRect() const
{
    return QRect(posx,posy,alto,bajo);
}

void BOMBA::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap ninja(":/imagen/fuego.png");
    painter->drawPixmap(boundingRect(),ninja,ninja.rect());


}



