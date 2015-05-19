/* File:  TimeOff.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */
#include "TimeOff.h"

TimeOff::TimeOff(std::string n,std::string id){
    name=n;
    eid=id;
}
void TimeOff::setMaxSickDays(int m){
    maxSickDays.setHours(m);
}
float TimeOff::getMaxSickDays(){
    return maxSickDays.getDays();
}
void TimeOff::setSickTaken(int s){
    sickTaken.setHours(s);
}
float TimeOff::getSickTaken(){
    return sickTaken.getDays();
}
void TimeOff::setMaxVacation(int v){
    if(v<=240)
        maxVacation.setHours(v);
    else
        maxVacation.setHours(240);
}
float TimeOff::getMaxVacation(){
    return maxVacation.getDays();
}
void TimeOff::setVacTaken(int vt){
    vacTaken.setHours(vt);
}
float TimeOff::getVacTaken(){
    return vacTaken.getDays();
}
void TimeOff::setMaxUnpaid(int mu){
    maxUnpaid.setHours(mu);
}
float TimeOff::getMaxUnpaid(){
    return maxUnpaid.getDays();
}
void TimeOff::setUnpaidTaken(int pt){
    unpaidTaken.setHours(pt);
}
float TimeOff::getUnpaidTaken(){
    return unpaidTaken.getDays();
}
void TimeOff::setName(std::string n){
    name=n;
}
std::string TimeOff::getName(){
    return name;
}
void TimeOff::setEID(std::string id){
    eid=id;
}
std::string TimeOff::getEID(){
    return eid;
}