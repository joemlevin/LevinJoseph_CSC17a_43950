/* File:  TimeOff.h
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */

#ifndef TIMEOFF_H
#define	TIMEOFF_H
#include "NumDay.h"
#include <string>
class TimeOff{
private:
    NumDay maxSickDays;
    NumDay sickTaken;
    NumDay maxVacation;
    NumDay vacTaken;
    NumDay maxUnpaid;
    NumDay unpaidTaken;
    std::string name;
    std::string eid;
public:
    TimeOff(std::string,std::string);
    void setMaxSickDays(int);
    float getMaxSickDays();
    void setSickTaken(int);
    float getSickTaken();
    void setMaxVacation(int);
    float getMaxVacation();
    void setVacTaken(int);
    float getVacTaken();
    void setMaxUnpaid(int);
    float getMaxUnpaid();
    void setUnpaidTaken(int);
    float getUnpaidTaken();
    void setName(std::string);
    std::string getName();
    void setEID(std::string);
    std::string getEID();
    
};


#endif	/* TIMEOFF_H */

