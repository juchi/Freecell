#ifndef ACESPOT_H
#define ACESPOT_H

#include "cardspot.h"

class Board;
class Card;

class AceSpot : public CardSpot
{
public:
    AceSpot(Board*);
    bool canStackCard(Card*);
    bool isStackable();
    void setChild(Card *);
};

#endif // ACESPOT_H
