/* 
 * File:   AbsBS
 * Author: Joseph Levin
 * C++ Project 2 - Spring 2015 43950
 * 6/5/2015
 */

#ifndef ABSBS_H
#define	ABSBS_H
//!Abstract class for the Battleship board
class AbsBS{
    public:
        //!2D char array to store the board
        virtual char** flBoard()=0;
        //!outputs the board
        virtual void pBoard()=0;
};

#endif	/*  ABSBS_H */

