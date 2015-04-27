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
    indx=new int[size];
    for(int i=0;i<size;i++){
        data[i]=rand()%90+10;
        indx[i]=i;
    }
}

void Array::prntArray(){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<data[indx[i]]<<" ";
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
        indx=NULL;
    }
}

Array::~Array(){
    if(size!=0){
        delete []data;
        delete []indx;
    }
}

int Array::getVal(int idx){
    if(idx>=0&&idx<size)return data[indx[idx]];
    return data[0];
}

void Array::setVal(int idx, int val){
    if(idx>=0&&idx<size) data[indx[idx]]=val;
}

void Array::reFill(){
    if(size>0){
        delete []data;
        delete []indx;
    }
    fillArray();
}

void Array::sort(){
    for(int ilst=0;ilst<size-1;ilst++){
        for(int jelm=ilst+1;jelm<size;jelm++){
            //swap the data in place with an exclusive or
            if(data[indx[ilst]]>data[indx[jelm]]){
                    data[indx[ilst]]=data[indx[ilst]]^data[indx[jelm]];
                    data[indx[jelm]]=data[indx[ilst]]^data[indx[jelm]];
                   data[indx[ilst]]=data[indx[ilst]]^data[indx[jelm]];
            }
        }
    }
}
