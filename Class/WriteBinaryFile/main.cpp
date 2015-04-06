/* 
 * File:   student.h
 * Author: Dr. Mark Lehr
 * Created on March 30, 2015, 1:16 PM
 */

//System Libraries
#include <cstdlib>
#include <fstream>
#include<ctime>
#include <iostream>
using namespace std;

//User Libraries
#include "student.h"

//Global Constants

//Function Prototypes
Student *filStu(int);
void prntStu(Student *,int);
void wrtStu(char *,Student *,int);
Student *readStu(char *,int);

//Start Execution Here
int main(int argc, char** argv) {
    //Initialize the random number generator
    srand(time(0));
    //Fill the Student array
    int nStudents=36;
    Student *stu=filStu(nStudents);
    //Write to a file all the students in binary form
    char fn[]="stu.dat";
    wrtStu(fn,stu,nStudents);
    //Print out the student records
    cout<<"Size of a student record = "<<sizeof(Student)<<endl;
    cout<<"Size of all student records = "<<sizeof(stu)<<endl;
    prntStu(stu,nStudents);
    //Find 35th student
    Student *one=readStu(fn,35);
    cout<<"The 35th student:"<<endl;
    prntStu(one,1);
    //Deallocate memory
    delete []stu;
    //Exit stage right
    return 0;
}

Student *readStu(char *fn,int rec){
    //Open file for binary
    fstream in;
    in.open(fn,ios::in|ios::binary);
    //Allocate memory for one student
    Student *one=new Student;
    //{position read point
    in.seekg((rec-1)*sizeof(Student),ios::beg);
    //Read from the file
    in.read(reinterpret_cast<char *>(one),sizeof(Student)*rec);
    //exi
    in.close();
    //return the record
    return one;
}

void wrtStu(char *fn,Student *a,int n){
    //Open file for binary
    fstream out;
    out.open(fn,ios::out|ios::binary);
    //Write to the file
    out.write(reinterpret_cast<char *>(a),sizeof(Student)*n);
    //exit
    out.close();
}

void prntStu(Student *a,int n){
    //Output the results
    for(int rec=0;rec<n;rec++){
        cout<<"Student ID = "<<a[rec].sid;
        cout<<" Score = "<<a[rec].score;
        cout<<" Grade = "<<a[rec].grade<<endl;
    }
}

Student *filStu(int n){
    //Allocate memory
    Student *csc17a=new Student[n];
    //fill for each record
    for(int rec=0;rec<n;rec++){
        csc17a[rec].sid=rand();
        csc17a[rec].score=rand()%30+70;
        if(csc17a[rec].score>89)
            csc17a[rec].grade='A';
        else if(csc17a[rec].score>79)
            csc17a[rec].grade='B';
        else
            csc17a[rec].grade='C';
    }
    //Return the records
    return csc17a;
}

