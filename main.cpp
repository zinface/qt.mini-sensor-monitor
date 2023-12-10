#include "mainwindow.h"
#include "minifloatingwindow.h"
#include "simplesensormonitor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_DisableHighDpiScaling);

    QApplication a(argc, argv);
    SimpleSensorMonitor w;
    w.show();
    return a.exec();
}
