#include "studywindow.h"
#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include "Helper/shapehelper.h"

StudyWindow::StudyWindow(QWidget *parent) : QWidget(parent)
{
    CreateLayout();
}

StudyWindow::~StudyWindow()
{
    if(shape != NULL)
        delete shape;
}

void StudyWindow::CreateLayout()
{
    QHBoxLayout *head = new QHBoxLayout;
    QVBoxLayout *layout = new QVBoxLayout(this);

    btnGroup = new QButtonGroup(this);
    connect(this->btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(clickedRbtn()));
    rbtnSquare = new QRadioButton(this);
    rbtnSquare->setText(tr("正方形"));
    rbtnRect = new QRadioButton(this);
    rbtnRect->setText(tr("长方形"));
    rbtnCircular = new QRadioButton(this);
    rbtnCircular->setText(tr("圆形"));
    rbtnTriangle = new QRadioButton(this);
    rbtnTriangle->setText(tr("三角形"));
    rbtnLadder = new QRadioButton(this);
    rbtnLadder->setText(tr("梯形"));
    rbtnStar = new QRadioButton(this);
    rbtnStar->setText(tr("星形"));
    rbtnMoon = new QRadioButton(this);
    rbtnMoon->setText(tr("月牙形"));

    btnGroup->addButton(rbtnSquare, 0);
    btnGroup->addButton(rbtnRect, 1);
    btnGroup->addButton(rbtnCircular, 2);
    btnGroup->addButton(rbtnTriangle, 3);
    btnGroup->addButton(rbtnLadder, 4);
    btnGroup->addButton(rbtnStar, 5);
    btnGroup->addButton(rbtnMoon, 6);

    head->addWidget(rbtnSquare);
    head->addWidget(rbtnRect);
    head->addWidget(rbtnCircular);
    head->addWidget(rbtnTriangle);
    head->addWidget(rbtnLadder);
    head->addWidget(rbtnStar);
    head->addWidget(rbtnMoon);

    btnNext = new QPushButton;
    btnNext->setText(tr("下一个"));
    btnNext->setEnabled(false);
    connect(this->btnNext, SIGNAL(clicked(bool)), this, SLOT(clickedBtnNext()));
    head->addWidget(btnNext);
    head->addStretch();
    layout->addLayout(head);

    //shape = new Triangle();
    graphicsView = new QGraphicsView(this);
    graphicsScene = new QGraphicsScene(this);
    //graphicsScene->addItem(shape);
    graphicsView->setScene(graphicsScene);
    layout->addWidget(graphicsView);
}

void StudyWindow::clickedBtnNext()
{
    if(shape != NULL){
        delete shape;
        shape = NULL;
    }
    shape = ShapeHelper::GetShape(this->rbtnCheckedID);
    graphicsScene->addItem(shape);
}

void StudyWindow::clickedRbtn()
{
    if(this->rbtnCheckedID == btnGroup->checkedId())
        return;
    this->rbtnCheckedID = btnGroup->checkedId();
    if(shape != NULL){
        delete shape;
        shape = NULL;
    }
    shape = ShapeHelper::GetShape(this->rbtnCheckedID);
    graphicsScene->addItem(shape);
    btnNext->setEnabled(true);
}
