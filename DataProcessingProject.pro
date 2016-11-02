#-------------------------------------------------
#
# Project created by QtCreator 2016-10-25T00:40:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = DataProcessingProject
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    dataProcessor.cpp \
    graphPlotter.cpp \
    ../qcustomplot/qcustomplot.cpp \
    dataGenerator.cpp \
    dataReader.cpp

HEADERS  += mainwindow.h \
    dataProcessor.h \
    graphPlotter.h \
    ../qcustomplot/qcustomplot.h \
    dataGenerator.h \
    dataReader.h

FORMS    += mainwindow.ui
