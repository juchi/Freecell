#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <QObject>

#include "card.h"
#include "deck.h"

class QGraphicsProxyWidget;
class QGraphicsView;
class QWidget;

class AceSpot;
class ColumnSpot;
class Freecell;
class BoardScene;

class Board : public QObject
{
    Q_OBJECT
public:
    Board();

    void dealCards();
    void collectCards();

    void freeCard(Card* card);
    int countFreeCells();
    bool hasEnoughFreecells(int cardsToMove);

    void automaticMove(Card*);
    void unselectCard();
    void selectCard(Card*);

    void setSelectedCard(Card*);
    Card* getSelectedCard();
    void addItem(QGraphicsProxyWidget*);

    QWidget* getBoardWidget();

public slots:
    bool tryAutomaticAceMove(Card* card = 0);

protected:
    std::vector<AceSpot*> mAceSpots;
    std::vector<Freecell*> mFreeCells;

    const static int NB_COLUMNS = 8;
    Card* mLeafColumns[NB_COLUMNS];
    ColumnSpot* mColumns[NB_COLUMNS];

    Deck* mDeck;
    QGraphicsView *mBoardWidget;
    BoardScene* mScene;

    Card* mSelectedCard;
    std::vector<Card*> mCards;
};

#endif // BOARD_H
