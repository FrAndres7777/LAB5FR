
#ifndef BOMBER_H
#define BOMBER_H
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsItem>// CONFERERIR CAPACIDAD DE SER OBJETOS VISIBLES


//con QGraficsItem Volvemos BOMBER un Item GRafico
class BOMBER: public QGraphicsItem
{
    //ATRIBUTOs
    int posx,posy,radio,velocidad; //radio tamaño de la figura


public:
    BOMBER();


    BOMBER(int x , int y , int r);
    QRectF boundingRect() const;//LIMITES DEL RECTANGULO QUE DELIMITA TU OBJETO
    //paint como se mostrara pintado
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget= nullptr);

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    int getPosx() const;
    void setPosx(int newPosx);
    int getPosy() const;
    void setPosy(int newPosy);
    int getVelocidad() const;
    void setVelocidad(int newVelocidad);
};

#endif // BOMBER_H
