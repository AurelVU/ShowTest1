#ifndef TEST_GAUSSNEWTON_H
#define TEST_GAUSSNEWTON_H


#include <QtTest>
#include <GaussNewton/gaussnewton.h>
#include <QObject>

class Test_GaussNewton  : public QObject
{
    Q_OBJECT
public:
    explicit Test_GaussNewton(QObject *parent = nullptr);

private slots: // должны быть приватными
    void calculeteJrTest();
    void computeGradientGHTest();
    void performGaussNewtonTest1();
    void performGaussNewtonTest2();
    void performGaussNewtonTest3();
    void performGaussNewtonTest4();
    void performGaussNewtonTest5();
    void performGaussNewtonTest6();
    void performGaussNewtonTest7();
};


#endif // TEST_GAUSSNEWTON_H
