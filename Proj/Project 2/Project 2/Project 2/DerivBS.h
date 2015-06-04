/* 
 * File:   DerivBS.h
 * Author: Joseph Levin
 * C++ Project 2 - Spring 2015 43950
 * 6/5/2015
 */
#ifndef DERIVBS_H
#define	DERIVBS_H

/*!
 * DerivBS is a derived class of BaseBS. It contains addition functions
 * for handling the computer logic
 */
class DerivBS:BaseBS{
    public:
        //!displays a version of the board with ships masked
        void radar();
        //!place for DerivBS randomly places ships for computer
        void place();
        //!target for DerivBS randomly fires on spots for computer
        void target();
};


#endif	/* DERIVBS_H */

