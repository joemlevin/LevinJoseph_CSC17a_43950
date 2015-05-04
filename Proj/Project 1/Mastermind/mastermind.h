/* 
 * File:   mastermind.h
 * Author: Joseph
 *
 * Created on April 26, 2015, 7:47 PM
 */

#ifndef MASTERMIND_H
#define	MASTERMIND_H

/*!
 * Answer stores the correct code in an int array and the max guesses allowed
 */
struct Answer{
    //!stores the integer combination
    int *code;
    //!keeps track of maximum guesses allowed
    int mxGuess;
    
};

/*!
 * Guess stores a guess in an int array, the number of correct positions
 * associated with the guess and the number of correct numbers
 */
struct Guess{
    //!stores the guess
    int *code;
    //!tallies the number of correct positions in a guess
    int corPos;
    //!tallies the number of correct numbers in a guess
    int corNum;
};

/*!
 * Guesses stores a pointer a Guess (one for each turn) and
 * the total number of guesses taken
 */
struct Guesses{
    //!array of guess attempts
    Guess *guess;
    //!how many guesses have been taken
    int nGuess;
};

/*!
 * Stats stores the number of wins, losses, and number of guesses
 */
struct Stats{
    //!number of wins
    int wins;
    //!number of loses
    int loses;
    //!number of guesses
    int nGuess;
};



#endif	/* MASTERMIND_H */

