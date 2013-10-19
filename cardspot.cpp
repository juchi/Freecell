#include "cardspot.h"
#include <QGraphicsProxyWidget>
#include <QPointF>
#include "card.h"
#include "board.h"

CardSpot::CardSpot(Board* board)
{
    mProxy = 0;
    mBoard = board;
}

bool CardSpot::isEmpty()
{
    return mChild == 0;
}

bool CardSpot::canStackCard(Card* card)
{
    return isEmpty() && card->isMovable();
}

bool CardSpot::isStackable()
{
    return false;
}

void CardSpot::setPosition(QPointF pos)
{
    mProxy->setPos(pos);
}

QPoint CardSpot::getChildPosition()
{
    return mProxy->pos().toPoint();
}

void CardSpot::select()
{
    Card* card = mBoard->getSelectedCard();
    if (card && canStackCard(card)) {
        card->setParent(this);
    }
}
