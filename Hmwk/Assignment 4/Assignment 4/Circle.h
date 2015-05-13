/* File:   Circle.h
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */


#ifndef CIRCLE_H
#define	CIRCLE_H

class Circle{
    private:
        float radius;
        const float pi = 3.14159;
    public:
        Circle();
        Circle(float);
        void setRadius(float);
        float getRadius();
        float getArea();
        float getDiameter();
        float getCircumference();
    
};



#endif	/* CIRCLE_H */

