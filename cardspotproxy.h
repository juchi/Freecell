#ifndef FREECELLPROXY_H
#define FREECELLPROXY_H

#include <QGraphicsProxyWidget>

class CardSpot;

/*!
 * \brief The CardSpotProxy class
 *
 * A proxy widget that represents any card spot (freecell, ace spot, column spot).
 */
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
