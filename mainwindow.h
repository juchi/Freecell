#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Board;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

    void endGame();
signals:

public slots:
    void newGame();

protected:
    Board* mBoard;
};

#endif // MAINWINDOW_H
