#pragma once

#include <QVector>

class DataGenerator
{
public:
    DataGenerator();
    static QVector<double> generateDefaultRandomVector(size_t size, unsigned int seed, double first = 0, double second = 1);
    static QVector<double> generateCustomRandomVector(size_t size, unsigned int seed, double first = 0, double second = 1);

private:
    static int takeNFirstDigits(int number, int n);
};
