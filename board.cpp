#include <iostream>
#include <cstdlib>//rand number generate 
#include <ctime>//call current use for srand()
#include "board.h"


using namespace std ; 

// Function: Prompt user for their desired width and height of board
// Input: w(by reference): width of board.  h(by reference): height of board
//no return value, pass by reference of w and h 
void user_defined_board_size(int &w, int &h){
    cout<<"Please enter the desired width and height of the board respectively";
    cin >> w >> h ;
}

// Function: Intializing the game board with x row and y column
//           Then randomly places 2 crosses and 1 circle on the board
// Input: x: width of board.  y: height of board.   gameBoard: 2D array of board
void init_board(int x, int y, char **gameBoard){
    
    //use array of pointers to realize a function of 2d dynamic arrays 
    gameBoard = new char*[y]; // 1 dimensional  allocate  memory space
    for(int height = 0 ; height < y; height++ ){
        gameBoard[height] = new char[x];
    }
    //two for loops initialise the board 
    for(int row = 0 ; row  < y ; row ++ ){
        for(int column = 0 ; column <x ; column++ ){
            gameBoard[row][column]='!';
        }
    }
    
    srand(time(NULL));
    //randomise 
    char init[3]={'X','O','X'};
    for(int i = 0 ; i < 3 ; i ++){
        int row = rand()%y;
        int column = rand()%x;
        gameBoard[row][column] = init[i]; 
    }

}

// Function: Print the game board
// Input: x: width of board.  y: height of board.   gameBoard: 2D array of board
void print_board(int w, int h, char **gameBoard){
    //some pattern around the board need to be added
    for(int row = 0 ; row < h ; row++){
        cout<<"                         "<<endl;
        for(int column = 0 ; column < w ; column++){
            cout<<""<<gameBoard[row][column];
        }
        cout<<""<<endl;
    }
}
