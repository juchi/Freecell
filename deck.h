#ifndef DECK_H
#define DECK_H

#include <vector>

class Board;
class Card;

class Deck
{
public:
    Deck(Board* board);

    void shuffle();
    void showCards();
    Card* drawCard();

    int getSize();

protected:
    void build(Board* board);

    std::vector<Card*> mCards;

};

#endif // DECK_H
