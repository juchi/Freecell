#include "card.h"
#include "cardwidget.h"
#include "cardproxy.h"
#include "board.h"

#include <iostream>
#include <sstream>

Card::Card(cardcolor color, cardvalue value, Board* board) : AbstractCardHolder()
{
    mChild = 0;
    mColor = color;
    mValue = value;
    mBoard = board;
    mIsOnAceSpot = false;

    mWidget = new CardWidget();
    mWidget->setText(getLabel().c_str());
    mWidget->setColor(getColor());
    setSelected(false);

    mProxy = new CardProxy(this);
    mProxy->setWidget(mWidget);
    mBoard->addItem(mProxy);
}

void Card::presents()
{
    std::cout << getLabel() << std::endl;
}

std::string Card::getLabel()
{
    return getValueName() + " of " + getColorName();
}

void Card::setParent(AbstractCardHolder* parent)
{
    if (mParent) {
        mParent->setChild(0);
    }
    mParent = parent;
    if (mParent) {
        mParent->setChild(this);
        updatePosition();
        mBoard->unselectCard();
    }
}

int Card::countChildren()
{
    if (mChild == 0) {
        return 0;
    }
    return mChild->countChildren() + 1;
}

bool Card::canStackCard(Card* card)
{
    return isStackable() && getChild() == 0 && card->isMovable() && isValidParentOf(card);
}

bool Card::isStackable()
{
    return mParent->isStackable();
}

bool Card::isMovable()
{
    if (mIsOnAceSpot) {
        return false;
    }
    if (mChild == 0) {
        return true;
    }
    return isValidParentOf(mChild) && mChild->isMovable() && mBoard->hasEnoughFreecells(countChildren() + 1);
}

bool Card::isValidParentOf(Card* card)
{
    if (card == 0) {
        return true;
    }
    if (mIsOnAceSpot) {
        return getValue() - card->getValue() == -1 && card->getColor() == getColor();
    }
    return getValue() - card->getValue() == 1 && card->getBlackRedColor() != getBlackRedColor();
}

void Card::setOnAceSpot(bool on)
{
    mIsOnAceSpot = on;
}

bool Card::isOnAceSpot()
{
    return mIsOnAceSpot;
}

std::string Card::getValueName()
{
    std::string cardValue = "";

    switch (mValue) {
    case ACE:
        cardValue = "ACE";
        break;
    case JACK:
        cardValue = "JACK";
        break;
    case QUEEN:
        cardValue = "QUEEN";
        break;
    case KING:
        cardValue = "KING";
        break;
    default:
        std::stringstream ss;
        ss << mValue;
        cardValue = ss.str();
        break;
    }

    return cardValue;
}

std::string Card::getColorName()
{
    std::string colorName = "";

    switch (mColor) {
    case HEARTS:
        colorName = "HEARTS";
        break;
    case DIAMONDS:
        colorName = "DIAMONDS";
        break;
    case SPADES:
        colorName = "SPADES";
        break;
    case CLUBS:
        colorName = "CLUBS";
        break;
    }

    return colorName;
}

cardvalue Card::getValue()
{
    return mValue;
}

cardcolor Card::getColor()
{
    return mColor;
}

char Card::getBlackRedColor()
{
    if (mColor == HEARTS || mColor == DIAMONDS) {
        return 1;
    }
    return 2;
}

QPoint Card::getChildPosition()
{
    QPoint pos = getPosition();
    int x = pos.x();
    int y = pos.y();
    if (!mIsOnAceSpot) {
        y += + CardWidget::HEIGHT / 8;
    }

    return QPoint(x, y);
}

QPoint Card::getPosition()
{
    return mPosition;
}

void Card::setPosition(QPoint pos)
{
    mPosition = pos;
    mWidget->move(mPosition);
    if (mChild) {
        mChild->updatePosition();
    }
}

void Card::updatePosition()
{
    setPosition(mParent->getChildPosition());
    setZIndex(mParent->getZIndex() + 1);
}

int Card::getTopZIndex()
{
    if (mChild) {
        return mChild->getTopZIndex();
    }
    return getZIndex() + 1;
}

int Card::getZIndex()
{
    return mProxy->zValue();
}

void Card::setZIndex(int index, bool cascade)
{
    mProxy->setZValue(index);
    if (mChild && cascade) {
        mChild->setZIndex(index + 1);
    }
}

void Card::show()
{
    mWidget->show();
}

void Card::hide()
{
    mWidget->hide();
}

void Card::select()
{
    mBoard->selectCard(this);
}

void Card::setSelected(bool selected)
{
    if (selected) {
        mWidget->setStyleSheet("CardWidget {background-color:white;border: 2px solid yellow;border-radius:5px;}");
    } else {
        mWidget->setStyleSheet("CardWidget {background-color:white;border: 2px solid black;border-radius:5px;}");
    }
}

void Card::automaticMove()
{
    mBoard->automaticMove(this);
}
