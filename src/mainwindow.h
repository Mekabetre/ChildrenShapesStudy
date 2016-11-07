#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMdiArea>
#include <QMdiSubWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);
private slots:
    void clickedStudy();
    void clickedTest();
    void clickedExit();

    void cascadeSubWindows();
    void tileSubWindows();
private:
    QMdiArea * mdi_area;
private:
    QMenu * menuStudy;
    QMenu * layoutMenu;
    QMenu * menuHelp;
private:
    QAction * actionStudy;
    QAction * actionTest;
    QAction * actionExit;

    QAction * cascadeAction;
    QAction * tileAction;
private:
    void CreateMenus();
    void CreateActions();
};

#endif // MAINWINDOW_H
