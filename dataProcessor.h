#pragma once

#include <QVector>
#include <qmath.h>
#include <ctime>

#include "statistics.h"

class DataProcessor
{
public:
    DataProcessor();
    static QVector<double> addSpikeValues(QVector<double> const &yValues, int numberOfSpikes, int spikeOrder);
    static QVector<double> eliminateSpikeValues(QVector<double> const &yValues, double lowerBound, double upperBound);
    static QVector<double> addShift(QVector<double> const &yValues, double shift);
    static QVector<double> eliminateShift(QVector<double> const &yValues);
    static QVector<double> amplitudeSpectrum(QVector<double> const &yValues);
    static QVector<double> addAnotherFunction(QVector<double> const &first, QVector<double> const &second);
    static QVector<double> multiplyAnotherFunction(QVector<double> const &first, QVector<double> const &second);
    static QVector<double> convolution(QVector<double> const &yValues, QVector<double> const &hValues);
};
