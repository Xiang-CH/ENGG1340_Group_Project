//judge_helper.h
#ifndef judgeHelper_h
#define judgeHelper_h

//Function: Judgeing if their is five in a row in the horizontal direction
//Input: x,y: the coordinate of the newly placed go
//Output: true of false for whether their is five in a row in the horizontal direction
bool judge_horizontal(int x, int y);

//Function: Judgeing if their is five in a row in the vertical direction
//Input: x,y: the coordinate of the newly placed go
//Output: true of false for whether their is five in a row in the vertical direction
bool judge_vertical(int x, int y);

//Function: Judgeing if their is five in a row in the diagonal directions
//Input: x,y: the coordinate of the newly placed go
//Output: true of false for whether their is five in a row in the diagonal directions
bool judge_diagonal(int x, int y);

#endif