#include "shapehelper.h"
#include "Model/square.h"
#include "Model/rect.h"
#include "Model/circular.h"
#include "Model/ladder.h"
#include "Model/star.h"
#include "Model/moon.h"

Shape *ShapeHelper::GetShape(int id)
{
    switch(id){
    case 0:
        return new Square;
    case 1:
        return new Rect;
    case 2:
        return new Circular(200 - 50, 150 - 50);
    case 3:
        return new Triangle;
    case 4:
        return new Ladder;
    case 5:
        return new Star;
    case 6:
        return new Moon;
    default:
        return NULL;
    }
}
