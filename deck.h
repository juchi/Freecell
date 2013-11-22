#ifndef DECK_H
#define DECK_H

#include <vector>

class Board;
class Card;

/*!
 * \brief A card deck
 */
class Deck
{
public:
    Deck(Board* board);

    void shuffle();
    Card* drawCard();
    void pushCard(Card*);

    int getSize();

protected:
    void build(Board* board);

    std::vector<Card*> mCards;

};

#endif // DECK_H
