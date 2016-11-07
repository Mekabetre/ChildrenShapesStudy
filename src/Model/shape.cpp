#include "shape.h"
#include <cmath>

Shape::Shape(int _width, int _height)
{
    this->width = _width;
    this->height = _height;
    this->color = SetColor();
}

QRectF Shape::boundingRect() const
{
    return QRectF(-1*width,-1*height,2*width,2*height);
}

void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPainterPath path;
    QBrush brush(this->color);
    vector<QPointF>::iterator e = this->points.begin();
    path.moveTo(*e);
    e++;
    while(e != this->points.end()){
        path.lineTo(*e);
        e++;
    }
    path.closeSubpath();
    path.setFillRule(Qt::WindingFill);

    painter->fillPath(path, brush);
}

vector<QPointF> Shape::GetPoints()
{
    return this->points;
}

QString Shape::GetName()
{
    return this->name;
}

int Shape::getShapeID() const
{
    return this->shapeID;
}

double Shape::PointToLineDistance(QPointF point, QPointF l1, QPointF l2)
{
    double K = (l1.y() - l2.y())/(1.0 * (l1.x() - l2.x()));
    return (abs(K * point.x() - point.y() - K * l1.x() + l1.y())) / (1.0 * sqrt(K * K + 1));
}

bool Shape::IsInTheRange(QPointF p)
{
    if(p.y() > -1*height && p.y() < height && p.x() > -1*width && p.x() < width)
        return true;
    else
        return false;
}

QColor Shape::SetColor()
{
    QColor color(qrand()%256, qrand()%256, qrand()%256);
    return color;
}

vector<QPointF> Shape::getPoints() const
{
    return points;
}

void Shape::setPoints(const vector<QPointF> &value)
{
    points = value;
}

void Shape::setShapeID(int value)
{
    shapeID = value;
}

QColor Shape::getColor() const
{
    return color;
}

void Shape::setColor(const QColor &value)
{
    color = value;
}

QPointF Shape::GetPoint()
{
    return QPointF((int)pow(-1, qrand() % 2) * qrand() % this->width, (int)pow( -1, qrand() % 2) * qrand() % this->height);
}

double Shape::GetDistance(QPointF ponit1, QPointF ponit2)
{
    double result = pow((ponit1.x() - ponit2.x()), 2) + pow(ponit1.y() - ponit2.y(), 2);
    return sqrt(result);
}
