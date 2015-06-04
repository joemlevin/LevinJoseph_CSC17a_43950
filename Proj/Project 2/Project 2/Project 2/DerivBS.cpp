/* 
 * File:   DerivBS.cpp
 * Author: Joseph Levin
 * C++ Project 2 - Spring 2015 43950
 * 6/5/2015
 */

#include "DerivBS.h"
#include<iostream>
#include<iomanip>
#include <cstdlib>

using namespace std;


//!constructor for DerivBS calls BaseBS constructor
DerivBS::DerivBS(int s):BaseBS(s){;}
//!displays a version of the board with ships masked
void DerivBS::radar(){
    cout<<"  ";
    for (int i=0;i<size;i++) {
        cout<<setw(3)<<setfill(' ')<<i<<" ";
    }
    cout<<endl;
    for (int i=0;i<size; i++) {
        cout<<"  "<<setw(25)<<setfill('-')<<'-'<<endl;
        cout<<i<<" ";
        for (int j=0;j<size;j++) {
            //if ship isn't at that spot, place piece at i,j
            if(board[i][j]!=piece[2]){
                cout<<"|"<<setw(2)<<setfill(' ')<<board[i][j]<<" ";
            }
            //if ship is at that spot, mask ship by placing blank spot instead
            else{
                cout<<"|"<<setw(2)<<setfill(' ')<<piece[3]<<" ";
            }
        }
        cout<<"| "<<endl;
    }
    cout<<"  "<<setw(25)<<setfill('-') << '-' << endl;
}
//!place for DerivBS randomly places ships for computer
void DerivBS::place(){
    int row, col;
    for(int i=0;i<size;i++){
        do{
            row=(rand()%6);
            col=(rand()%6);
        } while(board[row][col]!=piece[3]);//piece[3]==blank space
        board[row][col]=piece[2];//piece[2] == '+', ship
    }
}
//!target for DerivBS randomly fires on spots for computer
void target();

