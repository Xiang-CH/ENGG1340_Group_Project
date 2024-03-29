//game_play.cpp
#include "game_play.h"



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


void num_guess(Player &player1 , Player &player2, Player &currentPlayer){

    int number1 , number2 ; 
    srand(seed2);//randomise
    int guessnumber = rand()%100 ;//generate the number need to be guessed by players
    cout<<"Number guess time!!! \nWho ever guesses a number closer to the random number ranging from 0 to 99 will go first" << endl;
    cout<<player1.name<<" please enter a number between 0 to 99: ";
    cin>>number1;
    //input check
    while(cin.fail() or number1 < 0 or number1 > 99){
        cout<<"Please enter a valid number (0-99): ";
        cin.clear();//clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the char of enter a newline
        cin>>number1;
    }
    cout<<player2.name<<" please enter a number between 0 to 99: ";
    cin>>number2;
    //input check
    while(cin.fail() or number2 < 0 or number2 > 99){
        cout<<" please enter a valid number (0-99): ";
        cin.clear();//clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//ignore the char of enter a newline
        cin>>number2;
    }
    //calculate difference part........
    number1 = abs(number1 - guessnumber);
    number2 = abs(number2-guessnumber);
    //determine the first start player according to the guess
    if(number1<number2){
        cout<<player1.name<<" plays first with the go: O"<<endl;
        player1.go='O';
        player2.go='X';
        currentPlayer = player1;

    }
    else if(number1 > number2){
        cout<<player2.name<<" plays first with the go: O"<<endl;
        player2.go='O';
        player1.go='X';
        currentPlayer = player2;

    }
    else if(number1 == number2){
        int start= 0; 
        cout<<"same guess,random start"<<endl;
        start = rand()%2 ; 
        if(start == 0 ){
            cout<<player1.name<<" plays first with the go O"<<endl;
            player1.go='O';
            player2.go='X';
            currentPlayer = player1;
        }
        else{
            cout<<player2.name<<" plays first with the go O"<<endl;
            player2.go='O';
            player1.go='X';
            currentPlayer = player2;
        }
    }

    
}


bool place_go(char **gameBoard, int width , int height, Player& current_player ){
    int x , y ;
    cout << endl;
    cout << current_player.name << "'s round, please place go (" << current_player.go <<")"<< endl;
    cout << "Enter -1 to save game" << endl;
    while(true){
        cout<<"Enter x coordinate: ";
        cin>> x;
        while(cin.fail() or x < -1 or x >= width ){
            cout<<"please enter a valid int： ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>x; 
        }
        if (x == -1){
            return true;
        }
        cout<<"Enter y coordinate: ";
        cin>> y ;
        while(cin.fail() or y < 0 or y >= height ){
            cout<<"Please enter a valid int： ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>y; 
        }
        if(gameBoard[y][x]!='_'){
            cout<<"This position is occupied"<<endl;
            continue;
        }
        else{
            gameBoard[y][x]= current_player.go;
            current_player.x = x;
            current_player.y = y;
            break;
        }
    }
    return false;
}


bool switch_go(char **gameboard , int width , int height , const Player &player1 , const Player &player2  ){
    //use for store the x, y coordinate of a go
    struct point{
        int xcoordinate ;
        int ycoordinate ;
    };

    //use for store the point of go which is X and O
    vector<point>cross;
    vector<point>circle;

    point currentposition;
    point position;

    cout<<"Heartbeat time!\none of each player's go will switch automatically"<<endl;

    //loop through all the element and find the point is X and O
    //add them to vector respectively
    for(int row = 0 ; row < height ; row++ ){
        for(int column = 0 ; column < width ; column++ ){
            if(gameboard[row][column]=='X'){
                currentposition.xcoordinate=column;
                currentposition.ycoordinate=row;
                cross.push_back(currentposition);
            }
            else if(gameboard[row][column] == 'O'){
                currentposition.xcoordinate=column;
                currentposition.ycoordinate=row;
                circle.push_back(currentposition);
            }
        }
    }

    int index = 0 ;
    srand(seed2);//randomise
    //store the position in two variable, current position and position for switch use
    index = rand()%cross.size();
    currentposition = cross[index];
    index = rand()%circle.size();
    position = circle[index];

    //directly change the go  opposite
    gameboard[currentposition.ycoordinate][currentposition.xcoordinate] = 'O';
    gameboard[position.ycoordinate][position.xcoordinate]='X';
    print_board(width,height,gameboard);

    //check-win due to the switch
    if( judge(currentposition.xcoordinate,currentposition.ycoordinate,gameboard,width,height) &&
            judge(position.xcoordinate,currentposition.ycoordinate,gameboard,width,height)){
        cout<<"tie"<<endl;
        return true;
    }
    else if(judge(currentposition.xcoordinate,currentposition.ycoordinate,gameboard,width,height)){
        if(player1.go=='O'){
            cout<<player1.name<<"Won!"<<endl;
        }
        else{
            cout<<player2.name<<"Won!"<<endl;
        }
        return true;
    }
    else if(judge(position.xcoordinate,position.ycoordinate,gameboard,width,height)){
        if(player1.go=='X'){
            cout<<player1.name<<"Won!"<<endl;
        }
        else{
            cout<<player2.name<<"Won!"<<endl;
        }
        return true;
    }

    return false;

}


void switch_player(const Player& player1, const Player& player2, Player& current_player){
    if (player1.id == current_player.id){
        current_player = player2;
    }
    else{
        current_player = player1;
    }
}


int count_go(char **gameBoard , int width , int height){

    int counter = 0 ;
    for(int row =0 ; row < height ; row ++ ){
        for( int column  = 0 ; column < width ; column++ ){
            if(gameBoard[row][column]!= '_'){
                counter++;
            }
        }
    }
    return counter ;
}
