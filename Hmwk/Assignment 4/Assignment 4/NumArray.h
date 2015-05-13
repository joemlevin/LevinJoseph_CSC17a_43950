/* 
 * File:   NumArray.h
 * Author: Joe
 *
 * Created on May 11, 2015, 4:21 PM
 */

#ifndef NUMARRAY_H
#define	NUMARRAY_H

class NumArray{
    private:
        float *array;//array of floats
        int size;//size of array
    public:
        NumArray(int);//constructor for array
        ~NumArray();//destructor
        void fillArr();//fills array with random values
        float getNum(int);//returns number at position
        void setNum(int,float);//sets number at given position
        float getLow();//returns lowest value
        float getHigh();//returns highest value
        float getAvg();//returns average value
        void prnt();//prints the array
};



#endif	/* NUMARRAY_H */

