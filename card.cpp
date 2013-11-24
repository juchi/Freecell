/*
 * This file is part of Freecell.
 *
 * Freecell is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Freecell is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Freecell.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "card.h"
#include "cardwidget.h"
#include "cardproxy.h"
#include "board.h"

#include <QPropertyAnimation>

#include <iostream>
#include <sstream>

Card::Card(cardcolor color, cardvalue value, Board* board) : AbstractCardHolder()
{
    mChild = 0;
    mColor = color;
    mValue = value;
    mBoard = board;
    mIsOnAceSpot = false;
    mSelected = false;

    mWidget = new CardWidget();
    mWidget->setText(getLabel());
    mWidget->setColor(getColor());
    setSelected(false);

    mProxy = new CardProxy(this);
    mProxy->setWidget(mWidget);
    mBoard->addItem(mProxy);
}

void Card::presents()
{
    std::cout << getLabel().toStdString() << std::endl;
}

QString Card::getLabel()
{
    return getValueName() + " of " + getColorName();
}

QPixmap Card::getWidgetPixmap()
{
    return mWidget->grab();
}

void Card::setParent(AbstractCardHolder* parent, bool animate)
{
    if (mParent) {
        mParent->setChild(0);
    }
    mParent = parent;
    if (mParent) {
        mParent->setChild(this);
        updatePosition(animate);
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

QString Card::getValueName()
{
    QString cardValue = "";

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
        cardValue = ss.str().c_str();
        break;
    }

    return cardValue;
}

QString Card::getColorName()
{
    QString colorName = "";

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

void Card::animatePosition(QPoint pos)
{
    mPosition = pos;
    setZIndex(100);

    QPropertyAnimation *animation = new QPropertyAnimation(mWidget, "pos");
    animation->setDuration(100);
    animation->setStartValue(mWidget->pos());
    animation->setEndValue(mPosition);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    QObject::connect(animation, SIGNAL(finished()), this, SLOT(resetZIndex()));

    if (mChild) {
        mChild->updatePosition(true);
    }
}

void Card::setPosition(QPoint pos)
{
    mPosition = pos;
    mWidget->move(mPosition);
    if (mChild) {
        mChild->updatePosition();
    }
}

void Card::updatePosition(bool animate)
{
    if (animate) {
        animatePosition(mParent->getChildPosition());
    } else {
        setPosition(mParent->getChildPosition());
        setZIndex(mParent->getZIndex() + 1);
    }
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

void Card::resetZIndex()
{
    setZIndex(mParent->getZIndex() + 1);
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
    mSelected = selected;
    if (mSelected) {
        mWidget->setStyleSheet("CardWidget {background-color:white;border: 2px solid yellow;border-radius:5px;}");
    } else {
        mWidget->setStyleSheet("CardWidget {background-color:white;border: 2px solid black;border-radius:5px;}");
    }
}

bool Card::isSelected()
{
    return mSelected;
}

void Card::automaticMove()
{
    mBoard->automaticMove(this);
}
