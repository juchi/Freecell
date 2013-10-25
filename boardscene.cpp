#include "boardscene.h"
#include <QGraphicsSceneMouseEvent>

BoardScene::BoardScene(const QRectF sceneRect, QObject* parent) : QGraphicsScene(sceneRect, parent)
{
}

void BoardScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsScene::mousePressEvent(event);
    if (!event->isAccepted() && event->button() == Qt::RightButton) {
        emit rightClick();
    }
}
