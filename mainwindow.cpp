#include "mainwindow.h"
#include "board.h"
#include <QMenuBar>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    QMenu* fileMenu = new QMenu("File");
    fileMenu->addAction("New game", this, SLOT(newGame()));
    fileMenu->addAction("Quit", qApp, SLOT(quit()));
    menuBar()->addMenu(fileMenu);

    setWindowTitle("Freecell");

    mBoard = new Board();
    QWidget* widget = mBoard->getBoardWidget();
    setCentralWidget(widget);

    newGame();
}

void MainWindow::newGame()
{
    endGame();
    mBoard->dealCards();
}

void MainWindow::endGame()
{
    mBoard->collectCards();
}
