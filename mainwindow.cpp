#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    sizeN(5000),
    discreteStep(0.001)
{
    ui->setupUi(this);
    printSpikePlots();
}

void MainWindow::printSpikePlots() {
    QVector<double> xValues = DataGenerator::generateDiscreteStepVector(sizeN, discreteStep);
    QVector<double> yValues = DataGenerator::generateHarmonicFunc(sizeN, discreteStep, 5, 0.5);
    QVector<double> yValues2 = DataGenerator::generateHarmonicFunc(sizeN, discreteStep, 15, 1);
    QVector<double> yValues3 = DataProcessor::addAnotherFunction(yValues, yValues2);
    QVector<double> yValues4 = DataProcessor::addSpikeValues(yValues3, 15, 2);
    QVector<double> yValues5 = DataProcessor::addShift(yValues4, -3);

    QVector<double> yValues6 = DataProcessor::eliminateShift(yValues5);
    QVector<double> yValues7 = DataProcessor::eliminateSpikeValues(yValues6, -5, 5);
    QVector<double> yValues8 = DataGenerator::generateTrend(sizeN, discreteStep, 4);
    QVector<double> yValues9 = DataProcessor::addAnotherFunction(yValues5, yValues8);

    GraphPlotter::setAxisRange(ui->widget, 0, 5, -12, 12);
    GraphPlotter::plotFunction(ui->widget, xValues, yValues5);
    GraphPlotter::setAxisRange(ui->widget_2, 0, 5, -12, 12);
    GraphPlotter::plotFunction(ui->widget_2, xValues, yValues9);
}

MainWindow::~MainWindow()
{
    delete ui;
}
