/* File:   main.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 4 - Spring 2015 43950
 * Created on May 11, 2015, 3:15 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

//User Libraries
#include "Circle.h"
#include "NumArray.h"
#include "Coin.h"
#include "Loan.h"
#include "NumDay.h"
#include "TimeOff.h"

//Function Prototypes
void menu(); //Main menu function
void clrscrn(); //Clear Screen function
short slct(); //menu selection
bool again(); //problem repeater
void prb138();//driver for problem 13.8 (Circle Class)
void prb1310();//driver for problem 13.10 (Number Array)
void prb1312();//driver for problem 13.12 (Con Toss Simulator)
void prb1313();//driver for problem 13.13 (Tossing Coins for a Dollar)
void prb1315();//driver for problem 13.15 (Mortage Payment)
void prb144();//driver for problem 14.4 (NumDay class)
void prb145();//driver for problem 14.5(Time Off))

//Execution begins
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    prb145();
    return 0;
    
}

//!slct serves to take in input for menu selection, performs error checks
//!and then returns the value if it passes checks
short slct(){
    short pick; //for menu selectin
    bool check=false;
    cout<<"Assignment 4"<<endl;
    cout<<"Problem 13.8 (Circle Class)"<<endl;
    do{
        cin>>pick;
        if(cin.fail()||pick<=0&&pick!=-1||pick>7){//error checking
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Error. Invalid selection. Try again."<<endl;
        }
        else
            check=true;//valid input
    }while(!check);
    return pick;
}
/*!
 * again asks the user if they would like to repeat the current problem
 * it returns true if the user does, false if they do not
 */
bool again(){
    bool check=false;
    char pick;
    cout<<"Would you like to repeat this problem? y/n"<<endl;
    do{
        cin>>pick;
        if(cin.fail()||tolower(pick)!='y'&&tolower(pick)!='n'){//only accepts
            cin.clear();                                       //y or n as input
            cin.ignore(256,'\n');
            cout<<"Error. Invalid selection. Try again."<<endl;
        }
        else if(tolower(pick)=='y'){//user wants to repeat
            check=true;
            cin.clear();
            cin.ignore(256,'\n');
            return true;
        }
        else{ //user does not want to repeat
            cin.clear();
            cin.ignore(256,'\n');
            check=true;
        return false;
        }
    }while(!check);
}//end
/*!
 * prb138 is the driver for problem 13.8(Circle Class)
 */
void prb138(){
    //Prompt user to input radius"
    float r;
    cout<<"Enter the radius of the circle"<<endl;
    cin>>r;
    //Create Circle class with given r
    Circle c(r);
    //Output radius, diameter, circumference, and area of circle
    cout<<setprecision(1)<<fixed;
    cout<<"The radius of the circle is "<<c.getRadius()<<endl;
    cout<<"The diameter of the circle is "<<c.getDiameter()<<endl;
    cout<<"The circumference of the circle is "<<c.getCircumference()<<endl;
    cout<<"The area of the circle is "<<c.getArea()<<endl;
    cout<<endl;
    //Ask for new radius
    cout<<"Enter another radius."<<endl;
    cin>>r;
    //Set radius to new value
    c.setRadius(r);
    //Output new values for circle member functions
    cout<<"The radius of the circle is now "<<c.getRadius()<<endl;
    cout<<"The diameter of the circle is now "<<c.getDiameter()<<endl;
    cout<<"The circumference of the circle is now "<<c.getCircumference()<<endl;
    cout<<"The area of the circle is now "<<c.getArea()<<endl;
}//end
/*!
 * prb1310 is the main driver for problem 13.10 (Number Array)
 */
void prb1310(){
    //variables
    int indx;//index
    int size;//size of array
    float val;//value within array
    //Prompt user for the size of the array
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    //create NumArray class with size given
    NumArray a(size);
    //output the original array
    cout<<"The array is: ";
    a.prnt();
    //prompt to alter a value within array
    cout<<"Enter the location of the value"
            " you'd like to edit (1 thru "<<size<<")"<<endl;
    cin>>indx;
    //prompt for new value
    cout<<"Enter the new value for location "<<indx<<endl;
    cin>>val;
    //set the corresponding element of indx to val
    a.setNum(indx-1,val);
    //output array with altered value
    cout<<"The array is now:";
    a.prnt();
    //Prompt user to retrieve an individual value
    cout<<"Enter the location of a value"
            " you'd like to retrieve (1 thru "<<size<<")"<<endl;
    cin>>indx;
    //output val
    cout<<"The value at location "<<indx<<" is "<<a.getNum(indx-1)<<endl;
    //output the low, high, and average of the array
    cout<<"The highest value is "<<a.getHigh()<<endl;
    cout<<"The lowest value is "<<a.getLow()<<endl;
    cout<<"The average value is "<<a.getAvg()<<endl;
}//end
/*!
 * prb1312 is the driver for problem 13.12 (Coin Toss Simulator)
 */
