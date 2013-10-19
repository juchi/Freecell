#ifndef COLUMNSPOT_H
#define COLUMNSPOT_H

#include "cardspot.h"

class Board;

class ColumnSpot : public CardSpot
{
public:
    ColumnSpot(Board*);
    bool isStackable();
    bool canStackCard(Card *);
};

#endif // COLUMNSPOT_H
