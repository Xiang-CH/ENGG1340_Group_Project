// board.h
#ifndef board_h
#define board_h
#include <iostream>
#include <cstdlib>//rand number generate 
#include <ctime>//call current use for srand()

using namespace std ; 

// Function: Prompt user for their desired width and height of board
// Input: w(by reference): width of board.  h(by reference): height of board
void user_defined_board_size(int &w, int &h);

// Function: Initializing the game board with x row and y column
//           Then randomly places 2 crosses and 1 circle on the board
// Input: x: width of board.  y: height of board.   gameBoard: 2D array of board
void init_board(int x, int y, char ** gameBoard);


// Function: Print the game board
// Input: x: width of board.  y: height of board.   gameBoard: 2D array of board
void print_board(int w, int h, char ** gameBoard);

#endif 
