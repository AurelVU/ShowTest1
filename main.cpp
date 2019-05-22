#include "mainwindow.h"
#include <QApplication>
#include <test_gaussnewton.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Test_GaussNewton *test = new Test_GaussNewton;
    QTest::qExec(test, argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
