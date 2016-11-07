#include "dataProcessor.h"

DataProcessor::DataProcessor()
{

}

QVector<double> DataProcessor::addAnotherFunction(const QVector<double> &first, const QVector<double> &second) {
    QVector<double> result(first.size());
    for (int i = 0; i < first.size(); ++i) {
        result[i] = first[i] + second[i];
    }
    return result;
}

QVector<double> DataProcessor::harmonicFunc(size_t size, double discreteStep, double frequency)
{
    QVector<double> result(size);
    for (int i = 0; i < size; ++i) {
        double xPoint = i * discreteStep;
        result[i] = 10 * qSin(2 * M_PI * frequency * xPoint);
    }
    return result;
}

QVector<double> DataProcessor::addSpikeValues(const QVector<double> &yValues, int numberOfSpikes, int spikeOrder)
{
    QVector<double> result = yValues;
    QVector<double> randomGen(yValues.size());

    for (int i = 0; i < randomGen.size(); ++i) {
        randomGen[i] = i;
    }

    double minValue = *std::min_element(yValues.begin(), yValues.end());
    double maxValue = *std::max_element(yValues.begin(), yValues.end());
    double range = (maxValue - minValue) / 2;
    double rangeMin = spikeOrder * range;
    double rangeMax = (spikeOrder + 2) * range;
    srand(time(NULL));

    for (int i = 0; i < numberOfSpikes; ++i) {
        int randIndex = rand() % randomGen.size();
        int index = randomGen[randIndex];
        double num =((double)rand()/(double)RAND_MAX);
        if (num >= 0.5) {
            result[index] = (num - 0.5) * 2 * range + rangeMin + maxValue;
        } else {
            result[index] =  - num * range - rangeMin + minValue;
        }
        //result[index] = num * 2 * range - range;
        randomGen[randIndex] = randomGen[randomGen.size() - 1];
        randomGen.removeLast();
    }

    return result;
}

QVector<double> DataProcessor::amplitudeSpectrum(const QVector<double> &yValues)
{
    int N = yValues.size();
    QVector<double> result(N);
    for (int k = 0; k < N; ++k) {
        double re = 0;
        double im = 0;
        for (int n = 0; n < N; ++n) {
            re += yValues[n] * cos(2 * M_PI * k * n / N);
            im += yValues[n] * sin(2 * M_PI * k * n / N);
        }
        re /= N;
        im /= N;
        result[k] = sqrt(im * im + re * re);
    }
    return result;
}
