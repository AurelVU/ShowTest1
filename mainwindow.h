#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Problem/problem.h>
#include <GaussNewton/gaussnewton.h>
#include <GaussNewton/variable.h>
#include <QPainter>
#include <QPoint>
#include <QHBoxLayout>
#include <Problem/getterproblem.h>
#include <Problem/getterproblemfile.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QVector<VectorN<float, 2>> oldPoints;
    QVector<VectorN<float, 2>> powerPoints;
    QVector<VectorN<float, 2>> points;
    QVector<QPair<int, int>> edges;
    QVector<QPair<int, int>> r;

private slots:
    void on_pushButton_clicked();

protected:
    void paintEvent(QPaintEvent *) override;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
