#include "triangle.h"
#include <cmath>

Triangle::Triangle(int _width, int _height) : Shape(_width, _height)
{
    this->SetPoints();
    SetName();
}

void Triangle::SetName()
{
    this->shapeID = 3;
    this->name = QObject::tr("三角形");
}

void Triangle::SetPoints()
{
    QPointF point1;
    QPointF point2;
    QPointF point3;
    while(1){
        point1 = GetPoint();
        point2 = GetPoint();
        if(GetDistance(point1, point2) > 25)
            break;
    }
    double l1, l2, l3;
    this->points.push_back(point1);
    this->points.push_back(point2);
    while(1){
        point3 = GetPoint();
        l1 = GetDistance(point1, point2);
        l2 = GetDistance(point1, point3);
        l3 = GetDistance(point2, point3);
        if(l1 + l2 > l3 && abs(l1 - l2) < l3 && PointToLineDistance(point3, point1, point2) > 25){
            this->points.push_back(point3);
            break;
        }
    }
}
