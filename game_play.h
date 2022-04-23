// game_play.h
#ifndef gamePlay_h
#define gamePlay_h
#include "player.h"

//Function: Randomly generates a number between 0 and 99 and promote players to enter a number
//Output: Return the player with the closer guess
int num_guess();

//Funtion: Place go on the board at location row x and column y
//Input: x,y: the cooridinates to place go.   go: the type of go (X or O)
void place_go(int x, int y, char go);

//Function: Switch the current player
//Input: current_player: the current player.  go: the type of go (X or O) for the current player
void switch_player(char &currentGo, Player *&current_player);

#endif
