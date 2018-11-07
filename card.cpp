#include <iostream>
#include <string>
#include  "card.h"

string Card::toString() const{
  return rankString(myRank) + suitString(mySuit);
}

