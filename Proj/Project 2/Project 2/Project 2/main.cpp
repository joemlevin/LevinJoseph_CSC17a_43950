/* 
 * File:   main.cpp
 * Author: Joseph Levin
 * C++ Project 2 - Spring 2015 43950
 * 6/5/2015
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

//User Libraries
#include "mastermind.h"
#include "DerivBS.h"

//Global Constants

//Function Prototypes
Answer *getAns(int,int);//generates an answer
bool again();//replay function
bool menu();//returns to menu
int *getG(int);//gets guess from user
int getL();//returns length for code combination
short slct();
Stats *load();//loads stats structure
void play(Stats *,int,int);//launches the game
void pAns(Answer *,Guesses *,int);//prints the answer
void save(Stats *);//saves the stats structure as binary file
void pBoard(Guesses *,Answer *,int);//prints the game board
void checkG(Answer *,Guess *,int);//checks guess against answer
void instrct();
void purge(Answer *, Guesses *,int);//deletes all structures related to a game
void seeStats(Stats *);//Displays stats
void clrscrn();//clears screen
void playMM(Stats *);//driver for mastermind game
void playBS(Stats *);//driver for battleship 
int getDim();//gets dimension for BattleShip board

//Begin
int main(int argc, char** argv) {
//    srand(time(0));
//    short optn;
    Stats *s=new Stats;
    s->wins=0;
    s->loses=0;
    s->nGuess=0;
//    do{
//        clrscrn();
//        optn=slct();
//        switch(optn){
//            case 1:
//                do{
//                    clrscrn();
//                    instrct();
//                }while(!menu());
//                break;
//            case 2:
//                s=load();
//                break;
//            case 3:
//                do{
//                    clrscrn();
//                    seeStats(s);
//                }while(!menu());
//                break;
//            case 4:
//                do{
//                    clrscrn();
//                    int l=getL();
//                    play(s,10,l);
//                }while(again());
//                break;
//            case -1:
//                cout<<"Thanks for playing!"<<endl;
//                break;
//            default:
//                cout<<"Invalid option selected..."
//                        "it's not that hard, really."<<endl;
//                break;
//        }
//    }while(optn!=-1);
//    //clean up!
//    delete s;

    playBS(s);
    return 0;
}

//!Clear screen function outputs a ton of new lines in order to clear
//!the command prompt to look nice
void clrscrn(){
    for(int i=0; i<100; i++)
        cout<<endl;
}//end
//!getAns dynamically creates a Answer struct, fills the code array with
//!random integers 0-9, sets nGuess to max (max # of guesse) and then returns
Answer *getAns(int max, int row){
    Answer *answer=new Answer;
    answer->mxGuess=max;//max number of guesses allowed
    answer->code=new int[row];//the combination is 'row' digits long
    for(int i=0;i<row;i++)
        answer->code[i]=rand()%8+1;//fill code with 1-9
    return answer;
}//end
//!checkG takes in an Answer struct. It copies the contents of the code array
//!into another int array and compares each element to a Guess array
//!It changes the elments in the temp int array to -1 as it finds matches
//!in order to ensure no duplicate matches are found
//!if an element in the guess matches the position and number of the answer
//!both the correct number and correct position counters are incremented
//!otherwise if only the number is matched then the correct number indication
//!is incremented. Man this is a long description.
void checkG(Answer *a,Guesses *g,int row){
    int *ta=new int[row];//temp array to store answer
    int *tg=new int[row];//temp array to store guess
    for(int i=0;i<row;i++){
        ta[i]=a->code[i];//copy answer to temp answer
        tg[i]=g->guess[g->nGuess-1].code[i];//copy guess to temp guess
    }
    //loop through arrays to check for both correct position and correct number
    for(int i=0;i<row;i++){
        if(tg[i]==ta[i]){
            g->guess[g->nGuess-1].corPos++;
            g->guess[g->nGuess-1].corNum++;
            ta[i]=-1;//no duplicates
            tg[i]=-1;
        }
    }
    //loop through temp answer again
    for(int i=0;i<row;i++){
        //loop through guess
        for(int j=0;j<row;j++){
            //check for same number
            if(ta[i]==tg[j]&&i!=j&&tg[j]!=-1&&ta[i]!=-1){//same num, diff pos
                g->guess[g->nGuess-1].corNum++;
                ta[i]=-1;
                tg[j]=-1;
            }
        }
    }
    delete []ta;
    delete []tg;
}//end
/*!
 * getG prompts the user to enter a 4 digit combination, separated by spaces
 * it stores it as a string, and checks if every odd element is a digit 1-8
 * and then checks if every even is a space
 * if this is true, it then converts each odd element into an int and stores
 * it in an int array and returns this array
 * takes an int to specify how big an int array to create
 */
