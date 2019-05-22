#include "test_gaussnewton.h"

Test_GaussNewton::Test_GaussNewton(QObject *parent) :
    QObject(parent)
{
}

void Test_GaussNewton::calculeteJrTest()
{

}

void Test_GaussNewton::computeGradientGHTest()
{

}

void Test_GaussNewton::performGaussNewtonTest2()
{
    QVector<VectorN<float, 2>> points;
    QVector<VectorN<float, 2>> pPoints;
    QVector<QPair<int, int>> eiges;
    QVector<QPair<int, int>> rubbing;
    QVector<float> values;
    QVector<float> res;
    points << VectorN<float, 2>(0, 0);
    pPoints << VectorN<float, 2>(5, 5);
    rubbing << QPair<int, int>(0, 0);
    Problem<2> problem2(points, pPoints, eiges, rubbing);
    values << 0 << 0 << 1 << 0 << 0 << 1;
    res << 5 << 5 << 1 << 0 << 0 << 1;
    QCOMPARE(performGaussNewton(values, problem2, 50), res);
    points.clear();
    pPoints.clear();
    rubbing.clear();
    values.clear();
    res.clear();
}

void Test_GaussNewton::performGaussNewtonTest3()
{
    QVector<VectorN<float, 2>> points;
    QVector<VectorN<float, 2>> pPoints;
    QVector<QPair<int, int>> eiges;
    QVector<QPair<int, int>> rubbing;
    QVector<float> values;
    QVector<float> res;

    points << VectorN<float, 2>(5, 5) << VectorN<float, 2>(0, 0);
    pPoints << VectorN<float, 2>(5, 5);
    rubbing << QPair<int, int>(0, 0);
    eiges << QPair<int, int>(0, 1);
    Problem<2> problem3(points, pPoints, eiges, rubbing);
    values << 5 << 5 << 0 << 0 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1;
    res << 5 << 5 << 0 << 0 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1;
    QCOMPARE(performGaussNewton(values, problem3, 50), res);
    points.clear();
    pPoints.clear();
    rubbing.clear();
    values.clear();
    res.clear();
}

void Test_GaussNewton::performGaussNewtonTest4()
{
    QVector<VectorN<float, 2>> points;
    QVector<VectorN<float, 2>> pPoints;
    QVector<QPair<int, int>> eiges;
    QVector<QPair<int, int>> rubbing;
    QVector<float> values;
    QVector<float> res;

    points << VectorN<float, 2>(10, 0) << VectorN<float, 2>(0, 0);
    pPoints << VectorN<float, 2>(5, 5) << VectorN<float, 2>(5, -5);
    rubbing << QPair<int, int>(0, 0) << QPair<int, int>(1, 1);
    eiges << QPair<int, int>(0, 1);
    Problem<2> problem4(points, pPoints, eiges, rubbing);
    values << 10 << 0 << 0 << 0 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1;
    res << 5 << 5 << 5 << -5 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1;
    auto res_s = performGaussNewton(values, problem4, 50).mid(0, 4);
    for(int i = 0; i < 4; i++)
        QVERIFY(res_s[i] - res[i] < 0.1);
    points.clear();
    pPoints.clear();
    rubbing.clear();
    values.clear();
    res.clear();
}

void Test_GaussNewton::performGaussNewtonTest5()
{
    QVector<VectorN<float, 2>> points;
    QVector<VectorN<float, 2>> pPoints;
    QVector<QPair<int, int>> eiges;
    QVector<QPair<int, int>> rubbing;
    QVector<float> values;
    QVector<float> res;

    points << VectorN<float, 2>(10, 0) << VectorN<float, 2>(0, 0) << VectorN<float, 2>(5, 0);
    pPoints << VectorN<float, 2>(5, 5) << VectorN<float, 2>(5, -5);
    rubbing << QPair<int, int>(0, 0) << QPair<int, int>(1, 1);
    eiges << QPair<int, int>(0, 2) << QPair<int, int>(1, 2);
    Problem<2> problem4(points, pPoints, eiges, rubbing);
    values << 10 << 0 << 0 << 0 << 5 << 0 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1;
    res << 5 << 5 << 5 << -5 << 5 << 0  << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1;
    auto res_s = performGaussNewton(values, problem4, 50).mid(0, 6);
    for(int i = 0; i < 6; i++)
        QVERIFY(res_s[i] - res[i] < 0.1);
    points.clear();
    pPoints.clear();
    rubbing.clear();
    values.clear();
    res.clear();
}

