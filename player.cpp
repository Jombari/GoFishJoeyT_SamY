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
        if(myHand.size() <7){
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
        Card removalCard;
        for(int x = 0;x<myHand.size();x++){
            if(myHand[x].getRank() == c.getRank()){
                removalCard = myHand[x];
                myHand.erase(myHand.begin()+x);
                return removalCard;
            };
        }
        return removalCard;
    };

    string player::showHand() const{
        string hand = "";
        for(int x = 0; x<myHand.size();x++){
            hand+= myHand[x].toString() + "  ";
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
        return myBook.size()/2;
    };

    Card player::chooseCardFromHand() const{
        int num = rand()%getHandSize();
        return myHand[num];

    };
    Card player::takeTurn(){
        Card tmp = chooseCardFromHand();
        cout << myName << " asks - Do you have a " << tmp.getRank()  << "?" << "\n";
        return tmp;
    };

    void player::checkHandForPairs(){
        vector<Card>::iterator itr;
        for(int x = 0;x<myHand.size();x++){
            for(int y = x+1;y<myHand.size();y++){
                if(myHand[x].getRank() == myHand[y].getRank()){
                    this->bookCards(myHand[x],myHand[y]);
                    this->removeCardFromHand(myHand[x]);
                    this->removeCardFromHand(myHand[y-1]);
                }
            }
        }
    };
