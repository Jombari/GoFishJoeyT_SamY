//
// Created by Samuel Yeboah on 11/9/2018.
//
#include <iostream>
#include <string>
#include <ctime>
#include  "card.h"
#include <cstdlib>
#include <sstream>
#include <algorithm>

Card::Card(){
    srand(time(0));
    myRank = -1;
};

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
    srand(time(0));
};

string Card::toString() const{
    srand(time(0));
    return rankString(myRank) + suitString(mySuit);
};

bool Card::sameSuitAs(const Card& c) const {
    srand(time(0));
    if(c.mySuit == this->mySuit) {
        return true;
    }
    return false;
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
    if(r >1 && r < 11){
        std::ostringstream os;
        os << r;
        return os.str();

     }

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
    srand(time(0));
    return rhs.myRank == this->myRank && this->sameSuitAs(rhs);
};

bool Card::operator != (const Card& rhs) const{
    srand(time(0));
    if(rhs.myRank == this->myRank && this->sameSuitAs(rhs)){
        return false;
    }
    return true;
};

