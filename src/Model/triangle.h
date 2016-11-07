#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <QPainter>

class Triangle : public Shape
{
public:
    Triangle(int _width = 200, int _height = 70);
    void SetName();
    void SetPoints();
};

#endif // TRIANGLE_H
