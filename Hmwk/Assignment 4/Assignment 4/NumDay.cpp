/* File:   NumDay.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */

#include "NumDay.h"

NumDay::NumDay(int h){
    hours=h;
    days=h/8.0;
}
void NumDay::setHours(int h){
    hours=h;
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
    NumDay temp(hours+right.hours);
    return temp;
}
NumDay NumDay::operator-(const NumDay &right){
    NumDay temp(hours-right.hours);
    return temp;
}
NumDay NumDay::operator++(){
    ++hours;
    setDays(hours);
    return *this;
}
NumDay NumDay::operator++(int){
    NumDay temp(hours);
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
    NumDay temp(hours);
    hours--;
    setDays(hours);
    return temp;
}

