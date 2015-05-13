/* File:   Circle.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */

#include <iostream>
#include <cstdlib>
#include <stdio.h>

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

NumArray::~NumArray(){
    if (size!=0)delete []array;
}

float NumArray::getNum(int n){
    return array[n];
}

void NumArray::setNum(int indx,float val){
    if(indx>=0&&indx<size)array[indx]=val;
}

float NumArray::getLow(){
    float val;
    if(size!=0){
        val=array[0];
        for(int i=0;i<size;i++){
            if(array[i]<val)
                val=array[i];
        }
    }
    return val;
}

float NumArray::getHigh(){
    float val;
    if(size!=0){
        val=array[0];
        for(int i=0;i<size;i++){
            if(array[i]>val)
                val=array[i];
        }
    }
    return val;
}

float NumArray::getAvg(){
    float sum=0.0;
    if(size!=0){
        for(int i=0;i<size;i++)
            sum+=array[i];
    }
    return sum/size;
}

void NumArray::prnt(){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
        if(i%10==9)cout<<endl;
    }
    cout<<endl;
}
