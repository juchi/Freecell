#ifndef FREECELL_H
#define FREECELL_H

#include "cardspot.h"

class Board;

class Freecell : public CardSpot
{
public:
    Freecell(Board*);
};

#endif // FREECELL_H
