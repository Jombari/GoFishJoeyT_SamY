#include  "deck.h"

Deck::Deck(){

};

void Deck::shuffle(){

};

Card Deck::dealCard(){
    Card tmp;
    if(myIndex == 52)
        return tmp;
    myIndex ++;
    return myCards[myIndex-1];

};

int  Deck::size() const{
    return SIZE - myIndex;
};
