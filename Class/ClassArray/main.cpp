/* 
 * File:   main.cpp
 * Author: Joe
 *
 * Created on April 20, 2015, 1:03 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>


using namespace std;

//User Libraries
#include "Array.h"

//Global Constants

//Function Prototypes

/*
 * 
 */
int main(int argc, char** argv) {
    //Declare variables
    int n=100;
    Array a(n);
    //Print the initial results
    cout<<"The original Array: "<<endl;
    a.prntArray();
    //Refill the array
    a.reFill();
    //Print the array again
    cout<<"The re-filled array:"<<endl;
    a.prntArray();
    //set last value
    a.setVal(n-2,100);
    //print aray
    cout<<"100 set to next to last value"<<endl;
    a.prntArray();
    //Sort the array
    a.sort();
    //Print the array again
    cout<<"The sorted array:"<<endl;
    a.prntArray();
    //Retrieve a property and a data point
    cout<<endl;
    cout<<"The size of the array = "<<a.getSize()<<endl;
    cout<<"The last value of the array = "<<a.getVal(n)<<endl;
    //Exit the program
    return 0;
}

