/* 
 * File:   BSboard.h
 * Author: Joseph Levin
 * C++ Project 2 - Spring 2015 43950
 * 6/5/2015
 */

#ifndef BSBOARD_H
#define	BSBOARD_H
//!Abstract class for the Battleship board
class BSboard{
    public:
        //!2D char array to store the board
        virtual char** board(int)=0;
        //!outputs the board
        virtual void output()=0;
        virtual ~BSboard()=0;
};

#endif	/* BSBOARD_H */

