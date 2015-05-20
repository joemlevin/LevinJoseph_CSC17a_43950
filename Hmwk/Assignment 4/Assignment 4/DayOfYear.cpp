/* File:   DayOfYear.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */
#include "DayOfYear.h"
#include <iostream>
DayOfYear::DayOfYear(int d){
    if(d<=365&&day>0)
        day=d;
    else
        day=-1;
}
std::string DayOfYear::getMonth(){
    if(day>=1&&day<=31)
        return (month[0]+" "+days[day-1]);
    else if(day>31&&day<=59){
        return (month[1]+" "+days[day-32]);
    }
    else if(day>59&&day<=90){
        return (month[2]+" "+days[day-60]);
    }
    else if(day>90&&day<=120){
        return (month[3]+" "+days[day-91]);
    }
    else if(day>120&&day<=151){
        return (month[4]+" "+days[day-121]);
    }
    else if(day>151&&day<=181){
        return (month[5]+" "+days[day-152]);
    }
    else if(day>181&&day<=212){
        return (month[6]+" "+days[day-182]);
    }
    else if(day>212&&day<=243){
        return (month[7]+" "+days[day-213]);
    }
    else if(day>243&&day<=273){
        return (month[8]+" "+days[day-244]);
    }
    else if(day>273&&day<=304){
        return (month[9]+" "+days[day-274]);
    }
    else if(day>304&&day<=334){
        return (month[10]+" "+days[day-305]);
    }
    else{
        return (month[11]+" "+days[day-335]);
    }
}
void DayOfYear::print(){
    std::cout<<getMonth()<<std::endl;
}