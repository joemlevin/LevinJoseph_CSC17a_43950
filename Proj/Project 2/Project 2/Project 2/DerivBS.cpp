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
    ships=0;
    for(int i=0;i<size;i++){
        //randomly picks spots until it finds one that isn't occupied already
        do{
            row=(rand()%size);
            col=(rand()%size);
        }while(board[row][col]!=piece[3]);//piece[3]==blank space
        board[row][col]=piece[2];//piece[2] == '+', ship
        ships++;
    }
}
//!target for DerivBS handles the player firing on the computer's board
//!it prompts for the coordinates one component a time, checks for any errors
//!and decides if it was a hit or miss and announces such
void DerivBS::target(){
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
        ships--;
    } 
    //if a ship wasn't hit, replace with O and announce miss
    else{
        board[row][col]=piece[1];
    }
}