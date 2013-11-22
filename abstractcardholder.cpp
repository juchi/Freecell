#include "abstractcardholder.h"

/*!
 * \brief Construtor
 */
AbstractCardHolder::AbstractCardHolder()
{
    mParent = 0;
    mChild = 0;
}

AbstractCardHolder* AbstractCardHolder::getParent()
{
    return mParent;
}

void AbstractCardHolder::setChild(Card* card)
{
    mChild = card;
}

Card* AbstractCardHolder::getChild()
{
    return mChild;
}

int AbstractCardHolder::getZIndex()
{
    return 0;
}
