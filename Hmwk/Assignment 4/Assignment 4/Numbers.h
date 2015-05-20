/* File:  Numbers.h
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */

#ifndef NUMBERS_H
#define	NUMBERS_H
#include <string>

class Numbers{
private:
    int number;
    std::string lessThan20[20]={"zero","one","two","three","four","five","six",
                            "seven","eight","nine","ten","eleven","twelve",
                            "thirteen","fourteen","fifteen","sixteen",
                            "seventeen","eighteen","nineteen"};
    std::string lessThan100[8]={"twenty","thirty","forty","fifty","sixty",
                                "seventy","eighty","ninety"};
    std::string hundred="hundred";
    std::string thousand="thousand";
public:
    Numbers(int);
    std::string getThousand();
    std::string getHundred();
    std::string getTensAndOnes();
    void print();
};


#endif	/* NUMBERS_H */

