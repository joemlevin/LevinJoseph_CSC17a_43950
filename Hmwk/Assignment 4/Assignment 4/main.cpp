/* File:   main.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries
#include "Circle.h"

//Function Prototypes
void menu(); //Main menu function
void clrscrn(); //Clear Screen function
short slct(); //menu selection
bool again(); //problem repeater
void prb138();//driver for problem 13.8 (Circle Class)

//Execution begins
int main(int argc, char** argv) {
    
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
    Circle c(r);
    cout<<setprecision(1)<<fixed;
    cout<<"The radius of the circle is "<<c.getRadius()<<endl;
    cout<<"The diameter of the circle is "<<c.getDiameter()<<endl;
    cout<<"The circumference of the circle is "<<c.getCircumference()<<endl;
    cout<<"The area of the circle is "<<c.getArea()<<endl;
    cout<<endl;
    cout<<"Enter another radius."<<endl;
    cin>>r;
    c.setRadius(r);
    cout<<"The radius of the circle is now "<<c.getRadius()<<endl;
    cout<<"The diameter of the circle is now "<<c.getDiameter()<<endl;
    cout<<"The circumference of the circle is now "<<c.getCircumference()<<endl;
    cout<<"The area of the circle is now "<<c.getArea()<<endl;
}
