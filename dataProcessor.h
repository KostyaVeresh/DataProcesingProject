#pragma once

#include <QVector>
#include <qmath.h>
#include <ctime>

class DataProcessor
{
public:
    DataProcessor();
    static  QVector<double> harmonicFunc(size_t size, double discreteStep, double frequency);
    static QVector<double> addSpikeValues(QVector<double> const &yValues, int numberOfSpikes, int spikeOrder);
    static QVector<double> amplitudeSpectrum(QVector<double> const &yValues);
    static QVector<double> addAnotherFunction(QVector<double> const &first, QVector<double> const &second);
};
