#include <iostream>

using namespace std;

#include "board.h"
#include <QApplication>

int main (int argc, char * argv[])
{
    srand(time(0));
    std::cout << std::endl;

    QApplication app(argc, argv);

    Board board;

    return app.exec();
}

