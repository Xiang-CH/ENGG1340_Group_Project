// game_play.h
#ifndef gamePlay_h
#define gamePlay_h

#include "player.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//pass the address of two player in this function
//change the element in two struct 
void addPlayers(Player &player1 , Player &player2);

//Function: Randomly generates a number between 0 and 99 and promote players to enter a number,
//          Who guess the closer will play O and become the current player
//Input: player 1 by reference, player 2 by reference, current player by reference
void num_guess(Player &player1 , Player &player2, Player &currentPlayer);

//Function: Place go on the board at location row x and column y by user input.
//Input: width, height: width and height of the game board.  gameBoard: the current game board
//       current_player: the current player
//Output: True player wants to save game,  False: Player wants to continue the game
bool place_go(char **gameBoard, int width , int height, Player& current_player);

//Function: Switch the current player
//Input: current_player: the current player by reference.  player1: player 1.   player2L player 2.
void switch_player(const Player& player1, const Player& player2, Player& current_player);

#endif