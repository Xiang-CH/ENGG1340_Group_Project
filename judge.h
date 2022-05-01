// judge.h
#ifndef judge_h
#define judge_h
#include "judge_helper.h"

//Function: For judging if there is five in a row
//Input: x,y: the coordinates of where the go was placed.   gameBoard: current game board.
//        w: width of board.    h: height of board
//Outputs: true or false for whether win or not
bool judge(int x, int y, char ** gameBoard, int w, int h);

#endif