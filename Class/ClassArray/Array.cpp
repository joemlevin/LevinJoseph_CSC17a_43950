/* 
 * File:   Array.h
 * Author: Joseph Levin
 *
 * Created on April 20, 2015, 1:04 PM
 * Purpose; Our first Array class
 */

#include<cstdlib>;
#include<ctime>;
#include <iostream>;
using namespace std;
#include "Array.h"

void Array::fillArray(){
    data=new int[size];
    for(int i=0;i<size;i++){
        data[i]=rand()%90+10;
    }
}

void Array::prntArray(){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<data[i]<<" ";
        if(i%10==9)
            cout<<endl;
    }
}

Array::Array(int n){
    if(n>1){
        size=n;
        fillArray();
    }else{
        size=0;
        data=NULL;
    }
}

Array::~Array(){
    if(size!=0)delete []data;
}

int Array::getVal(int indx){
    if(indx>=0&&indx<size)return data[indx];
    return data[0];
}

void Array::setVal(int indx, int val){
    if(indx>=0&&indx<size) data[indx]=val;
}

void Array::reFill(){
    if(size>0)delete []data;
    fillArray();
}

void Array::sort(){
    for(int ilst=0;ilst<size-1;ilst++){
        for(int jelm=ilst+1;jelm<size;jelm++){
            //swap the data in place with an exclusive or
            if(data[ilst]>data[jelm]){
                    data[ilst]=data[ilst]^data[jelm];
                    data[jelm]=data[ilst]^data[jelm];
                    data[ilst]=data[ilst]^data[jelm];
            }
        }
    }
}
