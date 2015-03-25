/* 
 * File:   main.cpp
 * Author: Joseph Levin
 * Created on March 25, 2015, 12:54 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries
#include "Array.h"

//Global Constants

//Function Prototypes
Array *flArray(int);
void prntAry(const Array *, int);
void destroy(Array *);
void copy(Array &,const Array *);

int main(int argc, char** argv) {
    //Set random number seed
    srand(time(0));
    //Declare variables
    Array *vec=flArray(100);
    //Print the array
    cout<<"Show the original (Lehr has bad copy here)"<<endl;
    prntAry(vec,10);
    //Perform a proper copy
    cout<<"Make a proper copy"<<endl;
    Array vec2;
    copy(vec2,vec);
    vec2.data[0]=100;
    cout<<"Copy changed. The original remains the same"<<endl;
    prntAry(vec,10);
    prntAry(&vec2,10);
    //Destroy the array and exit
    destroy(vec);
    

    return 0;
}

void copy(Array &b,const Array *a){
    //Perform a copy
    b.size=a->size;
    for(int i=0;i<a->size;i++){
        b.data[i]=a->data[i];
    }
}

void destroy(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array, int perLine){
    //Print the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i] <<" ";
        //cout<<(*array).data[i] <<" ";
        //cout<<*((*array).data+i)<<" ";
        //cout<<*(*array).data+i<<" ";//cannot do this
        
        if((i+1)%perLine==0)
            cout<<endl;
    }
    //Done
    cout<<endl;
}

Array *flArray(int n){ //n must be positive integer
    //Create a pointer to the structure
    Array *array=new Array;//must return valid address
    //Allocate memory for the array 
    array->data=new int[n];
    array->size=n;
    //Fill the array with 2 digit integers
    for(int i=0;i<array->size;i++){
        array->data[i]=rand()%90+10;
       
    }
    //Done
    
    return array;
}

