#include "rect.h"

Rect::Rect(int _width, int _height) : Shape(_width, _height)
{
    SetName();
    SetPoints();
}

void Rect::SetName()
{
    this->shapeID = 1;
    this->name = QObject::tr("长方形");
}

void Rect::SetPoints()
{
    QPointF point1;
    QPointF point2;
    QPointF point3;
    QPointF point4;
    while(1)
    {
        point1 = GetPoint();
        double ptpdistance;
        while(1)
        {
            point2 = GetPoint();
            ptpdistance = GetDistance(point1, point2);
            if(ptpdistance >= 25)
                break;
        }

        point3.setX(point1.x() + (point1.y() - point2.y()));
        point3.setY(point1.y() - (point1.x() - point2.x()));
        point4.setX(point2.x() + (point1.y() - point2.y()));
        point4.setY(point2.y() + (point3.y() - point1.y()));

        double scale = (qrand() % 8 + 8.0) / 20.0;//(8~16) /

        point3 = point3 + scale*(point3 - point1);//x y均按照等比例变化
        point4 = point4 + scale*(point4 - point2);


        if(IsInTheRange(point4) && IsInTheRange(point3))
            break;
    }
    this->points.push_back(point1);
    this->points.push_back(point2);
    this->points.push_back(point4);
    this->points.push_back(point3);
}
