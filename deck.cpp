#include "deck.h"
#include "card.h"

Deck::Deck(Board* board)
{
    build(board);
}

void Deck::shuffle()
{
    char c;
    std::vector<Card*> tmpCards;
    std::vector<Card*>::iterator it;

    while (mCards.size()) {
        c = rand() % mCards.size();
        it = mCards.begin() + c;
        tmpCards.push_back(*it);
        mCards.erase(it);
    }
    mCards = tmpCards;
}

void Deck::showCards()
{
    for (unsigned int i = 0; i < mCards.size(); i++) {
        mCards.at(i)->presents();
    }
}

void Deck::build(Board* board)
{
    mCards.clear();

    for (cardcolor i = HEARTS; i<= CLUBS; i++) {
        for (cardvalue j = ACE; j <= KING; j++) {
            pushCard(new Card(i, j, board));
        }
    }
}

Card* Deck::drawCard()
{
    Card* card = mCards.back();
    mCards.pop_back();

    return card;
}

void Deck::pushCard(Card* card)
{
    mCards.push_back(card);
}

int Deck::getSize()
{
    return mCards.size();
}
