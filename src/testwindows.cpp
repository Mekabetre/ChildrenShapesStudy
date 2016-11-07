#include "testwindows.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "Model/square.h"
#include <Model/circular.h>
#include <Helper/datahelper.h>
#include "historywindows.h"

TestWindows::TestWindows(QWidget *parent) : QWidget(parent)
{
    CreateLayout();
}

TestWindows::~TestWindows()
{
    ClearQuestions();
}

void TestWindows::CreateLayout()
{
    QGridLayout * answerLayout = new QGridLayout;
    QGridLayout * operateLayout = new QGridLayout;
    answerBox = new QGroupBox(tr("答案选择"));
    answerBox->setEnabled(false);

    QHBoxLayout * head = new QHBoxLayout;
    QVBoxLayout *layout = new QVBoxLayout(this);

    btnGroup = new QButtonGroup(this);
    connect(this->btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(clickedRbtn()));
    rbtnHid = new QRadioButton(this);
    rbtnHid->setVisible(false);
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
    btnPre = new QPushButton;
    btnPre->setText(tr("上一题"));
    connect(btnPre, SIGNAL(clicked(bool)), this, SLOT(clickedPreBtn()));
    btnNext = new QPushButton;
    btnNext->setText(tr("下一题"));
    connect(btnNext, SIGNAL(clicked(bool)), this, SLOT(clickedNextBtn()));
    btnNewTest = new QPushButton(tr("开始答题"));
    connect(btnNewTest, SIGNAL(clicked(bool)), this, SLOT(clickedStartBtn()));
    btnReView = new QPushButton(tr("历史记录"));
    connect(btnReView, SIGNAL(clicked(bool)), this, SLOT(clickedHistory()));
    btnCommit = new QPushButton(tr("提交答案"));
    btnCommit->setEnabled(false);
    connect(btnCommit, SIGNAL(clicked(bool)), this, SLOT(clickedCommitBtn()));

    btnGroup->addButton(rbtnSquare, 0);
    btnGroup->addButton(rbtnRect, 1);
    btnGroup->addButton(rbtnCircular, 2);
    btnGroup->addButton(rbtnTriangle, 3);
    btnGroup->addButton(rbtnLadder, 4);
    btnGroup->addButton(rbtnStar, 5);
    btnGroup->addButton(rbtnMoon, 6);
    btnGroup->addButton(rbtnHid, 7);
    answerLayout->addWidget(rbtnSquare, 0, 0);
    answerLayout->addWidget(rbtnRect, 0, 1);
    answerLayout->addWidget(rbtnCircular, 0, 2);
    answerLayout->addWidget(rbtnTriangle, 0, 3);
    answerLayout->addWidget(rbtnLadder, 1, 0);
    answerLayout->addWidget(rbtnStar, 1, 1);
    answerLayout->addWidget(rbtnMoon, 1, 2);
    answerLayout->addWidget(btnPre, 0, 4);
    answerLayout->addWidget(btnNext, 1, 4);
    answerBox->setLayout(answerLayout);

    operateLayout->addWidget(btnNewTest, 0, 0);
    operateLayout->addWidget(btnReView, 0, 1);
    operateLayout->addWidget(btnCommit, 1, 0, 1, 2);

    head->addWidget(answerBox);
    head->addLayout(operateLayout);

    labelStatus = new QLabel;
    head->addWidget(labelStatus);


    head->addStretch();
    layout->addLayout(head);

    graphicsView = new QGraphicsView(this);
    graphicsScene = new QGraphicsScene(this);
    graphicsView->setScene(graphicsScene);
    layout->addWidget(graphicsView);
}

void TestWindows::CreateQuestion()
{
    for(int i = 0; i < 10; i++){
        Question question(qrand()%7);
        questions.push_back(question);
    }
}

void TestWindows::ClearQuestions()
{
    vector<Question>::iterator question = this->questions.begin();
    while(question !=  this->questions.end()){
        delete (*question).getShape();
        question++;
    }
    this->questions.clear();
}

void TestWindows::SetAnswerTitle()
{
    if(isAnswering)
        answerBox->setTitle(tr("答案选择：") + QString::number(questionIndex) + tr("/10"));
    else
        answerBox->setTitle(tr("答案选择"));
}

void TestWindows::showAnswer()
{
    if(isAnswering){
        labelStatus->setText(tr(""));
        return;
    }
    if((*currentQuestion).getChoseShapeID() == (*currentQuestion).getShape()->getShapeID())
        labelStatus->setText(tr("你答对了呢~"));
    else
        labelStatus->setText(tr("正确答案：")+ (*currentQuestion).getShape()->GetName()+ tr("\r\n你的答案：") + (*currentQuestion).getChoseShapeName());
}

void TestWindows::SetRadioBtnEnable()
{
    rbtnSquare->setEnabled(true);
    rbtnRect->setEnabled(true);
    rbtnCircular->setEnabled(true);
    rbtnLadder->setEnabled(true);
    rbtnMoon->setEnabled(true);
    rbtnStar->setEnabled(true);
    rbtnTriangle->setEnabled(true);
}

