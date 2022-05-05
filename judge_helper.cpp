#include "judge_helper.h"


bool judge_horizontal(int x, int y, char ** gameBoard, int boardWidth){
    int counter = 1; // for counter number of gos in a row
    int idx = x - 1; // the current x index
    char const goType = gameBoard[y][x]; // the go type placed by user
    // check to the left of the placed go
    while (idx >= 0 and gameBoard[y][idx] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx--;
    }
    //check to the right of the placed go
    idx = x + 1;
    while (idx < boardWidth and gameBoard[y][idx] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx++;
    }
    return false;
}

bool judge_vertical(int x, int y, char ** gameBoard, int boardHeight){
    int counter = 1; // for counter number of gos in a row
    int idx = y - 1; // the current y index
    char const goType = gameBoard[y][x]; // the go type placed by user
    // check to the top of the placed go
    while (idx >= 0 and gameBoard[idx][x] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx--;
    }
    // check to the bottom of the placed go
    idx = y + 1;
    while (idx < boardHeight and gameBoard[idx][x] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx++;
    }
    return false;
}

bool judge_leftTop_to_rightDown_diagonal(int x, int y, char ** gameBoard, int boardHeight, int boardWidth){
    int counter = 1; // for counter number of gos in a row
    int idx = 1; // the current index to add to x and y
    char const goType = gameBoard[y][x]; // the go type placed by user
    // check to the left top of the placed go
    while (x-idx >= 0 && y-idx >=0 && gameBoard[y-idx][x-idx] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx++;
    }
    // check to the right down of the placed go
    idx = 1;
    while (x+idx < boardWidth && y+idx < boardHeight && gameBoard[y+idx][x+idx] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx++;
    }
    return false;
}


bool judge_leftDown_to_rightTop_diagonal(int x, int y, char ** gameBoard, int boardHeight, int boardWidth){
    int counter = 1; // for counter number of gos in a row
    int idx = 1; // the current index to add to x and y
    char const goType = gameBoard[y][x]; // the go type placed by user
    // check to the left down of the placed go
    while (x-idx >= 0 && y+idx < boardHeight && gameBoard[y+idx][x-idx] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx++;
    }
    // check to the right top of the placed go
    idx = 1;
    while (x+idx < boardWidth && y-idx >= 0 && gameBoard[y-idx][x+idx] == goType){
        counter ++;
        if (counter >= 5) return true;
        idx++;
    }
    return false;
}