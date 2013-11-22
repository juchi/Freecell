#ifndef CARDPROXY_H
#define CARDPROXY_H

#include <QGraphicsProxyWidget>

class Card;

/*!
 * \brief The CardProxy class
 *
 * A QGraphicsProxyWidget reimplemented in order to manage mouse events
 * over the cards of the board.
 */
class CardProxy : public QGraphicsProxyWidget
{
public:
    explicit CardProxy(Card* card);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    Card* mCard;
};

#endif // CARDPROXY_H
