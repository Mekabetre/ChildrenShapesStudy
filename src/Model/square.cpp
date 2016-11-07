#include "square.h"
#include <QPointF>

Square::Square(int _width, int _height) : Shape(_width, _height)
{
    SetPoints();
    SetName();
}

void Square::SetName()
{
    this->shapeID = 0;
    this->name = QObject::tr("正方形");
}

void Square::SetPoints()
{

    QPointF point1;
    QPointF point2;
    QPointF point3;
    QPointF point4;
    while(1)
    {
        point1 = GetPoint();
        while(1)
        {
            point2 = GetPoint();
            if(GetDistance(point1, point2) >= 25)
                break;
        }

        point3.setX(point1.x() + (point1.y() - point2.y()));
        point3.setY(point1.y() - (point1.x() - point2.x()));
        point4.setX(point2.x() + (point1.y() - point2.y()));
        point4.setY(point2.y() + (point3.y() - point1.y()));
        if(IsInTheRange(point4) && IsInTheRange(point3))
            break;
    }
    this->points.push_back(point1);
    this->points.push_back(point2);
    this->points.push_back(point4);
    this->points.push_back(point3);
}
