#include <iostream>
#include <string>
#include <random>
#include "player.h"

Player::Player(){

};

void Player::addCard(Card c){
    myHand.push_back(c);
};

void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);

};

bool Player::checkHandForBook(Card &c1, Card &c2){

};

bool Player::rankInHand(Card c) const{
    vector<char>::iterator iter;

    for (iter = charList.begin(); iter != charList.end(); iter++) {
        std::cout << *iter;
    }
};

Card Player::chooseCardFromHand() const{
    int range = myHand.end() - myHand.begin() ;
    return  myHand[rand()%range];

};

bool Player::cardInHand(Card c) const{

};

Card Player::removeCardFromHand(Card c){
    std::remove(myHand.begin(),myHand.end(),c);
};

string Player::showHand() const{

};

string Player::showBooks() const{

};

int Player::getHandSize() const{

};

int Player::getBookSize() const{
return myBook.end() - myBook.begin();
};

bool Player::checkHandForPair(Card &c1, Card &c2){

};

bool Player::sameRankInHand(Card c) const{

};
