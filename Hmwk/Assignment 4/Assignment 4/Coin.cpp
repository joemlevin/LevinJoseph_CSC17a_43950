/* File:   Coin.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 * Purpose: Coin class definition
 */

#include <ctime>
#include <cstdlib>
#include "Coin.h"
#include "Circle.h"

Coin::Coin(){
    int flip=rand()%2+1;
    if(flip==1)
        sideUp="Heads";
    else
        sideUp="Tails";
}

void Coin::toss(){
    int flip=rand()%2+1;
    if(flip==1)
        sideUp="Heads";
    else
        sideUp="Tails";
}

std::string Coin::getSideUp(){
    return sideUp;
}