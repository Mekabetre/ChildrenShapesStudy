#ifndef DATAHELPER_H
#define DATAHELPER_H

#include <vector>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QObject>
#include "Model/question.h"
#include "Model/circular.h"

using namespace std;

#include <Model/question.h>

class DataHelper
{
public:
    DataHelper();
public:
    static void DeleteData(QString fileName);
    static vector<Question> ReadData(QString fileName);
    static void SaveData(vector<Question> questions);
    static vector<QString> GetList();
private:
    static void WritePointsAndColor(QTextStream &out, Shape * shape);
};

#endif // DATAHELPER_H
