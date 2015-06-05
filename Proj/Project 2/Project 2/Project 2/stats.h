/* 
 * File:   stats.h
 * Author: Joseph Levin
 * C++ Project 2 - Spring 2015 43950
 * 6/5/2015
 */

#ifndef STATS_H
#define	STATS_H
/*!
 * Stats stores the number of wins, losses, and number of guesses
 */
struct Stats{
    //!number of wins for Mastermind
    int winsMM;
    //!number of loses for Mastermind
    int losesMM;
    //!number of guesses for Mastermind
    int nGuess;
    //!number of wins for BattleShip
    int winsBS;
    //!number of loses for BattleShip
    int losesBS;
};


#endif	/* STATS_H */