void TestWindows::SetRadioBtnNotEnable()
{
    rbtnSquare->setEnabled(false);
    rbtnRect->setEnabled(false);
    rbtnCircular->setEnabled(false);
    rbtnLadder->setEnabled(false);
    rbtnMoon->setEnabled(false);
    rbtnStar->setEnabled(false);
    rbtnTriangle->setEnabled(false);
}

void TestWindows::clickedRbtn()
{
    if(!isAnswering)
        return;
    (*currentQuestion).setChoseShapeID(btnGroup->checkedId());
    switch(btnGroup->checkedId()){
    case 0:
        (*currentQuestion).setChoseShapeName(tr("正方形"));
        break;
    case 1:
        (*currentQuestion).setChoseShapeName(tr("长方形"));
        break;
    case 2:
        (*currentQuestion).setChoseShapeName(tr("圆形"));
        break;
    case 3:
        (*currentQuestion).setChoseShapeName(tr("三角形"));
        break;
    case 4:
        (*currentQuestion).setChoseShapeName(tr("梯形"));
        break;
    case 5:
        (*currentQuestion).setChoseShapeName(tr("星形"));
        break;
    case 6:
        (*currentQuestion).setChoseShapeName(tr("月牙形"));
        break;
    default:
        break;
    }
}

void TestWindows::clickedPreBtn()
{
    graphicsScene->removeItem((*currentQuestion).getShape());
    --currentQuestion;

    if((*currentQuestion).getChoseShapeID() == -1)
        rbtnHid->setChecked(true);
    else
        ((QRadioButton *)btnGroup->button((*currentQuestion).getChoseShapeID()))->setChecked(true);

    graphicsScene->addItem((*currentQuestion).getShape());
    this->btnNext->setEnabled(true);
    if(currentQuestion == this->questions.begin())
        this->btnPre->setEnabled(false);
    else
        this->btnPre->setEnabled(true);

    questionIndex--;
    SetAnswerTitle();
    showAnswer();
}

void TestWindows::clickedNextBtn()
{
    graphicsScene->removeItem((*currentQuestion).getShape());
    currentQuestion++;

    if((*currentQuestion).getChoseShapeID() == -1)
        rbtnHid->setChecked(true);
    else
        ((QRadioButton *)btnGroup->button((*currentQuestion).getChoseShapeID()))->setChecked(true);

    graphicsScene->addItem((*currentQuestion).getShape());
    this->btnPre->setEnabled(true);
    if(currentQuestion == --(this->questions.end()))
        this->btnNext->setEnabled(false);
    else
        this->btnNext->setEnabled(true);

    questionIndex++;
    SetAnswerTitle();
    showAnswer();
}

void TestWindows::clickedStartBtn()
{
    ClearQuestions();
    CreateQuestion();
    currentQuestion = questions.begin();
    graphicsScene->addItem((*currentQuestion).getShape());
    this->btnPre->setEnabled(false);
    btnNext->setEnabled(true);
    answerBox->setEnabled(true);
    btnCommit->setEnabled(true);
    btnReView->setEnabled(false);
    isAnswering = 1;
    questionIndex = 1;
    SetAnswerTitle();
    SetRadioBtnEnable();
}

void TestWindows::clickedCommitBtn()
{
    int all = 0;
    int haveAnswer = 0;
    vector<Question>::iterator question = this->questions.begin();
    while(question !=  this->questions.end()){
        all++;
        if((*question).getChoseShapeID() != -1)
            haveAnswer++;
        question++;
    }
    QMessageBox::StandardButton result = QMessageBox::question(this, tr("提交？"), tr("总题数：")+ QString::number(all) +tr("\r\n你回答了：")+ QString::number(haveAnswer) +tr("\r\n是否提交？"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel);
    if(result == QMessageBox::Cancel)
        return;

    isAnswering = 0;
    SetAnswerTitle();

    haveAnswer = 0;
    question = this->questions.begin();
    while(question !=  this->questions.end()){
        if((*question).getChoseShapeID() == (*question).getShape()->getShapeID())
            haveAnswer++;
        question++;
    }

    QMessageBox::information(this, tr("结果"), tr("总题数：")+ QString::number(all) + tr("\r\n你答对了：")+ QString::number(haveAnswer), QMessageBox::Ok);

    btnCommit->setEnabled(false);
    btnReView->setEnabled(true);
    SetRadioBtnNotEnable();
    DataHelper::SaveData(this->questions);
}

void TestWindows::clickedHistory()
{
    HistoryWindows window;
    window.exec();
    if(window.haveChose)
    {
        ClearQuestions();
        this->questions = window.questions;

        currentQuestion = questions.begin();
        graphicsScene->addItem((*currentQuestion).getShape());
        this->btnPre->setEnabled(false);
        btnNext->setEnabled(true);
        answerBox->setEnabled(true);
        btnCommit->setEnabled(false);
        btnReView->setEnabled(true);
        isAnswering = 0;
        questionIndex = 1;
        SetAnswerTitle();
        showAnswer();
        SetRadioBtnNotEnable();
    }
}
