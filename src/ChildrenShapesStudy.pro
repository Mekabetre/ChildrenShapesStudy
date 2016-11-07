#-------------------------------------------------
#
# Project created by QtCreator 2016-10-19T14:11:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChildrenShapesStudy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Model/shape.cpp \
    studywindow.cpp \
    Model/triangle.cpp \
    Helper/shapehelper.cpp \
    Model/square.cpp \
    Model/rect.cpp \
    Model/circular.cpp \
    Model/ladder.cpp \
    Model/star.cpp \
    Model/moon.cpp \
    testwindows.cpp \
    Model/question.cpp \
    Helper/datahelper.cpp \
    historywindows.cpp

HEADERS  += mainwindow.h \
    Model/shape.h \
    studywindow.h \
    Model/triangle.h \
    Helper/shapehelper.h \
    Model/square.h \
    Model/rect.h \
    Model/circular.h \
    Model/ladder.h \
    Model/star.h \
    Model/moon.h \
    testwindows.h \
    Model/question.h \
    Helper/datahelper.h \
    historywindows.h
