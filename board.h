#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <QObject>

#include "card.h"
#include "deck.h"

class QGraphicsProxyWidget;
class QGraphicsScene;
class QGraphicsView;
class AceSpot;
class ColumnSpot;
class Freecell;

class Board : public QObject
{
    Q_OBJECT
public:
    Board();

    void dealCards();
    void freeCard(Card* card);
    int countFreeCells();
    bool hasEnoughFreecells(int cardsToMove);

    void automaticMove(Card*);
    void unselectCard();
    void selectCard(Card*);

    void setSelectedCard(Card*);
    Card* getSelectedCard();
    void addItem(QGraphicsProxyWidget*);

protected:
    std::vector<AceSpot*> mAceSpots;
    std::vector<Freecell*> mFreeCells;

    const static int NB_COLUMNS = 8;
    Card* mLeafColumns[NB_COLUMNS];
    ColumnSpot* mColumns[NB_COLUMNS];

    Deck* mDeck;
    QGraphicsView *mBoardWidget;
    QGraphicsScene* mScene;

    Card* mSelectedCard;
};

#endif // BOARD_H
