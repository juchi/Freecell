#ifndef CARDSPOT_H
#define CARDSPOT_H

#include "abstractcardholder.h"

class Board;
class Card;
class QPointF;
class QGraphicsProxyWidget;

class CardSpot : public AbstractCardHolder
{
public:
    CardSpot(Board*);
    bool isEmpty();
    virtual bool canStackCard(Card* card);
    bool isStackable();
    void setPosition(QPointF pos);
    QPoint getChildPosition();

    void select();

protected:
    Board* mBoard;
    QGraphicsProxyWidget* mProxy;
};

#endif // CARDSPOT_H
