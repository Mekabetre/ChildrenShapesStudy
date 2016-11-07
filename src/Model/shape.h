#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <QPointF>
#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>
#include <QColor>
#include <QBrush>

using namespace std;

class Shape: public QGraphicsItem
{
public:
    Shape(int _width, int _height);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void SetPoints() = 0;
    vector<QPointF> GetPoints();
    virtual void SetName() = 0;
    virtual QString GetName();
    virtual int getShapeID() const;

    QColor getColor() const;
    void setColor(const QColor &value);

    void setShapeID(int value);

    vector<QPointF> getPoints() const;
    void setPoints(const vector<QPointF> &value);

private:
    QColor SetColor();
protected:
    int shapeID;
    QColor color;//颜色
    int width;//画布的宽高的一半，为什么一半？原点在中心。
    int height;
    QString name;//名称
    vector<QPointF> points;//图形的点

    QPointF GetPoint();//根据画布的宽高随机获取一个点
    double GetDistance(QPointF ponit1, QPointF ponit2);//两个点的距离
    double PointToLineDistance(QPointF point, QPointF l1, QPointF l2);//点到直线的距离
    bool IsInTheRange(QPointF);
};

#endif // SHAPE_H