void Test_GaussNewton::performGaussNewtonTest6()
{
    QVector<VectorN<float, 2>> points;
    QVector<VectorN<float, 2>> pPoints;
    QVector<QPair<int, int>> eiges;
    QVector<QPair<int, int>> rubbing;
    QVector<float> values;
    QVector<float> res;

    points << VectorN<float, 2>(2, 0) << VectorN<float, 2>(0, 2) << VectorN<float, 2>(-2, 0) << VectorN<float, 2>(0, -2);
    pPoints << VectorN<float, 2>(0, 4) << VectorN<float, 2>(0, -4);
    rubbing << QPair<int, int>(1, 0) << QPair<int, int>(3, 1);
    eiges << QPair<int, int>(0, 1) << QPair<int, int>(1, 2) << QPair<int, int>(2, 3) << QPair<int, int>(3, 0);
    Problem<2> problem4(points, pPoints, eiges, rubbing);
    values << 2 << 0 << 0 << 2 << -2 << 0 << 0 << -2 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1;
    res << 2 << 0 << 0 << 4 << -2 << 0 << 0 << -4 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1;
    auto res_s = performGaussNewton(values, problem4, 200).mid(0, 8);
    res = res.mid(0, 8);
    for(int i = 0; i < 8; i++)
        QVERIFY(res_s[i] - res[i] < 0.1);
    points.clear();
    pPoints.clear();
    rubbing.clear();
    values.clear();
    res.clear();
}

void Test_GaussNewton::performGaussNewtonTest7()
{
    QVector<VectorN<float, 2>> points;
    QVector<VectorN<float, 2>> pPoints;
    QVector<QPair<int, int>> eiges;
    QVector<QPair<int, int>> rubbing;
    QVector<float> values;
    QVector<float> res;

    points << VectorN<float, 2>(10, 0) << VectorN<float, 2>(0, 0) << VectorN<float, 2>(5, 5);
    pPoints << VectorN<float, 2>(10, 10) << VectorN<float, 2>(0, 10);
    rubbing << QPair<int, int>(2, 0) << QPair<int, int>(2, 1);
    eiges << QPair<int, int>(0, 1) << QPair<int, int>(1, 2)<< QPair<int, int>(2, 0);
    Problem<2> problem4(points, pPoints, eiges, rubbing);
    values << 10 << 0 << 0 << 0 << 5 << 5  << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1;
    res << 10 << 0 << 0 << 0 << 5 << 10 << 1 << 0 << 0 << 1<< 1 << 0 << 0 << 1 << 1 << 0 << 0 << 1;
    auto res_s = performGaussNewton(values, problem4, 200).mid(0, 6);
    res = res.mid(0, 6);
    for(int i = 0; i < 6; i++)
        QVERIFY(res_s[i] - res[i] < 0.1);
    points.clear();
    pPoints.clear();
    rubbing.clear();
    values.clear();
    res.clear();
}

void Test_GaussNewton::performGaussNewtonTest1()
{
    QVector<VectorN<float, 2>> points;
    QVector<VectorN<float, 2>> pPoints;
    QVector<QPair<int, int>> eiges;
    QVector<QPair<int, int>> rubbing;
    QVector<float> values;
    QVector<float> res;

    points << VectorN<float, 2>(5, 5);
    pPoints << VectorN<float, 2>(5, 5);
    rubbing << QPair<int, int>(0, 0);
    Problem<2> problem(points, pPoints, eiges, rubbing);
    values << 5 << 5 << 1 << 0 << 0 << 1;
    res << 5 << 5 << 1 << 0 << 0 << 1;
    QCOMPARE(performGaussNewton(values, problem, 50), res);
    points.clear();
    pPoints.clear();
    rubbing.clear();
    values.clear();
    res.clear();
}
