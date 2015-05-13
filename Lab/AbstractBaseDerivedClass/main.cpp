/* 
 * File:   main.cpp
 * Author: Joe
 *
 * Created on May 13, 2015, 12:53 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>

using namespace std;

//User Libraries
#include "BaseDeck.h"
#include "Card.h"
//Execution begins here!
int main(int argc, char** argv) {

    //Declare our deck
    BaseDeck deck;
    //Shufle the deck
    deck.shuffle();
    //Deal some cards
    int *hand=deck.deal();
    //Display the hand
    for(int card=0;card<5;card++){
        Card a(hand[card]);
        cout<<a.face()<<" "<<a.suit()<<" "<<a.value()<<endl;
    }
    //Delete the hand
    delete []hand;
    //Exit Stage Right
    return 0;
}

