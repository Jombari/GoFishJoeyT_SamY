//
// Created by Samuel Yeboah on 11/9/2018.
//

#ifndef GOFISHREDO_DECK_H
#define GOFISHREDO_DECK_H

#include "card.h"

class Deck{
    static const int SIZE = 52;

public:
    Deck();           // pristine, sorted Deck

    void shuffle();   // shuffle the cards in the current Deck
    Card dealCard();   // get a card, after 52 are dealt, fail

    int  size() const; // # cards left in the Deck
    void toDeckString();

private:
    Card myCards[SIZE];
    int myIndex;  // current card to deal
};
#endif //GOFISHREDO_DECK_H
