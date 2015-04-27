/* 
 * File:   main.cpp
 * Author: Joseph Levin
 * C++ Project 1 Mastermind
 * Created on April 26, 2015, 7:01 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

//User Libraries
#include "mastermind.h"

//Global Constants

//Function Prototypes
Answer *getAns(int,int);//generates an answer
void checkG(Answer *,Guess *,int);//checks guess against answer
int main(int argc, char** argv) {
    
    srand(time(0));
    Answer *test=getAns(10,4);
    for(int i=0;i<4;i++)
        cout<<test->code[i]<<" ";
    cout<<endl;
    cout<<"Max Guess: "<<test->mxGuess<<endl;

    return 0;
}

//getAns dynamically creates a Answer struct, fills the code array with
//random integers 0-9, sets nGuess to max (max # of guesse) and then returns
Answer *getAns(int max, int row){
    Answer *answer=new Answer;
    answer->mxGuess=max;//max number of guesses allowed
    answer->corNum=0;//starts correct numbers at zero
    answer->corPos=0;//starts correct positions at zero
    answer->code=new int[row];//the combination is 'row' digits long
    for(int i=0;i<row;i++)
        answer->code[i]=rand()%9-1;//fill code with 1-9
    return answer;
}//end
//checkG compares each element in the code int array of guess to answer
//for each element of guess that has the same position and number as in answer
//the corPos and corNum variables in answer are incremented
//for each element of guesst that has only the correct position,
//corPos is incremented only
void checkG(Answer *answer,Guess *guess,int row){
    int gdex=0;//tracks the index for guess
    int adex=0;//tracks the index for answer
    do{
        if()
    }
}