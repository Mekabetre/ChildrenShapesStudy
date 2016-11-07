#ifndef STUDYWINDOW_H
#define STUDYWINDOW_H

#include <QWidget>
#include <QGraphicsWidget>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include "Model/shape.h"
#include "Model/triangle.h"
#include <QRadioButton>
#include <QButtonGroup>

class StudyWindow : public QWidget
{
    Q_OBJECT
public:
    explicit StudyWindow(QWidget *parent = 0);
    ~StudyWindow();
private:
    void CreateLayout();
private:
    Shape * shape = NULL;
    int rbtnCheckedID = -1;
    QButtonGroup * btnGroup;
    QRadioButton * rbtnSquare;
    QRadioButton * rbtnRect;
    QRadioButton * rbtnCircular;
    QRadioButton * rbtnTriangle;
    QRadioButton * rbtnLadder;
    QRadioButton * rbtnStar;
    QRadioButton * rbtnMoon;
    QPushButton * btnNext;
    QGraphicsItem * graphicsItem;
    QGraphicsScene * graphicsScene;
    QGraphicsView * graphicsView;
public slots:
    void clickedBtnNext();
    void clickedRbtn();
};

#endif // STUDYWINDOW_H
