#include <iostream>
#include "player.h"
#include <fstream>
using namespace std;

void dealHand(Deck &d, player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

int main() {
    ofstream outputFile;
    outputFile.open("output.txt");
    //number of cards required per hand
    const int numCards = 7;
    int noMatchCnt = 0;
    //players for game
    player p1("Joey");
    player p2("Sam");

    //deck for game
    Deck d;
    d.shuffle();

    dealHand(d, p1, numCards);
    outputFile << p1.getName() << " hand: " << p1.showHand();
    outputFile.close();

    outputFile.open("output.txt");
    dealHand(d, p2, numCards);
    outputFile << p2.getName() << " hand: " << p2.showHand();
    outputFile.close();

    //remove pairs that are already in hand
    p1.checkHandForPairs();
    p2.checkHandForPairs();
    outputFile.open("output.txt");
    outputFile << "\n";
    outputFile << p1.getName() << " hand: " << p1.showHand();
    outputFile << p2.getName() << " hand: " << p2.showHand();
    outputFile.close();

    while(p2.getBookSize() + p1.getBookSize() != 26) {
        //player 1s turn
        bool guessAgain;
        if (p1.getHandSize() == 0) {
            p1.addCard(d.dealCard());
        }else if(noMatchCnt == 4){
            break;
        } else {
            do {
                if (p1.getHandSize() == 0) {
                    p1.addCard(d.dealCard());
                }
                guessAgain = false;
                Card guess = p1.takeTurn();
                setbuf(stdout, 0);
                if (p2.cardInHand(guess)) {
                    Card gMatch = p2.removeCardFromHand(guess);

                    outputFile.open("output.txt");
                    outputFile << p2.getName() << " says - Yes, I have a " << gMatch.getRank();
                    outputFile << "\n";
                    outputFile.close();

                    Card temp = p1.removeCardFromHand(guess);
                    p1.bookCards(gMatch, guess);

                    outputFile.open("output.txt");
                    outputFile << p1.getName() << " books the " << guess.getRank();
                    outputFile << "\n";
                    outputFile.close();
                    guessAgain = true;
                } else {
                    outputFile.open("output.txt");
                    outputFile << p2.getName() << " says - Go Fish";
                    outputFile << "\n";
                    outputFile.close();
                    if(d.size() > 0) {
                        Card newCard = d.dealCard();
                        p1.addCard(newCard);

                        outputFile.open("output.txt");
                        outputFile << p1.getName() << " draws " + newCard.toString();
                        outputFile << "\n";
                        outputFile.close();
                    }
                    else{
                        outputFile.open("output.txt");
                        outputFile << "\nThere are no more cards to draw\n";
                        outputFile.close();
                        noMatchCnt++;
                    }
                }
            } while (guessAgain);
        }
        p1.checkHandForPairs();
        // player 2s turn
        if (p2.getHandSize() == 0) {
            p2.addCard(d.dealCard());
            break;
        } else if(noMatchCnt == 4){
            break;
        } else {
            do {
                if (p2.getHandSize() == 0) {
                    p2.addCard(d.dealCard());
                    break;
                }
                guessAgain = false;
                Card guess = p2.takeTurn();
                if (p1.cardInHand(guess)) {
                    Card gMatch = p1.removeCardFromHand(guess);

                    outputFile.open("output.txt");
                    outputFile << p1.getName() << " says - Yes, I have a " << gMatch.getRank();
                    outputFile << "\n";
                    outputFile.close();

                    Card temp = p2.removeCardFromHand(guess);
                    p2.bookCards(gMatch, guess);

                    outputFile.open("output.txt");
                    outputFile << p2.getName() << " books the " << guess.getRank();
                    outputFile << "\n";
                    outputFile.close();

                    guessAgain = true;
                } else {
                    outputFile.open("output.txt");
                    outputFile << p1.getName() << " says - Go Fish";
                    outputFile << "\n";
                    outputFile.close();

                    if(d.size()>0) {
                        Card newCard = d.dealCard();
                        p2.addCard(newCard);
                        setbuf(stdout, 0);

                        outputFile.open("output.txt");
                        outputFile << p2.getName() << " draws " + newCard.toString();
                        outputFile << "\n";
                        outputFile.close();
                    }
                    else{
                        outputFile.open("output.txt");
                        outputFile << "There are no more cards to draw. \n";
                        outputFile.close();
                    }
                }
            } while (guessAgain);
            p2.checkHandForPairs();
        }
    }
    outputFile.open("output.txt");
    outputFile <<"Game Over";
    outputFile << p1.showHand() << p1.showBooks();
    outputFile << p2.showHand() << p2.showBooks();
    outputFile.close();
    return 0;
}

