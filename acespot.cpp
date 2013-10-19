#include "acespot.h"
#include "board.h"
#include "cardwidget.h"
#include "cardspotproxy.h"
#include <QFrame>

AceSpot::AceSpot(Board* board) : CardSpot(board)
{
    mProxy = new CardSpotProxy(this);
    QFrame* widget = new QFrame();
    widget->resize(CardWidget::WIDTH, CardWidget::HEIGHT);
    widget->setStyleSheet("background-color:#00FF00;border:1px solid black;");
    mProxy->setWidget(widget);
    mBoard->addItem(mProxy);
}

bool AceSpot::canStackCard(Card* card)
{
    if (CardSpot::canStackCard(card) && card->getValue() == ACE) {
        return true;
    }
    return false;
}

bool AceSpot::isStackable()
{
    return true;
}

void AceSpot::setChild(Card* card)
{
    CardSpot::setChild(card);
    if (card) {
        card->setOnAceSpot(true);
    }
}
