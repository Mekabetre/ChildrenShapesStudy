#include "moon.h"

Moon::Moon(int _width, int _height) : Shape(_width, _height)
{
    SetName();
    SetPoints();
}

void Moon::SetName()
{
    this->shapeID = 6;
    this->name = QObject::tr("月牙形");
}

void Moon::SetPoints()
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
            if(ptpdistance >= 35)
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
    this->points.push_back((point3 + point4) / 2);

    double scale = (qrand() % 8 + 8.0) / 20.0;//(8~16) /
    point3 = point3 - scale*(point3 - point1);//x y均按照等比例变化
    point4 = point4 - scale*(point4 - point2);
    this->points.push_back((point3 + point4) / 2);
}

void Moon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPainterPath path;
    QBrush brush(this->color);
    vector<QPointF>::iterator e = this->points.begin();
    path.moveTo(*e);
    path.quadTo(*(e + 2), *(e + 1));
    path.moveTo(*e);
    path.quadTo(*(e + 3), *(e + 1));
    painter->fillPath(path, brush);
}
