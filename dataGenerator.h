#pragma once

#include <QVector>
#include <qmath.h>

class DataGenerator
{
public:
    DataGenerator();
    static QVector<double> generateDiscreteStepVector(size_t size, double discreteStep);
    static QVector<double> generateTrend(size_t size, double discreteStep, int multiply = 1);
    static QVector<double> generateDefaultRandomVector(size_t size, unsigned int seed, double first = 0, double second = 1);
    static QVector<double> generateCustomRandomVector(size_t size, unsigned int seed, double first = 0, double second = 1);
    static QVector<double> generateHarmonicFunc(size_t size, double discreteStep, double frequency, double amplitude);

private:
    static int takeNFirstDigits(int number, int n);
};
