#include "freecell.h"
#include "board.h"
#include "cardwidget.h"
#include "cardspotproxy.h"

#include <QFrame>

Freecell::Freecell(Board* board) : CardSpot(board)
{
    mProxy = new CardSpotProxy(this);
    mProxy->setData(0, QVariant("freecell"));

    QFrame* widget = new QFrame();
    widget->resize(CardWidget::WIDTH, CardWidget::HEIGHT);
    widget->setStyleSheet("background-color:#00FF00;border:1px solid black;");
    mProxy->setWidget(widget);
    mBoard->addItem(mProxy);
}

