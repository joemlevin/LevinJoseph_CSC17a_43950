/* 
 * File:   main.cpp
 * Author: Joe
 *
 * Created on June 1, 2015, 1:28 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#include "LessSimpleVector.h"

/*
 * 
 */
int main(int argc, char** argv) {

    int size=10;
    SimpleVector<int> sv(size);
    for(int i=0;i<size;i++)
        sv[i]=i;
    for(int i=0;i<size;i++)
        cout<<sv[i]<<" ";
    sv.push(size);
    cout<<endl;
    for(int i=0;i<size+1;i++)
        cout<<sv[i]<<" ";
    sv.push(3);
    cout<<endl;
    for(int i=0;i<size+2;i++)
        cout<<sv[i]<<" ";
    return 0;
}

