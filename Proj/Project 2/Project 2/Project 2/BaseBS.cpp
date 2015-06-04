/* 
 * File:   BaseBS.cpp
 * Author: Joseph Levin
 * C++ Project 2 - Spring 2015 43950
 * 6/5/2015
 */

//Libraries
#include <iostream>
#include <iomanip>//board formatting
#include <cstdlib>//for rand
#include "BaseBS.h"

using namespace std;

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
void BaseBS::place(){
    bool conf1,conf2,conf3;//error buffers
    ships=0;//begin with no ships placed
    int row, col;//for checking the given coordinate
    for(int i=0;i<size;i++){//will place size # of ships
        do{
            cout<<"Enter the row coordinate for where to begin ship "
                    <<ships+1<<endl;
            //check confirms to false
            conf1=false;
            conf2=false;
            conf3=false;
            do{//gets the row coordinate
                cin>>row;
                if (cin.fail()||(row<0||row>size-1)){//size-1 denotes edge of board
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout<<"Error. Invalid input."<<endl;
                } else
                    conf1=true;//row coordinate is acceptable
            } while(cin.fail()||row<0||row>size-1||!conf1);
            cout<<"Enter the column coordinate for where to begin ship "
                    <<ships+1<<endl;
            do{
                cin>>col;
                if (cin.fail()||(col<0||col>size-1)){
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout<<"Error. Invalid input."<<endl;
                } else
                    conf2=true;//column coordinate is acceptable
            } while(cin.fail()||col<0||row>size-1||!conf1);
            if(board[row][col]!=piece[3]){//piece[3] == blank space
                cout << "This spot is already occupied" << endl;
            }
            else {
                board[row][col]=piece[2];//piece[2]== '+'
                ships++;//added ship to board
                conf3=true;//process is completed successfully
            }
        }while(!conf3);
    }
}
//!target for BaseBS handles the computer firing on the player's board
//!it is a glorified random number generator
void BaseBS::target(){
    bool confirm=false;
    int row,col;
    //randomly fires at spots until it
    do{
        row=(rand()%6);
        col=(rand()%6);
        //piece[3]==blank, piece[2]==ship
        if(board[row][col]==piece[3]||board[row][col]==piece[2])
            confirm=true;
    } while(!confirm);
    //piece[2]==ship,piece[0]==X
    if (board[row][col]==piece[2]){
        board[row][col]=piece[0];
        ships--;
        //piece[1]==O
    } else
        board[row][col]=piece[1];
}