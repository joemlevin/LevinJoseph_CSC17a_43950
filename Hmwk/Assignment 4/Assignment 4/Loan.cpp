/* File:   Loan.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */
#include "Loan.h"
#include "Circle.h"
void Loan::setAmnt(float n){
    if(n>=0.0f)amnt=n;
    else amnt=-1;
}
void Loan::setRate(float r){
    if(r>=0.0f)rate=r;
    else rate=-1;
}
void Loan::setYear(int t){
    if(t>0)year=t;
    else year=-1;
}
float Loan::getPay(){
    float base=1+(rate/12);
    float term=1.0f;
    for(int i=0;i<year*12;i++)
        term*=base;
    return (amnt*(rate/12)*term)/(term-1);
}
float Loan::getTotal(){
    return getPay()*static_cast<float>(year);
}