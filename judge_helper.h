//judge_helper.h
#ifndef judgeHelper_h
#define judgeHelper_h

//Function: Judging if there is five in a row in the horizontal direction
//Input: x,y: the coordinate of the newly placed go.  boardWidth: the width of the board, gameBoard: game board
//Output: true of false for whether there is five in a row in the horizontal direction
bool judge_horizontal(int x, int y, char ** gameBoard, int boardWidth);

//Function: Judging if there is five in a row in the vertical direction
//Input: x,y: the coordinate of the newly placed go. boardWidth: the Height of the board, gameBoard: game board
//Output: true of false for whether there is five in a row in the vertical direction
bool judge_vertical(int x, int y, char ** gameBoard, int boardHeight);

//Function: Judging if there is five in a row in the diagonal directions left top to right down (\)
//Input: x,y: the coordinate of the newly placed go. boardWidth,boardHeight: the width/height of the board, gameBoard: game board
//Output: true of false for whether there is five in a row in the diagonal directions
bool judge_leftTop_to_rightDown_diagonal(int x, int y, char ** gameBoard, int boardHeight, int boardWidth);

//Function: Judging if there is five in a row in the diagonal directions left down to right top (/)
//Input: x,y: the coordinate of the newly placed go. boardWidth,boardHeight: the width/height of the board, gameBoard: game board
//Output: true of false for whether there is five in a row in the diagonal directions
bool judge_leftDown_to_rightTop_diagonal(int x, int y, char ** gameBoard, int boardHeight, int boardWidth);

#endif