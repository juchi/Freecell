#ifndef BOARDSCENE_H
#define BOARDSCENE_H

#include <QGraphicsScene>

class BoardScene : public QGraphicsScene
{
    Q_OBJECT
public:
    BoardScene(const QRectF sceneRect, QObject* parent = 0);

signals:
    void rightClick();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BOARDSCENE_H
