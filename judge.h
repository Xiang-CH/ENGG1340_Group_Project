// judge.h
#ifndef judge_h
#define judge_h
#include "judge_helper.h"

// Function: To judge if a player won the game
// Input: x,y: the coordinate of the newest placed go.   w: width of game board.    h: height of game board
//        gameBoard: the current game board
// Output: true: the player won.    false: the player did not win
bool judge(int x, int y, char ** gameBoard, int w, int h);

#endif