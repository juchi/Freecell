#include "cardproxy.h"
#include <QGraphicsSceneMouseEvent>
#include "card.h"
#include <iostream>
#include <QWidget>
#include <QGraphicsScene>
#include "cardspotproxy.h"

CardProxy::CardProxy(Card* card) :
    QGraphicsProxyWidget()
{
    mCard = card;
    setData(0, QVariant("card"));
}

void CardProxy::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mCard->select();
        mCard->setZIndex(100);
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
    } else if (event->button() == Qt::LeftButton) {
        QList<QGraphicsItem*> items = this->scene()->items(event->scenePos());

        for (int i = 0; i < items.size(); i++) {
            if (items[i] != this && items[i]->data(0) == QVariant("card")) {
                CardProxy* proxy = dynamic_cast<CardProxy*>(items[i]);
                if (proxy->mCard->getChild() == 0) {
                    proxy->mCard->select();
                }
                break;
            } else if (items[i] != this && items[i]->data(0) == QVariant("acespot")) {
                CardSpotProxy* proxy = dynamic_cast<CardSpotProxy*>(items[i]);
                proxy->select();
                break;
            } else if (items[i] != this && items[i]->data(0) == QVariant("freecell")) {
                CardSpotProxy* proxy = dynamic_cast<CardSpotProxy*>(items[i]);
                proxy->select();
                break;
            }
        }
        mCard->updatePosition();
    }
}

void CardProxy::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        mCard->setPosition(event->scenePos().toPoint() - event->buttonDownPos(Qt::LeftButton).toPoint());
    }
}
