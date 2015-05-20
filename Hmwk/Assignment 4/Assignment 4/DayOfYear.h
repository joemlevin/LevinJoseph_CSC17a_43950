/* File:   DayOfYear.h
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */

#ifndef DAYOFYEAR_H
#define	DAYOFYEAR_H
#include <string>

class DayOfYear{
private:
    int day;
    std::string month[12]={"January","February","March","April","May","June",
                            "July","August","September","October","November",
                             "December"};
    std::string days[31]={"1","2","3","4","5","6","7","8","9","10","11",
                         "12","13","14","15","16","17","18","19","20","21",
                         "22","23","24","25","26","27","28","29","30","31"};
public:
    DayOfYear(int);
    std::string getMonth();
    void print();
};



#endif	/* DAYOFYEAR_H */

