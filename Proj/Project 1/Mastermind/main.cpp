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
Code *getAns(int,int);//generates an answer
void uGuess(Code *);//player guess function
int main(int argc, char** argv) {
    
    srand(time(0));
    
    Code *test=getAns();
    for(int i=0;i<4;i++)
        cout<<test->code[i]<<" ";
    cout<<endl;
    cout<<"Max Guess: "<<test->nGuess<<endl;

    return 0;
}

//getAns dynamically creates a Code struct, fills the code array with
//random integers 0-9, sets nGuess to max (max # of guesse) and then returns
Code *getAns(int max, int row){
    Code *answer=new Code;
    answer->nGuess=max;//10 is the maximum number of guesses allowed
    answer->code=new int[row];//the combination is 4 digits long
    for(int i=0;i<row;i++)
        answer->code[i]=rand()%9;//fill code with 1-9
    return answer;
}//end
void uGuess(Code *guess){
    
}


