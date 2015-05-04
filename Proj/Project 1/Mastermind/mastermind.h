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
    int *code;//!stores the integer combination
    int mxGuess;//!keeps track of maximum guesses allowed
    
};

/*!
 * Guess stores a guess in an int array, the number of correct positions
 * associated with the guess and the number of correct numbers
 */
struct Guess{
    int *code;//!stores the guess
    int corPos;//!tallies the number of correct positions in a guess
    int corNum;//!tallies the number of correct numbers in a guess
};

/*!
 * Guesses stores a pointer a Guess (one for each turn) and
 * the total number of guesses taken
 */
struct Guesses{
    Guess *guess;//!array of guess attempts
    int nGuess;//!how many guesses have been taken
};

/*!
 * Stats stores the number of wins, losses, and number of guesses
 */
struct Stats{
    int wins;//!number of wins
    int loses;//!number of loses
    int nGuess;//!number of guesses
};



#endif	/* MASTERMIND_H */

