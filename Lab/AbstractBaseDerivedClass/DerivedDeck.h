/* 
 * File:   DerivedDeck.h
 * Author: Joe
 *
 * Created on May 13, 2015, 1:51 PM
 */

#ifndef DERIVEDDECK_H
#define	DERIVEDDECK_H
#include "BaseDeck.h"
#include "AbsDeck.h"

class DerivedDeck:public BaseDeck{
    public:
        DerivedDeck();
        int *more;
};

#endif	/* DERIVEDDECK_H */

