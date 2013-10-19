QT += widgets
QT += core
CONFIG += console

SOURCES += main.cpp \
    card.cpp \
    deck.cpp \
    board.cpp \
    cardwidget.cpp \
    cardproxy.cpp \
    cardspot.cpp \
    freecell.cpp \
    abstractcardholder.cpp \
    columnspot.cpp \
    cardspotproxy.cpp \
    acespot.cpp

HEADERS += \
    card.h \
    deck.h \
    board.h \
    cardwidget.h \
    cardproxy.h \
    cardspot.h \
    freecell.h \
    abstractcardholder.h \
    columnspot.h \
    cardspotproxy.h \
    acespot.h

RESOURCES += \
    resources.qrc

