/* 
 * File:   main.cpp
 * Author: Joe
 *
 * Created on April 23, 2015, 3:26 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout<<" "<<setw(74)<<setfill('-')<<"-"<<endl;
    cout<<"|"<<setw(14)<<setfill(' ')<<"|"<<setw(20)<<setfill(' ')<<"|"
            <<setw(18)<<setfill(' ')<<"|"<<setw(22)<<setfill(' ')<<"|"<<endl;
    cout<<"|"<<setw(9)<<setfill(' ')<<right<<"ENGINE"<<setw(5)
            <<setfill(' ')<<"|"<<setw(15)<<setfill(' ')<<right<<"ENGINEERING"
            <<setw(5)<<setfill(' ')<<"|"<<setw(12)<<setfill(' ')
            <<right<<"BARRACKS"<<setw(6)<<setfill(' ')<<"|"<<setw(14)
            <<setfill(' ')<<"COMMAND"<<setw(8)<<setfill(' ')<<"|"<<endl;
    cout<<"|"<<setw(8)<<setfill(' ')<<right<<"ROOM"<<setw(6)
            <<setfill(' ')<<"|"<<setw(11)<<setfill(' ')<<right<<"BAY"
            <<setw(9)<<setfill(' ')<<"|"<<setw(12)<<setfill(' ')
            <<right<<"        "<<setw(6)<<setfill(' ')<<"|"<<setw(12)
            <<setfill(' ')<<"DECK"<<setw(10)<<setfill(' ')<<"|"<<endl;
    cout<<"|"<<setw(14)<<setfill(' ')<<"|"<<setw(20)<<setfill(' ')<<"|"
            <<setw(18)<<setfill(' ')<<"|"<<setw(22)<<setfill(' ')<<"|"<<endl;
    cout<<" "<<setw(74)<<setfill('-')<<"-"<<endl;

    return 0;
}

