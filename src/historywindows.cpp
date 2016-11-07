#include "historywindows.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include "Helper/datahelper.h"


HistoryWindows::HistoryWindows()
{
    haveChose = false;
    CreateLayout();
    LoadList();
}

void HistoryWindows::CreateLayout()
{
    QHBoxLayout * layout = new QHBoxLayout(this);
    QVBoxLayout * right = new QVBoxLayout;
    btnRead =new QPushButton(tr("载入"));
    connect(btnRead, SIGNAL(clicked(bool)), this, SLOT(clickedBtnRead()));
    btnDelete =new QPushButton(tr("删除"));
    connect(btnDelete, SIGNAL(clicked(bool)), this, SLOT(clickedBtnDelete()));
    right->addStretch();
    right->addWidget(btnRead);
    right->addWidget(btnDelete);

    listWidget = new QListWidget;
    layout->addWidget(listWidget);
    layout->addLayout(right);
}

void HistoryWindows::LoadList()
{
    vector<QString> history = DataHelper::GetList();
    vector<QString>::iterator e = history.begin();
    while(e != history.end()){
        listWidget->addItem(*e);
        e++;
    }
}

void HistoryWindows::clickedBtnRead()
{
    QList<QListWidgetItem *> items = listWidget->selectedItems();
    if(items.count() < 1)
        return;
    this->questions = DataHelper::ReadData(items[0]->text().replace(" ", "").replace("-", "").replace(":", ""));
    this->haveChose = true;
    this->close();
}

void HistoryWindows::clickedBtnDelete()
{
    QList<QListWidgetItem *> items = listWidget->selectedItems();
    if(items.count() < 1)
        return;
    DataHelper::DeleteData(items[0]->text().replace(" ", "").replace("-", "").replace(":", ""));
    listWidget->removeItemWidget(items[0]);
}
