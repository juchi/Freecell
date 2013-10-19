#include "cardproxy.h"
#include <QGraphicsSceneMouseEvent>
#include "card.h"

CardProxy::CardProxy(Card* card) :
    QGraphicsProxyWidget()
{
    mCard = card;
}

void CardProxy::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mCard->select();
    } else if (event->button() == Qt::RightButton) {
        mCard->setZIndex(mCard->getTopZIndex(), false);
    }
}

void CardProxy::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        if (mCard->getChild() == 0) {
            mCard->automaticMove();
        } else {
            int index = 1;
            if (mCard->getParent()) {
                index = mCard->getParent()->getZIndex() + 1;
            }
            mCard->setZIndex(index, false);
        }
    }
}
