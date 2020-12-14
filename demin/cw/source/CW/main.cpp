#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(0)));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
