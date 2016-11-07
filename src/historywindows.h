#ifndef HISTORYWINDOWS_H
#define HISTORYWINDOWS_H

#include <QDialog>
#include <QListWidget>
#include <QPushButton>
#include "Model/question.h"

class HistoryWindows : public QDialog
{
    Q_OBJECT
private:
    QPushButton * btnRead;
    QPushButton * btnDelete;
    QListWidget * listWidget;
private:
    void CreateLayout();
    void LoadList();
private slots:
    void clickedBtnRead();
    void clickedBtnDelete();
public:
    HistoryWindows();
    bool haveChose = false;
    vector<Question> questions;
};

#endif // HISTORYWINDOWS_H
