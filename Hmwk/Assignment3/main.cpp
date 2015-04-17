/* File:   main.cpp
 * Author: Joseph Levin
 * Assignment: C++ Assignment 3 - Spring 2015 43950
 * Created on April 5, 2015, 7:38 PM
 */

//System Libraries
#include <cstdlib>
#include<iostream>
#include<cctype>
#include<cstring>
#include<string>
#include<fstream>

using namespace std;

//User Libraries
#include "Speaker.h"
#include "Report.h"
#include "Movie.h"

//Global Constants

//Function Prototypes
void menu(); //Main menu function
void clrscrn(); //Clear Screen function
short slct(); //menu selection
bool again(); //problem repeater
void prb104();//driver for problem 10.4 (Avg. # of letters)
void prb106();//driver for problem 10.6 (Vowels and Consonants)
void prb119();//driver for problem 11.9 (Speakers' Bureau)
void prb127();//driver for problem 12.7 (Sentence Filter))
void prb128();//driver for problem 12.8 (Array/File Functions)
void prb1211();//driver for problem 12.1 (Coroporate Sales Data Output)
void prb101();//driver for problem 10.1 (C-String Length)
void prb111();//driver for problem 11.1 (Movie Data))
void prb112();//driver for problem 11.2 (Movie Profit))
void prb121();//driver for problem 12.1 (File Head Program)
int cntw(char *);//returns the number of words in a c-string
int lavg(char *,int);//determines average number of letters
void prntc(char*);//prints cstring
int vow(char *);//counts vowels in cstring
int con(char*);//counts consonants in cstring
Speaker *filSpkr();//creates a Speaker structure w/ default listings
void prntSpk(Speaker *,int);//prints a Speaker Structure
string getName();//For editing speaker name
string getPhone();//For editing speaker phone
string getFee();//for editing speaker fee
string getTopic();//for editing speaker topic
void arrayToFile(string,int *,int);//stores int array as binary file
void fileToArray(string, int *,int);
int getSales(int);//gets the sales for a quarter of a company
int cLength(char *);//counts the length of a c-string
void prntMovie(MovieData);//prints the contents of MovieData structure

