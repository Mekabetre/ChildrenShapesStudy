#ifndef STAR_H
#define STAR_H

#include <Model/shape.h>

class Star: public Shape
{
public:
    Star(int _width = 200, int _height = 70);
    void SetName();
    void SetPoints();
};

#endif // STAR_H
