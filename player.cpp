//
// Created by Samuel Yeboah on 11/9/2018.
//

#include "player.h"
using namespace std;

    player::player(string name){
        myName = name;
    };

    string player::getName() const {
        return myName;
    };


    void player::addCard(Card c){
        if(myHand.size() <5){
            myHand.push_back(c);
        }
        return;
    };  //adds a card to the hand

    //Adds card to the book
    void player::bookCards(Card c1, Card c2){
        myBook.push_back(c1);
        myBook.push_back(c2);
        return;
    };

    //Does the player have the card c in her hand?
    bool player::cardInHand(Card c)const{
        vector <Card> ::const_iterator itr;
        for(itr=myHand.begin();itr!=myHand.end();itr++){
            if(c.getRank() == itr->getRank()){
                return true;
            }
        }
        return false;
    }

    //Remove the card c from the hand and return it to the caller
    Card player::removeCardFromHand(Card c){
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

    string player::showHand() const{
        vector<Card>::const_iterator itr;
        string hand = "";
        for(itr = myHand.begin(); itr!=myHand.end();itr++){
            hand+= itr->toString() + "  ";
        }
        hand+= "\n";
        return hand;
    };

    string player::showBooks() const{
        vector<Card>::const_iterator itr;
        string books = "";
        int newLineFlag = 0;
        for(itr = myBook.begin();itr!=myBook.end();itr++){
            books+= itr->toString();
            books+= "   ";
            newLineFlag++;
            if(newLineFlag==2){
                newLineFlag = 0;
                books += "\n";
            }
        }
        return books;
    };

    int player::getHandSize() const{
        return myHand.size();
    };
    int player::getBookSize() const{
        return myBook.size();
    };


    Card player::chooseCardFromHand() const{
        return myHand[rand()%getHandSize()];

    };
    void player::takeTurn(){
        Card tmp = chooseCardFromHand();
        cout << myName << " asks - Do you have a " << tmp.getRank()  << "?" << endl


    };
