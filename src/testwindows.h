#ifndef TESTWINDOWS_H
#define TESTWINDOWS_H

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QGroupBox>
#include <QRadioButton>
#include <QGraphicsView>
#include <QLabel>
#include <Helper/shapehelper.h>
#include "Model/question.h"
#include <vector>
#include <QTextStream>
using namespace std;

class TestWindows : public QWidget
{
    Q_OBJECT
public:
    explicit TestWindows(QWidget *parent = 0);
    ~TestWindows();
private:
    void CreateLayout();
    void CreateQuestion();
    void ClearQuestions();
    void SetAnswerTitle();
    void showAnswer();
    void SetRadioBtnEnable();
    void SetRadioBtnNotEnable();
public slots:
    void clickedRbtn();
    void clickedPreBtn();
    void clickedNextBtn();
    void clickedStartBtn();
    void clickedCommitBtn();
    void clickedHistory();
private:
    bool isAnswering = 0;
    int questionIndex = -1;

    Shape * shape = NULL;
    int rbtnCheckedID = -1;
    QGroupBox * answerBox;
    QButtonGroup * btnGroup;
    QRadioButton * rbtnSquare;
    QRadioButton * rbtnRect;
    QRadioButton * rbtnCircular;
    QRadioButton * rbtnTriangle;
    QRadioButton * rbtnLadder;
    QRadioButton * rbtnStar;
    QRadioButton * rbtnMoon;
    QRadioButton * rbtnHid;

    QGraphicsScene * graphicsScene;
    QGraphicsView * graphicsView;

    vector<Question> questions;
    vector<Question>::iterator currentQuestion;

    QPushButton * btnPre;
    QPushButton * btnNext;

    QLabel * labelStatus;

    QPushButton * btnNewTest;
    QPushButton * btnReView;
    QPushButton * btnCommit;
};

#endif // TESTWINDOWS_H
