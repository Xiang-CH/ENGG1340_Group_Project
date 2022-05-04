//save_load.h
#ifndef saveLoad_h
#define saveLoad_h
#include "player.h"
#include "game_play.h"
#include "board.h"
#include <fstream>
#include <iostream>
#include <string>

const char File_Name[19] = "last_game_data.txt";

// Text file format
/*  width height count
    current player name
    player 1 name,go
    player 2 name,go
    board row 1
    board row 2
    ...
*/


//Function: To save the current progress of the game into a text file
//Inputs: current_player: the current player.  p1: player 1.  p2: player2.  gameBoard: the current status of game board
//         width: width of board.    height: height of board.
void save_game(const Player& current_player, const Player& p1, const Player& p2, char ** gameBoard, int width, int height);

//Function: To load previous progress of the game into the current game.
//Inputs: current_player: the current player.  p1: player 1.  p2: player2.  gameBoard: the current status of game board
void load_game(Player& current_player, Player &p1, Player &p2, char ** gameBoard);


//Functions: To get the width and height of the previous game
//Inputs: w: width by reference. h:height by reference
bool get_board_dimension(int &w, int &h);

//Function: To delete the previously saved game data if the player choose to
void delete_game_data();

#endif
