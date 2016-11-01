#pragma once

#include "../qcustomplot/qcustomplot.h"

class GraphPlotter
{
public:
    GraphPlotter();
    static void PlotFunction(QCustomPlot *plotWidget,
                             QVector<double> const &xValues,
                             QVector<double> const &yValues
                             );
};
