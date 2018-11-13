//
// Created by Samuel Yeboah on 11/9/2018.
//

#ifndef GOFISHREDO_PLAYER_H
#define GOFISHREDO_PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Deck.h"

using namespace std;
class player {
public:
    player();

    player(string name);

    string getName() const ;


    void addCard(Card c);  //adds a card to the hand
    void bookCards(Card c1, Card c2);

    //Does the player have the card c in her hand?
    bool cardInHand(Card c) const;

    //Remove the card c from the hand and return it to the caller
    Card removeCardFromHand(Card c);

    bool checkHandForPair(Card &c1, Card &c2);

    string showHand() const;
    string showBooks() const;

    int getHandSize() const;
    int getBookSize() const;

    void takeTurn();

    Card chooseCardFromHand() const;

private:
    vector<Card> myHand;
    vector<Card> myBook;

    string myName;
};


#endif //GOFISHREDO_PLAYER_H
