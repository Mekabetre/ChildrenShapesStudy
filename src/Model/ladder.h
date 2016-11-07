#ifndef LADDER_H
#define LADDER_H

#include "Model/shape.h"

class Ladder : public Shape
{
public:
    Ladder(int _width = 200, int _height = 70);
    void SetName();
    void SetPoints();
};

#endif // LADDER_H
