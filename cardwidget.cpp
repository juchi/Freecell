#include "cardwidget.h"
#include <QVBoxLayout>

CardWidget::CardWidget(QWidget *parent) :
    QFrame(parent)
{
    mLabel = new QLabel(this);


    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setMargin(0);
    hLayout->addWidget(mLabel);

    mColorLabel = new QLabel(this);
    mColorLabel->setAlignment(Qt::AlignTop | Qt::AlignRight);
    hLayout->addWidget(mColorLabel);

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addLayout(hLayout);
    vLayout->setMargin(10);

    mBigColorLabel = new QLabel(this);
    mBigColorLabel->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    vLayout->addWidget(mBigColorLabel, 1);

    setLayout(vLayout);
    resize(WIDTH, HEIGHT);
}

void CardWidget::setText(QString text)
{
    mLabel->setText(text);
    mLabel->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    mLabel->setStyleSheet("background-color:white;");
    mLabel->setWordWrap(true);
}

void CardWidget::setColor(cardcolor color)
{
    QString resource;
    switch (color) {
    case HEARTS:
        resource = "hearts";
        break;
    case DIAMONDS:
        resource = "diamonds";
        break;
    case SPADES:
        resource = "spades";
        break;
    case CLUBS:
        resource = "clubs";
        break;
    }

    QPixmap pix = QPixmap(":/icons/" + resource).scaledToWidth(WIDTH / 8, Qt::SmoothTransformation);
    mColorLabel->setPixmap(pix);
    pix = QPixmap(":/icons/" + resource).scaledToWidth(WIDTH * 3 / 4, Qt::SmoothTransformation);
    mBigColorLabel->setPixmap(pix);

}
