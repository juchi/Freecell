#include "cardspotproxy.h"
#include "cardspot.h"

#include <QGraphicsSceneMouseEvent>

CardSpotProxy::CardSpotProxy(CardSpot* cardSpot, QGraphicsItem *parent) :
    QGraphicsProxyWidget(parent)
{
    mCardSpot = cardSpot;
}

void CardSpotProxy::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mCardSpot->select();
    }
}
