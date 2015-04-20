/* 
 * File:   Array.h
 * Author: Joseph Levin
 *
 * Created on April 20, 2015, 1:04 PM
 * Purpose; Our first Array class
 */

#ifndef ARRAY_H
#define	ARRAY_H

class Array{
    private:
      int *data;//Array containing data
      int size;//Size of the array
      void fillArray();//Fills the Array with Random NUmbers
    public:
        Array(int);//Constructor
        ~Array();//Destructor
        int getSize(){return size;}
        int getVal(int);///Retrieve Array information
        void setVal(int,int);//Mutate a value in the Array
        void reFill();//Call the fill array again
        void sort();//Sort but don't return
        void prntArray();//print the array
    
};


#endif	/* ARRAY_H */

