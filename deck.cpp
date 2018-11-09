/
// Created by Samuel Yeboah on 11/9/2018.
//
#include "card.h"
#include  "Deck.h"
using namespace std;
Deck::Deck(){
    Card::Suit cardType;
    myIndex = 0;
    int spot = 0;
    for(int x = 0; x<4;x++){
        if(x==0){
            cardType = Card::spades;
        }
        else if(x==1){
            cardType = Card::diamonds;
        }
        else if(x==2){
            cardType = Card::clubs;
        }
        else{
            cardType = Card::hearts;
        }
        for(int y = 0; y<13; y++){
                Card *temp = new Card(y+1,cardType);
                myCards[spot] = *temp;
                //setbuf(stdout, 0);
                //cout << myCards[spot].getRank() << "\n";
                spot++;
        }

    }
};

void Deck::shuffle(){
    for(int x =0;x<100;x++){
        int firstNum = rand()%51+0;
        int secondNum = rand()%51+0;
        Card firstCard = myCards[firstNum];
        Card secondCard = myCards[secondNum];
        myCards[secondNum] = firstCard;
        myCards[firstNum] = secondCard;
    }
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

void Deck::toDeckString(){
    for(int x =0; x<52; x++){
        cout << myCards[x].toString() << "\n";
    }
}
