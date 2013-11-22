#ifndef ACESPOT_H
#define ACESPOT_H

#include "cardspot.h"

class Board;
class Card;

/*!
 * \brief Represents ace spot objects
 *
 * The ace spot is the base of the card stack for a given color, going from ace to king.
 * This class handles the behaviour of the spot in order to allow only aces to
 * be stacked directly on it.
 */
class AceSpot : public CardSpot
{
public:
    AceSpot(Board*);

    bool canStackCard(Card*);
    bool isStackable();
    void setChild(Card *);
};

#endif // ACESPOT_H
