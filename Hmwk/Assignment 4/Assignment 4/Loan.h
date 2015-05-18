/* File:   Loan.h
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */

#ifndef LOAN_H
#define	LOAN_H

class Loan{
private:
    float amnt;
    float rate;
    int year;
public:
    Loan(){amnt=0.0f; rate=0.0f; year=0;}
    void setAmnt(float);
    void setRate(float);
    void setYear(int);
    float getPay();
    float getTotal();
};


#endif	/* LOAN_H */

