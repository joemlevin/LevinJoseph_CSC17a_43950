/* File:   NumDay.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */

#include "NumDay.h"

NumDay::NumDay(){
    hours=0;
    days=0.0;
}
void NumDay::setHours(int h){
    hours=h;
    setDays(h);
}
void NumDay::setDays(int h){
    days=h/8.0;
}
int NumDay::getHours(){
    return hours;
}
float NumDay::getDays(){
    return days;
}
NumDay NumDay::operator+(const NumDay &right){
    NumDay temp;
    temp.hours=hours+right.hours;
    temp.setDays(temp.hours);
    return temp;
}
NumDay NumDay::operator-(const NumDay &right){
    NumDay temp;
    temp.hours=hours-right.hours;
    temp.setDays(temp.hours);
    return temp;
}
NumDay NumDay::operator++(){
    ++hours;
    setDays(hours);
    return *this;
}
NumDay NumDay::operator++(int){
    NumDay temp;
    temp.hours=hours;
    temp.days=days;
    hours++;
    setDays(hours);
    return temp;
}
NumDay NumDay::operator--(){
    --hours;
    setDays(hours);
    return *this;
}
NumDay NumDay::operator--(int){
    NumDay temp;
    temp.hours=hours;
    temp.days=days;
    hours--;
    setDays(hours);
    return temp;
}

