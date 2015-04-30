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
#include <string>
#include <cstring>

using namespace std;

//User Libraries
#include "mastermind.h"

//Global Constants

//Function Prototypes
Answer *getAns(int,int);//generates an answer
void checkG(Answer *,Guess *,int);//checks guess against answer
int *getG(int);//gets guess from user

//Begin
int main(int argc, char** argv) {
    
//    srand(time(0));
//        Answer *test=getAns(10,4);
//    Guess *temp=new Guess;
//    temp->code=new int[4];
    
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
        answer->code[i]=rand()%8+1;//fill code with 1-9
    return answer;
}//end
//checkG takes in an Answer struct. It copies the contents of the code array
//into another int array and compares each element to a Guess array
//It changes the elments in the temp int array to -1 as it finds matches
//in order to ensure no duplicate matches are found
//if an element in the guess matches the position and number of the answer
//both the correct number and correct position counters are incremented
//otherwise if only the number is matched then the correct number indication
//is incremented. Man this is a long description.
void checkG(Answer *answer,Guess *guess,int row){
    int *ta=new int[row];//temp array to store answer
    int *tg=new int[row];//temp array to store guess
    for(int i=0;i<row;i++){
        ta[i]=answer->code[i];//copy answer to temp answer
        tg[i]=guess->code[i];//copy guess to temp guess
    }
    //loop through arrays to check for both correct position and correct number
    for(int i=0;i<row;i++){
        if(tg[i]==ta[i]){
            answer->corPos++;
            answer->corNum++;
            ta[i]=-1;//no duplicates
            tg[i]=-1;
        }
    }
    //loop through temp answer again
    for(int i=0;i<row;i++){
        //loop through guess
        for(int j=0;j<row;j++){
            //check for same number
            if(ta[i]==tg[j]&&i!=j&&tg[i]!=-1&&ta[i]!=-1){//same num, diff pos
                answer->corNum++;
                ta[i]=-1;
                tg[j]=-1;
            }
        }
    }
    delete []ta;
    delete []tg;
}//end
/*
 * getG prompts the user to enter a 4 digit combination, separated by spaces
 * it stores it as a string, and checks if every odd element is a digit 1-8
 * and then checks if every even is a space
 * if this is true, it then converts each odd element into an int and stores
 * it in an int array and returns this array
 * takes an int to specify how big an int array to create
 */
int *getG(int row){
    //declare variables
    int *temp=new int[row];//will be returned
    string guess;//for character checking
    bool check;//input validation
    cout<<"Enter a "<<row
            <<" digit combination (1-8) separated by spaces."<<endl;
    do{
        check=true;
        cin>>guess;
        if(guess.size()!=2*row-1){//row digits plus spaces between
            cout<<"You must enter "<<row<<" digits separated by spaces."
                    <<"Try again."<<endl;
            bool check=false;
        }
        else{
            for(int i=0;i<2*row-1;i++){
                if(i%2!=0&&!isdigit(guess[i]))//every odd must be digit
                    check=false;
                else if(i%2!=0&&(atoi(&guess[i])>8||atoi(&guess[i])<1))
                    check=false;
                else{
                    if(!isspace(guess[i]))
                        check=false;
                }
            }   
        }
        for(int i=0;i<row;i++)
            temp[i]=atoi(&guess[i+1])
    }while(!check);
}