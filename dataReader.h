#pragma once

#include <QVector>

class DataReader
{
public:
    DataReader();
    static QVector<double> readDatFile(const QString &path);
};
