#include "graphPlotter.h"

GraphPlotter::GraphPlotter()
{

}

void GraphPlotter::setAxisRange(QCustomPlot *plotWidget,
                                double xRange1, double xRange2,
                                double yRange1, double yRange2) {
    plotWidget->xAxis->setRange(xRange1, xRange2);
    plotWidget->yAxis->setRange(yRange1, yRange2);
}

void GraphPlotter::plotFunction(QCustomPlot *plotWidget,
                                const QVector<double> &xValues,
                                const QVector<double> &yValues
                                ) {

    if (plotWidget->graph() == 0) {
        plotWidget->addGraph();
    }
    plotWidget->graph(0)->setData(xValues, yValues);
    plotWidget->replot();
}
