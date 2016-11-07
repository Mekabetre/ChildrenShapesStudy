#include "question.h"
#include "Model/moon.h"

Question::Question(int shapeID)
{
    shape = ShapeHelper::GetShape(shapeID);
}

Question::~Question()
{
}

int Question::getChoseShapeID() const
{
    return choseShapeID;
}

void Question::setChoseShapeID(int value)
{
    choseShapeID = value;
}

QString Question::getChoseShapeName() const
{
    return choseShapeName;
}

void Question::setChoseShapeName(const QString &value)
{
    choseShapeName = value;
}

Shape *Question::getShape() const
{
    return shape;
}
