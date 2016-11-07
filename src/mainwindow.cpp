#include "mainwindow.h"
#include <QMessageBox>
#include "studywindow.h"
#include "testwindows.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle(tr("幼儿形状学习工具"));
    this->mdi_area = new QMdiArea;
    this->mdi_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->mdi_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->setCentralWidget(this->mdi_area);//设置布局由QMdiArea管理

    CreateActions();
    CreateMenus();
}

MainWindow::~MainWindow()
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton result = QMessageBox::question(this,tr("提示"),tr("是否退出程序？"),QMessageBox::Yes|QMessageBox::No);
    if(result == QMessageBox::Yes){
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::clickedStudy()
{
    StudyWindow * window = new StudyWindow;
    window->setAttribute(Qt::WA_DeleteOnClose);
    this->mdi_area->addSubWindow(window);
    window->show();
    this->mdi_area->activeSubWindow()->resize(this->width() - 100, this->height() - 100);
}

void MainWindow::clickedTest()
{
    TestWindows * window = new TestWindows;
    window->setAttribute(Qt::WA_DeleteOnClose);
    mdi_area->addSubWindow(window);
    window->show();
    mdi_area->activeSubWindow()->resize(this->width() - 100, this->height() - 100);
}

void MainWindow::clickedExit()
{
    this->close();
}

void MainWindow::cascadeSubWindows()
{
    this->mdi_area->cascadeSubWindows();
}

void MainWindow::tileSubWindows()
{
    this->mdi_area->tileSubWindows();
}

void MainWindow::CreateMenus()
{
    this->menuStudy = this->menuBar()->addMenu(tr("学习"));
    this->menuStudy->addAction(this->actionStudy);
    this->menuStudy->addAction(this->actionTest);
    this->menuStudy->addSeparator();
    this->menuStudy->addAction(this->actionExit);

    this->layoutMenu = this->menuBar()->addMenu(tr("窗口"));
    this->layoutMenu->addAction(cascadeAction);
    this->layoutMenu->addAction(tileAction);
}

void MainWindow::CreateActions()
{
    this->actionStudy = new QAction(tr("学习"), this);
    this->actionStudy->setShortcut(tr("Ctrl+s"));
    connect(this->actionStudy, SIGNAL(triggered(bool)), this, SLOT(clickedStudy()));
    this->actionTest = new QAction(tr("测试"), this);
    this->actionTest->setShortcut(tr("Ctrl+t"));
    connect(this->actionTest, SIGNAL(triggered(bool)), this, SLOT(clickedTest()));
    this->actionExit = new QAction(tr("退出"), this);
    this->actionExit->setShortcut(tr("Ctrl+q"));
    connect(this->actionExit, SIGNAL(triggered(bool)), this, SLOT(clickedExit()));

    cascadeAction = new QAction(tr("层叠窗口"), this);
    this->cascadeAction->setShortcut(tr("Ctrl+q"));
    connect(this->cascadeAction,SIGNAL(triggered()),this,SLOT(cascadeSubWindows()));
    this->tileAction = new QAction(tr("并列窗口"), this);
    this->tileAction ->setShortcut(tr("Ctrl+r"));
    connect(this->tileAction,SIGNAL(triggered()),this,SLOT(tileSubWindows()));
}
