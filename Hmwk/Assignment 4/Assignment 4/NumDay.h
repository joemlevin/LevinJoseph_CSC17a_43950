/* File:  NumDay.h
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */


#ifndef NUMDAY_H
#define	NUMDAY_H

class NumDay{
private:
    int hours;
    float days;
public:
    //Constructor
    NumDay(int);
    //Mutators
    void setHours(int);
    void setDays(int);
    //Accessors
    int getHours();
    float getDays();
    //Overloaded operators
    NumDay operator+(const NumDay &);
    NumDay operator-(const NumDay &);
    NumDay operator++();
    NumDay operator++(int);
    NumDay operator--();
    NumDay operator--(int);
};



#endif	/* NUMDAY_H */

