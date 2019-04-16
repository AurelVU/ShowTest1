#ifndef GETTERPROBLEMFINFILE_H
#define GETTERPROBLEMFINFILE_H

#include <Problem/getterproblem.h>
#include <QFile>
#include <QTextStream>


template <int N>
class GetterProblemFile : public GetterProblem<N>
{
public:
    QString path;
    QFile file;
    QVector<VectorN<float, N>> getPoints() override;
    QVector<VectorN<float, N>> getPowerPoints() override;
    QVector<QPair<int, int>> getEiges() override;
    QVector<QPair<int, int>> getRubbing() override;
    GetterProblemFile(QString _Path);
};

template<int N>
QVector<VectorN<float, N>> GetterProblemFile<N>::getPoints()
{
    QVector<VectorN<float, N>> res;

    QFile file(path);
    QString str;
    file.open(QFile::ReadOnly);
    QTextStream streamInput(&file);
    while(!streamInput.atEnd()) {
            str = streamInput.readLine();
            QStringList strSplited;
            strSplited = str.split(' ', QString::SkipEmptyParts);
            if (strSplited[0] == "p") {
                res << VectorN<float, N>(strSplited[1].toFloat(), strSplited[2].toFloat());
            }
    }
    return res;
}

template<int N>
QVector<VectorN<float, N>> GetterProblemFile<N>::getPowerPoints()
{
    QVector<VectorN<float, N>> res;

    QFile file(path);
    QString str;
    file.open(QFile::ReadOnly);
    QTextStream streamInput(&file);
    while(!streamInput.atEnd()) {
            str = streamInput.readLine();
            QStringList strSplited;
            strSplited = str.split(' ', QString::SkipEmptyParts);
            if (strSplited[0] == "pp") {
                res << VectorN<float, N>(strSplited[1].toFloat(), strSplited[2].toFloat());
            }
    }
    return res;
}

template<int N>
QVector<QPair<int, int>> GetterProblemFile<N>::getEiges()
{
    QVector<QPair<int, int>> res;

    QString str;
    QFile file(path);
    file.open(QFile::ReadOnly);
    QTextStream streamInput(&file);
    while(!streamInput.atEnd()) {
            str = streamInput.readLine();
            QStringList strSplited;
            strSplited = str.split(' ', QString::SkipEmptyParts);
            if (strSplited[0] == 'e') {
                res << QPair<int, int>(strSplited[1].toInt(), strSplited[2].toInt());
            }
    }
    return res;
}

template<int N>
QVector<QPair<int, int>> GetterProblemFile<N>::getRubbing()
{
    QVector<QPair<int, int>> res;

    QString str;
    QFile file(path);
    file.open(QFile::ReadOnly);
    QTextStream streamInput(&file);
    while(!streamInput.atEnd()) {
            str = streamInput.readLine();
            QStringList strSplited;
            strSplited = str.split(' ', QString::SkipEmptyParts);
            if (strSplited[0] == 'r') {
                res << QPair<int, int>(strSplited[1].toInt(), strSplited[2].toInt());
            }
    }
    return res;
}

template<int N>
GetterProblemFile<N>::GetterProblemFile(QString _Path)
{
    path = _Path;
}



#endif // GETTERPROBLEMFINFILE_H
