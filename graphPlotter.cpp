#include "graphPlotter.h"

GraphPlotter::GraphPlotter()
{

}

void GraphPlotter::PlotFunction(QCustomPlot *plotWidget,
                                const QVector<double> &xValues,
                                const QVector<double> &yValues
                                ) {

    if (plotWidget->graph() == 0) {
        plotWidget->addGraph();
    }
    plotWidget->graph(0)->setData(xValues, yValues);
    plotWidget->replot();
}
