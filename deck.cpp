#include "deck.h"
#include "card.h"

/*!
 * \brief Constructor
 * \param board The board
 */
Deck::Deck(Board* board)
{
    build(board);
}

/*!
 * \brief Shuffle the cards in this deck
 *
 * The cards are randomly reordered in the deck. Any number of cards can be
 * present in the deck.
 */
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

/*!
 * \brief Build the deck
 *
 * The function creates the cards ordered by color and vale
 * and adds them to the deck successively.
 *
 * \param board The board
 */
void Deck::build(Board* board)
{
    mCards.clear();

    for (cardcolor i = HEARTS; i<= CLUBS; i++) {
        for (cardvalue j = ACE; j <= KING; j++) {
            pushCard(new Card(i, j, board));
        }
    }
}

/*!
 * \brief Draw the last card from the deck
 * \return A card
 */
Card* Deck::drawCard()
{
    Card* card = mCards.back();
    mCards.pop_back();

    return card;
}

/*!
 * \brief Push a card at the end of the deck
 * \param card The card to add
 */
void Deck::pushCard(Card* card)
{
    mCards.push_back(card);
}

/*!
 * \brief Get the number of cards in the deck
 * \return The size (int)
 */
int Deck::getSize()
{
    return mCards.size();
}
