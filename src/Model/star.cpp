#include "star.h"


Star::Star(int _width, int _height) : Shape(_width, _height)
{
    SetPoints();
    SetName();
}

void Star::SetName()
{
    this->shapeID = 5;
    this->name = QObject::tr("星形");
}

void Star::SetPoints()
{
    double angle = 2*3.14 / 5;//圆上五个点平分
    QPointF center;
    double radius;
    double rotate = angle * (qrand() % 50) / 50.0;//旋转一个角得角度相当于没旋转

    while(1){
        center = GetPoint();
        radius = qrand() % 50 + 30;

        QPointF point1(center.x(), center.y() + radius);
        QPointF point2(center.x(), center.y() - radius);
        QPointF point3(center.x() + radius, center.y());
        QPointF point4(center.x() - radius, center.y());

        if(!IsInTheRange(point1) || !IsInTheRange(point2) || !IsInTheRange(point3) || !IsInTheRange(point4)){
            continue;
        }

        point1 = QPointF(center.x() + radius * cos(rotate), center.y() + radius * sin(rotate));
        point2 = QPointF(center.x() + radius * cos(rotate + angle), center.y() + radius * sin(rotate + angle));
        point3 = QPointF(center.x() + radius * cos(rotate + 2*angle), center.y() + radius * sin(rotate + 2*angle));
        point4 = QPointF(center.x() + radius * cos(rotate + 3*angle), center.y() + radius * sin(rotate + 3*angle));
        QPointF point5(center.x() + radius * cos(rotate + 4*angle), center.y() + radius * sin(rotate + 4*angle));

        this->points.push_back(point1);
        this->points.push_back(point4);
        this->points.push_back(point2);
        this->points.push_back(point5);
        this->points.push_back(point3);

        break;
    }
}