int *getG(int row){
    //declare variables
    int *temp=new int[row];//will be returned
    string guess;//for character checking
    bool check;//input validation
    cout<<"Enter a "<<row
            <<" digit combination (1-8) separated by spaces."<<endl;
    do{
        check=true;
        getline(cin,guess);
        if(guess.size()!=2*row-1){//row digits plus spaces between
            cout<<"You must enter "<<row<<" digits separated by spaces."
                    <<"Try again!"<<endl;
            check=false;;
        }
        else{
            //every odd must be 1-8, and every even must be space
            for(int i=0;i<2*row-1;i++){
                //check odds for all digits
                if(i%2==0&&!isdigit(guess[i])){
                    check=false;
                    cout<<"Please only enter digits. Try again!"<<endl;
                }
                //check if all digits are 1-8
                else if(i%2==0&&(atoi(&guess[i])>8||atoi(&guess[i])<1)){
                    check=false;
                    cout<<"Digits must all be between 1 & 8. Try again!"<<endl;
                    break;
                }
                //check if every even is space
                else{
                    if(!isspace(guess[i])&&!isdigit(guess[i])){
                        check=false;
                        cout<<"Every digit must be "
                                <<"separated by a space. Try again!"<<endl;
                    }
                }
            }   
        }
    }while(!check);
    //copy digits into int array to return
    for(int i=0;i<row;i++)
        temp[i]=atoi(&guess[2*i]);
    //int array ready to return
    return temp;
}//end
/*!
 * pBoard takes in pointers to an Answer and Guess, and an int
 * specifying the code length. It prints out dashed lines indicating
 * how many guesses remain and also prints out all previous guesses
 */
void pBoard(Guesses *g, Answer *a, int r){
    //X's represent the mystery code
    for(int i=0;i<r;i++)
        cout<<"X ";
    cout<<endl;
    //-'s represent spaces left for remaining guesses
    for(int i=0;i<(a->mxGuess)-(g->nGuess)+1;i++){
        for(int j=0;j<r;j++)
            cout<<"- ";
        cout<<endl;
    }
    //all previous guesses
    if(g->nGuess-1!=0){
    for(int i=g->nGuess-2;i>=0;i--){
        for(int j=0;j<r;j++)
            cout<<g->guess[i].code[j]<<" ";
        cout<<" N:"<<g->guess[i].corNum
        <<" P:"<<g->guess[i].corPos<<endl;
    }
    }
 //finished
}//end
/*!
 * getL prompts the user to enter either 4, 6, or 8. It then returns
 * the value selected as an int. No parameters
 */
int getL(){
    int l;//length of code
    bool check=false;//error checking flag
    cout <<"Please the code length!"<<endl<<"Options: 4, 6, 8"<<endl;
    do{
        cin>>l;
        if(cin.fail()||(l!=4&&l!=6&&l!=8)){
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Sorry! You have to choose "
                    "either 4, 6, or 8. Try again!"<<endl;
        }
        else
            check=true;
    }while(!check);
    return l;
}//end
/*!
 * pAns prints the answer code
 */
void pAns(Answer *a,Guesses *g,int r){
    //Show Answer
    for(int i=0;i<r;i++)
        cout<<a->code[i]<<" ";
    
    cout<<" <- Answer!"<<endl;
    //-'s represent spaces left for remaining guesses
    for(int i=0;i<(a->mxGuess)-(g->nGuess);i++){
        for(int j=0;j<r;j++)
            cout<<"- ";
        cout<<endl;
    }
    //all previous guesses
    if(g->nGuess!=0){
    for(int i=g->nGuess-1;i>=0;i--){
        for(int j=0;j<r;j++)
            cout<<g->guess[i].code[j]<<" ";
        cout<<" N:"<<g->guess[i].corNum
        <<" P:"<<g->guess[i].corPos<<endl;
    }
    }
}//end
/*!
 * play is the main driver for Mastermind gameplay. It handles turn taking,
 * win/lose checks, as well as stat saving. Void function, takes in an integer
 * to determine max # of guesses and an integer to determine code length
 */
