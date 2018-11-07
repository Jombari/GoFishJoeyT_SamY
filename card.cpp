#include <iostream>
#include <string>
#include  "card.h"

Card::Card(){

};

Card::Card(int rank, Suit s){
  myRank = rank;
  mySuit = s;

};

string Card::toString() const{
  return rankString(myRank) + suitString(mySuit);
};

bool Card::sameSuitAs(const Card& c) const {

};

int  Card::getRank() const{
  return myRank;
};

string Card::suitString(Suit s) const{

};

string Card::rankString(int r) const{

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


};

bool Card::operator != (const Card& rhs) const{


};


