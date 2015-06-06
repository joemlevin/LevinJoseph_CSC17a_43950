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
        //char piece[4]={'X','O','+', ' '};
        char* piece;
        //!dimension of board
        int size;
        //!ships on board
        int ships;
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
        //!place handles the ship placing procedure for the player.
        //!it checks to make sure the given coordinates are within
        //!the acceptable range of size, and then sets the given tile
        //!to the + char to represent a ship has been placed
        void place();
        //!target handles the process of targeting a spot to fire on it
        void target();
        //!getShips returns the value of the ships member variable
        int getShips(){return ships;}
};
#endif	/* BASEBS_H */