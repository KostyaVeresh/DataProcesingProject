#include "dataGenerator.h"

DataGenerator::DataGenerator()
{

}

QVector<double> DataGenerator::generateDiscreteStepVector(size_t size, double discreteStep) {
    QVector<double> result(size);
    for (size_t i = 0; i < size; ++i) {
        result[i] = i * discreteStep;
    }
    return result;
}

QVector<double> DataGenerator::generateHarmonicFunc(size_t size, double discreteStep, double frequency, double amplitude) {
    QVector<double> result(size);
    for (size_t i = 0; i < size; ++i) {
        double xPoint = i * discreteStep;
        result[i] = amplitude * qSin(2 * M_PI * frequency * xPoint);
    }
    return result;
}

QVector<double> DataGenerator::generateDefaultRandomVector(size_t size, unsigned int seed, double first, double second)
{
    QVector<double> randomVector(size);
       srand(seed);
       for (size_t i = 0; i < size; ++i) {
           randomVector[i] = ((double)rand() / (double)RAND_MAX);
       }

       return randomVector;
}

QVector<double> DataGenerator::generateCustomRandomVector(size_t size, unsigned int seed, double first, double second)
{
    QVector<double> randomVector(size);
    unsigned long int newNum = seed;
    for (size_t i = 0; i < size; ++i) {
        newNum = (419 * newNum + 6173) % 29282;
        randomVector[i] = takeNFirstDigits(newNum, 5) / 10000.0;
    }
    return randomVector;
}

int DataGenerator::takeNFirstDigits(int number, int n)
{
    int digitNum = (int)log10(number);
    if (digitNum < n)
        return number % (int)pow(10, digitNum);
    number /= pow(10, digitNum - n);
    return number % n;
}
