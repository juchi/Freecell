#ifndef CARDPROXY_H
#define CARDPROXY_H

#include <QGraphicsProxyWidget>
class Card;

class CardProxy : public QGraphicsProxyWidget
{
    Q_OBJECT
public:
    explicit CardProxy(Card* card);

signals:

public slots:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    Card* mCard;
};

#endif // CARDPROXY_H
