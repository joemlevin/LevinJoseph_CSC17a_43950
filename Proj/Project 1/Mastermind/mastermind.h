/* 
 * File:   mastermind.h
 * Author: Joseph
 *
 * Created on April 26, 2015, 7:47 PM
 */

#ifndef MASTERMIND_H
#define	MASTERMIND_H

struct Code{
    int *code;//stores the integer combination
    int nGuess;//keeps track of number of guesses taken
};

struct Stats{
    int wins;//number of wins
    int loses;//number of loses
};



#endif	/* MASTERMIND_H */

