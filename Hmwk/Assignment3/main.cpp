/* File:   main.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 3 - Spring 2015 43950
 * Created on April 5, 2015, 7:38 PM
 */

//System Libraries
#include <cstdlib>
#include<iostream>

//User Libraries

//Global Constants

//Function Prototypes
void menu(); //Main menu function
void clrscrn(); //Clear Screen function
short slct(); //menu selection
bool again(); //problem repeater
void prb104();//driver for problem 10.4 (Avg. # of letters)
void prb106();//driver for problem 10.6 (Vowels and Consonants))
int cntw(char *);//returns the number of words in a c-string
int lavg(char *,int);//determines average number of letters
void prntc(char*);//prints cstring
int vow(char *);//counts vowels in cstring
int con(char*);//counts consonants in cstring

using namespace std;

int main(int argc, char** argv) {
    
    prb106();
    //menu();
    return 0;
}
//Menu function, displays all assignments and prompts for which
//the user would like to go to.
void menu(){
    
    clrscrn(); //clears the screen of all text
    short pick = slct();
    switch(pick){
        case 1:
            clrscrn();
            prb104();
            break;
        case -1:
            cout<<"That's all, folks."<<endl;
        default:
            cout<<"Until next time."<<endl;
    }
}//end

//Clear screen function outputs a ton of new lines in order to clear
//the command prompt to look nice
void clrscrn(){
    for(int i=0; i<100; i++)
        cout<<endl;
}//end

//slct serves to take in input for menu selection, performs error checks
//and then returns the value if it passes checks
short slct(){
    short pick; //for menu selection
    bool check=false;
    cout<<"Assignment 2"<<endl;
    cout<<"Choose an option from the menu: "<<endl
            <<"1. Problem 10.4 (Average Number of Letters)"<<endl
            <<"-1 to quit"<<endl;
    do{
        cin>>pick;
        if(cin.fail()||pick<=0&&pick!=-1||pick>6){//error checking
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Error. Invalid selection. Try again."<<endl;
        }
        else
            check=true;//valid input
    }while(!check);
    return pick;
}//end
//again prompts the user to see if they want to run the same problem again
//and returns to menu if not
bool again(){
    bool check=false;
    char pick;
    cout<<"Would you like to run this problem again? y/n"<<endl;
    do{
        cin>>pick;
        if(cin.fail()||tolower(pick)!='y'&&tolower(pick)!='n'){//only accepts
            cin.clear();                                       //y or n as input
            cin.ignore(256,'\n');
            cout<<"Error. Invalid selection. Try again."<<endl;
        }
        else if(tolower(pick)=='y'){//user wants to repeat
            check=true;
            return true;
        }
        else{ //user does not want to repeat
            check=true;
        return false;
        }
    }while(!check);
    
}//end
void prb104(){
    //get string from user
    cin.clear();
    cin.ignore(256,'\n');
    do{
        int size=60;
        char words[size];
        cout<<"Enter a sentence up to "<<size<<" characters long."<<endl;
        cin.getline(words,size);
        //output number of words and average letters per word
        int numWords=cntw(words);
        int avg=lavg(words,numWords);
        cout<<endl<<"The sentence you entered: "<<endl;
        prntc(words);
        cout<<endl<<"The number of words is "<<numWords<<endl;
        cout<<"The average letters per word is "<<avg<<endl;
    }while(again());
    menu();
    
}//end
void prb106(){
    int size=60;
    char a[size];
    char choose;
    cout<<"Enter a string of up to 60 characters."<<endl;
    cin.getline(a,size);
    cout<<"A) Count the number of vowels in the string"<<endl
        <<"B) Count the number of consonants in the string"<<endl
        <<"C) Count both the vowels and the consonants in the string"<<endl
        <<"D) Enter another string"<<endl
        <<"E) Exit the program"<<endl;
    do{
        cout<<"Choose an option"<<endl;
        cin>>choose;
        if(choose=='A')
            cout<<"The number of vowels is "<<vow(a)<<endl;
        else if(choose=='B')
            cout<<"The number of consonants is "<<con(a)<<endl;
        else if(choose=='C'){
            cout<<"The number of vowels and consonants is "<<vow(a)+con(a)
                    <<endl;
        }
        else if(choose=='D'){
        }
        else
            cout<<"Returning to menu"<<endl;
    }while(choose!='E');
    menu();
}
//cntw takes in a pointer to a c-string and counts the number of words in
//the string. Returns it as an integer
int cntw(char *a){
    int count=1;//keeps track of number of spaces, indicating each new word
    int index=0;//moves through c-string starting at begin address
    int letter=0;//counts letters
    while(*(a+index)!='\0'){//looks for null terminator at end of string
        if(isalpha(*(a+index)))
            letter++;//helps differentiate between spaces due to new words
        if(*(a+index)==' '&&letter!=0){//indicates a new word has begun
            count++;
            letter=0;
        }
        index++;
    }
    return count;
    
}//end
//lavg determines the average number of letters per word in
//a c-string of words. Takes a pointer to a c-string and the number of
//words in the string as aruguments and returns an integer
int lavg(char *a,int w){
    int count=0;//counts the letters
    int index=0;//moves thru cstring
    int avg=0;
    //count thru cstring to determine number of letters
    while(*(a+index)!='\0'){
        //ignore any non-alphabetical
        if(isalpha(*(a+index)))
            count++;
        index++;
    }
    return count/w;
    
}//end
void prntc(char* a){
    int index=0;
    while(*(a+index)!='\0'){
        cout<<*(a+index);
        index++;
    }
}//end
//vow counts the number of vowels found in a cstring and returns it as an int
int vow(char *a){
    int v=0;//counts vowels found
    int index=0;
    while(*(a+index)!='\0'){
        if(tolower(*(a+index))=='a'||tolower(*(a+index))=='e'||
                tolower(*(a+index))=='i'||tolower(*(a+index))=='o'||
                tolower(*(a+index))=='u') //only if a,e,i,o,u
            v++;
        index++;
    }
    return v;
}//end
//con counts the number of consonants found in a cstring
int con(char *a){
    int v=0;//counts vowels found
    int i=0;
    while(*(a+i)!='\0'){
        if(isalpha(*(a+i))!=0&&(tolower(*(a+i))!='a'&&tolower(*(a+i))!='e'&&
                tolower(*(a+i))!='i'&&tolower(*(a+i))!='o'&&
                tolower(*(a+i))!='u')) //must be alphabetical and not vowel
            v++;
        i++;
    }
    return v;
}//end
