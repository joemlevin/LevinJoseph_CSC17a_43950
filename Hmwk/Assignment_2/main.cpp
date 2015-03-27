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
void menu(); //Main menu function
void clrscrn(); //Clear Screen function
short slct(); //menu selection
bool again(); //problem repeater
void prnt(int *,int,int);//prints dynamic array, perline amount
void prbavg();//mean, median, and mode calculation problem
int *mode(int[],int); //Mode determining function
float median(int[],int); //median determining function
float mean(int[],int); //Mean determining function
void bubSort(int *, int);

//Let the games begin!
int main(int argc, char** argv) {
    
    srand(time(0));
    menu();
    return 0;
}

//Menu function, displays all assignments and prompts for which
//the user would like to go to.
void menu(){
    
    clrscrn(); //clears the screen of all text
    short pick = slct();
    switch(pick){
        case 1:
            prbavg();
            break;
        case -1:
            cout<<"That's all, folks."<<endl;
        default:
            cout<<"Until next time."<<endl;
    }
}//end

//Clear screen function outputs a ton of new lines in order to clear
//the command prompt to look nice
void clrscrn(){
    for(int i=0; i<100; i++)
        cout<<endl;
}//end

//slct serves to take in input for menu selection, performs error checks
//and then returns the value if it passes checks
short slct(){
    short pick; //for menu selection
    bool check=false;
    cout<<"Assignment 2"<<endl;
    cout<<"Choose an option from the menu: "<<endl
            <<"1. Median, Mean, and Mode"<<endl;
    do{
        cin>>pick;
        if(cin.fail()||pick<=0&&pick!=-1||pick>1){//error checking
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Error. Invalid selection. Try again."<<endl;
        }
        else
            check=true;//valid input
    }while(!check);
    return pick;
}//end
//again prompts the user to see if they want to run the same problem again
//and returns to menu if not
bool again(){
    bool check=false;
    char pick;
    cout<<"Would you like to run this problem again? y/n"<<endl;
    do{
        cin>>pick;
        if(cin.fail()||tolower(pick)!='y'&&tolower(pick)!='n'){//only accepts
            cin.clear();                                       //y or n as input
            cin.ignore(256,'\n');
            cout<<"Error. Invalid selection. Try again."<<endl;
        }
        else if(tolower(pick)=='y'){//user wants to repeat
            check=true;
            return true;
        }
        else{ //user does not want to repeat
            check=true;
        return false;
        }
    }while(!check);
    
}//end
//prnt prints the contents of a dynamic array formatted to
//the desired line width
void prnt(int *a,int size,int perLine){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
}
void prbavg(){
    clrscrn();
    do{
        int n=19;
        int pl=10;
        int a[n];
        for(int i=0;i<n;i++)
            a[i]=rand()%9+1;
        int *m=mode(a,n);
        cout<<"Randomly determined values"<<endl;
        prnt(a,n,pl);
        cout<<endl<<"The "<<m[0]<<" mode(s) are:"<<endl;
        for(int i=2;i<(m[0]+2);i++){//prints m from the start of mode values
            cout<<m[i]<<" ";
        }
        cout<<endl<<"With a frequency of "<<m[1]<<endl;
        cout<<endl;
        cout<<"The median is: "<<setprecision(1)<<fixed<<median(a,n)<<endl;
        cout<<"The mean is: "<<mean(a,n)<<endl;
    }while(again());
    menu();
    
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
    //end
    return m;
}//end
//median calculates the median of a sample of values
//and returns it as a float
float median(int a[],int n){
    float med=0.0f;
    for(int i=0;i<n;i++)
        med+=a[i];
    med=med/static_cast<float>(n);
    return med;
}//end
//mean calculates the mean value of a sample of values
//and returns it as a float
float mean(int a[],int n){
    float m=0.0;
    int mid=n/2;
    if(n%2==0){//even value so no clear middle value
        m=(a[mid]+a[mid+1])/2.0;//takes the average of the two "mids"
    }
    else
        m=a[mid]*1.0;
    return m;
}
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