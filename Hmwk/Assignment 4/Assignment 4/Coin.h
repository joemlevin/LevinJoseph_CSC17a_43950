/* File:   Coin.h
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */


#ifndef COIN_H
#define	COIN_H
#include <string>
class Coin{
    private:
        std::string sideUp;
    public:
        Coin();
        void toss();
        std::string getSideUp();
};


#endif	/* COIN_H */

