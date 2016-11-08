#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    sizeN(500),
    discreteStep(0.01)
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
    QVector<double> yValues10 = DataGenerator::generateConstantVector(sizeN, 1.5);
    QVector<double> yValues11 = DataProcessor::addAnotherFunction(yValues10,
                          DataGenerator::generateHarmonicFunc(sizeN, discreteStep, 1, 0.5));
    QVector<double> yValues12 = DataGenerator::generateDefaultRandomVector(sizeN, time(NULL), -4, 4);
    yValues12 = DataProcessor::addAnotherFunction(yValues12,
                                                  DataGenerator::generateHarmonicFunc(sizeN, discreteStep, 3, 2));
    yValues12 = DataProcessor::addAnotherFunction(yValues12,
                                                  DataGenerator::generateHarmonicFunc(sizeN, discreteStep, 1, 1));
    QVector<double> yValues13 = DataProcessor::amplitudeSpectrum(yValues12);



    GraphPlotter::setAxisRange(ui->widget, 0, 5, -8, 8);
    GraphPlotter::plotFunction(ui->widget, xValues, yValues12);
    GraphPlotter::setAxisRange(ui->widget_2, 0, 5, 0, 5);
    GraphPlotter::plotFunction(ui->widget_2, xValues, yValues13);
}

MainWindow::~MainWindow()
{
    delete ui;
}
