/* 
 * File:   mastermind.h
 * Author: Joseph
 *
 * Created on April 26, 2015, 7:47 PM
 */

#ifndef MASTERMIND_H
#define	MASTERMIND_H

struct Answer{
    int *code;//stores the integer combination
    int mxGuess;//keeps track of maximum guesses allowed
    
};

struct Guess{
    int *code;//stores the guess
    int corPos;//tallies the number of correct positions in a guess
    int corNum;//tallies the number of correct numbers in a guess
};

struct Guesses{
    Guess *guess;//array of guess attempts
    int nGuess;//how many guesses have been taken
};

struct Stats{
    int wins;//number of wins
    int loses;//number of loses
    int nGuess;//number of loses
};



#endif	/* MASTERMIND_H */

