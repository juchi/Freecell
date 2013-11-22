#include "cardspotproxy.h"
#include "cardspot.h"

#include <QGraphicsSceneMouseEvent>

/*!
 * \brief Constructor
 * \param cardSpot The card spot object to link
 * \param parent The parent item
 */
CardSpotProxy::CardSpotProxy(CardSpot* cardSpot, QGraphicsItem *parent) :
    QGraphicsProxyWidget(parent)
{
    mCardSpot = cardSpot;
}

/*!
 * \brief Access to the card spot object's select() method
 */
void CardSpotProxy::select()
{
    mCardSpot->select();
}

/*!
 * \brief Handles mouse press events
 * \param event The mouse event
 */
void CardSpotProxy::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mCardSpot->select();
    }
}
