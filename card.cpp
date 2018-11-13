//
// Created by Samuel Yeboah on 11/9/2018.
//
#include <iostream>
#include <string>
#include <random>
#include "time.h"
#include  "card.h"

Card::Card(){
    srand(time(0));
};

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
    srand(time(0));
};

string Card::toString() const{
  return rankString(myRank) + suitString(mySuit);
};

bool Card::sameSuitAs(const Card& c) const {

  return mySuit == c.mySuit;


};

int  Card::getRank() const{
    srand(time(0));
    return myRank;
};

string Card::suitString(Suit s) const{
    srand(time(0));
    switch(s){
        case spades:
            return "s";

        case hearts:
            return "h";

        case clubs:
            return "c";

        case diamonds:
            return "d";
    }
};

string Card::rankString(int r) const{
    srand(time(0));
    if(r >1 && r < 11)
        return  std::to_string(r);

    switch(r){
        case 1:
            return "A";
        case 11:
            return "J";
        case 12:
            return "Q";

        case 13:
            return "K";
    }
};

bool Card::operator == (const Card& rhs) const{
  return mySuit == rhs.mySuit && myRank == rhs.myRank;
};

bool Card::operator != (const Card& rhs) const{
  return mySuit != rhs.mySuit || myRank != rhs.myRank;

};



