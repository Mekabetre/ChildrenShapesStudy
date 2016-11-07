#include "ladder.h"

Ladder::Ladder(int _width, int _height) : Shape(_width, _height)
{
    SetName();
    SetPoints();
}

void Ladder::SetName()
{
    this->shapeID = 4;
    this->name = QObject::tr("梯形");
}

void Ladder::SetPoints()
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
            if(ptpdistance >= 45)
                break;
        }

        point3.setX(point1.x() + (point1.y() - point2.y()));
        point3.setY(point1.y() - (point1.x() - point2.x()));
        point4.setX(point2.x() + (point1.y() - point2.y()));
        point4.setY(point2.y() + (point3.y() - point1.y()));

        QPointF temp;
        temp = point3;

        double scale = (qrand() % 5 + 3.0) / 14.0;
        point3 = point3 + scale*(point4 - point3);

        scale = (qrand() % 5 + 3.0) / 16.0;
        point4 = point4 - scale*(point4 - temp);


        if(IsInTheRange(point4) && IsInTheRange(point3))
            break;
    }
    this->points.push_back(point1);
    this->points.push_back(point2);
    this->points.push_back(point4);
    this->points.push_back(point3);
}
