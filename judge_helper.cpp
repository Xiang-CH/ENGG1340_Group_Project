//
// Created by 陈想 on 1/5/2022.
//
#include "judge_helper.h"


bool judge_horizontal(int x, int y, char ** gameBoard, int boardWidth){
    int counter = 1; // for counter number of gos in a row
    int idx = x - 1; // the current x index
    char const goType = gameBoard[x][y]; // the go type placed by user
    //To the left of the placed go
    while (idx >= 0 and gameBoard[idx][y] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx--;
    }
    //To the right of the placed go
    idx = x + 1;
    while (idx < boardWidth and gameBoard[idx][y] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx++;
    }
    return false;
}

bool judge_vertical(int x, int y, char ** gameBoard, int boardHeight){
    int counter = 1; // for counter number of gos in a row
    int idx = y - 1; // the current x index
    char const goType = gameBoard[x][y]; // the go type placed by user
    //To the top of the placed go
    while (idx >= 0 and gameBoard[x][idx] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx--;
    }
    //To the bottom of the placed go
    idx = x + 1;
    while (idx < boardHeight and gameBoard[x][idx] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx++;
    }
    return false;
}

bool judge_leftTop_to_rightDown_diagonal(int x, int y, char ** gameBoard, int boardHeight, int boardWidth){
    int counter = 1; // for counter number of gos in a row
    int idx = 1; // the current index to add to x and y
    char const goType = gameBoard[x][y]; // the go type placed by user
    //To the left top of the placed go
    while (x-idx >= 0 && y-idx >=0 && gameBoard[x-idx][y-idx] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx++;
    }
    //To the right down of the placed go
    idx = 1;
    while (x+idx < boardWidth && y+idx < boardHeight && gameBoard[x+idx][y+idx] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx++;
    }
    return false;
}


bool judge_leftDown_to_rightTop_diagonal(int x, int y, char ** gameBoard, int boardHeight, int boardWidth){
    int counter = 1; // for counter number of gos in a row
    int idx = 1; // the current index to add to x and y
    char const goType = gameBoard[x][y]; // the go type placed by user
    //To the left down of the placed go
    while (x-idx >= 0 && y+idx < boardHeight && gameBoard[x-idx][y+idx] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx++;
    }
    //To the right top of the placed go
    idx = 1;
    while (x+idx < boardWidth && y-idx >= 0 && gameBoard[x+idx][y-idx] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx++;
    }
    return false;
}