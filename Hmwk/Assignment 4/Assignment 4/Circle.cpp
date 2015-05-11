/* File:   Circle.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */

#include <iostream>
#include <cstdlib>
using namespace std;
#include "Circle.h"


Circle::Circle()//default constructor
    {radius=0.0;}

Circle::Circle(float r)//constructor with radius argument
    {radius=r;}

void Circle::setRadius(float r){radius=r;}//mutator for radius

float Circle::getRadius(){return radius;}//getter for radius

float Circle::getArea(){return pi*radius*radius;}//calculates area

float Circle::getDiameter(){return 2*radius;}//calculates diameter

float Circle::getCircumference(){return 2*pi*radius;}//calculates circumference
        
