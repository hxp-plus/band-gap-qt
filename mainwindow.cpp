#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QImage>
#include <QtCharts/QChart>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString filename = "/home/hxp/band-gap-qt/test.png";
    QImage image(filename);
    QPixmap pic=QPixmap::fromImage(image);
    ui->label->setPixmap(pic.scaled(1600,900,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    connect(ui->pushButton, SIGNAL (released()), this, SLOT (handleButton()));
}

void MainWindow:: handleButton()
{
    ui->doubleSpinBox->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

