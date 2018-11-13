
//
// Created by Samuel Yeboah on 11/9/2018.
//

#include "Player.h"
using namespace std;

    Player::Player(string name){
        myName = name;
    };

    string Player::getName() const {
        return myName;
    };


    void Player::addCard(Card c){
        if(myHand.size() <5){
            myHand.push_back(c);
        }
        return;
    };  //adds a card to the hand

    //Adds card to the book
    void Player::bookCards(Card c1, Card c2){
        myBook.push_back(c1);
        myBook.push_back(c2);
    };

    //Does the Player have the card c in her hand?
    bool Player::cardInHand(Card c)const{
        vector <Card> ::const_iterator itr;
        for(itr=myHand.begin();itr!=myHand.end();itr++){
            if(c.getRank() == itr->getRank()){
                return true;
            }
        }
        return false;
    }

    //Remove the card c from the hand and return it to the caller
    Card Player::removeCardFromHand(Card c){
        vector <Card> ::iterator itr;
        Card removalCard;
        for(itr = myHand.begin();itr!=myHand.end();itr++){
            if(itr->getRank() == c.getRank()){
                removalCard = *itr;
                myHand.erase(itr);
                return removalCard;
            };
        }
        return removalCard;
    };

    string Player::showHand() const{
        vector<Card, std::allocator<Card> >::const_iterator itr;
        string hand = "";
        for(itr = myHand.begin(); itr!=myHand.end();itr++){
            hand+= itr->toString() + " ";
        }
    };
    string Player::showBooks() const{};

    int Player::getHandSize() const{
        return myHand.size();
    };
    int Player::getBookSize() const{
        return myBook.size();
    };
