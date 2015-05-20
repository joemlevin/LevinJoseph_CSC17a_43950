/* File:  Numbers.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */
#include "Numbers.h"
#include <iostream>
#include <string>

Numbers::Numbers(int n){
    if(n>=0&&n<10000)
        number=n;
    else
        number=-1;
}
std::string Numbers::getThousand(){
    int t=(number/1000)%10;
    if(t!=0){
        return (lessThan20[t]+" "+thousand);
    }
    else
        return lessThan20[0];
}
std::string Numbers::getHundred(){
    int t=(number/100)%10;
    if(t!=0){
        return (lessThan20[t]+" "+hundred);
    }
    else
        return lessThan20[0];
}
std::string Numbers::getTensAndOnes(){
    int t=number%100;
    if(t>=20){
        int o=number%10;
        t=(number/10)%10;
        if(o==0)
            return (lessThan100[t-2]);
        else
            return (lessThan100[t-2]+" "+lessThan20[o]);
    }
    else{
        return lessThan20[t];
    }
}
void Numbers::print(){
    if(getThousand()!="zero")
        std::cout<<getThousand()<<" ";
    if(getHundred()!="zero")
        std::cout<<getHundred()<<" ";
    std::cout<<getTensAndOnes()<<std::endl;
}