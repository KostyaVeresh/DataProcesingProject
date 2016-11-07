#pragma once

#include "../qcustomplot/qcustomplot.h"

class GraphPlotter
{
public:
    GraphPlotter();
    static void setAxisRange(QCustomPlot *plotWidget,
                             double xRange1, double xRange2,
                             double yRange1, double yRange2);
    static void plotFunction(QCustomPlot *plotWidget,
                             QVector<double> const &xValues,
                             QVector<double> const &yValues
                             );
};
