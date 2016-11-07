#include "datahelper.h"

DataHelper::DataHelper()
{

}

void DataHelper::DeleteData(QString fileName)
{
    vector<QString> list;

    QFile file("list.bat");
    if(!file.exists())
        return;

    if(file.open(QFile::ReadOnly)){
        QTextStream stream(&file);
        while(!stream.atEnd()){
            list.push_back(stream.readLine());
        }
    }
    file.close();
    if(file.open(QFile::WriteOnly|QFile::Truncate)){
        QTextStream stream(&file);

        vector<QString>::iterator e = list.begin();
        while(e != list.end()){
            if((*e).split(" ")[0] == fileName){
                e++;
                continue;
            }
            stream << *e;
            stream << "\r\n";
            e++;
        }
    }
    file.close();
    QFile datafile(QObject::tr("Data/") + fileName + QObject::tr(".bat"));
    datafile.remove();
}

vector<Question> DataHelper::ReadData(QString fileName)
{
    vector<Question> questions;
    QFile file(QObject::tr("Data/") + fileName + QObject::tr(".bat"));
    if(!file.exists())
        return questions;

    if(file.open(QFile::ReadOnly)){
        QTextStream stream(&file);
        while(!stream.atEnd()){
            QString xoxo = stream.readLine();
            if(xoxo.length() == 0)
                continue;
            int shapeID = stream.readLine().toInt();//得到shape ID
            Question question(shapeID);
            QString color = stream.readLine();
            question.getShape()->setColor(QColor(color.split(" ")[0].toInt(), color.split(" ")[1].toInt(), color.split(" ")[2].toInt()));//设置颜色
            QStringList points = stream.readLine().split(" ");
            vector<QPointF> _points;
            for(int i = 0; i < points.count(); i++){
                QPointF point(points[i].toDouble(), points[i + 1].toDouble());
                i++;
                _points.push_back(point);
            }
            question.getShape()->setPoints(_points);
            if(shapeID == 2){//圆多了一个半径
                ((Circular *)question.getShape())->setRadius(stream.readLine().toInt());
            }
            //最后处理用户原有输入
            QStringList userAnswer = xoxo.split(" ");
            question.setChoseShapeID(userAnswer[0].toInt());
            if(userAnswer.count() > 1)
                question.setChoseShapeName(userAnswer[1]);
            questions.push_back(question);
        }
    }
    file.close();
    return questions;
}

void DataHelper::SaveData(vector<Question> questions)
{
    QFile list("list.bat");
    QDateTime time = QDateTime::currentDateTime();
    if(list.open(QFile::WriteOnly|QFile::Append)){
        QTextStream out(&list);
        QString strTime = time.toString("yyyy-MM-dd hh:mm:ss");
        out << time.toString("yyyyMMddhhmmss");
        out << " ";
        out << strTime + "\r\n";
    }
    list.close();

    QFile file(QObject::tr("Data/") + time.toString("yyyyMMddhhmmss") + QObject::QObject::tr(".bat"));
    if(file.open(QFile::WriteOnly|QFile::Append)){
        QTextStream out(&file);
        vector<Question>::iterator question = questions.begin();
        while(question !=  questions.end()){
            out << QString::number((*question).getChoseShapeID()) + QObject::QObject::tr(" ") + (*question).getChoseShapeName();
            out << "\r\n";
            switch((*question).getShape()->getShapeID()){
            case 0:
                WritePointsAndColor(out, (*question).getShape());
                break;
            case 1:
                WritePointsAndColor(out, (*question).getShape());
                break;
            case 2:
                WritePointsAndColor(out, (*question).getShape());
                out << QString::number(((Circular*)(*question).getShape())->getRadius());
                out << "\r\n";
                break;
            case 3:
                WritePointsAndColor(out, (*question).getShape());
                break;
            case 4:
                WritePointsAndColor(out, (*question).getShape());
                break;
            case 5:
                WritePointsAndColor(out, (*question).getShape());
                break;
            case 6:
                WritePointsAndColor(out, (*question).getShape());
                break;
            }
            question++;
        }
    }
    file.close();
}

vector<QString> DataHelper::GetList()
{
    vector<QString> list;

    QFile file("list.bat");
    if(!file.exists())
        return list;

    if(file.open(QFile::ReadOnly)){
        QTextStream stream(&file);
        while(!stream.atEnd()){
            QString str = stream.readLine();
            list.push_back(str.split(" ")[1] + QObject::tr(" ") + str.split(" ")[2]);
        }
    }
    file.close();

    return list;
}


void DataHelper::WritePointsAndColor(QTextStream &out, Shape *shape)
{
    out << shape->getShapeID();//先存ID
    out << "\r\n";
    QColor color = shape->getColor();
    out << QString::number(color.red()) + QObject::QObject::tr(" ") + QString::number(color.green()) + QObject::QObject::tr(" ") + QString::number(color.blue());//再存颜色
    out << "\r\n";
    vector<QPointF> points = shape->GetPoints();
    vector<QPointF>::iterator point = points.begin();
    while(point !=  points.end()){
        if(point != points.begin()){
            out << " ";
        }
        QPointF temp = *point;
        out << QString::number(temp.x()) + QObject::tr(" ") + QString::number(temp.y());
        point++;
    }
    out << "\r\n";
}