void prb1312(){
   Coin coin;//instance of Coin class
   int heads=0;//counter for heads
   int tails=0;//counter for tails
   cout<<"The initial side up is "<<coin.getSideUp()<<endl;
   for(int i=0;i<20;i++){
       coin.toss();
       if(coin.getSideUp()=="Heads"){
           cout<<"Toss #"<<i+1<<" landed on "<<coin.getSideUp()<<endl;
           heads++;
       }
       else{
           cout<<"Toss #"<<i+1<<" landed on "<<coin.getSideUp()<<endl;
           tails++;
       }
   }
   cout<<"Total heads: "<<heads<<endl;
   cout<<"Total tails: "<<tails<<endl;
}//end
/*!
 * prb1313() is the driver for problem 13.13 (Tossing Coins for a Dollar)
 * A game in which you toss 3 coins, a quarter, dime, and nickel, with the
 * goal being to end up with $1 exactly.
 */
void prb1313(){
    //Initialize three Coin's, one for quarters, nickels, and dimes
    Coin q,n,d;
    char next;
    float total=0.0f;
    cout<<"Welcome to Problem 13.13!"<<endl
            <<"Each round, three coins will be tossed:"<<endl
            <<"a quarter ($.25), a dime ($.10), and a nickel ($.05)."<<endl
            <<"Every coin that lands heads up will be added to your total"<<endl
            <<"The goal is for the game to end on $1.00 exactly."<<endl
            <<"If it does, you win! If you go over, you lose. Simple!"<<endl;
    do{
        cout<<"Type 'f' to flip the coins"<<endl;
        do{
            cin>>next;
            if(tolower(next)!='f')
                cout<<"You need to type 'f'. It's not that hard, really"<<endl;
        }while(tolower(next)!='f');
        q.toss();
        d.toss();
        n.toss();
        if(q.getSideUp()=="Heads"){
            cout<<"The quarter landed heads up! That's +$.25!"<<endl;
            total+=.25;
        }
        else{
            cout<<"The quarter landed tails up! Nothing was added."<<endl;
        }
        if(d.getSideUp()=="Heads"){
            cout<<"The dime landed heads up! That's +$.10!"<<endl;
            total+=.10;
        }
        else{
            cout<<"The dime landed tails up! Nothing was added."<<endl;
        }
        if(n.getSideUp()=="Heads"){
            cout<<"The nickel landed heads up! That's +$.05!"<<endl;
            total+=.05;
        }
        else{
            cout<<"The nickel landed tails up! Nothing was added."<<endl;
        }
        cout<<"Your total: $"<<setprecision(2)<<fixed<<total<<endl;
    }while(total<1.00f);
    if(total==1.00f){
        cout<<"Your total: $"<<setprecision(2)<<fixed<<total<<endl;
        cout<<"You win! Congratulations!"<<endl;
    }
    else{
        cout<<"Your total: $"<<setprecision(2)<<fixed<<total<<endl;
        cout<<"You lose! Congratulations! ... Oh, no. Sorry!"<<endl;
    }
}//end
/*!
 * prb1315 is the driver for problem 13.15 (Mortgage Payment)
 */
void prb1315(){
    Loan loan;
    float a, r;
    int y;
    cout<<"Enter the initial amount of the loan"<<endl;
    do{
        cin>>a;
        loan.setAmnt(a);
        if(loan.getAmnt()==-1)
            cout<<"Must enter a positive amount"<<endl;
    }while(loan.getAmnt()==-1);
    cout<<"Enter the interest rate of the loan"<<endl;
    do{
        cin>>r;
        loan.setRate(r);
        if(loan.getRate()==-1)
            cout<<"Must enter a positive amount"<<endl;
    }while(loan.getRate()==-1);
    cout<<"Enter the year length of the loan"<<endl;
    do{
        cin>>y;
        loan.setYear(y);
        if(loan.getYear()==-1)
            cout<<"Must enter an integer greater than 0"<<endl;
    }while(loan.getYear()==-1);
    cout<<loan.getAmnt()<<" "<<loan.getRate()<<" "<<loan.getYear()<<endl;
    cout<<"The monthly payment is $"<<loan.getPay()<<endl;
    cout<<"The total amount repaid will be $"<<loan.getTotal()<<endl;
}//end
/*!
 * prb144 is the main driver for problem 14.4 (NumDay class).
 * It demonstrations the functionality of the NumDay class
 * which includes mathematical operator overloading,
 * and increment/decrement overloading
 */
