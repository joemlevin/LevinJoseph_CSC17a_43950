/* 
 * File:   AbsDeck.h
 * Author: Joe
 * Created on May 13, 2015, 12:54 PM
 */

#ifndef ABSDECK_H
#define	ABSDECK_H
class AbsDeck{
    public:
        virtual void shuffle()=0;
        virtual int *deal()=0;
};


#endif	/* ABSDECK_H */

