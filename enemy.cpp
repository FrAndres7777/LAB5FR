
#include "enemy.h"


//con QGraficsItem Volvemos BOMBER un Item GRafico
int ENEMY::getPosx() const
{
    return posx;
}

void ENEMY::setPosx(int newPosx)
{
    posx = newPosx;
}

int ENEMY::getPosy() const
{
    return posy;
}

void ENEMY::setPosy(int newPosy)
{
    posy = newPosy;
}

int ENEMY::getVelocidad() const
{
    return velocidad;
}

void ENEMY::setVelocidad(int newVelocidad)
{
    velocidad = newVelocidad;
}

ENEMY::ENEMY()
{
    this->radio=25;
    this->velocidad=5;

}


ENEMY::ENEMY(int x, int y, int r)
{
    // ASIGNACION DE VALORES DE BOMBER
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=1.5;
    setPos(posx,posy);
}

QRectF ENEMY::boundingRect() const
{
    return QRectF(posx,posy,2*radio,2*radio);
}

void ENEMY::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::red);
    //painter->drawEllipse(boundingRect());
    QPixmap ninja(":/imagen/fantasma.png");
    painter->drawPixmap(boundingRect(),ninja,ninja.rect());


}

void ENEMY::MoveUp()
{
    posy-=velocidad;
    setPos(posx, posy);
}

void ENEMY::MoveDown()
{
    posy+=velocidad;
    setPos(posx, posy);
}

void ENEMY::MoveLeft()
{
    posx-=velocidad;
    setPos(posx, posy);
}

void ENEMY::MoveRight()
{
    posx+=velocidad;
    setPos(posx, posy);
}


