#ifndef SHAPEHELPER_H
#define SHAPEHELPER_H

#include "Model/shape.h"
#include "Model/triangle.h"

class ShapeHelper
{
public:
    static Shape* GetShape(int id);
};

#endif // SHAPEHELPER_H
