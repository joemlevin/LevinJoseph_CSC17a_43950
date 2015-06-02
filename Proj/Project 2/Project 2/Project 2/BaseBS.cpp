/* 
 * File:   BaseBS.cpp
 * Author: Joseph Levin
 * C++ Project 2 - Spring 2015 43950
 * 6/5/2015
 */

#include <iostream>
#include <iomanip>
#include "BaseBS.h"

using namespace std;

        char** board;
        //!X is hit, O is miss, + is ship, <space> is empty
        char piece[4]={'X','O','+', ' '};
        //!dimension of board
        int size;

BaseBS::BaseBS(int s){
    size=s;
    board=flBoard();
}
BaseBS::~BaseBS(){
    for(int i=0;i<size;i++){
        delete []board[i];
    }
    delete []board;
}
/*!
 * flBoard() initializes the board with all empty spaces
 */
char** BaseBS::flBoard(){
    char** board = new char*[size];
    for (int i=0;i<size; i++){
        board[i]=new char[size];
    }
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++)
            board[i][j]=piece[3];
    }

    return board;
}
void BaseBS::pBoard(){
    cout<<"  ";
    for (int i=0;i<size;i++) {
        cout<<setw(3)<<setfill(' ')<<i<<" ";
    }
    cout<<endl;
    for (int i=0;i<size; i++) {
        cout<<"  "<<setw(25)<<setfill('-')<<'-'<<endl;
        cout<<i<<" ";
        for (int j=0;j<size;j++) {
            cout<<"|"<<setw(2)<<setfill(' ')<<board[i][j]<<" ";
        }
        cout<<"| "<<endl;
    }
    cout<<"  "<<setw(25)<<setfill('-') << '-' << endl;
}