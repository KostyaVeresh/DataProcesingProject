#include "dataReader.h"

DataReader::DataReader()
{

}

QVector<double> DataReader::readDatFile(const QString &path)
{
    QVector<double> result;
    QFile file(path);
    QTextStream in(&file);
    while (!file.atEnd()) {
        float num;
        in >> num;
        result.append(num);
    }
    return result;
}
