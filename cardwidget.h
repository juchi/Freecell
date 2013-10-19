#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QFrame>
#include <QLabel>
#include "card.h"

class CardWidget : public QFrame
{
    Q_OBJECT
public:
    CardWidget(QWidget *parent = 0);

    void setText(QString);
    void setColor(cardcolor color);

    const static int WIDTH = 140;
    const static int HEIGHT = 230;

protected:

    QLabel* mLabel;
    QLabel* mColorLabel;
    QLabel* mBigColorLabel;
};

#endif // CARDWIDGET_H
