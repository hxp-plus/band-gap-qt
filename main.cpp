#include "mainwindow.h"

#include <QApplication>
#include "MatlabEngine.hpp"
#include "MatlabDataArray.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
