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
    int corPos;//tallies the number of correct positions in a guess
    int corNum;//tallies the number of correct numbers in a guess
};

struct Guess{
    int *code;//stores the guess
    int nGuess;//tracks guesses taken
};

struct Stats{
    int wins;//number of wins
    int loses;//number of loses
};



#endif	/* MASTERMIND_H */

