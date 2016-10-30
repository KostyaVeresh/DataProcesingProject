#pragma once

#include <QVector>
#include <qmath.h>

class DataProcessor
{
public:
    DataProcessor();
    static  QVector<double> harmonicFunc(size_t size, double discreteStep, double frequency);
    static QVector<double> addSpikeValues(QVector<double> const &yValues, int numberOfSpikes, int spikeOrder);
};
