#include "board.h"
#include "cardwidget.h"
#include "cardproxy.h"
#include "columnspot.h"
#include "acespot.h"
#include "freecell.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPointF>

Board::Board() : QObject()
{
    int i;

    for (i = 0; i < NB_COLUMNS; i++) {
        mLeafColumns[i] = 0;
    }

    mSelectedCard = 0;

    mBoardWidget = new QGraphicsView();
    mBoardWidget->setStyleSheet("background-color:green;");

    mScene = new QGraphicsScene(QRectF(0, - (int)(CardWidget::HEIGHT * 1.2), 1200, 700), mBoardWidget);
    mBoardWidget->setScene(mScene);

    Freecell* freecell;
    for (i = 0; i < 4; i++) {
        freecell = new Freecell(this);
        freecell->setPosition(QPointF(i * CardWidget::WIDTH, mScene->sceneRect().y()));
        mFreeCells.push_back(freecell);
    }

    AceSpot* aceSpot;
    for (i = 0; i < 4; i++) {
        aceSpot = new AceSpot(this);
        aceSpot->setPosition(QPointF((4+i) * CardWidget::WIDTH, mScene->sceneRect().y()));
        mAceSpots.push_back(aceSpot);
    }

    ColumnSpot* columnSpot;
    for (i = 0; i < NB_COLUMNS; i++) {
        columnSpot = new ColumnSpot(this);
        columnSpot->setPosition(QPointF(i * CardWidget::WIDTH, 0));
        mColumns[i] = columnSpot;
    }

    mDeck = new Deck(this);

    dealCards();
    mBoardWidget->show();
}

void Board::addItem(QGraphicsProxyWidget *proxy)
{
    mScene->addItem(proxy);
}

void Board::dealCards()
{
    Card* card;
    int i = 0, col = 0;
    while (mDeck->getSize()) {
        card = mDeck->drawCard();
        QPoint pos((i % NB_COLUMNS) * CardWidget::WIDTH, (i / NB_COLUMNS) * CardWidget::HEIGHT / 8);
        card->setPosition(pos);
        card->setParent(mLeafColumns[col]);
        mLeafColumns[col] = card;

        // first line
        if (i / NB_COLUMNS == 0) {
            card->setParent(mColumns[i]);
        }
        col = ++i % NB_COLUMNS;
    }
}

void Board::freeCard(Card* card)
{
    Card* cell = 0;//getFreeCell();
    if (cell) {
        cell = card;
    }
}

int Board::countFreeCells()
{
    int count = 0;
    std::vector<Freecell*>::iterator it;
    for (it = mFreeCells.begin(); it < mFreeCells.end(); it++) {
        if ((*it)->isEmpty()) {
            count++;
        }
    }

    return count;
}

bool Board::hasEnoughFreecells(int cardsToMove)
{
    int capability = countFreeCells() + 1;

    return capability >= cardsToMove;
}

void Board::automaticMove(Card* card)
{
    std::vector<AceSpot*>::iterator itAce;
    for (itAce = mAceSpots.begin(); itAce < mAceSpots.end(); itAce++) {

    }

    std::vector<Freecell*>::iterator itFreecell;
    for (itFreecell = mFreeCells.begin(); itFreecell < mFreeCells.end(); itFreecell++) {
        if ((*itFreecell)->isEmpty()) {
            card->setParent(*itFreecell);
            break;
        }
    }
}

void Board::unselectCard()
{
    if (mSelectedCard) {
        mSelectedCard->setSelected(false);
        mSelectedCard = 0;
    }
}

void Board::selectCard(Card* card)
{
    if (mSelectedCard == card) {
        unselectCard();
    } else if (mSelectedCard && card->canStackCard(mSelectedCard)) {
        if (card->isOnAceSpot()) {
            mSelectedCard->setOnAceSpot(true);
        }
        mSelectedCard->setParent(card);
    } else {
        setSelectedCard(card);
    }
}

void Board::setSelectedCard(Card* card)
{
    if (mSelectedCard) {
        mSelectedCard->setSelected(false);
    }
    mSelectedCard = card;
    mSelectedCard->setSelected(true);
}

Card* Board::getSelectedCard()
{
    return mSelectedCard;
}
