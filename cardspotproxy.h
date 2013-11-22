#ifndef FREECELLPROXY_H
#define FREECELLPROXY_H

#include <QGraphicsProxyWidget>

class CardSpot;
class QGraphicsSceneMouseEvent;

class CardSpotProxy : public QGraphicsProxyWidget
{
public:
    CardSpotProxy(CardSpot* cardSpot, QGraphicsItem *parent = 0);

    void select();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    CardSpot* mCardSpot;
};

#endif // FREECELLPROXY_H
