/* 
 * File:   BaseCard.h
 * Author: Joe
 *
 * Created on May 13, 2015, 12:58 PM
 */

#ifndef CARD_H
#define	CARD_H

#include "AbsDeck.h"

class Card{
    private:
        int num;
    public:
        Card(int);
        char suit();
        char face();
        int value();
            
};

#endif	/* CARD_H */

