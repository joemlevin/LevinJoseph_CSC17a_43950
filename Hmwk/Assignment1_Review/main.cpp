/* 
 * File:   main.cpp
 * Author: Joseph
 *
 * Created on March 14, 2015, 1:53 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//global constants
const float YEN_PER_DOLLAR=121.39f;//conversion rate for USD to Yen
const float EUROS_PER_DOLLAR=0.95f;//conversion rate for USD to Euros

//Function prototypes
void menu(); //Main menu function
void clrscrn(); //Clear Screen function
short slct(); //menu selection
void prb312(); //driver for problem 3.12
void prb313(); //driver for problem 3.13
void prb410(); //driver for problem 4.10
float celsius(); //gets input from user for temperature
float ctof(float);//converts celsius to fahrenehit
bool again(); //problem repeater
int dollars(); //prompts user for integer dollar amount and returns it
float yen(int); //converts usd to yen
float euro(int); //converts usd to euro
int month(); // returns integer for month 1-12
int year(); //returns integer for year
bool leap(int); //checks for leap year
void days(int, int); //output numbers of day of a given year and month

int main(int argc, char** argv) {
    menu();
    return 0;
}

//Menu function, displays all assignments and prompts for which
//the user would like to go to.
void menu(){
    
    clrscrn(); //clears the screen of all text
    short pick = slct();
    switch(pick){
        case 1:
            clrscrn(); //clears screen before executing first problem
            prb312(); //calls the driver for problem 3.12
            break;
        case 2:
            clrscrn();
            prb313();
            break;
        case 3:
            clrscrn();
            prb410();
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
    cout<<"Choose an option from the menu: "<<endl
            <<"1. Problem 3.12"<<endl
            <<"2. Problem 3.13"<<endl
            <<"3. Problem 4.10"<<endl
            <<"-1 to quit"<<endl;
    do{
        cin>>pick;
        if(cin.fail()||pick<=0&&pick!=-1||pick>7){//error checking
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Error. Invalid selection. Try again."<<endl;
        }
        else
            check=true;//valid input
    }while(!check);
    return pick;
}//end

//prb312 is the driver for problem 3.12
void prb312(){
    do{
        clrscrn();//clears console
        float c=celsius(); //calls celsius to get celsius temp from user
        float t=ctof(c);//converts c to fahrenheit
        cout<<c<<" degrees celsius is "<<
                setprecision(1)<<fixed<<t<<" degrees fahrenheit."<<endl;
    }while(again()); //repeats process if true, goes to menu if false
    menu();
}//end
//prb 313 is the main driver for problem 3.13
void prb313(){
    do{
        clrscrn();//clears console
        int usd=dollars(); //USD amount
        float e=euro(usd); //convers to euros
        float y=yen(usd); //converts to yen
        cout<<"$"<<usd<<setprecision(2)<<fixed//outputs to 2 decimal places
                <<" is "<<e<<" euros and "<<y<<" yen."<<endl;
    }while(again()); //repeats process if true, goes to menu if false
    menu();    
}//end
//prb410 is the main driver for problem 4.10
void prb410(){
    do{
        clrscrn();//clears console
        int m=month();//gets month
        int y=year();//gets year
        days(m,y);//displays days
    }while(again());//checks for repeat
    menu();//goes back to menu

}
//celsius prompts user to enter a temperature for conversion
float celsius(){
    bool check = false;
    float num; //stores user inputted value
    cout<<"Enter a temperature in celsius to convert to fahrenheit."<<endl;
    do{
        cin>>num;
        if(cin.fail()){
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Error. Invalid selection. Try again."<<endl;
        }
        else
            check=true;
    }while(!check);
    return num;
}//end
//ctof takes in a float and converts the value to fahrenheit temperature
float ctof(float celsius){
    return ((9*celsius)/5)+32;
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
//dollars prompts user to enter an integer amount for USD and
// returns it as an integer
int dollars(){
    int dollars;
    bool check = false;
    cout<<"Enter a dollar amount in USD for conversion to Euros and Yen."<<endl;
    do{
        cin>>dollars;
        if(cin.fail()||dollars<0){//user did not enter positive integer
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Error. Invalid selection. Try again."<<endl;
        }
        else{ //user entered positive integer
            check=true;
            return dollars;
        }
    }while(!check);
}//end
//yen takes in an integer for USD and statically casts it to float
//and converts to yen, and then returns that value as a float
float yen(int usd){
    return static_cast<float>(usd)*YEN_PER_DOLLAR;
}//end
//euro takes in an integer for USD and statically casts it to float
//and converts to euro, and then returns that value as a float
float euro(int usd){
    return static_cast<float>(usd)*EUROS_PER_DOLLAR;
}//end
//month prompts user for an integer month 1-12, checks to see if it's positive
//and between 1-12, and returns it as an integer if it is
int month(){
    int m;
    bool check=false;
    cout<<"Enter a month 1-12"<<endl;
    do{
        cin>>m;
        if(cin.fail()||m<=0||m>12){
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Error. Not a valid month."<<endl;
        }
        else
            check=true;
    }while(!check);
    return m;
}//end
//year prompts user for a year value, positive integer, and returns it
int year(){
    int y;
    bool check=false;
    cout<<"Enter a year"<<endl;
    do{
        cin>>y;
        if(cin.fail()|y<0){
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Error. Not a valid year."<<endl;
        }
        else
            check=true;
    }while(!check);
    return y;   
}//end
//leap takes in an integer for a year and checks to see if it is a leap year
//returns true for leap, false for not leap
bool leap(int year){
    if(year%400==0||year%4==0)//leap years are divisible by 400 or 4
        return true; //leap year
    else
        return false; //not leap year
}//end
//days takes in an integer for month and an integer for year
//and outputs numbers of day corresponding to that month in that year
void days(int month, int year){
    if(month==2&&leap(year)) //leap year on the second month
        cout<<"29 days"<<endl;
    else if(month==2&&!leap(year)) //not leap year on the second month
        cout<<"28 days"<<endl;
    else if(month==4||month==6||month==9||month==11)
        cout<<"30 days"<<endl;
    else
        cout<<"31 days"<<endl;
}//end
