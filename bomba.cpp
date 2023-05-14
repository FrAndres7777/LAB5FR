
#include "bomba.h"

BOMBA::BOMBA()
{

}
float BOMBA::getPosx() const
{
    return posx;
}

void BOMBA::setPosx(float newPosx)
{
    posx = newPosx;
}

float BOMBA::getPosy() const
{
    return posy;
}

void BOMBA::setPosy(float newPosy)
{
    posy = newPosy;
}

void BOMBA::MoveUp()
{
    posy-=velocidad;
    setPos(posx, posy);
}

void BOMBA::MoveDown()
{
    posy+=velocidad;
    setPos(posx, posy);
}

void BOMBA::MoveLeft()
{
    posx-=velocidad;
    setPos(posx, posy);
}

void BOMBA::MoveRight()
{
    posx+=velocidad;
    setPos(posx, posy);
}



BOMBA::BOMBA(float x, float y, int alto, int bajo)
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

void BOMBA::posicion(float newX, float newY)
{
    posx=newX;
    posy=newY;
    setPos(posx,posy);
}

void BOMBA::shot(float velx,float vel)
{
    posicion(posx+velx,posy+vel);
}



