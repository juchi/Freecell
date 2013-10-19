#include "columnspot.h"
#include "cardspotproxy.h"
#include <QFrame>
#include "cardwidget.h"
#include "board.h"

ColumnSpot::ColumnSpot(Board* board) : CardSpot(board)
{
    mProxy = new CardSpotProxy(this);
    QFrame* widget = new QFrame();
    widget->resize(CardWidget::WIDTH, CardWidget::HEIGHT);
    widget->setStyleSheet("background-color:#00FF00;border:1px solid black;");
    mProxy->setWidget(widget);
    mBoard->addItem(mProxy);
}

bool ColumnSpot::isStackable()
{
    return true;
}

bool ColumnSpot::canStackCard(Card* card)
{
    return isEmpty() && card->isMovable();
}
