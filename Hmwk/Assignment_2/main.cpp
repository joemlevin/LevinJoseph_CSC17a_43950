/* 
 * file: main.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 1 Review - Spring 2015 43950
 * Created on March 26, 2015, 1:34 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *mode(int[],int); //Mode determining function
float median(int[],int); //median determining function
float mean(int[],int); //Mean determining function
void bubSort(int *, int);

//Let the games begin!
int main(int argc, char** argv) {
    
    srand(time(0));
    int n=10;
    int a[n];
    for(int i=0;i<n;i++)
        a[i]=rand()%9+1;
    int *m=mode(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<(m[0]+2);i++)
        cout<<m[i]<<" ";
    cout<<endl;
    
    
//    bubSort(a,n);
//    for(int i=0;i<n;i++)
//        cout<<a[i]<<" ";
//    cout<<endl;
//    int val=a[0];//for tracking which values are modes
//    int count=0, freq=0, numMode=1;
//    for(int i=0;i<=n;i++){
//        if(a[i]==val)
//            count++;
//        else{
//            if(count>freq){
//                freq=count;
//                count=1;
//                numMode=1;
//                val=a[i];
//            }
//            else if(count==freq){
//                numMode++;
//                val=a[i];
//                count=1;
//            }
//            else{
//                val=a[i];
//                count=1;
//            }
//        }
//    }
//    cout<< "# of modes: " <<numMode<<endl;
//    cout<<"Frequency: "<<freq<<endl;

    return 0;
}

int *mode(int a[],int n){
    //sorts the array
    bubSort(a,n);
    int val=a[0];//for tracking which values are modes
    int count=0, //counts occurrences of element in array
            freq=0, //tracks the highest frequency found in array so far
            numMode=1; //tracks the number of elements with frequency found
    for(int i=0;i<=n;i++){
        if(a[i]==val)
            count++;
        else{
            if(count>freq){//a[i] occurs more than val
                freq=count;
                count=1;
                numMode=1;
                val=a[i];
            }
            else if(count==freq){//a[i] occurs same amount as val
                numMode++;
                val=a[i];
                count=1;
            }
            else{//a[i] occurs less than val
                val=a[i];
                count=1;
            }
        }
    }
    int *m=new int[(numMode+2)];//+2 for # of modes and frequency
    m[0]=numMode;
    m[1]=freq;
    count=0;//compared to freq to find modes
    int index=2;//moves along m to store every mode found
    val=a[0];
    for(int i=0;i<n;i++){
        if(a[i]==val)
            count++;
        if(count==freq){
            m[index]=val; //adds val as a mode
            index++; //bumps to next slot in mode array
            val=a[i+1];
            count=0;
        }
        if(a[i]!=val){//start examining next value in array
            count=1;//value at i counts as 1
            val=a[i];
        }
}
    return m;
}
//int *mode(int a[], int n){
//    //copy given array into dynamic array and sort
//    int *b=new int[n];
//    int freq=-1; //tracks the highest frequency found
//    int val=-1;//determines the value being counted
//    int count=0; //counts occurrences of each value in array
//    int posMode; //possible mode in array
//    int numMode=0; //number of modes in array
//    for(int i=0;i<n;i++){
//        b[i]=a[i];
//    }
//    bubSort(b,n);
//    //loop through sorted array and determine modes
//    for(int i=0;i<n;i++){
//        if(b[i]!=val){
//            if(count>freq){ //value counted previously occurs more often
//                freq=count; //replaces highest frequency with new count
//                posMode=b[i]; //replaces possible mode with new value
//                numMode=1; //resets the number of modes found
//            }
//            else if(count==freq){
//                numMode++; //increments the number of modes found
//            }
//            else //count<freq
//                posMode=posMode; //the possible stays the same
//            val=b[i];
//            count=0; //resets count to zero for next value
//        }
//        else
//            count++;
//    }
//    //create dynamic array for storing information regarding mode
//        int *m=new int[numMode+2]; //stores size, frequency, and values of modes
//        m[0]=numMode; //how many modes there are
//        m[1]=freq; //frequency of occurrence
//        count=0; //reuse count for determining which values are modes
//        val=-1;
//        int index=2;//stores values with freq of mode into location in m
//        for(int i=0;i<n;i++){
//            if(b[i]!=val){
//                val=b[i];
//                count=0;
//            }
//            else
//                count++;
//            if(count==freq)
//                m[index]=val;
//        }
//        return m;
//    
//}
void bubSort(int *a,int size){
    for(int i=0; i<size; i++)
    {
        for (int j=0; j<size-1;j++)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}//end