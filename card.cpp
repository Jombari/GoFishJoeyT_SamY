#include <iostream>
#include <string>
#include <random>
#include  "card.h"

Card::Card(){
  srand(time(0));

};

Card::Card(int rank, Suit s){
  srand(time(0));
  myRank = rank;
  mySuit = s;

};

string Card::toString() const{
  return rankString(myRank) + suitString(mySuit);
};

bool Card::sameSuitAs(const Card& c) const {

  return mySuit == c.mySuit;

};

int  Card::getRank() const{
  return myRank;
};

string Card::suitString(Suit s) const{
  switch(myRank){
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


