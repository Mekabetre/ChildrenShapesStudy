#ifndef QUESTION_H
#define QUESTION_H

#include "shape.h"
#include "Helper/shapehelper.h"

class Question
{
public:
    Question(int shapeID);
    ~Question();

//    Question(Question &question);
//    void operator =(Question question);
public:
    int getChoseShapeID() const;
    void setChoseShapeID(int value);

    QString getChoseShapeName() const;
    void setChoseShapeName(const QString &value);

    Shape *getShape() const;
private:
    Shape * shape = NULL;
    int choseShapeID = -1;
    QString choseShapeName;
};

#endif // QUESTION_H
