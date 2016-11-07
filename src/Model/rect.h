#ifndef RECT_H
#define RECT_H

#include <Model/shape.h>

class Rect:public Shape
{
public:
    Rect(int _width = 200, int _height = 70);
    void SetName();
    void SetPoints();
};

#endif // RECT_H
