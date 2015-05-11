/* File:   Circle.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */

#include <iostream>
#include <cstdlib>

using namespace std;

#include "NumArray.h"

void NumArray::fillArr(){
    float n;
    for(int i=0;i<size;i++){
        cout<<"Enter number "<<i+1<<endl;
        cin>>n;
        array[i]=n;
    }
}

NumArray::NumArray(int n){
    if(n>1){
        size=n;
        array=new float[size];
        fillArr();
    }
    else{
        size=0;
        array=NULL;
    }
}
