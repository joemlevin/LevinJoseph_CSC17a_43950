/* 
 * File:   BaseBS.cpp
 * Author: Joseph Levin
 * C++ Project 2 - Spring 2015 43950
 * 6/5/2015
 */

//Libraries
#include <iostream>
#include <iomanip>//board formatting
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
void BaseBS::target(){
    int row, col;
    bool conf1,conf2,conf3;//error buffers
    do{
        conf1=false;
        conf2=false;
        conf3=false;
        cout<<"Enter the row (vertical) component of the coordinate "
                <<"you wish to fire upon"<<endl;
        do{
            cin>>row;
            if (cin.fail()||row<0||row>size-1) {
                cin.clear();
                cin.ignore(256,'\n');
                cout<<"Error. Invalid selection." << endl;
            } else
                conf1=true;
        }while(cin.fail()||row<0||row>size-1||!conf1);
        cout<<"Enter the column (horizontal) component "
                <<"of the coordinate you wish to fire upon"<<endl;
        do{
            cin>>col;
            if(cin.fail()||col<0||col>size-1){
                cin.clear();
                cin.ignore(256,'\n');
                cout<<"Error. Invalid selection."<<endl;
            }else
                conf2=true;
        }while(cin.fail()||col<0||col>size-1||!conf2);
        if(board[row][col]!=piece[3]&&board[row][col]!=piece[2])
            cout<<"This spot has been fired upon already."<<endl;
        else
            conf3=true;
    } while (!conf3);
    //if a ship was hit, replace with X and decrease remaining ships
    //and announce hit was successful
    if (board[row][col]==piece[2]){
        board[row][col]=piece[0];
        cout<<"Ship at position ("<<row<<","<<col<<")"<<" destroyed!"<<endl;
        ships--;
    } 
    //if a ship wasn't hit, replace with O and announce miss
    else{
        board[row][col]=piece[1];
        cout<<"Ship at position ("<<row<<","<<col<<")"<<" missed."<<endl;
    }
}