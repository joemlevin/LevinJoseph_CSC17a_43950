/* 
 * File:   Coin.h
 * Author: Joe
 *
 * Created on May 13, 2015, 3:13 PM
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

