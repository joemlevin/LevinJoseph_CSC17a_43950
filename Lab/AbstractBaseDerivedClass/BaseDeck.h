/* 
 * File:   BaseDeck.h
 * Author: Joe
 *
 * Created on May 13, 2015, 1:23 PM
 */

#ifndef BASEDECK_H
#define	BASEDECK_H
#include "AbsDeck.h"

class BaseDeck:AbsDeck{
    protected:
        int place;
        int *cards;
        int size;
    public:
        BaseDeck();
        ~BaseDeck(){delete []cards;};
        void shuffle();
        int *deal();
};


#endif	/* BASEDECK_H */