void play(Stats *s,int m,int r){
    //generate answer
    cin.clear();
    cin.ignore(265,'\n');
    char optn;
    Answer *a=getAns(m,r);
    //generate and prepare Guesses
    Guesses *g=new Guesses;
    g->nGuess=0;
    g->guess=new Guess[m];
    for(int i=0;i<m;i++){
        g->guess[i].corNum=0;
        g->guess[i].corPos=0;
    }
    //loop until win/lose
    do{
        clrscrn();
        g->nGuess++;
        pBoard(g,a,r);
        g->guess[g->nGuess-1].code=getG(r);
        checkG(a,g,r);
    }while(g->nGuess<a->mxGuess&&g->guess[g->nGuess-1].corPos!=r);
    clrscrn();
    pAns(a,g,r);
    if(g->guess[g->nGuess-1].corPos==r){
        cout<<"You cracked the code! You win!"<<endl;
        s->wins++;
    }
    else{
        cout<<"You didn't crack the code! You lose... Sorry!"<<endl;
        s->loses++;
    }
    s->nGuess+=g->nGuess;
    cout<<"Would you like to save your stats? y/n"<<endl;
    do{
        cin>>optn;
        if(tolower(optn)!='y'&&tolower(optn)!='n')
            cout<<"Sorry, that's not a valid option. Please try again."<<endl;
        else if(tolower(optn)=='y'){
            save(s);
            cout<<"Stats saved!"<<endl;
        }
        else
            cout<<"Stats not saved."<<endl;
    }while(tolower(optn)!='y'&&tolower(optn)!='n');
    //clean up
    purge(a,g,m);
}//end
/*!
 * purge takes in an Answers and Guesses pointer and deletes all dynamically
 * allocated elements of the struct, as well as the structs themselves
 * and then points them to nullptrs
 */
void purge(Answer *a,Guesses *g,int m){
    delete []a->code;
    a->code=NULL;
    delete a;
    for(int i=0;i<m;i++){
        delete []g->guess[i].code;
        g->guess[i].code=NULL;
    }
    delete g->guess;
    g->guess=NULL;
    delete g;
    g=NULL;
}
/*!
 * save takes in a Stats struct pointer. It prompts the user for a name
 * to store the stats struct under, and then writes the contents of the Stats
 * to a binary file. Returns void
 */
void save(Stats *s){
    cin.clear();
    cin.ignore(256,'\n');
    ofstream out;//file stream
    cout<<"Enter the name to store the stats under"<<endl;
    string name;
    getline(cin,name);
    out.open(name.c_str(),ios::binary);
    out.write(reinterpret_cast<char *>(s),sizeof(Stats));
    out.close();
}//end
/*!
 * load prompts the user for a name, and attempts to open a file
 * with that name. If found, it reads the contents into a Stats structure
 * and returns it.
 */
