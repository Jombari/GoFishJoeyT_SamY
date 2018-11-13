//
// Created by Samuel Yeboah on 11/9/2018.
//

#ifndef GOFISHREDO_Player_H
#define GOFISHREDO_Player_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "card.h"

using namespace std;
class Player {
public:
    Player();

    Player(string name);

    string getName() const ;


    void addCard(Card c);  //adds a card to the hand
    void bookCards(Card c1, Card c2);

    //Does the Player have the card c in her hand?
    bool cardInHand(Card c) const;

    //Remove the card c from the hand and return it to the caller
    Card removeCardFromHand(Card c);

    string showHand() const;
    string showBooks() const;

    int getHandSize() const;
    int getBookSize() const;

private:
    vector<Card> myHand;
    vector<Card> myBook;

    string myName;
};


#endif //GOFISHREDO_Player_H