int main(int argc, char** argv) {
    
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
            clrscrn();
            prb104();
            break;
        case 2:
            clrscrn();
            prb106();
            break;
        case 3:
            clrscrn();
            prb119();
            break;
        case 4:
            clrscrn();
            prb127();
            break;
        case 5:
            clrscrn();
            prb128();
            break;
        case 6:
            clrscrn();
            prb1211();
            break;
        case 7:
            clrscrn();
            prb101();
            break;
        case 8:
            clrscrn();
            prb111();
            break;
        case 9:
            clrscrn();
            prb112();
            break;
        case 10:
            clrscrn();
            prb121();
            break;
        case -1:
            cout<<"That's all, folks."<<endl;
            break;
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
            <<"1. Problem 10.4 (Average Number of Letters)"<<endl
            <<"2. Problem 10.6 (Vowels and Consonants)"<<endl
            <<"3. Problem 11.9 (Speaker's Bureau)"<<endl
            <<"4. Problem 12.7 (Sentence Filter)"<<endl
            <<"5. Problem 12.8 (Array/File Functions)"<<endl
            <<"6. Problem 12.11 (Corporate Sales)"<<endl
            <<"7. Problem 10.1 (String Length"<<endl
            <<"8. Problem 11.1 (Movie Data)"<<endl
            <<"9. Problem 11.2 (Movie Profit)"<<endl
            <<"10. Problem 12.1 (File Header)"<<endl
            <<"-1 to quit"<<endl;
    do{
        cin>>pick;
        if(cin.fail()||pick<=0&&pick!=-1||pick>10){//error checking
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
void prb104(){
    //get string from user
    do{
        cin.clear();//clear and ignore ensure the buffer is free of \n
        cin.ignore(256,'\n');
        int size=60;
        char words[size];
        cout<<"Enter a sentence up to "<<size<<" characters long."<<endl;
        cin.getline(words,size);
        //output number of words and average letters per word
        int numWords=cntw(words);
        int avg=lavg(words,numWords);
        cout<<endl<<"The sentence you entered: "<<endl;
        prntc(words);
        cout<<endl<<"The number of words is "<<numWords<<endl;
        cout<<"The average letters per word is "<<avg<<endl;
    }while(again());
    menu();
    
}//end
void prb106(){
    cin.clear();
    cin.ignore(265,'\n');
    int size=60;
    char a[size];
    char choose;
    cout<<"Enter a string of up to 60 characters."<<endl;
    cin.getline(a,size);
    cout<<"A) Count the number of vowels in the string"<<endl
        <<"B) Count the number of consonants in the string"<<endl
        <<"C) Count both the vowels and the consonants in the string"<<endl
        <<"D) Enter another string"<<endl
        <<"E) Exit the program"<<endl;
    do{
        cout<<"Choose an option"<<endl;
        cin>>choose;
        if(choose=='A')
            cout<<"The number of vowels is "<<vow(a)<<endl;
        else if(choose=='B')
            cout<<"The number of consonants is "<<con(a)<<endl;
        else if(choose=='C'){
            cout<<"The number of vowels and consonants is "<<vow(a)+con(a)
                    <<endl;
        }
        else if(choose=='D'){
            cout<<"Enter a string of up to 60 characters."<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin.getline(a,size);
        }
        else
            cout<<"Returning to menu"<<endl;
    }while(choose!='E');
    menu();
}//end
void prb119(){
    Speaker *list=filSpkr();
    int size=10;
    short pick=-3;
    do{
        cout<<"Speaker's Bureau"<<endl;
        cout<<"1. Speaker List"<<endl;
        cout<<"2. Edit Speakers"<<endl;
        cout<<"-1 to quit"<<endl;
        cout<<"Enter the number corresponding to what you want to do"<<endl;
        cin>>pick;
        switch(pick){
            case 1:
                clrscrn();
                prntSpk(list,size);
                break;
            case 2:
                clrscrn();
                for(int i=0;i<size;i++){
                    cout<<i+1<<". "<<list[i].name<<endl;
                }
                cout<<"Enter the number corresponding to the speaker"<<endl;
                short slct1,slct2;
                cin>>slct1;
                cout<<"1. Name"<<endl
                        <<"2. Phone Number"<<endl
                        <<"3. Fee"<<endl
                        <<"4. Topic"<<endl;
                cout<<"Enter the number corresponding to what you would"<<
                        " like to edit"<<endl;
                cin>>slct2;
                switch(slct2){
                    case 1:
                        cin.clear();
                        cin.ignore(256,'\n');
                        list[slct1-1].name=getName();
                        break;
                    case 2:
                        cin.clear();
                        cin.ignore(256,'\n');
                        list[slct1-1].phone=getPhone();
                        break;
                    case 3:
                        cin.clear();
                        cin.ignore(256,'\n');
                        list[slct1-1].fee=getFee();
                        break;
                    case 4:
                        cin.clear();
                        cin.ignore(256,'\n');
                        list[slct1-1].topic=getTopic();
                        break;
                    default:
                        cout<<"Error. Invalid selection."<<endl;
                        break;
                }
            case -1:
                cout<<"Program terminating"<<endl;
                break;
            default:
                cout<<"Default"<<endl;
                break;
    }
    }while(pick!=-1);
    menu();
}//end
void prb127(){
    do{
        char ch;//for storing each character
        string file;//file name to open
        ifstream inFile;
        string sentence;//output
        cout<<"Enter the name of the file you'd like to filter."
                <<" Pre-made file name: test.dat"<<endl;
        do{
            cin>>file;
            inFile.open(file.c_str());
            if(!inFile)
                cout<<"Error. Invalid file name."<<endl;
        }while(!inFile);
        bool newLine=true;
        fstream outFile;
        outFile.open("output.dat",ios::out);
        inFile.get(ch);
        while(inFile){
            if(newLine){
                outFile.put(toupper(ch));
                newLine=false;
                inFile.get(ch);
            }
            else if(ch=='.'){
                outFile.put(ch);
                inFile.get(ch);
                while(ch==' '||ch=='\n'){
                    outFile.put(ch);
                    inFile.get(ch);
                }
                outFile.put(toupper(ch));
                inFile.get(ch);
            }
            else{
                outFile.put(tolower(ch));
                inFile.get(ch);
            }
        }
        inFile.close();
        outFile.close();
        //output formatted file
        cout<<"The file after formatting: "<<endl;
        inFile.open("output.dat");
        getline(inFile,sentence);
        while(inFile){
            cout<<sentence;
            getline(inFile,sentence);
        }
        cout<<endl;
        inFile.close();
    }while(again());
    menu();
}//end
void prb128(){
    do{
        string file;
        int size;
        cout<<"Enter the size of the array you'd like to generate."<<endl;
        cin>>size;
        int *num=new int[size];
        for(int i=0;i<size;i++)
            num[i]=rand()%90+10;
        cout<<"The array has been generated: "<<endl;
        for(int i=0;i<size;i++){
            if(i%10==0)
                cout<<endl;
            cout<<num[i]<<" ";
        }
        cout<<endl<<"Enter the file name to store array in."<<endl;
        cin>>file;
        cout<<"Generating binary file"<<endl;
        arrayToFile(file,num,size);
        cout<<"Copying file to new array"<<endl;
        int *num2=new int[size];
        fileToArray(file,num2,size);
        cout<<"Copied Array:"<<endl;
        for(int i=0;i<size;i++){
            if(i%10==0)
                cout<<endl;
            cout<<num2[i]<<" ";
        }
        cout<<endl;
        delete []num;
        delete []num2;
}while(again());
menu();
}//end
void prb1211(){
    do{//Create the report struct
    const int QRT=4;//number of quarters in a year
    Report *report=new Report[4];
    int sales;//for storing sales for each quarter
    string divName[QRT]={"North","East","South","West"};//names of divisions
    for(int i=0;i<QRT;i++){//add names to structures
        report[i].name=divName[i];
    }
    for(int i=0;i<QRT;i++){//get the sales of each quarter
        cout<<report[i].name<<" Division:"<<endl;
        for(int j=0;j<QRT;j++){
            sales=getSales(j);
            report[i].sales[j]=sales;
        }
    }
    //Write data to file named report.dat
    cout<<"Writing data to 'report.dat'"<<endl;
    fstream outFile("report.dat",ios::out);
    for(int i=0;i<QRT;i++){
        outFile<<report[i].name<<" Division:"<<endl;
        for(int j=0;j<QRT;j++){
            outFile<<"Quarter "<<report[i].quarter[j]<<" sales: "<<
                    "$"<<report[i].sales[j]<<endl;
        }
    }
    cout<<"Writing successful"<<endl;
    //clean up
    delete []report;
    }while(again());//end of problem
    menu();
}//end
void prb101(){
    do{
        char *c=new char[50];
        cout<<"Enter up to 50 characters"<<endl;
        cin.getline(c,50);
        cout<<"Length is "<<cLength(c)<<endl;
        delete []c;
    }while(again());
    menu();
}//end
void prb111(){
    do{
        MovieData movie1;
        movie1.title="The Attack of the Angry Baby Koala";
        movie1.director="Brynn Caddel";
        movie1.year="2015";
        movie1.runTime="120";
        MovieData movie2;
        movie2.title="Mountain Bikes!";
        movie2.director="Ricardo Gonzalez";
        movie2.year="2013";
        movie2.runTime="125";
        prntMovie(movie1);
        cout<<endl;
        prntMovie(movie2);
    }while(again());
    menu();
}//end
void prb112(){
    do{
        MovieData movie1;
        movie1.title="The Attack of the Angry Baby Koala";
        movie1.director="Brynn Caddel";
        movie1.year="2015";
        movie1.runTime="120";
        movie1.revenue=10000;
        movie1.production=5000;
        MovieData movie2;
        movie2.title="Mountain Bikes!";
        movie2.director="Ricardo Gonzalez";
        movie2.year="2013";
        movie2.runTime="125";
        movie2.revenue=5000;
        movie2.production=10000;
        prntMovie(movie1);
        cout<<"Profit: $"<<movie1.revenue-movie1.production<<endl;
        cout<<endl;
        prntMovie(movie2);
        cout<<"Loss: $"<<(movie2.revenue)-(movie2.production)<<endl;
    }while(again());
    menu();
}//end
void prb121(){
    do{
        cout<<"Enter the name of a file (correct: FileHead.dat)"<<endl;
    fstream inFile;
    string file;
    char ch;
    do{
        cin>>file;
        inFile.open(file.c_str());
        if(!inFile)
            cout<<"Invalid File Name. FileHead.dat is default"<<endl;
    }while(!inFile);
    int index=0;//counts up to 10
    inFile.get(ch);
    while(inFile){
        cout<<ch;
        inFile.get(ch);
        index++;
    }
    if(index!=10)
        cout<<endl<<"End of file reached before 10 characters"<<endl;
    cout<<endl;
    }while(again());
    menu();
}
//cntw takes in a pointer to a c-string and counts the number of words in
//the string. Returns it as an integer
int cntw(char *a){
    int count=1;//keeps track of number of spaces, indicating each new word
    int index=0;//moves through c-string starting at begin address
    int letter=0;//counts letters
    while(*(a+index)!='\0'){//looks for null terminator at end of string
        if(isalpha(*(a+index)))
            letter++;//helps differentiate between spaces due to new words
        if(*(a+index)==' '&&letter!=0){//indicates a new word has begun
            count++;
            letter=0;
        }
        index++;
    }
    return count;
    
}//end
//lavg determines the average number of letters per word in
//a c-string of words. Takes a pointer to a c-string and the number of
//words in the string as aruguments and returns an integer
int lavg(char *a,int w){
    int count=0;//counts the letters
    int index=0;//moves thru cstring
    int avg=0;
    //count thru cstring to determine number of letters
    while(*(a+index)!='\0'){
        //ignore any non-alphabetical
        if(isalpha(*(a+index)))
            count++;
        index++;
    }
    return count/w;
    
}//end
void prntc(char* a){
    int index=0;
    while(*(a+index)!='\0'){
        cout<<*(a+index);
        index++;
    }
}//end
//vow counts the number of vowels found in a cstring and returns it as an int
int vow(char *a){
    int v=0;//counts vowels found
    int index=0;
    while(*(a+index)!='\0'){
        if(tolower(*(a+index))=='a'||tolower(*(a+index))=='e'||
                tolower(*(a+index))=='i'||tolower(*(a+index))=='o'||
                tolower(*(a+index))=='u') //only if a,e,i,o,u
            v++;
        index++;
    }
    return v;
}//end
//con counts the number of consonants found in a cstring
int con(char *a){
    int v=0;//counts vowels found
    int i=0;
    while(*(a+i)!='\0'){
        if(isalpha(*(a+i))!=0&&(tolower(*(a+i))!='a'&&tolower(*(a+i))!='e'&&
                tolower(*(a+i))!='i'&&tolower(*(a+i))!='o'&&
                tolower(*(a+i))!='u')) //must be alphabetical and not vowel
            v++;
        i++;
    }
    return v;
}//end
//filSpkr creates an array of Speaker structures (size 10), and fills
//the contents automatically with "default" values
Speaker *filSpkr(){
    //Create Speaker array
    int size=10;
    Speaker *list=new Speaker[size];
    //fill all 10 with information
    list[0].name="Brynn Caddel";
    list[0].phone="2718381838";
    list[0].fee="3.14";
    list[0].topic="The Superiority of Marsupials";
    list[1].name="Ricardo Gonzalez";
    list[1].phone="9517122400";
    list[1].fee="2.00";
    list[1].topic="The Importance of Mountain Bikes";
    list[2].name="Alex Gonzales";
    list[2].phone="7602225412";
    list[2].fee="0.09";
    list[2].topic="Why Non-Bae's Gotta Pay";
    list[3].name="Adam Christensen";
    list[3].phone="9514118905";
    list[3].fee="10";
    list[3].topic="Meters?";
    list[4].name="Patrick Doran";
    list[4].phone="2127693424";
    list[4].fee="1.50";
    list[4].topic="Benefits to Carrying Your Shoes With You";
    list[5].name="Nornubari Kolbololololol";
    list[5].phone="4517682341";
    list[5].fee="8.12";
    list[5].topic="His Muscles";
    list[6].name="The Fern";
    list[6].phone="8424383376";
    list[6].fee="2.20";
    list[6].topic="How to Subtly Acquire Pencils";
    list[7].name="Joseph Levin";
    list[7].phone="9518076736";
    list[7].fee="0.01";
    list[7].topic="Thinking Before You Speak";
    list[8].name="Mumbles McGoo";
    list[8].phone="5555555555";
    list[8].fee="1,000,000";
    list[8].topic="How To Guarantee Nobody Will Understand a Thing You Say";
    list[9].name="Barack Obama";
    list[9].phone="9518675309";
    list[9].fee="16,394,000,000,000";
    list[9].topic="Folding Your Socks";
    //return
    return list;
}
//prntSpkt outputs the contents of a Speaker Structure
void prntSpk(Speaker *l,int size){
    for(int i=0;i<size;i++){
        cout<<i+1<<". "<<l[i].name<<endl
                <<"Phone Number: "<<l[i].phone<<endl
                <<"Speaker's Fee: $"<<l[i].fee<<endl
                <<"Speaker's Topic: "<<l[i].topic<<endl;
        cout<<endl;
    }
}//end
//getName gets a new name for a speaker and returns it as a string
string getName(){
    string name;
    cout<<"Enter the name of the speaker."<<endl;
    getline(cin,name);
    return name;
}//end
string getPhone(){
    string phone;
    cout<<"Enter the phone number of the speaker."<<endl;
    getline(cin,phone);
    return phone;
}//end
string getFee(){
    string fee;
    cout<<"Enter the fee of the speaker"<<endl;
    getline(cin,fee);
    return fee;
}//end
string getTopic(){
    string topic;
    cout<<"Enter the topic of the speaker"<<endl;
    getline(cin,topic);
    return topic;
}//end
//arrayToFile  reads an
//integer array into the file in binary format
void arrayToFile(string file,int *array,int size){
    fstream outFile;
    outFile.open(file.c_str(),ios::out|ios::binary);
    outFile.write(reinterpret_cast<char *>(array),size*sizeof(array));
    outFile.close();
    
}
void fileToArray(string file, int *array, int size){
    fstream inFile;
    inFile.open(file.c_str(),ios::in|ios::binary);
    inFile.read(reinterpret_cast<char *>(array),size*sizeof(array));
    inFile.close();
    
}//end
//getSales prompts the user for the number of sales for "quarter" to stre
//in a Report struct
int getSales(int quarter){
    int num;//stores the sales
    bool check;//for error checking
    cout<<"Enter the sales of quarter "<<quarter+1<<endl;
    do{
        cin>>num;
        if(cin.fail()||num<0)//must be positive
            cout<<"Invalid sales amount. Sales must be positive integer."<<endl;
        else
            check=true;
    }while(!check);
    return num;
}
//cLength counts the number of elements in a c-string and returns
//the value as an integer
int cLength(char *c){
    int count=0;//keeps track of elements
    while(c[count]!='\0'){
        count++;
    }
    return count;
}
//PrntMovie takes a MovieData struct as a parameter and prints its contents
void prntMovie(MovieData movie){
    cout<<"Title: "<<movie.title<<endl;
    cout<<"Director: "<<movie.director<<endl;
    cout<<"Year Released: "<<movie.year<<endl;
    cout<<"Run Time: "<<movie.runTime<<endl;
}
