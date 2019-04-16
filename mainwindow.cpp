#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GetterProblem<2> *getter = new GetterProblemFile<2>("/home/aurel/input_test.txt");
    Problem<2> problem(getter);
    points = getter->getPoints();
    edges = getter->getEiges();
    oldPoints = points;
    powerPoints = getter->getPowerPoints();
    r = getter->getRubbing();
    QVector<float> values;
    for (int i = 0; i < points.size(); i++)
        for (int j = 0; j < 2; j++)
            values << points[i][j];

    values = performGaussNewton(values, problem, 50);

    for (int i = 0; i < values.size() / 2; i++) {
        points[i][0] = values[2*i];
        points[i][1] = values[2*i + 1];
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.begin(ui->centralWidget);

    p.setPen(QPen(Qt::white,3,Qt::SolidLine));
    QPoint pointStart(30, 30);
    for (int i = 0; i < edges.size(); i++) {
        p.drawLine(2 * int((oldPoints[edges[i].first].x() + pointStart.x())),
                int(this->height() - 2 * (oldPoints[edges[i].first].y() + pointStart.y())),
                int(2 * (oldPoints[edges[i].second].x() + pointStart.x())),
                int(this->height() - 2 * (oldPoints[edges[i].second].y() + pointStart.y())));
    }
    p.setPen(QPen(Qt::red,3,Qt::SolidLine));

    for (int i = 0; i < edges.size(); i++) {
        p.drawLine(2 * int((points[edges[i].first].x() + pointStart.x())),
                int(this->height() - 2 * (points[edges[i].first].y() + pointStart.y())),
                2 * int((points[edges[i].second].x() + pointStart.x())),
                int(this->height() - 2 * (points[edges[i].second].y() + pointStart.y())));
    }
    p.setPen(QPen(Qt::green,3,Qt::SolidLine));
    for (int i = 0; i < r.size(); i++) {
        p.drawLine(2 * int((oldPoints[r[i].first].x() + pointStart.x())),
                int(this->height() - 2 * (oldPoints[r[i].first].y() + pointStart.y())),
                int(2 * (powerPoints[r[i].second].x() + pointStart.x())),
                int(this->height() - 2 * (powerPoints[r[i].second].y() + pointStart.y())));
    }
}