void prb144(){
    //initial set NumDay objects to 0
    NumDay day1,day2,day3;
    //Display initial contents
    cout<<"Initial hours (day 1, day 2): "
            <<day1.getHours()<<", "<<day2.getHours()<<endl;
    cout<<"Initial days (day 1, day 2), 8 hours per day: "
            <<day1.getDays()<<", "<<day2.getDays()<<endl;
    //Utilize mutators to set new hours and days
    int h1, h2;
    cout<<"Enter the hours for day 1"<<endl;
    cin>>h1;
    cout<<"Enter the hours for day 2"<<endl;
    cin>>h2;
    day1.setHours(h1);
    day2.setHours(h2);
    day1.setDays(h1);
    day2.setDays(h2);
    //Display new contents
    cout<<"Day 1: "<<day1.getHours()<<" hours or "
            <<day1.getDays()<<" days"<<endl;
    cout<<"Day 2: "<<day2.getHours()<<" hours or "
            <<day2.getDays()<<" days"<<endl;
    //Demonstrator addition/subtraction
    day3=day1+day2;
    cout<<"day 1's hours + day 2's hours = "<<day3.getHours()<<endl;
    cout<<"day 1's days + day 2's days = "<<day3.getDays()<<endl;
    day3=day1-day2;
    cout<<"day 1's hours - day 2's hours = "<<day3.getHours()<<endl;
    cout<<"day 1's days - day 2's days = "<<day3.getDays()<<endl;
    //Demonstrate incrementor and decrementor
    cout<<"Prefix incrementor on day 1:"<<endl;
    ++day1;
    cout<<day1.getHours()<<" hours or "<<day1.getDays()<<" days"<<endl;
    cout<<"Prefix decrementor on day 1:"<<endl;
    --day1;
    cout<<day1.getHours()<<" hours or "<<day1.getDays()<<" days"<<endl;
    cout<<"Postfix incrementor on day 2:"<<endl;
    day2++;
    cout<<day2.getHours()<<" hours or "<<day2.getDays()<<" days"<<endl;
    cout<<"Postfix decrementor on day 2:"<<endl;
    day2--;
    cout<<day2.getHours()<<" hours or "<<day2.getDays()<<" days"<<endl;
}//end
/*!
 * prb145 is the driver for problem 14.5 (Time Off). It implements
 * a number of NumDay classes
 */
void prb145(){
    //get name for EID
    string name, eid;
    int num;
    cout<<"Enter the employee's name"<<endl;
    getline(cin,name);
    cout<<"Enter the employee's identification number."<<endl;
    getline(cin,eid);
    TimeOff emp1(name,eid);
    cin.clear();
    cin.ignore(265,'\n');
    //Fill in the contents of the TimeOff object emp1
    cout<<"Enter the max sick hours allowed"<<endl;
    cin>>num;
    emp1.setMaxSickDays(num);
    cout<<"Enter the number of sick days taken"<<endl;
    cin>>num;
    emp1.setSickTaken(num);
    cout<<"Enter the max paid vacation hours allowed"<<endl;
    cin>>num;
    emp1.setMaxVacation(num);
    cout<<"Enter the number of vacation hours taken"<<endl;
    cin>>num;
    emp1.setVacTaken(num);
    cout<<"Enter the max unpaid vacation hours allowed"<<endl;
    cin>>num;
    emp1.setMaxUnpaid(num);
    cout<<"Enter the number of unpaid vacation hours taken"<<endl;
    cin>>num;
    emp1.setUnpaidTaken(num);
    cout<<"Employee name: "<<emp1.getName()<<endl;
    cout<<"Employee ID: "<<emp1.getEID()<<endl;
    cout<<"Max sick days: "<<emp1.getMaxSickDays()<<endl;
    cout<<"Sick days taken: "<<emp1.getSickTaken()<<endl;
    cout<<"Max vacation days: "<<emp1.getMaxVacation()<<endl;
    cout<<"Vacations days taken: "<<emp1.getVacTaken()<<endl;
    cout<<"Max unpaid vacation days: "<<emp1.getMaxUnpaid()<<endl;
    cout<<"Unpaid vacation days taken: "<<emp1.getUnpaidTaken()<<endl;
}