Stats *load(){
    cin.clear();
    cin.ignore(256,'\n');
    string name;
    ifstream in;
    cout<<"Enter the name of the person whose stats to load"<<endl;
    do{
        getline(cin,name);
        in.open(name.c_str(),ios::binary);
        if(in.fail()){
            cout<<"Name not found. Try again!"<<endl;
        }
        else{
            Stats *s=new Stats;
            in.read(reinterpret_cast<char *>(s),sizeof(Stats));
            in.close();
            return s;
        }
    }while(in.fail());
}
//!slct serves to take in input for menu selection, performs error checks
//!and then returns the value if it passes checks
short slct(){
    short pick; //for menu selection
    bool check=false;
    cout<<"Welcome to Mastermind!"<<endl;
    cout<<"Choose an option from the menu: "<<endl
            <<"1. View Instructions"<<endl
            <<"2. Load Stats File"<<endl
            <<"3. View Stats"<<endl
            <<"4. Play Game!"<<endl
            <<"-1 to quit"<<endl;
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
 * again asks the user if they would like to play another game
 * it returns true if the user does, false if they do not
 */
bool again(){
    bool check=false;
    char pick;
    cout<<"Would you like to play again? y/n"<<endl;
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
 * menu prompts the user if they want to return to the main menu.
 * if the user types 'y', it returns true
 * if the user types 'n', it returns false
 */
bool menu(){
    bool check=false;
    char pick;
    cout<<"Would you like to return to the menu? y/n"<<endl;
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
}
/*!
 * seeStats takes in Stats pointer. It displays the elements within,
 * (wins/loses/total guesses) and also calculates win percentage, and
 * correct guess percentage
 */
void seeStats(Stats *s){
    if(s->nGuess!=0){
        cout<<"Games played: "<<s->wins+s->loses<<endl;
        cout<<"Wins: "<<s->wins<<endl;
        cout<<"Losses: "<<s->loses<<endl;
        cout<<"Total guesses: "<<s->nGuess<<endl;
        cout<<setprecision(2)<<fixed
                <<"% Games won: "<<100*static_cast<float>(s->wins)/
               (static_cast<float>(s->wins)+static_cast<float>(s->loses))<<endl;
        cout<<setprecision(5)<<fixed
                <<"% Guesses correct: "<<100*static_cast<float>(s->wins)/
                static_cast<float>(s->nGuess)<<endl;
    }
    else
        cout<<"Stats File is empty!"<<endl;
}
/*!
 * instrct displays the rules for Code Breaker (based on Mastermind)
 */
void instrct(){
    cout<<"Mastermind is a game of decryption!"<<endl<<endl
            <<"In it, the player (that's you!)"<<endl
            <<"attempts to decipher a secret code generated at random."<<endl
            <<"The code consists of integers between 1 and 8."<<endl
            <<"The player chooses from 3 code lengths (4, 6, 8),"<<endl
            <<"and guesses at each of the individual digits that make up"
            " the secret code."<<endl
            <<"After each attempt the player is told how "
            "many correct numbers"<<endl
            <<"(shown as 'N') and correct position "
            "(shown as 'P') the attempt had."<<endl
            <<"The player wins by correctly determining"
            " all 4 correct numbers and positions."<<endl
            <<"Remember, a guess can have 4 correct numbers but 0 correct "
            "positions,"<<endl
            <<"but you can't have a correct position without"
            " it also being the correct number."<<endl
            <<endl<<"Good luck!"<<endl;
}//end
/*!
 * playBS is the main driver for BattleShip.
 * Parameters: a stats struct for storing stats
 */
void playBS(Stats *){
    int dim;//for storing dimension of board
    bool sConf=false;//confirming size is valid
    cout<<"Welcome to BattleShip!"
            " Please select the size board you'd like to play."<<endl;
    cout<<"1. 6x6"<<endl;
    cout<<"2. 8x8"<<endl;
    cout<<"3. 10x10"<<endl;
    do{
        try{
            dim=getDim();
            sConf=true;
        }
        catch(string invalid){
            cout<<invalid<<endl;
        }
    }while(!sConf);
    //initialize BaseBS (for player) and DerivBS (for computer) of dim
    BaseBS player(dim);
    DerivBS comp(dim);
    //randomly place computer's ships
    comp.place();
    //place players ships
    player.place();
    //begin rounds
    do{
        clrscrn();
        cout<<"Player board ("<<player.getShips()<<" ships remain)"<<endl;
        player.pBoard();
        cout<<endl;
        cout<<"Radar ("<<comp.getShips()<<" enemy ships remain)"<<endl;
        comp.pBoard();
        player.target();
        comp.target();
    }while(comp.getShips()!=0&&player.getShips()!=0);
    //Display boards final time
    cout<<"Player board ("<<player.getShips()<<" ships remain)"<<endl;
    player.pBoard();
    cout<<endl;
    cout<<"Radar ("<<comp.getShips()<<" enemy ships remain)"<<endl;
    comp.radar();
    //Determine victor
    if(comp.getShips()==0){
        cout<<"You win! Congratulations!"<<endl;
    }
    else{
        cout<<"You lose. Sorry!"<<endl;
    }
}//end
/*!
 * getDim prompts user for dimension for BattleShip board. It will throw
 * an exception if invalid, otherwise returns the value
 */
int getDim(){
    int dim;
    cin>>dim;
    if(dim<1||dim>3||cin.fail()){
        string invalid="Invalid selection for dimension. Try again.";
        throw invalid;
    }
    if(dim==1){
        dim=6;
    }
    else if(dim==2){
        dim=8;
    }
    else{
        dim=10;
    }
    return dim;
}