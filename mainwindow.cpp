#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QImage>
#include <QtCharts/QChart>
#include "MatlabEngine.hpp"
#include "MatlabDataArray.hpp"
#include "string.h"
#include <QMessageBox>
#include <QVariant>
#include "stdio.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::unique_ptr<matlab::engine::MATLABEngine> matlabPtr = matlab::engine::connectMATLAB();
    matlabPtr->eval(u"clc");
    matlabPtr->eval(u"clear");
    matlabPtr->eval(u"load('data/band_gap_hxp.mat');");
    matlabPtr->eval(u"PLANK_CONST = 6.62e-34;");
    matlabPtr->eval(u"SPEED_OF_LIGHT = 3e8;");
    matlabPtr->eval(u"ELECTRON_VOLT = 1.6e-19;");
    matlabPtr->eval(u"FIT_TYPE = 'poly1';");

    matlabPtr->eval(u"figure('visible', 'off');hold on;");
    matlabPtr->eval(u"plot_all_fig(flipud(base_line_x), \
                    flipud(base_line_y), \
                    flipud(transmittance_10min), \
                    flipud(transmittance_20min), \
                    flipud(transmittance_30min), \
                    flipud(transmittance_40min), \
                    {'0min', '10min', '20min', '30min', '40min'}, \
                    '$\\lambda(nm)$', 'Transmittance(%)', 'Origin Data', \
                    'southeast');");
    matlabPtr->eval(u"hold off;save_fig('original_data');");

    QString filename = "figures/original_data/original_data.png";
    QImage image(filename);
    QPixmap pic=QPixmap::fromImage(image);
    ui->label->setPixmap(pic.scaled(1600,900,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));


    connect(ui->pushButton, SIGNAL (released()), this, SLOT (handleButton()));
    connect(ui->pushButton_2, SIGNAL (released()), this, SLOT (handleButton_2()));
}

void MainWindow:: handleButton()
{

    std::unique_ptr<matlab::engine::MATLABEngine> matlabPtr = matlab::engine::connectMATLAB();

    matlabPtr->eval(u"base_line_x_to_electron_volts = PLANK_CONST .* SPEED_OF_LIGHT .* \
                    (base_line_x.*(1e-9)).^(-1) ./ ELECTRON_VOLT;");

    matlabPtr->eval(u"figure('visible', 'off');hold on;");
    matlabPtr->eval(u"plot_all_fig(base_line_x_to_electron_volts, \
                    (log((base_line_y ./ base_line_y).^(-1))).^2, \
                    (log((transmittance_10min ./ base_line_y).^(-1))).^2, \
                    (log((transmittance_20min ./ base_line_y).^(-1))).^2, \
                    (log((transmittance_30min ./ base_line_y).^(-1))).^2, \
                    (log((transmittance_40min ./ base_line_y).^(-1))).^2, \
                    {'0min', '10min', '20min', '30min', '40min'}, \
                    'Energy(eV)', '$(\\alpha \\hbar \\omega)^2$', \
                    'Graph Needed to Solve Band Gap', \
                    'northwest');");
    matlabPtr->eval(u"hold off;save_fig('graph_needed_to_solve_band_gap');");

    QString filename = "figures/graph_needed_to_solve_band_gap/graph_needed_to_solve_band_gap.png";
    QImage image(filename);
    QPixmap pic=QPixmap::fromImage(image);
    ui->label->setPixmap(pic.scaled(1600,900,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->pushButton->setEnabled(false);
    ui->pushButton->setText("（已完成）");

}

void MainWindow:: handleButton_2()
{
    std::unique_ptr<matlab::engine::MATLABEngine> matlabPtr = matlab::engine::connectMATLAB();

    QMessageBox msgbox;

    msgbox.setText((QString("lower_limit_1=find_closest(str2double(") +
                QVariant(ui->doubleSpinBox->value()).toString() +
                QString("), base_line_x_to_electron_volts);")));
    msgbox.exec();

    matlabPtr->eval((QString("lower_limit_1=find_closest(str2double('") +
                     QVariant(ui->doubleSpinBox->value()).toString() +
                     QString("'), base_line_x_to_electron_volts);")).toStdU16String());
    matlabPtr->eval((QString("upper_limit_1=find_closest(str2double('") +
                     QVariant(ui->doubleSpinBox_2->value()).toString() +
                     QString("'), base_line_x_to_electron_volts);")).toStdU16String());

    matlabPtr->eval(u"base_line_x_to_electron_volts_zoomed = \
                          base_line_x_to_electron_volts(lower_limit_1:upper_limit_1); \
                      base_line_y_zoomed = base_line_y(lower_limit_1:upper_limit_1); \
                      transmittance_10min_zoomed = transmittance_10min(lower_limit_1:upper_limit_1); \
                      transmittance_20min_zoomed = transmittance_20min(lower_limit_1:upper_limit_1); \
                      transmittance_30min_zoomed = transmittance_30min(lower_limit_1:upper_limit_1); \
                      transmittance_40min_zoomed = transmittance_40min(lower_limit_1:upper_limit_1);");
    matlabPtr->eval(u"figure('visible', 'off');hold on;");
    matlabPtr->eval(u"plot_all_fig(base_line_x_to_electron_volts_zoomed, \
                    (log((base_line_y_zoomed ./ base_line_y_zoomed).^(-1))).^2, \
                    (log((transmittance_10min_zoomed ./ base_line_y_zoomed).^(-1))).^2, \
                    (log((transmittance_20min_zoomed ./ base_line_y_zoomed).^(-1))).^2, \
                    (log((transmittance_30min_zoomed ./ base_line_y_zoomed).^(-1))).^2, \
                    (log((transmittance_40min_zoomed ./ base_line_y_zoomed).^(-1))).^2, \
                    {'0min', '10min', '20min', '30min', '40min'}, \
                    'Energy(eV)', '$(\\alpha \\hbar \\omega)^2$', \
                    'Graph Needed to Solve Band Gap', \
                    'northwest');");
    matlabPtr->eval(u"hold off;save_fig('graph_needed_to_solve_band_gap_zoomed');");

    QString filename = "figures/graph_needed_to_solve_band_gap_zoomed/graph_needed_to_solve_band_gap_zoomed.png";
    QImage image(filename);
    QPixmap pic=QPixmap::fromImage(image);
    ui->label->setPixmap(pic.scaled(1600,900,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->setText("（已完成）");
    ui->doubleSpinBox->setEnabled(false);
    ui->doubleSpinBox_2->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

