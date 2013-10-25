#ifndef CARD_H
#define CARD_H

#include <QPoint>

#include "abstractcardholder.h"

enum cardvalue {ACE=1, JACK=11, QUEEN=12, KING=13};
enum cardcolor {HEARTS=1, DIAMONDS=2, SPADES=3, CLUBS=4};

class CardWidget;

class CardProxy;
class Board;

class Card : public AbstractCardHolder
{
public:
    Card();
    Card(cardcolor color, cardvalue value, Board* board);

    void setParent(AbstractCardHolder*);
    int countChildren();

    bool canStackCard(Card*);
    bool isStackable();
    bool isMovable();
    bool isValidParentOf(Card*);
    void setOnAceSpot(bool);
    bool isOnAceSpot();

    std::string getValueName();
    std::string getColorName();
    void presents();
    std::string getLabel();

    cardvalue getValue();
    cardcolor getColor();
    char getBlackRedColor();

    QPoint getPosition();
    QPoint getChildPosition();
    void setPosition(QPoint pos);
    void updatePosition();
    int getTopZIndex();
    int getZIndex();
    void setZIndex(int index, bool cascade = true);
    void hide();
    void show();

    void select();
    void setSelected(bool selected);
    void automaticMove();

protected:
    cardcolor mColor;
    cardvalue mValue;

    Board* mBoard;
    CardWidget* mWidget;
    CardProxy* mProxy;

    QPoint mPosition;

    bool mIsOnAceSpot;

};
#endif // CARD_H
