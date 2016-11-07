#include "circular.h"

Circular::Circular(int _width, int _height) : Shape(_width, _height)
{
    SetName();
    SetPoints();
}

void Circular::SetName()
{
    this->shapeID = 2;
    this->name = QObject::tr("圆形");
}

void Circular::SetPoints()
{
    this->radius = qrand() % 50 + 50;

    QPointF point;
    while(1){
        point = GetPoint();

        QPointF point1(point.x(), point.y() + this->radius);
        QPointF point2(point.x(), point.y() - this->radius);
        QPointF point3(point.x() + this->radius, point.y());
        QPointF point4(point.x() - this->radius, point.y());

        if(IsInTheRange(point1) && IsInTheRange(point2) && IsInTheRange(point3) && IsInTheRange(point4)){
            this->points.push_back(point);
            break;
        }
    }
}

void Circular::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPainterPath path;
    QBrush brush(this->color);
    path.moveTo(*this->points.begin());
    QRectF rect((*this->points.begin()).x(), (*this->points.begin()).y(), this->radius, this->radius);
    path.arcTo(rect, 0, 360);
    painter->fillPath(path, brush);
}

int Circular::getRadius() const
{
    return radius;
}

void Circular::setRadius(int value)
{
    radius = value;
}
