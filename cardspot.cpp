#include "cardspot.h"
#include <QGraphicsProxyWidget>
#include <QPointF>
#include "card.h"
#include "board.h"

/*!
 * \brief Constructor
 * \param board The board
 */
CardSpot::CardSpot(Board* board) : AbstractCardHolder()
{
    mProxy = 0;
    mBoard = board;
}

/*!
 * \brief Check if the card stop is free, i.e. has no card stacked
 * \return boolean
 */
bool CardSpot::isEmpty()
{
    return mChild == 0;
}

/*!
 * \brief Check if a card can be stacked on this spot
 * \param card The card to check
 * \return boolean
 */
bool CardSpot::canStackCard(Card* card)
{
    return isEmpty() && card->isMovable();
}

/*!
 * \brief Check if the cards can be stacked one after another on this spot
 * \return boolean
 */
bool CardSpot::isStackable()
{
    return false;
}

/*!
 * \brief Set the position of the spot to pos
 * \param pos The position to set
 */
void CardSpot::setPosition(QPointF pos)
{
    mProxy->setPos(pos);
}

/*!
 * \brief Get the position for a child card
 * \return The desired position
 */
QPoint CardSpot::getChildPosition()
{
    return mProxy->pos().toPoint();
}

/*!
 * \brief Handle the selection of this card spot
 */
void CardSpot::select()
{
    Card* card = mBoard->getSelectedCard();
    if (card && canStackCard(card)) {
        card->setParent(this);
    }
}
