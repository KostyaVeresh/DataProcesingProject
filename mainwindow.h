#pragma once

#include <QMainWindow>

#include "dataGenerator.h"
#include "dataProcessor.h"
#include "graphPlotter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void printSpikePlots();
    void testConvolution();

    Ui::MainWindow *ui;
    int sizeN;
    double discreteStep;
};
