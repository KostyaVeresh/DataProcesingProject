#pragma once

#include "../qcustomplot/qcustomplot.h"

class GraphPlotter
{
public:
    GraphPlotter();
    static void drawFuncPlot(QCustomPlot *plotWidget);
};
