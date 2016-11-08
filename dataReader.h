#pragma once

#include <QVector>
#include <QFile>
#include <QTextStream>

class DataReader
{
public:
    DataReader();
    static QVector<double> readDatFile(const QString &path);
};
