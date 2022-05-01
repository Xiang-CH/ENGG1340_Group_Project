//game_play.cpp
#include "game_play.h"


//pass two player in this function
//change the element in two struct 
void addPlayers(Player &player1 , Player &player2){
    string name ; 

    cout << "Player 1: please enter your preferred name: ";
    cin >> name ;
    player1.name = name ;

    cout << "Player 2: please enter your preferred name: ";
    cin >> name ;
    cout << endl;
    player2.name = name ;
}

//Function: Randomly generates a number between 0 and 99 and promote players to enter a number
//Output: Return the player with the closer guess
void num_guess(Player &player1 , Player &player2){
    int number1 , number2 ; 
    srand(time(NULL));//randomise
    int guessnumber = rand()%100 ; 
    cout<<"Number guess time!!! \nWho ever guesses a number closer to the random number ranging from 0 to 99 will goes first" << endl;
    cout<<player1.name<<" please enter a number between 0 to 99: ";
    cin>>number1;
    //input check
    while(cin.fail() or number1 < 0 or number1 > 99){
        cout<<"please enter a valid number (0-99): ";
        cin.clear();//clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>>number1;
    }
    cout<<player2.name<<"please enter a number between 0 to 99: ";
    cin>>number2;
    while(cin.fail() or number2 < 0 or number2 > 99){
        cout<<"please enter a valid number (0-99): ";
        cin.clear();//clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>>number2;
    }
    //calculate difference part........
    number1 = abs(number1 - guessnumber);
    number2 = abs(number2-guessnumber);
    if(number1<number2){
        cout<<player1.name<<" plays first with O"<<endl;
        player1.go='O';
        player2.go='X';

    }
    else if(number1 > number2){
        cout<<player2.name<<" plays first with O"<<endl;
        player2.go='O';
        player1.go='X';

    }
    else if(number1 == number2){
        int start= 0; 
        cout<<"same guess,random start"<<endl;
        start = rand()%2 ; 
        if(start == 0 ){
            cout<<player1.name<<" plays first with O"<<endl;
            player1.go='O';
            player2.go='X';
        }
        else{
            cout<<player2.name<<" plays first with O"<<endl;
            player2.go='O';
            player1.go='X';
        }
    }

    
}

//Function: Place go on the board at location row x and column y
//Input: x,y: the coordinates to place go.   go: the type of go (X or O)
void place_go(char **gameboard, char go, int width , int height, Player current_player ){
    int x , y ; 
    cout<< current_player.name << "'s round, please place go" << endl;
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
