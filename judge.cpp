//
// Created by 陈想 on 1/5/2022.
//
#include "judge.h"

bool judge(int x, int y, char ** gameBoard, int w, int h){
    if (judge_horizontal(x, y, gameBoard, w) || judge_vertical(x, y, gameBoard, h) ||
            judge_leftDown_to_rightTop_diagonal(x, y, gameBoard, h, w) ||
            judge_leftTop_to_rightDown_diagonal(x, y, gameBoard, h, w)){
        return true;
    }
    else{
        return false;
    }
}