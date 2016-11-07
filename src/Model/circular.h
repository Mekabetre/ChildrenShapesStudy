#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "Model/shape.h"
#include <QRectF>

class Circular: public Shape
{
public:
    Circular(int _width = 200, int _height = 70);
    void SetName();
    void SetPoints();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getRadius() const;
    void setRadius(int value);

private:
    int radius;
};

#endif // CIRCULAR_H
