//game_play.cpp
#include "game_play.h"



//pass   two player in this function 
//change the element in two struct 
void addPlayer(Player &player1 , Player &player2){
    string name ; 
    string id ; 
    cout<<"Player 1: please enter your preference name :) and also player id"<<endl;
    cout<<"Name: ";
    cin>> name ; 
    cout<<endl;
    player1.name = name ; 
    cout<<"Id: ";
    cin>>id; 
    cout<<endl; 
    player2.id = id ; 
}

//Function: Randomly generates a number between 0 and 99 and promote players to enter a number
//Output: Return the player with the closer guess
void num_guess(Player &player1 , Player &player2){
    int number1 , number2 ; 
    srand(time(NULL));//randomise
    int guessnumber = rand()%100 ; 
    cout<<"guess time!!! who enter the number close to the random number ranged from 0 to 99 will go first";
    cout<<player1.name<<"please enter a number between 0 to 99";
    cin>>number1;
    //input check
    while(cin.fail()){
        cout<<"please enter a integer"<<endl;
        cin.clear();//clear input buffer 
        cin>>number1;
    }
    cout<<player2.name<<"please enter a number between 0 to 99";
    cin>>number2;
    while(cin.fail()){
        cout<<"please enter a integer"<<endl;
        cin.clear();//clear input buffer 
        cin>>number2;
    }
    //calculate difference part........
    number1 = abs(number1 - guessnumber);
    number2 =abs(number2-guessnumber); 
    if(number1<number2){
        cout<<player1.name<<"go first with O"<<endl;
        player1.go='O';
        player2.go='X';

    }
    else if(number1 > number2){
        cout<<player2.name<<"go first with O"<<endl;
        player2.go='O';
        player1.go='X';

    }
    else if(number1 == number2){
        int start= 0; 
        cout<<"same guess,random start"<<endl;
        start = rand()%2 ; 
        if(start == 0 ){
            cout<<player1.name<<"start first with O"<<endl;
            player1.go='O';
            player2.go='X';
        }
        else{
            cout<<player2.name<<"start first with O"<<endl;
            player2.go='O';
            player1.go='X';
        }
    }

    
}

//Funtion: Place go on the board at location row x and column y
//Input: x,y: the coordinates to place go.   go: the type of go (X or O)
void place_go(char **gameboard, char go, int width , int height ){
    int x , y ; 
    cout<<"please enter the x, y Coordinates in the board";
    while(true){
        cout<<"enter x coordinate: ";
        cin>> x;
        while(cin.fail() or x < 0 or x >= width ){
            cout<<"please enter a valid int";
            cin.clear();
            cin>>x; 
        }
        cout<<"enter y coordinate: ";
        cin>> y ;
        while(cin.fail() or y < 0 or y >= height ){
            cout<<"please enter a valid int";
            cin.clear();
            cin>>y; 
        }
        if(gameboard[y][x]!=' '){
            cout<<"this position is occupied"<<endl;
            continue;
        }
        else{
            gameboard[y][x]= go;
            break;
        }
    }
}

//Function: Switch the current player
//Input: current_player: the current player.  go: the type of go (X or O) for the current player
void switch_player(char &currentGo, Player current_player);
