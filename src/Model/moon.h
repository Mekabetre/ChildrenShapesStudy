#ifndef MOON_H
#define MOON_H

#include <Model/shape.h>
#include <QRectF>

class Moon : public Shape
{
public:
    Moon(int _width = 200, int _height = 70);
    void SetName();
    void SetPoints();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MOON_H
