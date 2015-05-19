/* File:  TimeOff.h
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */

#ifndef TIMEOFF_H
#define	TIMEOFF_H
#include "NumDay.h"
class TimeOff{
private:
    NumDay maxSickDays(0);
    NumDay sickTaken(0);
    NumDay maxVacation(0);
    NumDay vacTaken(0);
    NumDay maxUnpad(0);
    NumDay unpaidTaken(0);
    std::string name;
    int eid;
public:
    TimeOff(std::string);
    
};


#endif	/* TIMEOFF_H */

