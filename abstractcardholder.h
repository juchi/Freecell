#ifndef ABSTRACTCARDHOLDER_H
#define ABSTRACTCARDHOLDER_H

class QPoint;
class Card;

class AbstractCardHolder
{
public:
    AbstractCardHolder();
    AbstractCardHolder* getParent();

    virtual void setChild(Card*);
    Card* getChild();

    virtual bool canStackCard(Card* card) = 0;
    virtual bool isStackable() = 0;

    virtual QPoint getChildPosition() = 0;
    virtual int getZIndex();

protected:
    AbstractCardHolder* mParent;
    Card* mChild;
};

#endif // ABSTRACTCARDHOLDER_H
