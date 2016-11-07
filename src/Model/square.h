#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square:public Shape
{
public:
    Square(int _width = 200, int _height = 70);
    void SetName();
    void SetPoints();
};

#endif // SQUARE_H
