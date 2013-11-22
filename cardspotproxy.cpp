#include "cardspotproxy.h"
#include "cardspot.h"

#include <QGraphicsSceneMouseEvent>

CardSpotProxy::CardSpotProxy(CardSpot* cardSpot, QGraphicsItem *parent) :
    QGraphicsProxyWidget(parent)
{
    mCardSpot = cardSpot;
}

void CardSpotProxy::select()
{
    mCardSpot->select();
}

void CardSpotProxy::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mCardSpot->select();
    }
}
