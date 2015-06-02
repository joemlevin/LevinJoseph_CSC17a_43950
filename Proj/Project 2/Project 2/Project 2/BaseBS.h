/* 
 * File:   BaseBS.h
 * Author: Joseph Levin
 * C++ Project 2 - Spring 2015 43950
 * 6/5/2015
 */

#ifndef BASEBS_H
#define	BASEBS_H
#include "AbsBS.h"

/*!
 * BaseBS is the base class for the battleship board.
 */
class BaseBS:AbsBS{
    protected:
        //!for storing the board
        char** board;
        //!X is hit, O is miss, + is ship, <space> is empty
        char piece[4]={'X','O','+', ' '};
        //!dimension of board
        int size;
    public:
        //!Constructor for base battleship board. Takes in an integer for
        //!the dimension of the board (area is nxn))
        BaseBS(int);
        //!Destructor for the board
        ~BaseBS();
        //!For initially filling board
        char** flBoard();
        //!For outputting the board formatted to show ships
        void pBoard();
            
};

#endif	/* BASEBS_H */

