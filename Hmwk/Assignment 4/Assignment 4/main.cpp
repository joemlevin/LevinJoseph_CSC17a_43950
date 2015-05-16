/* File:   main.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

//User Libraries
#include "Circle.h"
#include "NumArray.h"
#include "Coin.h"

//Function Prototypes
void menu(); //Main menu function
void clrscrn(); //Clear Screen function
short slct(); //menu selection
bool again(); //problem repeater
void prb138();//driver for problem 13.8 (Circle Class)
void prb1310();//driver for problem 13.10 (Number Array)
void prb1312();//driver for problem 13.12 (Con Toss Simulator)
void prb1313();//driver for problem 13.13 (Tossing Coins for a Dollar)

//Execution begins
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    prb1313();
    return 0;
}

//!slct serves to take in input for menu selection, performs error checks
//!and then returns the value if it passes checks
short slct(){
    short pick; //for menu selectin
    bool check=false;
    cout<<"Assignment 4"<<endl;
    cout<<"Problem 13.8 (Circle Class)"<<endl;
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
}
/*!
 * again asks the user if they would like to repeat the current problem
 * it returns true if the user does, false if they do not
 */
bool again(){
    bool check=false;
    char pick;
    cout<<"Would you like to repeat this problem? y/n"<<endl;
    do{
        cin>>pick;
        if(cin.fail()||tolower(pick)!='y'&&tolower(pick)!='n'){//only accepts
            cin.clear();                                       //y or n as input
            cin.ignore(256,'\n');
            cout<<"Error. Invalid selection. Try again."<<endl;
        }
        else if(tolower(pick)=='y'){//user wants to repeat
            check=true;
            cin.clear();
            cin.ignore(256,'\n');
            return true;
        }
        else{ //user does not want to repeat
            cin.clear();
            cin.ignore(256,'\n');
            check=true;
        return false;
        }
    }while(!check);
}//end
/*!
 * prb138 is the driver for problem 13.8(Circle Class)
 */
void prb138(){
    //Prompt user to input radius"
    float r;
    cout<<"Enter the radius of the circle"<<endl;
    cin>>r;
    //Create Circle class with given r
    Circle c(r);
    //Output radius, diameter, circumference, and area of circle
    cout<<setprecision(1)<<fixed;
    cout<<"The radius of the circle is "<<c.getRadius()<<endl;
    cout<<"The diameter of the circle is "<<c.getDiameter()<<endl;
    cout<<"The circumference of the circle is "<<c.getCircumference()<<endl;
    cout<<"The area of the circle is "<<c.getArea()<<endl;
    cout<<endl;
    //Ask for new radius
    cout<<"Enter another radius."<<endl;
    cin>>r;
    //Set radius to new value
    c.setRadius(r);
    //Output new values for circle member functions
    cout<<"The radius of the circle is now "<<c.getRadius()<<endl;
    cout<<"The diameter of the circle is now "<<c.getDiameter()<<endl;
    cout<<"The circumference of the circle is now "<<c.getCircumference()<<endl;
    cout<<"The area of the circle is now "<<c.getArea()<<endl;
}//end
/*!
 * prb1310 is the main driver for problem 13.10 (Number Array)
 */
void prb1310(){
    //variables
    int indx;//index
    int size;//size of array
    float val;//value within array
    //Prompt user for the size of the array
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    //create NumArray class with size given
    NumArray a(size);
    //output the original array
    cout<<"The array is: ";
    a.prnt();
    //prompt to alter a value within array
    cout<<"Enter the location of the value"
            " you'd like to edit (1 thru "<<size<<")"<<endl;
    cin>>indx;
    //prompt for new value
    cout<<"Enter the new value for location "<<indx<<endl;
    cin>>val;
    //set the corresponding element of indx to val
    a.setNum(indx-1,val);
    //output array with altered value
    cout<<"The array is now:";
    a.prnt();
    //Prompt user to retrieve an individual value
    cout<<"Enter the location of a value"
            " you'd like to retrieve (1 thru "<<size<<")"<<endl;
    cin>>indx;
    //output val
    cout<<"The value at location "<<indx<<" is "<<a.getNum(indx-1)<<endl;
    //output the low, high, and average of the array
    cout<<"The highest value is "<<a.getHigh()<<endl;
    cout<<"The lowest value is "<<a.getLow()<<endl;
    cout<<"The average value is "<<a.getAvg()<<endl;
}//end
/*!
 * prb1312 is the driver for problem 13.12 (Coin Toss Simulator)
 */
void prb1312(){
   Coin coin;//instance of Coin class
   int heads=0;//counter for heads
   int tails=0;//counter for tails
   cout<<"The initial side up is "<<coin.getSideUp()<<endl;
   for(int i=0;i<20;i++){
       coin.toss();
       if(coin.getSideUp()=="Heads"){
           cout<<"Toss #"<<i+1<<" landed on "<<coin.getSideUp()<<endl;
           heads++;
       }
       else{
           cout<<"Toss #"<<i+1<<" landed on "<<coin.getSideUp()<<endl;
           tails++;
       }
   }
   cout<<"Total heads: "<<heads<<endl;
   cout<<"Total tails: "<<tails<<endl;
}//end
/*!
 * prb1313() is the driver for problem 13.13 (Tossing Coins for a Dollar)
 * A game in which you toss 3 coins, a quarter, dime, and nickel, with the
 * goal being to end up with $1 exactly.
 */
void prb1313(){
    //Initialize three Coin's, one for quarters, nickels, and dimes
    Coin q,n,d;
    cout<<"Welcome to Problem 13.13!"<<endl
            <<"Each round, three coins will be tossed:"<<endl
            <<"a quarter ($.25), a dime ($.10), and a nickel ($.05)."<<endl
            <<"The goal is for the game to end on $1.00 exactly."<<endl
            <<"If it does, you win! If you go over, you lose. Simple!"<<endl
            <<"Type 'n' to begin. Good luck!"<<endl;
}