#include <iostream>

using namespace std;

#include "board.h"
#include "mainwindow.h"

#include <QApplication>

int main (int argc, char * argv[])
{
    srand(time(0));
    std::cout << std::endl;

    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}

